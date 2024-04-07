/***************************************************************
 * Name:      VPR_GUIApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Abdulmueen Alrashide ()
 * Created:   2024-03-31
 * Copyright: Abdulmueen Alrashide (www.abdulmueen .com)
 * License:
 **************************************************************/

#include "VPR_GUIApp.h"

//(*AppHeaders
#include "VPR_GUIMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(VPR_GUIApp);

bool VPR_GUIApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	VPR_GUIFrame* Frame = new VPR_GUIFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
