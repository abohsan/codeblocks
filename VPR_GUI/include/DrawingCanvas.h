#ifndef DRAWINGCANVAS_H
#define DRAWINGCANVAS_H
#include <wx/wx.h>
#include <list>
#include "graphicobject.h"
#include "PopupDialog.h"
//int MyStruct::staticMember = 10; // Definition of the static member
wxDECLARE_EVENT(CANVAS_RECT_ADDED, wxCommandEvent);
wxDECLARE_EVENT(CANVAS_RECT_REMOVED, wxCommandEvent);


class DrawingCanvas: public wxWindow
{
public:
    DrawingCanvas(wxWindow *parent, wxWindowID id, const wxPoint &pos, const wxSize&size);
    virtual ~DrawingCanvas();
    void addNewObject(int width, int height, int centerX, int centerY, double angle, wxColor color, const std::string &text, const std::string &objectType);
    void removeTopRect();

    int getObjectCount()
    {
        return objectList.size();
    }
    void connectSelected();
protected:

private:
    void OnPaint(wxPaintEvent &evt);
    void OnMouseDown(wxMouseEvent &event);
    void OnMouseMove(wxMouseEvent &event);
    void OnMouseUp(wxMouseEvent &event);
    void OnMouseLeave(wxMouseEvent &event);
    void OnRighClick(wxMouseEvent &event);

    void finishDrag();
    void finishRotation();

    void sendRectAddedEvent(const wxString &rectTitle);
    void sendRectRemovedEvent(const wxString &rectTitle);
    std::list<GraphicObject> objectList;
    GraphicObject *draggedObj;
    bool shouldRotate;
    int idCounter = 1;

    GraphicObject *select1 = nullptr;
    GraphicObject *select2 = nullptr;

    wxPoint2DDouble lastDragOrigin;
};


#endif // DRAWINGCANVAS_H
