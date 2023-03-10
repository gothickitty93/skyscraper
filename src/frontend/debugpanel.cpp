/*
	Skyscraper 1.12 Alpha - Debug Panel
	Copyright (C)2003-2023 Ryan Thoryk
	https://www.skyscrapersim.net
	https://sourceforge.net/projects/skyscraper/
	Contact - ryan@thoryk.com

	This program is free software; you can redistribute it and/or
	modify it under the terms of the GNU General Public License
	as published by the Free Software Foundation; either version 2
	of the License, or (at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program; if not, write to the Free Software
	Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
*/

//(*InternalHeaders(DebugPanel)
#include <wx/intl.h>
#include <wx/string.h>
//*)
#include "globals.h"
#include "sbs.h"
#include "camera.h"
#include "floor.h"
#include "elevator.h"
#include "elevatorcar.h"
#include "texture.h"
#include "skyscraper.h"
#include "debugpanel.h"
#include "scriptprocessor.h"
#include "enginecontext.h"
#include "console.h"
#include "meshcontrol.h"
#include "editelevator.h"
#include "keydialog.h"
#include "profilergui.h"
#include "stats.h"
#include "actionviewer.h"
#include "cameracontrol.h"
#include "skycontrol.h"
#include "objectinfo.h"
#include "enginemanager.h"
#include "peoplemanager.h"
#include "camtex.h"

namespace Skyscraper {

//(*IdInit(DebugPanel)
const long DebugPanel::ID_STATICTEXT1 = wxNewId();
const long DebugPanel::ID_STATICTEXT12 = wxNewId();
const long DebugPanel::ID_STATICTEXT2 = wxNewId();
const long DebugPanel::ID_STATICTEXT8 = wxNewId();
const long DebugPanel::ID_STATICTEXT3 = wxNewId();
const long DebugPanel::ID_STATICTEXT4 = wxNewId();
const long DebugPanel::ID_STATICTEXT5 = wxNewId();
const long DebugPanel::ID_STATICTEXT10 = wxNewId();
const long DebugPanel::ID_STATICTEXT9 = wxNewId();
const long DebugPanel::ID_STATICTEXT6 = wxNewId();
const long DebugPanel::ID_t_camerafloor = wxNewId();
const long DebugPanel::ID_t_floorname = wxNewId();
const long DebugPanel::ID_t_camerap = wxNewId();
const long DebugPanel::ID_t_rotation = wxNewId();
const long DebugPanel::ID_t_elevnumber = wxNewId();
const long DebugPanel::ID_t_elevfloor = wxNewId();
const long DebugPanel::ID_t_object = wxNewId();
const long DebugPanel::ID_t_clickposition = wxNewId();
const long DebugPanel::ID_t_collision = wxNewId();
const long DebugPanel::ID_STATICTEXT7 = wxNewId();
const long DebugPanel::ID_STATICTEXT11 = wxNewId();
const long DebugPanel::ID_chkCollisionDetection = wxNewId();
const long DebugPanel::ID_chkGravity = wxNewId();
const long DebugPanel::ID_chkFrameLimiter = wxNewId();
const long DebugPanel::ID_chkProcessElevators = wxNewId();
const long DebugPanel::ID_chkAutoShafts = wxNewId();
const long DebugPanel::ID_chkAutoStairs = wxNewId();
const long DebugPanel::ID_chkRandom = wxNewId();
const long DebugPanel::ID_CHECKBOX1 = wxNewId();
const long DebugPanel::ID_bFloorList = wxNewId();
const long DebugPanel::ID_bMeshControl = wxNewId();
const long DebugPanel::ID_bCameraControl = wxNewId();
const long DebugPanel::ID_bEditElevator = wxNewId();
const long DebugPanel::ID_bControlReference = wxNewId();
const long DebugPanel::ID_bStats = wxNewId();
const long DebugPanel::ID_bEngineManager = wxNewId();
const long DebugPanel::ID_bConsole = wxNewId();
const long DebugPanel::ID_bCameraTexture = wxNewId();
const long DebugPanel::ID_bObjectInfo = wxNewId();
const long DebugPanel::ID_bActionViewer = wxNewId();
const long DebugPanel::ID_bPeopleManager = wxNewId();
const long DebugPanel::ID_bSkyControl = wxNewId();
const long DebugPanel::ID_bProfiler = wxNewId();
const long DebugPanel::ID_bKeys = wxNewId();
const long DebugPanel::ID_bTextures = wxNewId();
const long DebugPanel::ID_bFloorInfo = wxNewId();
const long DebugPanel::ID_bLightControl = wxNewId();
const long DebugPanel::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(DebugPanel,wxFrame)
	//(*EventTable(DebugPanel)
	//*)
END_EVENT_TABLE()

DebugPanel::DebugPanel(Skyscraper *root, wxWindow* parent,wxWindowID id)
{
	//(*Initialize(DebugPanel)
	wxBoxSizer* BoxSizer10;
	wxBoxSizer* BoxSizer11;
	wxBoxSizer* BoxSizer8;
	wxBoxSizer* BoxSizer9;

	Create(parent, wxID_ANY, _("Simulator Control Panel"), wxDefaultPosition, wxDefaultSize, wxCAPTION|wxSYSTEM_MENU|wxCLOSE_BOX|wxMINIMIZE_BOX, _T("wxID_ANY"));
	Move(wxPoint(10,10));
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	BoxSizer11 = new wxBoxSizer(wxVERTICAL);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	BoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
	BoxSizer6 = new wxBoxSizer(wxVERTICAL);
	StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("Camera Floor:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	BoxSizer6->Add(StaticText1, 0, wxBOTTOM|wxALIGN_RIGHT, 5);
	StaticText10 = new wxStaticText(Panel1, ID_STATICTEXT12, _("Floor Name:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT12"));
	BoxSizer6->Add(StaticText10, 1, wxBOTTOM|wxALIGN_RIGHT, 5);
	StaticText2 = new wxStaticText(Panel1, ID_STATICTEXT2, _("Camera Position:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	BoxSizer6->Add(StaticText2, 0, wxBOTTOM|wxALIGN_RIGHT, 5);
	StaticText7 = new wxStaticText(Panel1, ID_STATICTEXT8, _("Camera Rotation:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT8"));
	BoxSizer6->Add(StaticText7, 1, wxBOTTOM|wxALIGN_RIGHT, 5);
	StaticText3 = new wxStaticText(Panel1, ID_STATICTEXT3, _("Elevator Number:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	BoxSizer6->Add(StaticText3, 0, wxBOTTOM|wxALIGN_RIGHT, 5);
	StaticText4 = new wxStaticText(Panel1, ID_STATICTEXT4, _("Elevator Floor:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	BoxSizer6->Add(StaticText4, 0, wxBOTTOM|wxALIGN_RIGHT, 5);
	StaticText5 = new wxStaticText(Panel1, ID_STATICTEXT5, _("Selected Object:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
	BoxSizer6->Add(StaticText5, 0, wxBOTTOM|wxALIGN_RIGHT, 5);
	StaticText9 = new wxStaticText(Panel1, ID_STATICTEXT10, _("Clicked Position:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT10"));
	BoxSizer6->Add(StaticText9, 1, wxBOTTOM|wxALIGN_RIGHT, 5);
	StaticText8 = new wxStaticText(Panel1, ID_STATICTEXT9, _("Last Collision:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT9"));
	BoxSizer6->Add(StaticText8, 1, wxBOTTOM|wxALIGN_RIGHT, 5);
	StaticText6 = new wxStaticText(Panel1, ID_STATICTEXT6, _("Framerate:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT6"));
	BoxSizer6->Add(StaticText6, 1, wxBOTTOM|wxALIGN_RIGHT, 5);
	BoxSizer4->Add(BoxSizer6, 0, wxRIGHT|wxALIGN_TOP, 5);
	BoxSizer7 = new wxBoxSizer(wxVERTICAL);
	t_camerafloor = new wxStaticText(Panel1, ID_t_camerafloor, wxEmptyString, wxDefaultPosition, wxSize(150,-1), wxST_NO_AUTORESIZE, _T("ID_t_camerafloor"));
	BoxSizer7->Add(t_camerafloor, 0, wxBOTTOM|wxALIGN_LEFT, 5);
	t_floorname = new wxStaticText(Panel1, ID_t_floorname, wxEmptyString, wxDefaultPosition, wxSize(150,-1), wxST_NO_AUTORESIZE, _T("ID_t_floorname"));
	BoxSizer7->Add(t_floorname, 1, wxBOTTOM|wxALIGN_LEFT, 5);
	t_camerap = new wxStaticText(Panel1, ID_t_camerap, wxEmptyString, wxDefaultPosition, wxSize(150,-1), wxST_NO_AUTORESIZE, _T("ID_t_camerap"));
	BoxSizer7->Add(t_camerap, 0, wxBOTTOM|wxALIGN_LEFT, 5);
	t_rotation = new wxStaticText(Panel1, ID_t_rotation, wxEmptyString, wxDefaultPosition, wxSize(150,-1), wxST_NO_AUTORESIZE, _T("ID_t_rotation"));
	BoxSizer7->Add(t_rotation, 1, wxBOTTOM|wxALIGN_LEFT, 5);
	t_elevnumber = new wxStaticText(Panel1, ID_t_elevnumber, wxEmptyString, wxDefaultPosition, wxSize(150,-1), wxST_NO_AUTORESIZE, _T("ID_t_elevnumber"));
	BoxSizer7->Add(t_elevnumber, 0, wxBOTTOM|wxALIGN_LEFT, 5);
	t_elevfloor = new wxStaticText(Panel1, ID_t_elevfloor, wxEmptyString, wxDefaultPosition, wxSize(150,-1), wxST_NO_AUTORESIZE, _T("ID_t_elevfloor"));
	BoxSizer7->Add(t_elevfloor, 0, wxBOTTOM|wxALIGN_LEFT, 5);
	t_object = new wxStaticText(Panel1, ID_t_object, wxEmptyString, wxDefaultPosition, wxSize(150,-1), wxST_NO_AUTORESIZE, _T("ID_t_object"));
	BoxSizer7->Add(t_object, 0, wxBOTTOM|wxALIGN_LEFT, 5);
	t_clickposition = new wxStaticText(Panel1, ID_t_clickposition, wxEmptyString, wxDefaultPosition, wxSize(150,-1), wxST_NO_AUTORESIZE, _T("ID_t_clickposition"));
	BoxSizer7->Add(t_clickposition, 1, wxBOTTOM|wxALIGN_LEFT, 5);
	t_collision = new wxStaticText(Panel1, ID_t_collision, wxEmptyString, wxDefaultPosition, wxSize(150,-1), wxST_NO_AUTORESIZE, _T("ID_t_collision"));
	BoxSizer7->Add(t_collision, 1, wxBOTTOM|wxALIGN_LEFT, 5);
	t_framerate = new wxStaticText(Panel1, ID_STATICTEXT7, wxEmptyString, wxDefaultPosition, wxSize(150,-1), wxST_NO_AUTORESIZE, _T("ID_STATICTEXT7"));
	BoxSizer7->Add(t_framerate, 1, wxBOTTOM|wxALIGN_LEFT, 5);
	BoxSizer4->Add(BoxSizer7, 0, wxALIGN_TOP, 5);
	BoxSizer2->Add(BoxSizer4, 0, wxRIGHT|wxALIGN_TOP, 10);
	BoxSizer5 = new wxBoxSizer(wxVERTICAL);
	StaticText11 = new wxStaticText(Panel1, ID_STATICTEXT11, _("Simulator Options"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT11"));
	BoxSizer5->Add(StaticText11, 0, wxBOTTOM|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	chkCollisionDetection = new wxCheckBox(Panel1, ID_chkCollisionDetection, _("Collision Detection"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_chkCollisionDetection"));
	chkCollisionDetection->SetValue(false);
	BoxSizer5->Add(chkCollisionDetection, 0, wxBOTTOM|wxALIGN_LEFT, 5);
	chkGravity = new wxCheckBox(Panel1, ID_chkGravity, _("Gravity"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_chkGravity"));
	chkGravity->SetValue(false);
	BoxSizer5->Add(chkGravity, 1, wxBOTTOM|wxALIGN_LEFT, 5);
	chkFrameLimiter = new wxCheckBox(Panel1, ID_chkFrameLimiter, _("Frame Limiter"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_chkFrameLimiter"));
	chkFrameLimiter->SetValue(false);
	chkFrameLimiter->Disable();
	chkFrameLimiter->Hide();
	BoxSizer5->Add(chkFrameLimiter, 0, wxBOTTOM|wxALIGN_LEFT, 5);
	chkProcessElevators = new wxCheckBox(Panel1, ID_chkProcessElevators, _("Process Elevators"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_chkProcessElevators"));
	chkProcessElevators->SetValue(false);
	BoxSizer5->Add(chkProcessElevators, 0, wxBOTTOM|wxALIGN_LEFT, 5);
	chkAutoShafts = new wxCheckBox(Panel1, ID_chkAutoShafts, _("Automatic Shafts"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_chkAutoShafts"));
	chkAutoShafts->SetValue(false);
	BoxSizer5->Add(chkAutoShafts, 0, wxBOTTOM|wxALIGN_LEFT, 5);
	chkAutoStairs = new wxCheckBox(Panel1, ID_chkAutoStairs, _("Automatic Stairs"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_chkAutoStairs"));
	chkAutoStairs->SetValue(false);
	BoxSizer5->Add(chkAutoStairs, 1, wxBOTTOM|wxALIGN_LEFT, 5);
	chkRandom = new wxCheckBox(Panel1, ID_chkRandom, _("Random Activity"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_chkRandom"));
	chkRandom->SetValue(false);
	BoxSizer5->Add(chkRandom, 1, wxBOTTOM|wxALIGN_LEFT, 5);
	chkVerbose = new wxCheckBox(Panel1, ID_CHECKBOX1, _("Verbose Mode"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
	chkVerbose->SetValue(false);
	BoxSizer5->Add(chkVerbose, 1, wxBOTTOM|wxALIGN_LEFT, 5);
	BoxSizer2->Add(BoxSizer5, 0, wxALL|wxALIGN_TOP, 0);
	BoxSizer11->Add(BoxSizer2, 0, wxTOP|wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 10);
	BoxSizer8 = new wxBoxSizer(wxHORIZONTAL);
	BoxSizer9 = new wxBoxSizer(wxVERTICAL);
	bFloorList = new wxButton(Panel1, ID_bFloorList, _("Floor List"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_bFloorList"));
	BoxSizer9->Add(bFloorList, 0, wxEXPAND, 5);
	bMeshControl = new wxButton(Panel1, ID_bMeshControl, _("Realtime Object Control"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_bMeshControl"));
	BoxSizer9->Add(bMeshControl, 0, wxEXPAND, 5);
	bCameraControl = new wxButton(Panel1, ID_bCameraControl, _("Camera Control"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_bCameraControl"));
	BoxSizer9->Add(bCameraControl, 0, wxEXPAND, 5);
	bEditElevator = new wxButton(Panel1, ID_bEditElevator, _("Elevator Editor"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_bEditElevator"));
	BoxSizer9->Add(bEditElevator, 0, wxEXPAND, 5);
	bControlReference = new wxButton(Panel1, ID_bControlReference, _("Control Reference"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_bControlReference"));
	BoxSizer9->Add(bControlReference, 1, wxEXPAND, 5);
	bStats = new wxButton(Panel1, ID_bStats, _("Simulator Statistics"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_bStats"));
	BoxSizer9->Add(bStats, 1, wxEXPAND, 5);
	bEngineManager = new wxButton(Panel1, ID_bEngineManager, _("Engine Manager"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_bEngineManager"));
	BoxSizer9->Add(bEngineManager, 1, wxEXPAND, 5);
	bConsole = new wxButton(Panel1, ID_bConsole, _("Console"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_bConsole"));
	BoxSizer9->Add(bConsole, 1, wxEXPAND, 5);
	bCameraTexture = new wxButton(Panel1, ID_bCameraTexture, _("CameraTexture Control"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_bCameraTexture"));
	BoxSizer9->Add(bCameraTexture, 1, wxEXPAND, 5);
	BoxSizer8->Add(BoxSizer9, 1, wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer10 = new wxBoxSizer(wxVERTICAL);
	bObjectInfo = new wxButton(Panel1, ID_bObjectInfo, _("Object Manager"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_bObjectInfo"));
	BoxSizer10->Add(bObjectInfo, 1, wxEXPAND, 5);
	bActionViewer = new wxButton(Panel1, ID_bActionViewer, _("Action Viewer"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_bActionViewer"));
	BoxSizer10->Add(bActionViewer, 1, wxEXPAND, 5);
	bPeopleManager = new wxButton(Panel1, ID_bPeopleManager, _("People Manager"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_bPeopleManager"));
	BoxSizer10->Add(bPeopleManager, 1, wxEXPAND, 5);
	bSkyControl = new wxButton(Panel1, ID_bSkyControl, _("Sky Control"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_bSkyControl"));
	BoxSizer10->Add(bSkyControl, 1, wxEXPAND, 5);
	bProfiler = new wxButton(Panel1, ID_bProfiler, _("Profiler"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_bProfiler"));
	BoxSizer10->Add(bProfiler, 1, wxEXPAND, 5);
	bKeys = new wxButton(Panel1, ID_bKeys, _("List Keys"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_bKeys"));
	BoxSizer10->Add(bKeys, 1, wxEXPAND, 5);
	bTextures = new wxButton(Panel1, ID_bTextures, _("List Textures"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_bTextures"));
	BoxSizer10->Add(bTextures, 1, wxEXPAND, 5);
	bFloorInfo = new wxButton(Panel1, ID_bFloorInfo, _("Floor Information"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_bFloorInfo"));
	BoxSizer10->Add(bFloorInfo, 1, wxEXPAND, 5);
	bLightControl = new wxButton(Panel1, ID_bLightControl, _("Light Control"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_bLightControl"));
	bLightControl->Disable();
	BoxSizer10->Add(bLightControl, 1, wxEXPAND, 5);
	BoxSizer8->Add(BoxSizer10, 1, wxLEFT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer11->Add(BoxSizer8, 1, wxTOP|wxBOTTOM|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 10);
	Panel1->SetSizer(BoxSizer11);
	BoxSizer11->Fit(Panel1);
	BoxSizer11->SetSizeHints(Panel1);
	BoxSizer1->Add(Panel1, 1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Connect(ID_chkCollisionDetection,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&DebugPanel::On_chkCollisionDetection_Click);
	Connect(ID_chkGravity,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&DebugPanel::On_chkGravity_Click);
	Connect(ID_chkFrameLimiter,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&DebugPanel::On_chkFrameLimiter_Click);
	Connect(ID_chkProcessElevators,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&DebugPanel::On_chkProcessElevators_Click);
	Connect(ID_chkAutoShafts,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&DebugPanel::On_chkAutoShafts_Click);
	Connect(ID_chkAutoStairs,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&DebugPanel::On_chkAutoStairs_Click);
	Connect(ID_chkRandom,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&DebugPanel::On_chkRandom_Click);
	Connect(ID_CHECKBOX1,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&DebugPanel::On_chkVerbose_Click);
	Connect(ID_bFloorList,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DebugPanel::On_bFloorList_Click);
	Connect(ID_bMeshControl,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DebugPanel::On_bMeshControl_Click);
	Connect(ID_bCameraControl,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DebugPanel::On_bCameraControl_Click);
	Connect(ID_bEditElevator,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DebugPanel::On_bEditElevator_Click);
	Connect(ID_bControlReference,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DebugPanel::On_bControlReference_Click);
	Connect(ID_bStats,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DebugPanel::On_bStats_Click);
	Connect(ID_bEngineManager,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DebugPanel::On_bEngineManager_Click);
	Connect(ID_bConsole,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DebugPanel::On_bConsole_Click);
	Connect(ID_bCameraTexture,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DebugPanel::On_bCameraTexture_Click);
	Connect(ID_bObjectInfo,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DebugPanel::On_bObjectInfo_Click);
	Connect(ID_bActionViewer,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DebugPanel::On_bActionViewer_Click);
	Connect(ID_bPeopleManager,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DebugPanel::On_bPeopleManager_Click);
	Connect(ID_bSkyControl,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DebugPanel::On_bSkyControl_Click);
	Connect(ID_bProfiler,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DebugPanel::On_bProfiler_Click);
	Connect(ID_bKeys,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DebugPanel::On_bKeys_Click);
	Connect(ID_bTextures,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DebugPanel::On_bTextures_Click);
	Connect(ID_bFloorInfo,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DebugPanel::On_bFloorInfo_Click);
	Connect(ID_bLightControl,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DebugPanel::On_bLightControl_Click);
	//*)
	Simcore = 0;
	skyscraper = root;
	mc = 0;
	ee = 0;
	cc = 0;
	kd = 0;
	stats = 0;
	objectinfo = 0;
	profiler = 0;
	actionviewer = 0;
	skycontrol = 0;
	emanager = 0;
	pmanager = 0;
	camtex = 0;
	timer = 0;

	OnInit();
}

DebugPanel::~DebugPanel()
{
	skyscraper->UnregisterDebugPanel();

	//delete timer;
	if (timer)
	{
		EnableTimer(false);
		delete timer;
	}
	timer = 0;
	if (mc)
		mc->Destroy();
	mc = 0;
	if (ee)
		ee->Destroy();
	ee = 0;
	if (cc)
		cc->Destroy();
	cc = 0;
	if (kd)
		kd->Destroy();
	kd = 0;
	if (stats)
		stats->Destroy();
	stats = 0;
	if (objectinfo)
		objectinfo->Destroy();
	objectinfo = 0;
	if (profiler)
		profiler->Destroy();
	profiler = 0;
	if (actionviewer)
		actionviewer->Destroy();
	actionviewer = 0;
	if (skycontrol)
		skycontrol->Destroy();
	skycontrol = 0;
	if (emanager)
		emanager->Destroy();
	emanager = 0;
	if (pmanager)
		pmanager->Destroy();
	pmanager = 0;
	if (camtex)
		camtex->Destroy();
	camtex = 0;
}

void DebugPanel::On_chkCollisionDetection_Click(wxCommandEvent& event)
{
	if (Simcore)
		Simcore->camera->EnableCollisions(chkCollisionDetection->GetValue());
}

void DebugPanel::On_chkFrameLimiter_Click(wxCommandEvent& event)
{
	if (Simcore)
		Simcore->FrameLimiter = chkFrameLimiter->GetValue();
}

void DebugPanel::On_chkProcessElevators_Click(wxCommandEvent& event)
{
	if (Simcore)
		Simcore->ProcessElevators = chkProcessElevators->GetValue();
}

void DebugPanel::On_chkAutoShafts_Click(wxCommandEvent& event)
{
	if (Simcore)
		Simcore->AutoShafts = chkAutoShafts->GetValue();
}

void DebugPanel::On_bFloorList_Click(wxCommandEvent& event)
{
	if (Simcore)
		Simcore->ShowFloorList();
}

void DebugPanel::On_bMeshControl_Click(wxCommandEvent& event)
{
	if (!mc)
		mc = new MeshControl(this, -1);

	mc->CenterOnScreen();
	mc->Show();
}

void DebugPanel::On_bEditElevator_Click(wxCommandEvent& event)
{
	if (!ee)
		ee = new editelevator(this, -1);

	ee->CenterOnScreen();
	ee->Show();
}

void DebugPanel::OnInit()
{
	Simcore = skyscraper->GetActiveEngine()->GetSystem();

	if (!Simcore)
		return;

	//set check boxes
	chkCollisionDetection->SetValue(Simcore->camera->CollisionsEnabled());
	chkGravity->SetValue(Simcore->camera->GetGravityStatus());
	chkFrameLimiter->SetValue(Simcore->FrameLimiter);
	chkProcessElevators->SetValue(Simcore->ProcessElevators);
	chkAutoShafts->SetValue(Simcore->AutoShafts);
	chkAutoStairs->SetValue(Simcore->AutoStairs);
	chkVerbose->SetValue(Simcore->Verbose);
	chkRandom->SetValue(Simcore->RandomActivity);

	if (!timer)
		timer = new Timer(this, Simcore);
	else
	{
		EnableTimer(false);
		timer->dp = this;
		timer->Simcore = Simcore;
	}

	EnableTimer(true);
}

void DebugPanel::Loop()
{
	if (skyscraper->GetActiveEngine())
	{
		if (Simcore != skyscraper->GetActiveEngine()->GetSystem())
			OnInit(); //reinitialize if active engine has changed
	}
	else
		return;

	SBS::Floor *floor = Simcore->GetFloor(Simcore->camera->CurrentFloor);

	t_camerap->SetLabel(TruncateNumber(Simcore->camera->GetPosition().x, 2) + wxT(", ") + TruncateNumber(Simcore->camera->GetPosition().y, 2) + wxT(", ") + TruncateNumber(Simcore->camera->GetPosition().z, 2));
	t_rotation->SetLabel(TruncateNumber(Simcore->camera->GetRotation().x, 2) + wxT(", ") + TruncateNumber(Simcore->camera->GetRotation().y, 2) + wxT(", ") + TruncateNumber(Simcore->camera->GetRotation().z, 2));
	t_camerafloor->SetLabel(SBS::ToString(Simcore->camera->CurrentFloor) + wxT(" (") + Simcore->camera->CurrentFloorID + wxT(")"));
	t_object->SetLabel(Simcore->camera->GetClickedMeshName());
	t_framerate->SetLabel(TruncateNumber(Simcore->FPS, 2));
	t_collision->SetLabel(Simcore->camera->LastHitMesh);
	t_clickposition->SetLabel(TruncateNumber(Simcore->camera->HitPosition.x, 2) + wxT(", ") + TruncateNumber(Simcore->camera->HitPosition.y, 2) + wxT(", ") + TruncateNumber(Simcore->camera->HitPosition.z, 2));
	if (floor)
		t_floorname->SetLabel(floor->Name);

	if (Simcore->GetElevatorCount() > 0)
	{
		bEditElevator->Enable(true);
		t_elevnumber->SetLabel(SBS::ToString(Simcore->ElevatorNumber));
		if (Simcore->GetElevator(Simcore->ElevatorNumber))
			t_elevfloor->SetLabel(SBS::ToString(Simcore->GetElevator(Simcore->ElevatorNumber)->GetCar(1)->GetFloor()));
	}
	else
		bEditElevator->Enable(false);

	if (ee)
	{
		if (ee->IsShown() == true)
			ee->Loop();
	}

	if (mc)
	{
		if (mc->IsShown() == true)
			mc->Loop();
	}

	if (cc)
	{
		if (cc->IsShown() == true)
			cc->Loop();
	}

	if (stats)
	{
		if (stats->IsShown() == true)
			stats->Loop();
	}

	if (objectinfo)
	{
		if (objectinfo->IsShown() == true)
			objectinfo->Loop();
	}

	if (profiler && Simcore)
	{
		if (profiler->IsShown() == true)
		{
			SBS::enable_profiling = true;
			profiler->Loop();
		}
		else
			SBS::enable_profiling = false;
	}

	if (actionviewer)
	{
		if (actionviewer->IsShown() == true)
			actionviewer->Loop();
	}

	if (skycontrol)
	{
		if (skycontrol->IsShown() == true)
			skycontrol->Loop();
	}

	if (emanager)
	{
		if (emanager->IsShown() == true)
			emanager->Loop();
	}

	if (pmanager)
	{
		if (pmanager->IsShown() == true)
			pmanager->Loop();
	}

	if (camtex)
	{
		if (camtex->IsShown() == true)
			camtex->Loop();
	}
}

void DebugPanel::Timer::Notify()
{
	if (dp)
		dp->Loop();
}

void DebugPanel::On_chkGravity_Click(wxCommandEvent& event)
{
	//enables or disables gravity
	if (Simcore)
		Simcore->camera->EnableGravity(chkGravity->GetValue());
}

void DebugPanel::On_chkAutoStairs_Click(wxCommandEvent& event)
{
	if (Simcore)
		Simcore->AutoStairs = chkAutoStairs->GetValue();
}

void DebugPanel::On_bCameraControl_Click(wxCommandEvent& event)
{
	if (!cc)
		cc = new CameraControl(this, -1);

	cc->CenterOnScreen();
	cc->Show();
}

void DebugPanel::On_bControlReference_Click(wxCommandEvent& event)
{
	if (!kd)
		kd = new KeyDialog(this, -1);

	kd->CenterOnScreen();
	kd->Show();
}

void DebugPanel::On_bStats_Click(wxCommandEvent& event)
{
	if (!stats)
		stats = new Stats(this, -1);

	stats->CenterOnScreen();
	stats->Show();
}

void DebugPanel::On_bConsole_Click(wxCommandEvent& event)
{
	skyscraper->ShowConsole();
}

void DebugPanel::On_chkVerbose_Click(wxCommandEvent& event)
{
	if (Simcore)
		Simcore->Verbose = chkVerbose->GetValue();
}

void DebugPanel::On_bObjectInfo_Click(wxCommandEvent& event)
{
	if (!objectinfo)
		objectinfo = new ObjectInfo(this, -1);

	objectinfo->CenterOnScreen();
	objectinfo->Show();
}

void DebugPanel::On_chkRandom_Click(wxCommandEvent& event)
{
	if (Simcore)
		Simcore->EnableRandomActivity(chkRandom->GetValue());
}

void DebugPanel::On_bProfiler_Click(wxCommandEvent& event)
{
	if (!profiler)
		profiler = new Profiler(this, -1);

	profiler->CenterOnScreen();
	profiler->Show();
}

void DebugPanel::On_bActionViewer_Click(wxCommandEvent& event)
{
	if (!actionviewer)
		actionviewer = new ActionViewer(this, -1);

	actionviewer->CenterOnScreen();
	actionviewer->Show();
}

void DebugPanel::On_bKeys_Click(wxCommandEvent& event)
{
	if (Simcore)
		Simcore->ListKeys();
}

void DebugPanel::On_bTextures_Click(wxCommandEvent& event)
{
	if (Simcore)
		Simcore->Report("\n" + Simcore->GetTextureManager()->ListTextures(true));
}

void DebugPanel::On_bFloorInfo_Click(wxCommandEvent& event)
{
	if (!Simcore)
		return;

	SBS::Floor *floor = Simcore->GetFloor(Simcore->camera->CurrentFloor);

	if (floor)
		floor->ShowInfo();
}

void DebugPanel::On_bSkyControl_Click(wxCommandEvent& event)
{
	if (!skycontrol)
		skycontrol = new SkyControl(this, -1);

	skycontrol->CenterOnScreen();
	skycontrol->Show();
}

void DebugPanel::On_bEngineManager_Click(wxCommandEvent& event)
{
	if (!emanager)
		emanager = new EngineManager(this, -1);

	emanager->CenterOnScreen();
	emanager->Show();
}

void DebugPanel::On_bPeopleManager_Click(wxCommandEvent& event)
{
	if (!pmanager)
		pmanager = new PeopleManager(this, -1);

	pmanager->CenterOnScreen();
	pmanager->Show();
}

void DebugPanel::EnableTimer(bool value)
{
	if (!timer)
		return;

	if (value == true)
		timer->Start(40);
	else
		timer->Stop();
}

void DebugPanel::ShowControlReference()
{
	wxCommandEvent event;
	On_bControlReference_Click(event);
}

wxString TruncateNumber(float value, int decimals)
{
	std::string number = SBS::TruncateNumber(value, decimals);
	wxString number2 = number;

	return number2;
}

wxString TruncateNumber(double value, int decimals)
{
	std::string number = SBS::TruncateNumber(value, decimals);
	wxString number2 = number;

	return number2;
}

bool IsNumeric(const wxString &string)
{
	std::string s;
	s = string;
	return SBS::IsNumeric(s);
}

bool IsNumeric(const wxString &string, int &number)
{
	std::string s;
	s = string;
	return SBS::IsNumeric(s, number);
}

bool IsNumeric(const wxString &string, float &number)
{
	std::string s;
	s = string;
	return SBS::IsNumeric(s, number);
}

bool IsNumeric(const wxString &string, double &number)
{
	std::string s;
	s = string;
	return SBS::IsNumeric(s, number);
}

void DebugPanel::On_bCameraTexture_Click(wxCommandEvent& event)
{
	if (!camtex)
		camtex = new CameraTextureControl(this, -1);

	camtex->CenterOnScreen();
	camtex->Show();
}

void DebugPanel::On_bLightControl_Click(wxCommandEvent& event)
{
}

}
