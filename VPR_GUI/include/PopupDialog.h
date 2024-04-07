#ifndef POPUPDIALOG_H_INCLUDED
#define POPUPDIALOG_H_INCLUDED
#include <wx/wx.h>


class PopupDialog : public wxDialog {
public:
    PopupDialog(wxWindow *parent, wxWindowID id = wxID_ANY, const wxString &title = wxT("Popup Dialog"));

    std::string GetSelectedOption() const { return selectedOption; }

private:
    void OnButton1(wxCommandEvent& event);
    void OnButton2(wxCommandEvent& event);
    void OnButton3(wxCommandEvent& event);

    std::string  selectedOption; // Store the selected option
    wxListBox *optionListBox;

    wxDECLARE_EVENT_TABLE();
};
#endif // POPUPDIALOG_H_INCLUDED
