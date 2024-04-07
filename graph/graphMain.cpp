/***************************************************************
 * Name:      graphMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Abdulmueen Alrashide ()
 * Created:   2024-03-30
 * Copyright: Abdulmueen Alrashide (www.abdulmueen .com)
 * License:
 **************************************************************/

#include "graphMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(graphFrame)
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

//(*IdInit(graphFrame)
const long graphFrame::ID_PANEL1 = wxNewId();
const long graphFrame::ID_BUTTON1 = wxNewId();
const long graphFrame::ID_BUTTON2 = wxNewId();
const long graphFrame::ID_BUTTON3 = wxNewId();
const long graphFrame::idMenuAddNew = wxNewId();
const long graphFrame::idMenuRemoveRect = wxNewId();
const long graphFrame::idMenuQuit = wxNewId();
const long graphFrame::idMenuAbout = wxNewId();
const long graphFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(graphFrame,wxFrame)
    //(*EventTable(graphFrame)
    //*)
END_EVENT_TABLE()

graphFrame::graphFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(graphFrame)
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;

    Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    SetClientSize(wxSize(1644,841));
    Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(0,40), wxSize(1644,801), wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    Button1 = new wxButton(this, ID_BUTTON1, _("Add Rect"), wxPoint(80,8), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    Button2 = new wxButton(this, ID_BUTTON2, _("Remove Top"), wxPoint(192,8), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    Button3 = new wxButton(this, ID_BUTTON3, _("Label"), wxPoint(376,8), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem3 = new wxMenuItem(Menu1, idMenuAddNew, _("AddNew"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(MenuItem3);
    MenuItem4 = new wxMenuItem(Menu1, idMenuRemoveRect, _("RemoveRect"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(MenuItem4);
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&graphFrame::OnAddButtonClick);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&graphFrame::OnRemoveButtonClick);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&graphFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&graphFrame::OnAbout);
    //*)
    wxSizer *sizer = new wxBoxSizer(wxVERTICAL);
    canvas = new DrawingCanvas(Panel1, wxID_ANY,wxDefaultPosition, Panel1->FromDIP(wxSize(640,480)));
    sizer->Add(canvas,1,wxEXPAND | wxALL,0);
    Panel1->SetSizerAndFit(sizer);
    rectCount = canvas->getObjectCount();
    }

graphFrame::~graphFrame()
{
    //(*Destroy(graphFrame)
    //*)
}

void graphFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void graphFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}



void graphFrame::OnAddButtonClick(wxCommandEvent& event)
{
    std::uniform_int_distribution sizeDistrib(this->FromDIP(50), this->FromDIP(100));
    std::uniform_int_distribution xDistrib(0, canvas->GetSize().GetWidth());
    std::uniform_int_distribution yDistrib(0, canvas->GetSize().GetHeight());
    std::uniform_real_distribution angleDistrib(0.0, M_PI * 2.0);

    std::uniform_int_distribution colorDistrib(0, 0xFFFFFF);

    rectCount++;
    canvas->addRect(sizeDistrib(randomGen), sizeDistrib(randomGen), xDistrib(randomGen), yDistrib(randomGen),
    angleDistrib(randomGen), wxColour(colorDistrib(randomGen)), "Rect #" + std::to_string(rectCount));
}


void graphFrame::OnRemoveButtonClick(wxCommandEvent& event)
{
    canvas->removeTopRect();
}


