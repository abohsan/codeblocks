/***************************************************************
 * Name:      drawingMain.h
 * Purpose:   Defines Application Frame
 * Author:    Abdulmueen Alrashide ()
 * Created:   2024-03-30
 * Copyright: Abdulmueen Alrashide (www.abdulmueen .com)
 * License:
 **************************************************************/

#ifndef DRAWINGMAIN_H
#define DRAWINGMAIN_H

//(*Headers(drawingFrame)
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

class drawingFrame: public wxFrame
{
    public:

        drawingFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~drawingFrame();

    private:

        //(*Handlers(drawingFrame)
        void paintPanel(wxMouseEvent& event);
        void ChangeColour(wxCommandEvent& event);
        //*)

        //(*Identifiers(drawingFrame)
        static const long ID_TEXTCTRL1;
        static const long ID_STATICTEXT1;
        static const long ID_BUTTON1;
        static const long ID_PANEL1;
        //*)

        //(*Declarations(drawingFrame)
        wxButton* Button1;
        wxPanel* Panel1;
        wxStaticText* StaticText1;
        wxTextCtrl* TextCtrl1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // DRAWINGMAIN_H
