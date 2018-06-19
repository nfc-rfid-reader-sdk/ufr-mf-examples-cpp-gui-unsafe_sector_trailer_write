/***************************************************************
 * Name:      sector_trailer_unsafeMain.h
 * Purpose:   Defines Application Frame
 * Author:    Aleksandar (Krstic)
 * Created:   2018-06-19
 * Copyright: Aleksandar (aleksandar.krstic@d-logic.rs)
 * License:
 **************************************************************/

#ifndef SECTOR_TRAILER_UNSAFEMAIN_H
#define SECTOR_TRAILER_UNSAFEMAIN_H

//(*Headers(sector_trailer_unsafeFrame)
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/radiobut.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/statusbr.h>
#include <wx/textctrl.h>
//*)

class sector_trailer_unsafeFrame: public wxFrame
{
    public:

        sector_trailer_unsafeFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~sector_trailer_unsafeFrame();

    private:

        //(*Handlers(sector_trailer_unsafeFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnbReaderOpenClick(wxCommandEvent& event);
        void OnbReaderCloseClick(wxCommandEvent& event);
        void OnbWriteClick(wxCommandEvent& event);
        void OnbClearClick(wxCommandEvent& event);
        //*)

        //(*Identifiers(sector_trailer_unsafeFrame)
        static const long ID_BUTTON1;
        static const long ID_BUTTON2;
        static const long ID_TEXTCTRL5;
        static const long ID_STATICTEXT1;
        static const long ID_TEXTCTRL1;
        static const long ID_STATICTEXT2;
        static const long ID_TEXTCTRL2;
        static const long ID_STATICTEXT3;
        static const long ID_TEXTCTRL3;
        static const long ID_RADIOBUTTON2;
        static const long ID_RADIOBUTTON1;
        static const long ID_STATICTEXT4;
        static const long ID_TEXTCTRL4;
        static const long ID_STATICTEXT6;
        static const long ID_TEXTCTRL7;
        static const long ID_BUTTON3;
        static const long ID_BUTTON4;
        static const long ID_STATICTEXT5;
        static const long ID_TEXTCTRL6;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(sector_trailer_unsafeFrame)
        wxButton* bClear;
        wxButton* bReaderClose;
        wxButton* bReaderOpen;
        wxButton* bWrite;
        wxRadioButton* AUTH_A;
        wxRadioButton* AUTH_B;
        wxStaticText* StaticText1;
        wxStaticText* StaticText2;
        wxStaticText* StaticText3;
        wxStaticText* StaticText4;
        wxStaticText* StaticText5;
        wxStaticText* StaticText6;
        wxStatusBar* StatusBar1;
        wxTextCtrl* ADDRESSING_MODE_LABEL;
        wxTextCtrl* ADDRESS_LABEL;
        wxTextCtrl* FUNCTION_STATUS;
        wxTextCtrl* KEY_LABEL;
        wxTextCtrl* OPEN_STATUS;
        wxTextCtrl* SECTOR_DATA;
        wxTextCtrl* TRAILER_DATA_LABEL;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // SECTOR_TRAILER_UNSAFEMAIN_H
