/***************************************************************
 * Name:      sector_trailer_unsafeApp.h
 * Purpose:   Defines Application Class
 * Author:    Aleksandar (Krstic)
 * Created:   2018-06-19
 * Copyright: Aleksandar (aleksandar.krstic@d-logic.rs)
 * License:
 **************************************************************/

#ifndef SECTOR_TRAILER_UNSAFEAPP_H
#define SECTOR_TRAILER_UNSAFEAPP_H

#include <wx/app.h>

class sector_trailer_unsafeApp : public wxApp
{
    public:
        virtual bool OnInit();
};

#endif // SECTOR_TRAILER_UNSAFEAPP_H
