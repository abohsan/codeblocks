/***************************************************************
 * Name:      graphApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Abdulmueen Alrashide ()
 * Created:   2024-03-30
 * Copyright: Abdulmueen Alrashide (www.abdulmueen .com)
 * License:
 **************************************************************/

#include "graphApp.h"

//(*AppHeaders
#include "graphMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(graphApp);

bool graphApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	graphFrame* Frame = new graphFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
