#include "../include/DrawingCanvas.h"
#include <wx/graphics.h>
#include <wx/dcbuffer.h>
#include <libssh2.h>
wxDEFINE_EVENT(CANVAS_RECT_ADDED, wxCommandEvent);
wxDEFINE_EVENT(CANVAS_RECT_REMOVED, wxCommandEvent);


DrawingCanvas::DrawingCanvas(wxWindow *parent, wxWindowID id, const wxPoint &pos, const wxSize&size):wxWindow(parent,id,pos,size)
{

    this->SetBackgroundStyle(wxBG_STYLE_PAINT); // needed for windows


    this->Bind(wxEVT_PAINT, &DrawingCanvas::OnPaint,this);
    this->Bind(wxEVT_LEFT_DOWN, &DrawingCanvas::OnMouseDown, this);
    this->Bind(wxEVT_RIGHT_DOWN, &DrawingCanvas::OnRighClick, this);
    this->Bind(wxEVT_MOTION, &DrawingCanvas::OnMouseMove, this);
    this->Bind(wxEVT_LEFT_UP, &DrawingCanvas::OnMouseUp, this);
    this->Bind(wxEVT_LEAVE_WINDOW, &DrawingCanvas::OnMouseLeave, this);

    addNewObject(this->FromDIP(100), this->FromDIP(25), this->FromDIP(510), this->FromDIP(20), 0, *wxRED, "Rect #1", "container");
    addNewObject(this->FromDIP(100), this->FromDIP(25), this->FromDIP(510), this->FromDIP(50), 0, *wxBLUE, "Rect #2", "container");
    addNewObject(this->FromDIP(100), this->FromDIP(25), this->FromDIP(510), this->FromDIP(80), 0, wxColor(255, 0, 255, 128), "Rect #3", "container");
    addNewObject(this->FromDIP(100), this->FromDIP(25), this->FromDIP(510), this->FromDIP(110), 0, wxColor(255, 0, 255, 128), "Rect #3", "container");

    this->draggedObj = nullptr;
    this->shouldRotate = false;
}

void DrawingCanvas::addNewObject(int width, int height, int centerX, int centerY, double angle, wxColor color, const std::string &text, const std::string &objectType)
{
    GraphicObject newObject;
    newObject.rect = {  -(width / 2.0),  -(height / 2.0), static_cast<double>(width), static_cast<double>(height) };
    newObject.color = color;
    newObject.text = text;
    newObject.objectType = objectType;
    newObject.connectedToId = 0;
    newObject.postion.x = centerX;
    newObject.postion.y = centerY;
    newObject.transform.Translate( static_cast<double>(centerX), static_cast<double>(centerY));
    newObject.transform.Rotate(angle);
    this->objectList.push_back(newObject);

    sendRectAddedEvent(text);
    Refresh();
}

void DrawingCanvas::removeTopRect()
{
    if (!this->objectList.empty() && draggedObj == nullptr)
    {
        auto text = this->objectList.back().text;
        this->objectList.pop_back();

        sendRectRemovedEvent(text);
        Refresh();
    }
}

void DrawingCanvas::OnPaint(wxPaintEvent &evt)
{
    wxAutoBufferedPaintDC dc(this);
    dc.Clear();
    wxGraphicsContext *gc = wxGraphicsContext::Create(dc);
    if(gc)
    {
        for (const auto &object : objectList)
        {
            //gc->SetTransform(gc->CreateMatrix(object.transform));

            if (object.connectedToId != 0){
                for (const GraphicObject& endPoint : objectList) {
                    if (endPoint.id == object.connectedToId ) {
                        gc->SetPen(wxPen(wxColour(0, 0, 0), 3)); // Black color, 2-pixel width
                        gc->StrokeLine(object.postion.x, object.postion.y, endPoint.postion.x, endPoint.postion.y);
                   //     gc->StrokeLine(object.rect.m_x, object.rect.m_y, endPoint.rect.m_x, endPoint.rect.m_y);
                        break;
                    }
                }
            }


            if (select1 && select2){
                if (object.id == select1->id || object.id == select2->id ){
                    gc->SetPen(wxPen(wxColour(0, 0, 0), 5)); // Black color, 2-pixel width
                }else{
                    gc->SetPen(wxPen(wxColour(0, 0, 0), 1)); // Black color, 2-pixel width
                }
            }else if (select1){
                if (object.id == select1->id ){
                    gc->SetPen(wxPen(wxColour(0, 0, 0), 5)); // Black color, 2-pixel width
                }else{
                    gc->SetPen(wxPen(wxColour(0, 0, 0), 1)); // Black color, 2-pixel width
                }
            }else if (select2){
                if (object.id == select2->id ){
                    gc->SetPen(wxPen(wxColour(0, 0, 0), 5)); // Black color, 2-pixel width
                }else{
                    gc->SetPen(wxPen(wxColour(0, 0, 0), 1)); // Black color, 2-pixel width
                }

            }else{
                gc->SetPen(wxPen(wxColour(0, 0, 0), 1)); // Black color, 2-pixel width
            }

            gc->SetBrush(wxBrush(object.color));
            double textWidth,textHeight;
            gc->DrawRectangle(object.postion.x + object.rect.m_x, object.postion.y + object.rect.m_y, object.rect.m_width, object.rect.m_height);
            gc->SetFont(*wxNORMAL_FONT,*wxWHITE);
            gc->GetTextExtent(object.text, &textWidth, &textHeight);
            gc->DrawText(object.text, object.postion.x + object.rect.m_x + (object.rect.m_width - textWidth) / 2.0, object.rect.m_y + object.postion.y + (object.rect.m_height - textHeight) / 2.0 );
       }
        delete gc;
    }
}
void DrawingCanvas::OnRighClick(wxMouseEvent &event){
        wxPoint clickPos = event.GetPosition();
        PopupDialog dialog(this);

        // Show the dialog as a modal dialog
        int result = dialog.ShowModal();
        // Process user selection
        if (result != wxID_CANCEL) {
            std::string option = dialog.GetSelectedOption();
            if (option == "container"){
                addNewObject(this->FromDIP(100), this->FromDIP(25), this->FromDIP(clickPos.x), this->FromDIP(clickPos.y), 0, *wxRED, option, option);
            } else if(option == "vSwitch"){
                addNewObject(this->FromDIP(100), this->FromDIP(25), this->FromDIP(clickPos.x), this->FromDIP(clickPos.y), 0, *wxGREEN,option,option);
            }

        } else {
            std::cout << "Cancel" << std::endl;
        }
}
void DrawingCanvas::connectSelected(){

    if (!select1  || !select2  ||  (select1->id == select2->id)){
    wxMessageBox("Two elements must be selected", "Connection ", wxOK | wxICON_ERROR);
       return ;
    }else{

        if (select1->objectType == "container" && select2->objectType == "vSwitch"){
            select1->connectedToId = select2->id;
            Refresh();
        }else if (select2->objectType == "container" && select1->objectType == "vSwitch"){
            select2->connectedToId = select1->id;
            Refresh();
        }
    }
}

void DrawingCanvas::OnMouseDown(wxMouseEvent &event)
{
    wxPoint clickPos = event.GetPosition();
    int range = 20; // Set the range to 5 pixels, adjust as needed

    auto clickedObjectIter = std::find_if(objectList.rbegin(), objectList.rend(), [clickPos, range](const GraphicObject &o)
    {
        return (clickPos.x >= o.postion.x - range && clickPos.x <= o.postion.x + range &&
                clickPos.y >= o.postion.y - range && clickPos.y <= o.postion.y + range);
    });


    if (clickedObjectIter != objectList.rend())
    {
        auto forwardIt = std::prev(clickedObjectIter.base());

        objectList.push_back(*forwardIt);
        objectList.erase(forwardIt);

        draggedObj = &(*std::prev(objectList.end()));
        if (select1  && select2  ){
            if (draggedObj->id == select2->id || draggedObj->id == select1->id){
            }else{
                select1 = select2;
                select2 = draggedObj;
            }
        }else if(!select2){
            select2 = draggedObj;
        }else if(!select1){
            select1 = select2;
            select2 = draggedObj;
        }

        lastDragOrigin = event.GetPosition();
     //   shouldRotate = wxGetKeyState(WXK_ALT);

        Refresh(); // for z order reversal
    }else{

    }
}
void DrawingCanvas::OnMouseMove(wxMouseEvent &event)
{
    if (draggedObj != nullptr)
    {




        if (shouldRotate)
        {
            double absoluteYDiff = event.GetPosition().y - lastDragOrigin.m_y;
            draggedObj->transform.Rotate(absoluteYDiff / 100.0 * M_PI);
        }
        else
        {

            draggedObj->postion = event.GetPosition();
        }

        lastDragOrigin = event.GetPosition();
        Refresh();
    }
}

void DrawingCanvas::OnMouseUp(wxMouseEvent &event)
{
    finishDrag();
    finishRotation();
}

void DrawingCanvas::OnMouseLeave(wxMouseEvent &event)
{
    finishDrag();
    finishRotation();
}

void DrawingCanvas::finishDrag()
{
    draggedObj = nullptr;
}

void DrawingCanvas::finishRotation()
{
    shouldRotate = false;
}

void DrawingCanvas::sendRectAddedEvent(const wxString &rectTitle)
{
    wxCommandEvent event(CANVAS_RECT_ADDED, GetId());
    event.SetEventObject(this);
    event.SetString(rectTitle);

    ProcessWindowEvent(event);
}

void DrawingCanvas::sendRectRemovedEvent(const wxString &rectTitle)
{
    wxCommandEvent event(CANVAS_RECT_REMOVED, GetId());
    event.SetEventObject(this);
    event.SetString(rectTitle);

    ProcessWindowEvent(event);
}

DrawingCanvas::~DrawingCanvas()
{
    //dtor
}
