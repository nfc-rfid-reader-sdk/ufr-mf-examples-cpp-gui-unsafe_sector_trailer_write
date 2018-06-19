/***************************************************************
 * Name:      sector_trailer_unsafeMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Aleksandar (Krstic)
 * Created:   2018-06-19
 * Copyright: Aleksandar (aleksandar.krstic@d-logic.rs)
 * License:
 **************************************************************/

#include "sector_trailer_unsafeMain.h"
#include <wx/msgdlg.h>
#include <string>
#include <string.h>
#include <cstring>
#include "lib/include/uFCoder.h"

using namespace std;
//(*InternalHeaders(sector_trailer_unsafeFrame)
#include <wx/intl.h>
#include <wx/settings.h>
#include <wx/string.h>
//*)
uint32_t ConvertStringToInt(string str, int base);
void ConvertStringToIntArray(string str, uint8_t *array, int base);
//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(sector_trailer_unsafeFrame)
const long sector_trailer_unsafeFrame::ID_BUTTON1 = wxNewId();
const long sector_trailer_unsafeFrame::ID_BUTTON2 = wxNewId();
const long sector_trailer_unsafeFrame::ID_TEXTCTRL5 = wxNewId();
const long sector_trailer_unsafeFrame::ID_STATICTEXT1 = wxNewId();
const long sector_trailer_unsafeFrame::ID_TEXTCTRL1 = wxNewId();
const long sector_trailer_unsafeFrame::ID_STATICTEXT2 = wxNewId();
const long sector_trailer_unsafeFrame::ID_TEXTCTRL2 = wxNewId();
const long sector_trailer_unsafeFrame::ID_STATICTEXT3 = wxNewId();
const long sector_trailer_unsafeFrame::ID_TEXTCTRL3 = wxNewId();
const long sector_trailer_unsafeFrame::ID_RADIOBUTTON2 = wxNewId();
const long sector_trailer_unsafeFrame::ID_RADIOBUTTON1 = wxNewId();
const long sector_trailer_unsafeFrame::ID_STATICTEXT4 = wxNewId();
const long sector_trailer_unsafeFrame::ID_TEXTCTRL4 = wxNewId();
const long sector_trailer_unsafeFrame::ID_BUTTON3 = wxNewId();
const long sector_trailer_unsafeFrame::ID_BUTTON4 = wxNewId();
const long sector_trailer_unsafeFrame::ID_STATICTEXT5 = wxNewId();
const long sector_trailer_unsafeFrame::ID_TEXTCTRL6 = wxNewId();
const long sector_trailer_unsafeFrame::idMenuQuit = wxNewId();
const long sector_trailer_unsafeFrame::idMenuAbout = wxNewId();
const long sector_trailer_unsafeFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(sector_trailer_unsafeFrame,wxFrame)
    //(*EventTable(sector_trailer_unsafeFrame)
    //*)
END_EVENT_TABLE()

sector_trailer_unsafeFrame::sector_trailer_unsafeFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(sector_trailer_unsafeFrame)
    wxBoxSizer* BoxSizer1;
    wxGridSizer* GridSizer1;
    wxGridSizer* GridSizer2;
    wxGridSizer* GridSizer3;
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;
    wxStaticBoxSizer* StaticBoxSizer1;

    Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
    GridSizer1 = new wxGridSizer(3, 1, -200, 0);
    StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, this, wxEmptyString);
    bReaderOpen = new wxButton(this, ID_BUTTON1, _("ReaderOpen()"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    StaticBoxSizer1->Add(bReaderOpen, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    bReaderClose = new wxButton(this, ID_BUTTON2, _("ReaderClose()"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    StaticBoxSizer1->Add(bReaderClose, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    OPEN_STATUS = new wxTextCtrl(this, ID_TEXTCTRL5, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY|wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL5"));
    StaticBoxSizer1->Add(OPEN_STATUS, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    GridSizer1->Add(StaticBoxSizer1, 1, wxALL|wxALIGN_TOP|wxALIGN_CENTER_HORIZONTAL, 5);
    GridSizer2 = new wxGridSizer(7, 2, 0, -10);
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Addressing mode : (example, for addressing mode 1, input 01 - hexadecimal) "), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    GridSizer2->Add(StaticText1, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    ADDRESSING_MODE_LABEL = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxSize(45,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    GridSizer2->Add(ADDRESSING_MODE_LABEL, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Trailer address : (example : for trailer 1, input 01 - hexadecimal)"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    GridSizer2->Add(StaticText2, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    ADDRESS_LABEL = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxSize(45,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    GridSizer2->Add(ADDRESS_LABEL, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("Sector trailer data (16 bytes, example : FFFF - 2 bytes) : "), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    GridSizer2->Add(StaticText3, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    TRAILER_DATA_LABEL = new wxTextCtrl(this, ID_TEXTCTRL3, wxEmptyString, wxDefaultPosition, wxSize(400,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
    GridSizer2->Add(TRAILER_DATA_LABEL, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    AUTH_A = new wxRadioButton(this, ID_RADIOBUTTON2, _("MIFARE_AUTHENT1A"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON2"));
    GridSizer2->Add(AUTH_A, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    AUTH_B = new wxRadioButton(this, ID_RADIOBUTTON1, _("MIFARE_AUTHENT1B"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON1"));
    GridSizer2->Add(AUTH_B, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("Key index : (example, for key index 1, input 01 - hexadecimal)"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    GridSizer2->Add(StaticText4, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    KEY_LABEL = new wxTextCtrl(this, ID_TEXTCTRL4, wxEmptyString, wxDefaultPosition, wxSize(45,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL4"));
    GridSizer2->Add(KEY_LABEL, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    bWrite = new wxButton(this, ID_BUTTON3, _("WRITE"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
    BoxSizer1->Add(bWrite, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    bClear = new wxButton(this, ID_BUTTON4, _("CLEAR"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON4"));
    BoxSizer1->Add(bClear, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5);
    GridSizer2->Add(BoxSizer1, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxSHAPED, 5);
    GridSizer1->Add(GridSizer2, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
    GridSizer3 = new wxGridSizer(1, 2, 0, -200);
    StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _("FUNCTION STATUS : "), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
    GridSizer3->Add(StaticText5, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    FUNCTION_STATUS = new wxTextCtrl(this, ID_TEXTCTRL6, wxEmptyString, wxDefaultPosition, wxSize(300,-1), wxTE_READONLY|wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL6"));
    GridSizer3->Add(FUNCTION_STATUS, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    GridSizer1->Add(GridSizer3, 1, wxALL|wxALIGN_LEFT|wxALIGN_BOTTOM, 5);
    SetSizer(GridSizer1);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);
    GridSizer1->Fit(this);
    GridSizer1->SetSizeHints(this);

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&sector_trailer_unsafeFrame::OnbReaderOpenClick);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&sector_trailer_unsafeFrame::OnbReaderCloseClick);
    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&sector_trailer_unsafeFrame::OnbWriteClick);
    Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&sector_trailer_unsafeFrame::OnbClearClick);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&sector_trailer_unsafeFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&sector_trailer_unsafeFrame::OnAbout);
    //*)
}

sector_trailer_unsafeFrame::~sector_trailer_unsafeFrame()
{
    //(*Destroy(sector_trailer_unsafeFrame)
    //*)
}

void sector_trailer_unsafeFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void sector_trailer_unsafeFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void sector_trailer_unsafeFrame::OnbReaderOpenClick(wxCommandEvent& event)
{
    UFR_STATUS status;

    status = ReaderOpen();

    if(status == UFR_OK){

        OPEN_STATUS -> SetValue("Port opened");
        OPEN_STATUS -> SetBackgroundColour("green");

    }else{

        OPEN_STATUS -> SetValue("Port not opened");
        OPEN_STATUS -> SetBackgroundColour("red");

    }
}



void sector_trailer_unsafeFrame::OnbReaderCloseClick(wxCommandEvent& event)
{
     UFR_STATUS status;

    status = ReaderClose();

    if(status == UFR_OK){

        OPEN_STATUS -> SetValue("Port closed");
        OPEN_STATUS -> SetBackgroundColour("green");

    }else{

        OPEN_STATUS -> SetValue("Port not closed");
        OPEN_STATUS -> SetBackgroundColour("red");

    }
}



void sector_trailer_unsafeFrame::OnbWriteClick(wxCommandEvent& event)
{

    UFR_STATUS status;
    wxString wxAddressingMode = "";
    wxString wxAddress = "";
    wxString wxSectorTrailer = "";
    wxString wxKey = "";
    wxString wxStatus = "";

    wxAddressingMode = ADDRESSING_MODE_LABEL->GetValue();
    wxAddress = ADDRESS_LABEL->GetValue();
    wxSectorTrailer = TRAILER_DATA_LABEL->GetValue();
    wxKey = KEY_LABEL->GetValue();

    string AddressingMode_Str = string(wxAddressingMode.mb_str());
    string Address_Str = string(wxAddress.mb_str());
    string SectorTrailer_Str = string(wxSectorTrailer.mb_str());
    string KeyIndex_Str = string(wxKey.mb_str());

    uint8_t addressing_mode = (uint8_t)ConvertStringToInt(AddressingMode_Str, 16);
    uint8_t address = (uint8_t)ConvertStringToInt(Address_Str, 16);
    uint8_t sector_trailer[16];
    uint8_t key_index = (uint8_t)ConvertStringToInt(KeyIndex_Str, 16);;

    ConvertStringToIntArray(SectorTrailer_Str, sector_trailer, 16);


    if(AUTH_A -> GetValue()){

        status = SectorTrailerWriteUnsafe(addressing_mode, address, sector_trailer, 0x60, key_index);

    }else if(AUTH_B -> GetValue()){

        status = SectorTrailerWriteUnsafe(addressing_mode, address, sector_trailer, 0x61, key_index);

    }

    wxStatus = UFR_Status2String(status);

    FUNCTION_STATUS->SetValue(wxStatus);

    if(status != UFR_OK){

        wxString msg = "";

        msg = wxStatus;

        wxMessageBox(msg, _("ERROR, status is : "));

    }

}

void ConvertStringToIntArray(string str, uint8_t *array, int base) {

    switch (base){
        case 16:
            for (unsigned int i = 0; i < str.length() / 2; i++) {

                string part = str.substr(i * 2, 2);

                array[i] = (uint8_t)ConvertStringToInt(part, 16);


            }
            break;

    }

}
uint32_t ConvertStringToInt(string str, int base) {

    char str1[32];
    char *ptr;

    strcpy(str1, str.c_str());

    return strtol(str1, &ptr, base);

}

void sector_trailer_unsafeFrame::OnbClearClick(wxCommandEvent& event)
{
    ADDRESSING_MODE_LABEL->Clear();
    ADDRESS_LABEL->Clear();
    TRAILER_DATA_LABEL->Clear();
    KEY_LABEL->Clear();
    FUNCTION_STATUS->Clear();
}
