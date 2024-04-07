/***************************************************************
 * Name:      drawingApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Abdulmueen Alrashide ()
 * Created:   2024-03-30
 * Copyright: Abdulmueen Alrashide (www.abdulmueen .com)
 * License:
 **************************************************************/

#include "drawingApp.h"

//(*AppHeaders
#include "drawingMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(drawingApp);

bool drawingApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	drawingFrame* Frame = new drawingFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
