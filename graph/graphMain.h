/***************************************************************
 * Name:      graphMain.h
 * Purpose:   Defines Application Frame
 * Author:    Abdulmueen Alrashide ()
 * Created:   2024-03-30
 * Copyright: Abdulmueen Alrashide (www.abdulmueen .com)
 * License:
 **************************************************************/

#ifndef GRAPHMAIN_H
#define GRAPHMAIN_H

//(*Headers(graphFrame)
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/panel.h>
#include <wx/statusbr.h>
//*)
#include <random>
#include "DrawingCanvas.h"
class graphFrame: public wxFrame
{
    public:

        graphFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~graphFrame();

    private:

        void OnAddButtonClick(wxCommandEvent &event);
        void OnRemoveButtonClick(wxCommandEvent &event);

        void OnRectAdded(wxCommandEvent &event);
        void OnRectRemoved(wxCommandEvent &event);

        wxPanel *createButtonPanel(wxWindow *parent);

        DrawingCanvas *canvas;
       // ChartControl *chart;

        int rectCount = 0;
        std::mt19937 randomGen;

        //(*Handlers(graphFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        //*)

        //(*Identifiers(graphFrame)
        static const long ID_PANEL1;
        static const long ID_BUTTON1;
        static const long ID_BUTTON2;
        static const long ID_BUTTON3;
        static const long idMenuAddNew;
        static const long idMenuRemoveRect;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(graphFrame)
        wxButton* Button1;
        wxButton* Button2;
        wxButton* Button3;
        wxMenuItem* MenuItem3;
        wxMenuItem* MenuItem4;
        wxPanel* Panel1;
        wxStatusBar* StatusBar1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // GRAPHMAIN_H
