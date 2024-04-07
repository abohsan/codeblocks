/***************************************************************
 * Name:      VPR_GUIMain.h
 * Purpose:   Defines Application Frame
 * Author:    Abdulmueen Alrashide ()
 * Created:   2024-03-31
 * Copyright: Abdulmueen Alrashide (www.abdulmueen .com)
 * License:
 **************************************************************/

#ifndef VPR_GUIMAIN_H
#define VPR_GUIMAIN_H

//(*Headers(VPR_GUIFrame)
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/notebook.h>
#include <wx/panel.h>
#include <wx/statusbr.h>
//*)
#include <random>
#include "include/DrawingCanvas.h"
class VPR_GUIFrame: public wxFrame
{
    public:

        VPR_GUIFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~VPR_GUIFrame();

    private:


        void OnRectAdded(wxCommandEvent &event);
        void OnRectRemoved(wxCommandEvent &event);

    //    wxPanel *createButtonPanel(wxWindow *parent);

        DrawingCanvas *canvas;
        // ChartControl *chart;

        int rectCount = 0;
        std::mt19937 randomGen;
        //(*Handlers(VPR_GUIFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnRemoveButtonClick(wxCommandEvent& event);
        void OnAddButtonClick(wxCommandEvent& event);
        void OnButton2Click(wxCommandEvent& event);
        //*)

        //(*Identifiers(VPR_GUIFrame)
        static const long ID_BUTTON1;
        static const long ID_BUTTON2;
        static const long ID_PANEL5;
        static const long ID_PANEL6;
        static const long ID_BUTTON3;
        static const long ID_PANEL1;
        static const long ID_PANEL2;
        static const long ID_PANEL3;
        static const long ID_PANEL4;
        static const long ID_NOTEBOOK1;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(VPR_GUIFrame)
        wxButton* Button1;
        wxButton* Button2;
        wxButton* Button3;
        wxNotebook* Notebook1;
        wxPanel* Panel1;
        wxPanel* Panel2;
        wxPanel* Panel3;
        wxPanel* Panel4;
        wxPanel* Panel5;
        wxPanel* Panel6;
        wxStatusBar* StatusBar1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // VPR_GUIMAIN_H
