/***************************************************************
 * Name:      sector_trailer_unsafeApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Aleksandar (Krstic)
 * Created:   2018-06-19
 * Copyright: Aleksandar (aleksandar.krstic@d-logic.rs)
 * License:
 **************************************************************/

#include "sector_trailer_unsafeApp.h"

//(*AppHeaders
#include "sector_trailer_unsafeMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(sector_trailer_unsafeApp);

bool sector_trailer_unsafeApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	sector_trailer_unsafeFrame* Frame = new sector_trailer_unsafeFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
