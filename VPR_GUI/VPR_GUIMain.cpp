/***************************************************************
 * Name:      VPR_GUIMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Abdulmueen Alrashide ()
 * Created:   2024-03-31
 * Copyright: Abdulmueen Alrashide (www.abdulmueen .com)
 * License:
 **************************************************************/

#include "VPR_GUIMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(VPR_GUIFrame)
#include <wx/intl.h>
#include <wx/settings.h>
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

//(*IdInit(VPR_GUIFrame)
const long VPR_GUIFrame::ID_BUTTON1 = wxNewId();
const long VPR_GUIFrame::ID_BUTTON2 = wxNewId();
const long VPR_GUIFrame::ID_PANEL5 = wxNewId();
const long VPR_GUIFrame::ID_PANEL6 = wxNewId();
const long VPR_GUIFrame::ID_BUTTON3 = wxNewId();
const long VPR_GUIFrame::ID_PANEL1 = wxNewId();
const long VPR_GUIFrame::ID_PANEL2 = wxNewId();
const long VPR_GUIFrame::ID_PANEL3 = wxNewId();
const long VPR_GUIFrame::ID_PANEL4 = wxNewId();
const long VPR_GUIFrame::ID_NOTEBOOK1 = wxNewId();
const long VPR_GUIFrame::idMenuQuit = wxNewId();
const long VPR_GUIFrame::idMenuAbout = wxNewId();
const long VPR_GUIFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(VPR_GUIFrame,wxFrame)
    //(*EventTable(VPR_GUIFrame)
    //*)
END_EVENT_TABLE()

VPR_GUIFrame::VPR_GUIFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(VPR_GUIFrame)
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;

    Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    SetClientSize(wxSize(1200,700));
    Notebook1 = new wxNotebook(this, ID_NOTEBOOK1, wxPoint(400,232), wxSize(1208,632), 0, _T("ID_NOTEBOOK1"));
    Panel1 = new wxPanel(Notebook1, ID_PANEL1, wxDefaultPosition, wxSize(1198,605), wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    Panel1->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_MENUHILIGHT));
    Button1 = new wxButton(Panel1, ID_BUTTON1, _("AddRect"), wxPoint(56,8), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    Button2 = new wxButton(Panel1, ID_BUTTON2, _("connect"), wxPoint(752,8), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    Panel5 = new wxPanel(Panel1, ID_PANEL5, wxPoint(8,48), wxSize(576,536), wxTAB_TRAVERSAL, _T("ID_PANEL5"));
    Panel5->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_GRADIENTACTIVECAPTION));
    Panel6 = new wxPanel(Panel1, ID_PANEL6, wxPoint(592,48), wxSize(576,536), wxTAB_TRAVERSAL, _T("ID_PANEL6"));
    Panel6->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNSHADOW));
    Button3 = new wxButton(Panel1, ID_BUTTON3, _("Remove Rect"), wxPoint(432,8), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
    Panel2 = new wxPanel(Notebook1, ID_PANEL2, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL2"));
    Panel3 = new wxPanel(Notebook1, ID_PANEL3, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL3"));
    Panel4 = new wxPanel(Notebook1, ID_PANEL4, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL4"));
    Notebook1->AddPage(Panel1, _("Network"), false);
    Notebook1->AddPage(Panel2, _("Element"), false);
    Notebook1->AddPage(Panel3, _("DataSet"), false);
    Notebook1->AddPage(Panel4, _("Config"), false);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
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

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&VPR_GUIFrame::OnAddButtonClick);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&VPR_GUIFrame::OnButton2Click);
    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&VPR_GUIFrame::OnRemoveButtonClick);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&VPR_GUIFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&VPR_GUIFrame::OnAbout);
    //*)



    wxSize panelSize = Panel6->GetSize();
    wxSizer *sizer = new wxBoxSizer(wxVERTICAL);
    canvas = new DrawingCanvas(Panel6, wxID_ANY,wxDefaultPosition, Panel6->FromDIP(wxSize(panelSize.GetWidth(),panelSize.GetHeight())));
    sizer->Add(canvas,1,wxEXPAND | wxALL,0);
    Panel6->SetSizerAndFit(sizer);


    rectCount = canvas->getObjectCount();
     SetStatusText("Ready", 0);


    canvas->Bind(CANVAS_RECT_ADDED, &VPR_GUIFrame::OnRectAdded, this); // add rect
    canvas->Bind(CANVAS_RECT_REMOVED, &VPR_GUIFrame::OnRectRemoved, this); // remove


}

VPR_GUIFrame::~VPR_GUIFrame()
{
    //(*Destroy(VPR_GUIFrame)
    //*)
}

void VPR_GUIFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void VPR_GUIFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}


void VPR_GUIFrame::OnRectAdded(wxCommandEvent &event)
{
    SetStatusText("New object added: named " + event.GetString(), 0);
}

void VPR_GUIFrame::OnRectRemoved(wxCommandEvent &event)
{
    SetStatusText("object is removed, named " + event.GetString(), 0);
}

void VPR_GUIFrame::OnRemoveButtonClick(wxCommandEvent& event)
{
    // canvas->removeTopRect();
     std::cout << std::endl;
}

void VPR_GUIFrame::OnAddButtonClick(wxCommandEvent& event)
{
    std::uniform_int_distribution sizeDistrib(this->FromDIP(50), this->FromDIP(100));
    std::uniform_int_distribution xDistrib(0, canvas->GetSize().GetWidth());
    std::uniform_int_distribution yDistrib(0, canvas->GetSize().GetHeight());
    std::uniform_real_distribution angleDistrib(0.0, M_PI * 2.0);

    std::uniform_int_distribution colorDistrib(0, 0xFFFFFF);

    rectCount++;
    canvas->addNewObject(sizeDistrib(randomGen), sizeDistrib(randomGen), xDistrib(randomGen), yDistrib(randomGen),
    angleDistrib(randomGen), wxColour(colorDistrib(randomGen)), "Rect #" + std::to_string(rectCount),"");
}

void VPR_GUIFrame::OnButton2Click(wxCommandEvent& event)
{

    canvas->connectSelected();
}
