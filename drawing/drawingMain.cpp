/***************************************************************
 * Name:      drawingMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Abdulmueen Alrashide ()
 * Created:   2024-03-30
 * Copyright: Abdulmueen Alrashide (www.abdulmueen .com)
 * License:
 **************************************************************/

#include "drawingMain.h"
#include <wx/msgdlg.h>
#include <wx/dcclient.h>
#include <wx/colordlg.h>
#include <wx/colourdata.h>

//(*InternalHeaders(drawingFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(drawingFrame)
const long drawingFrame::ID_TEXTCTRL1 = wxNewId();
const long drawingFrame::ID_STATICTEXT1 = wxNewId();
const long drawingFrame::ID_BUTTON1 = wxNewId();
const long drawingFrame::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(drawingFrame,wxFrame)
    //(*EventTable(drawingFrame)
    //*)
END_EVENT_TABLE()

drawingFrame::drawingFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(drawingFrame)
    Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    SetClientSize(wxSize(1307,524));
    Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(344,200), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    TextCtrl1 = new wxTextCtrl(Panel1, ID_TEXTCTRL1, _("1"), wxPoint(1096,48), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("Pen Width"), wxPoint(1008,56), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    Button1 = new wxButton(Panel1, ID_BUTTON1, _("Pen Color"), wxPoint(88,40), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&drawingFrame::ChangeColour);
    Panel1->Connect(wxEVT_MOTION,(wxObjectEventFunction)&drawingFrame::paintPanel,0,this);
    //*)
}

drawingFrame::~drawingFrame()
{
    //(*Destroy(drawingFrame)
    //*)
}

int PenX, PenY;
void drawingFrame::paintPanel(wxMouseEvent& event)
{
    wxClientDC ClientDC(Panel1);
    wxPen pen(Button1->GetBackgroundColour(), atoi(TextCtrl1->GetValue()));
    ClientDC.SetPen(pen);
    if(event.Dragging()) ClientDC.DrawLine(PenX,PenY,event.GetX(),event.GetY());

    PenX = event.GetX();
    PenY = event.GetY();
}
wxColour Colour;
void drawingFrame::ChangeColour(wxCommandEvent& event)
{
    wxColourData ColourData;
    wxColourDialog* cd = new wxColourDialog(this);
    if(cd->ShowModal() == wxID_OK)
    {
        ColourData = cd->GetColourData();
        Colour = ColourData.GetColour();
        Button1->SetBackgroundColour(Colour);
    }
    cd->Destroy();
}


