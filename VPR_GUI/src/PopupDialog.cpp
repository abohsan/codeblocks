
#include "../include/PopupDialog.h"


wxDEFINE_EVENT(PopupEvent, wxCommandEvent);

wxBEGIN_EVENT_TABLE(PopupDialog, wxDialog)
    EVT_BUTTON(wxID_OK, PopupDialog::OnButton1)
    EVT_BUTTON(wxID_APPLY, PopupDialog::OnButton2)
    EVT_BUTTON(wxID_CANCEL, PopupDialog::OnButton3)
wxEND_EVENT_TABLE()

PopupDialog::PopupDialog(wxWindow *parent, wxWindowID id, const wxString &title)
    : wxDialog(parent, id, title) {
    wxBoxSizer *sizer = new wxBoxSizer(wxVERTICAL);
    wxStaticText *text = new wxStaticText(this, wxID_ANY, wxT("click on the element that you want to add"));
    sizer->Add(text, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5);

    wxButton *theContainer = new wxButton(this, wxID_OK, wxT("Container"));
    wxButton *thevSwitch = new wxButton(this, wxID_APPLY , wxT("vSwitch"));
    wxButton *theCancel = new wxButton(this, wxID_CANCEL, wxT("Cancel"));

    wxBoxSizer *buttonSizer = new wxBoxSizer(wxHORIZONTAL);
    buttonSizer->Add(theContainer, 0, wxALL, 5);
    buttonSizer->Add(thevSwitch, 0, wxALL, 5);
    buttonSizer->Add(theCancel, 0, wxALL, 5);
    sizer->Add(buttonSizer, 0, wxALIGN_CENTER_HORIZONTAL, 5);
    SetSizerAndFit(sizer);
}

void PopupDialog::OnButton1(wxCommandEvent& event) {
    selectedOption = "container";
    EndModal(wxID_OK);
}

void PopupDialog::OnButton2(wxCommandEvent& event) {
    selectedOption = "vSwitch";
    EndModal(wxID_APPLY);
}

void PopupDialog::OnButton3(wxCommandEvent& event) {
    selectedOption = "";
    EndModal(wxID_CANCEL);
}
