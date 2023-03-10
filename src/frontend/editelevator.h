/*
	Skyscraper 1.12 Alpha - Edit Elevator Form
	Copyright (C)2004-2023 Ryan Thoryk
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

#ifndef EDITELEVATOR_H
#define EDITELEVATOR_H

//(*Headers(editelevator)
#include <wx/button.h>
#include <wx/checkbox.h>
#include <wx/dialog.h>
#include <wx/radiobut.h>
#include <wx/scrolbar.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/tglbtn.h>
//*)

namespace Skyscraper {

class editelevator: public wxDialog
{
	friend class Timer;
	public:
		editelevator(DebugPanel* parent,wxWindowID id = -1);
		virtual ~editelevator();

		//(*Identifiers(editelevator)
		static const long ID_tElevator;
		static const long ID_sNumber;
		static const long ID_tFloor;
		static const long ID_sFloor;
		static const long ID_bACPMode;
		static const long ID_bUpPeak;
		static const long ID_bDownPeak;
		static const long ID_bIndService;
		static const long ID_bInsService;
		static const long ID_Fire1Off;
		static const long ID_Fire1On;
		static const long ID_Fire1Bypass;
		static const long ID_Fire2Off;
		static const long ID_Fire2On;
		static const long ID_Fire2Hold;
		static const long ID_CHECKBOX1;
		static const long ID_chkRun;
		static const long ID_bUp;
		static const long ID_bGoToggle;
		static const long ID_bDown;
		static const long ID_tCar;
		static const long ID_sCar;
		static const long ID_tDoor;
		static const long ID_sDoor;
		static const long ID_bRefresh;
		static const long ID_bDumpFloors;
		static const long ID_bDumpQueues;
		static const long ID_bCall;
		static const long ID_bGo;
		static const long ID_bOpen;
		static const long ID_bOpenManual;
		static const long ID_bOpenShaftDoor;
		static const long ID_bStop;
		static const long ID_bChime;
		static const long ID_bEnqueueUp;
		static const long ID_bEnqueueDown;
		static const long ID_bClose;
		static const long ID_bCloseManual;
		static const long ID_bCloseShaftDoor;
		static const long ID_bHoldDoors;
		static const long ID_bStopDoors;
		static const long ID_STATICTEXT3;
		static const long ID_txtNumber;
		static const long ID_STATICTEXT5;
		static const long ID_txtName;
		static const long ID_bSetName;
		static const long ID_STATICTEXT9;
		static const long ID_txtType;
		static const long ID_bSetType;
		static const long ID_STATICTEXT4;
		static const long ID_txtEnabled;
		static const long ID_STATICTEXT6;
		static const long ID_txtShaft;
		static const long ID_STATICTEXT7;
		static const long ID_txtHeight;
		static const long ID_STATICTEXT8;
		static const long ID_txtDoorSize;
		static const long ID_STATICTEXT10;
		static const long ID_txtDoorDirection;
		static const long ID_STATICTEXT11;
		static const long ID_txtDoorsOpen;
		static const long ID_STATICTEXT12;
		static const long ID_txtBrakes;
		static const long ID_STATICTEXT13;
		static const long ID_txtStop;
		static const long ID_STATICTEXT42;
		static const long ID_txtDoorTimer;
		static const long ID_bSetDoorTimer;
		static const long ID_STATICTEXT61;
		static const long ID_txtQuickClose;
		static const long ID_bSetQuickClose;
		static const long ID_STATICTEXT44;
		static const long ID_txtSkipFloorText;
		static const long ID_bSetSkipFloorText;
		static const long ID_STATICTEXT52;
		static const long ID_txtAlarm;
		static const long ID_STATICTEXT28;
		static const long ID_txtWaitForDoors;
		static const long ID_STATICTEXT67;
		static const long ID_txtNudgeMode;
		static const long ID_bSetNudge;
		static const long ID_STATICTEXT32;
		static const long ID_txtDoorSensor;
		static const long ID_bDoorSensor;
		static const long ID_STATICTEXT86;
		static const long ID_txtActiveCallFloor;
		static const long ID_STATICTEXT87;
		static const long ID_txtActiveCallDirection;
		static const long ID_STATICTEXT70;
		static const long ID_txtNotified;
		static const long ID_STATICTEXT75;
		static const long ID_txtWaitForTimer;
		static const long ID_STATICTEXT76;
		static const long ID_txtLastChimeDirection;
		static const long ID_STATICTEXT56;
		static const long ID_txtLevelingSpeed;
		static const long ID_bSetLevelingSpeed;
		static const long ID_STATICTEXT57;
		static const long ID_txtLevelingOffset;
		static const long ID_bSetLevelingOffset;
		static const long ID_STATICTEXT88;
		static const long ID_txtLevelingOpen;
		static const long ID_bLevelingOpen;
		static const long ID_STATICTEXT58;
		static const long ID_txtMusicOn;
		static const long ID_bSetMusicOn;
		static const long ID_STATICTEXT77;
		static const long ID_txtMusicOnMove;
		static const long ID_bSetMusicOnMove;
		static const long ID_STATICTEXT78;
		static const long ID_txtFloorSounds;
		static const long ID_bSetFloorSounds;
		static const long ID_STATICTEXT79;
		static const long ID_txtFloorBeeps;
		static const long ID_bSetFloorBeeps;
		static const long ID_STATICTEXT80;
		static const long ID_txtMessageSounds;
		static const long ID_bSetMessageSounds;
		static const long ID_STATICTEXT81;
		static const long ID_txtAutoEnable;
		static const long ID_bSetAutoEnable;
		static const long ID_STATICTEXT82;
		static const long ID_txtReOpen;
		static const long ID_bSetReOpen;
		static const long ID_STATICTEXT83;
		static const long ID_txtAutoDoors;
		static const long ID_bSetAutoDoors;
		static const long ID_STATICTEXT84;
		static const long ID_txtOpenOnStart;
		static const long ID_STATICTEXT85;
		static const long ID_txtInterlocks;
		static const long ID_bInterlocks;
		static const long ID_STATICTEXT14;
		static const long ID_txtFloor;
		static const long ID_STATICTEXT15;
		static const long ID_txtPosition;
		static const long ID_STATICTEXT17;
		static const long ID_txtOriginFloor;
		static const long ID_STATICTEXT18;
		static const long ID_txtElevStart;
		static const long ID_STATICTEXT19;
		static const long ID_txtDoorOrigin;
		static const long ID_STATICTEXT20;
		static const long ID_txtShaftDoorOrigin;
		static const long ID_STATICTEXT50;
		static const long ID_txtOnFloor;
		static const long ID_STATICTEXT25;
		static const long ID_txtMotor;
		static const long ID_STATICTEXT54;
		static const long ID_txtCameraOffset;
		static const long ID_STATICTEXT71;
		static const long ID_txtMusicPosition;
		static const long ID_STATICTEXT38;
		static const long ID_txtQueueDirection;
		static const long ID_STATICTEXT40;
		static const long ID_txtQueueLastUp;
		static const long ID_STATICTEXT41;
		static const long ID_txtQueueLastDown;
		static const long ID_STATICTEXT51;
		static const long ID_txtQueueLastDirection;
		static const long ID_STATICTEXT68;
		static const long ID_txtQueueResets;
		static const long ID_STATICTEXT69;
		static const long ID_txtLimitQueue;
		static const long ID_bResetQueues;
		static const long ID_STATICTEXT21;
		static const long ID_txtUpSpeed;
		static const long ID_bSetUpSpeed;
		static const long ID_STATICTEXT16;
		static const long ID_txtDownSpeed;
		static const long ID_bSetDownSpeed;
		static const long ID_STATICTEXT22;
		static const long ID_txtAcceleration;
		static const long ID_bSetAcceleration;
		static const long ID_STATICTEXT23;
		static const long ID_txtDeceleration;
		static const long ID_bSetDeceleration;
		static const long ID_STATICTEXT1;
		static const long ID_txtAccelJerk;
		static const long ID_bSetAccelJerk;
		static const long ID_STATICTEXT29;
		static const long ID_txtDecelJerk;
		static const long ID_bSetDecelJerk;
		static const long ID_STATICTEXT26;
		static const long ID_txtRate;
		static const long ID_STATICTEXT27;
		static const long ID_txtDirection;
		static const long ID_STATICTEXT72;
		static const long ID_txtActiveDirection;
		static const long ID_STATICTEXT2;
		static const long ID_txtJerkRate;
		static const long ID_STATICTEXT49;
		static const long ID_txtDoorStopped;
		static const long ID_STATICTEXT53;
		static const long ID_txtIsIdle;
		static const long ID_STATICTEXT24;
		static const long ID_txtManualGo;
		static const long ID_STATICTEXT55;
		static const long ID_txtLeveling;
		static const long ID_STATICTEXT60;
		static const long ID_txtParking;
		static const long ID_STATICTEXT73;
		static const long ID_txtManualMove;
		static const long ID_STATICTEXT63;
		static const long ID_txtSlowSpeed;
		static const long ID_bSetSlowSpeed;
		static const long ID_STATICTEXT64;
		static const long ID_txtManualSpeed;
		static const long ID_bSetManualSpeed;
		static const long ID_STATICTEXT74;
		static const long ID_txtInspectionSpeed;
		static const long ID_bSetInspectionSpeed;
		static const long ID_STATICTEXT30;
		static const long ID_txtDestFloor;
		static const long ID_STATICTEXT43;
		static const long ID_txtIsMoving;
		static const long ID_STATICTEXT31;
		static const long ID_txtMoveElevator;
		static const long ID_STATICTEXT33;
		static const long ID_txtDistance;
		static const long ID_STATICTEXT34;
		static const long ID_txtDestination;
		static const long ID_STATICTEXT35;
		static const long ID_txtStopDistance;
		static const long ID_STATICTEXT36;
		static const long ID_txtTempDecel;
		static const long ID_STATICTEXT37;
		static const long ID_txtErrorOffset;
		static const long ID_STATICTEXT59;
		static const long ID_txtNotifyEarly;
		static const long ID_bNotifyEarly;
		static const long ID_STATICTEXT89;
		static const long ID_txtNotifyLate;
		static const long ID_bNotifyLate;
		static const long ID_STATICTEXT65;
		static const long ID_txtDepartureDelay;
		static const long ID_bSetDepartureDelay;
		static const long ID_STATICTEXT66;
		static const long ID_txtArrivalDelay;
		static const long ID_bSetArrivalDelay;
		static const long ID_STATICTEXT45;
		static const long ID_txtACPFloor;
		static const long ID_bSetACPFloor;
		static const long ID_STATICTEXT46;
		static const long ID_txtRecallFloor;
		static const long ID_bSetRecallFloor;
		static const long ID_STATICTEXT47;
		static const long ID_txtRecallAlternate;
		static const long ID_bSetRecallAlternate;
		static const long ID_STATICTEXT39;
		static const long ID_txtParkingFloor;
		static const long ID_bSetParkingFloor;
		static const long ID_STATICTEXT48;
		static const long ID_txtParkingDelay;
		static const long ID_bSetParkingDelay;
		static const long ID_STATICTEXT62;
		static const long ID_txtNudgeTimer;
		static const long ID_bSetNudgeTimer;
		//*)
		void Loop();
		void SetMainValues();

	protected:

		//(*Handlers(editelevator)
		void On_bCall_Click(wxCommandEvent& event);
		void On_bEnqueueUp_Click(wxCommandEvent& event);
		void On_bGo_Click(wxCommandEvent& event);
		void On_bEnqueueDown_Click(wxCommandEvent& event);
		void On_bOpen_Click(wxCommandEvent& event);
		void On_bClose_Click(wxCommandEvent& event);
		void On_bOpenManual_Click(wxCommandEvent& event);
		void On_bCloseManual_Click(wxCommandEvent& event);
		void On_bStop_Click(wxCommandEvent& event);
		void On_bHoldDoors_Click(wxCommandEvent& event);
		void On_bSetName_Click(wxCommandEvent& event);
		void On_bSetAcceleration_Click(wxCommandEvent& event);
		void On_bSetDeceleration_Click(wxCommandEvent& event);
		void On_bSetOpenSpeed_Click(wxCommandEvent& event);
		void On_bSetDoorAccel_Click(wxCommandEvent& event);
		void On_bDumpFloors_Click(wxCommandEvent& event);
		void On_bDumpQueues_Click(wxCommandEvent& event);
		void OnchkVisibleClick(wxCommandEvent& event);
		void On_chkVisible_Click(wxCommandEvent& event);
		void On_bSetJerk_Click(wxCommandEvent& event);
		void On_bSetDecelJerk_Click(wxCommandEvent& event);
		void On_bSetAccelJerk_Click(wxCommandEvent& event);
		void On_bOpenShaftDoor_Click(wxCommandEvent& event);
		void On_bCloseShaftDoor_Click(wxCommandEvent& event);
		void On_bSetDoorTimer_Click(wxCommandEvent& event);
		void On_bChime_Click(wxCommandEvent& event);
		void On_bACPMode_Toggle(wxCommandEvent& event);
		void On_bUpPeak_Toggle(wxCommandEvent& event);
		void On_bDownPeak_Toggle(wxCommandEvent& event);
		void On_bIndService_Toggle(wxCommandEvent& event);
		void On_bInsService_Toggle(wxCommandEvent& event);
		void On_bRefresh_Click(wxCommandEvent& event);
		void On_bSetSkipFloorText_Click(wxCommandEvent& event);
		void On_bSetACPFloor_Click(wxCommandEvent& event);
		void On_bSetRecallFloor_Click(wxCommandEvent& event);
		void On_bSetRecallAlternate_Click(wxCommandEvent& event);
		void On_Fire1Off_Select(wxCommandEvent& event);
		void On_Fire1On_Select(wxCommandEvent& event);
		void On_Fire1Bypass_Select(wxCommandEvent& event);
		void On_Fire2Off_Select(wxCommandEvent& event);
		void On_Fire2On_Select(wxCommandEvent& event);
		void On_Fire2Hold_Select(wxCommandEvent& event);
		void On_bStopDoors_Click(wxCommandEvent& event);
		void On_bUp_Toggle(wxCommandEvent& event);
		void On_bGoToggle_Toggle(wxCommandEvent& event);
		void On_bDown_Toggle(wxCommandEvent& event);
		void On_bResetQueues_Click(wxCommandEvent& event);
		void On_bSetParkingFloor_Click(wxCommandEvent& event);
		void On_bSetParkingDelay_Click(wxCommandEvent& event);
		void On_bSetLevelingSpeed_Click(wxCommandEvent& event);
		void On_bSetLevelingOffset_Click(wxCommandEvent& event);
		void On_bSetLevelingOpen_Click(wxCommandEvent& event);
		void On_bNotifyEarly_Click(wxCommandEvent& event);
		void On_chkRun_Click(wxCommandEvent& event);
		void On_bSetQuickClose_Click(wxCommandEvent& event);
		void On_bSetNudgeTimer_Click(wxCommandEvent& event);
		void On_bSetSlowSpeed_Click(wxCommandEvent& event);
		void On_bSetManualSpeed_Click(wxCommandEvent& event);
		void On_bSetDepartureDelay_Click(wxCommandEvent& event);
		void On_bSetArrivalDelay_Click(wxCommandEvent& event);
		void On_bSetInspectionSpeed_Click(wxCommandEvent& event);
		void On_bSetMusicOn_Click(wxCommandEvent& event);
		void On_bSetMusicOnMove_Click(wxCommandEvent& event);
		void On_bSetFloorSounds_Click(wxCommandEvent& event);
		void On_bSetFloorBeeps_Click(wxCommandEvent& event);
		void On_bSetMessageSounds_Click(wxCommandEvent& event);
		void On_bSetAutoEnable_Click(wxCommandEvent& event);
		void On_bSetReOpen_Click(wxCommandEvent& event);
		void On_bSetAutoDoors_Click(wxCommandEvent& event);
		void On_bInterlocks_Click(wxCommandEvent& event);
		void On_bSetNudge_Click(wxCommandEvent& event);
		void On_bDoorSensor_Click(wxCommandEvent& event);
		void On_bSetType_Click(wxCommandEvent& event);
		void On_bSetUpSpeed_Click(wxCommandEvent& event);
		void On_bSetDownSpeed_Click(wxCommandEvent& event);
		void On_bNotifyLate_Click(wxCommandEvent& event);
		//*)
		void OnInit();

		//(*Declarations(editelevator)
		wxBoxSizer* BoxSizer10;
		wxBoxSizer* BoxSizer1;
		wxBoxSizer* BoxSizer2;
		wxBoxSizer* BoxSizer3;
		wxBoxSizer* BoxSizer6;
		wxBoxSizer* BoxSizer8;
		wxBoxSizer* BoxSizer9;
		wxButton* bCall;
		wxButton* bChime;
		wxButton* bClose;
		wxButton* bCloseManual;
		wxButton* bCloseShaftDoor;
		wxButton* bDoorSensor;
		wxButton* bDumpFloors;
		wxButton* bDumpQueues;
		wxButton* bEnqueueDown;
		wxButton* bEnqueueUp;
		wxButton* bGo;
		wxButton* bHoldDoors;
		wxButton* bInterlocks;
		wxButton* bLevelingOpen;
		wxButton* bNotifyEarly;
		wxButton* bNotifyLate;
		wxButton* bOpen;
		wxButton* bOpenManual;
		wxButton* bOpenShaftDoor;
		wxButton* bRefresh;
		wxButton* bResetQueues;
		wxButton* bSetACPFloor;
		wxButton* bSetAccelJerk;
		wxButton* bSetAcceleration;
		wxButton* bSetArrivalDelay;
		wxButton* bSetAutoDoors;
		wxButton* bSetAutoEnable;
		wxButton* bSetDecelJerk;
		wxButton* bSetDeceleration;
		wxButton* bSetDepartureDelay;
		wxButton* bSetDoorTimer;
		wxButton* bSetDownSpeed;
		wxButton* bSetFloorBeeps;
		wxButton* bSetFloorSounds;
		wxButton* bSetInspectionSpeed;
		wxButton* bSetLevelingOffset;
		wxButton* bSetLevelingSpeed;
		wxButton* bSetManualSpeed;
		wxButton* bSetMessageSounds;
		wxButton* bSetMusicOn;
		wxButton* bSetMusicOnMove;
		wxButton* bSetName;
		wxButton* bSetNudge;
		wxButton* bSetNudgeTimer;
		wxButton* bSetParkingDelay;
		wxButton* bSetParkingFloor;
		wxButton* bSetQuickClose;
		wxButton* bSetReOpen;
		wxButton* bSetRecallAlternate;
		wxButton* bSetRecallFloor;
		wxButton* bSetSkipFloorText;
		wxButton* bSetSlowSpeed;
		wxButton* bSetType;
		wxButton* bSetUpSpeed;
		wxButton* bStop;
		wxButton* bStopDoors;
		wxCheckBox* chkRun;
		wxCheckBox* chkVisible;
		wxFlexGridSizer* FlexGridSizer1;
		wxFlexGridSizer* FlexGridSizer2;
		wxFlexGridSizer* FlexGridSizer3;
		wxFlexGridSizer* FlexGridSizer6;
		wxFlexGridSizer* FlexGridSizer7;
		wxRadioButton* Fire1Bypass;
		wxRadioButton* Fire1Off;
		wxRadioButton* Fire1On;
		wxRadioButton* Fire2Hold;
		wxRadioButton* Fire2Off;
		wxRadioButton* Fire2On;
		wxScrollBar* sCar;
		wxScrollBar* sDoor;
		wxScrollBar* sFloor;
		wxScrollBar* sNumber;
		wxStaticBoxSizer* StaticBoxSizer1;
		wxStaticBoxSizer* StaticBoxSizer2;
		wxStaticBoxSizer* StaticBoxSizer3;
		wxStaticBoxSizer* StaticBoxSizer5;
		wxStaticBoxSizer* StaticBoxSizer7;
		wxStaticBoxSizer* StaticBoxSizer8;
		wxStaticText* StaticText10;
		wxStaticText* StaticText11;
		wxStaticText* StaticText12;
		wxStaticText* StaticText13;
		wxStaticText* StaticText14;
		wxStaticText* StaticText15;
		wxStaticText* StaticText16;
		wxStaticText* StaticText17;
		wxStaticText* StaticText18;
		wxStaticText* StaticText19;
		wxStaticText* StaticText1;
		wxStaticText* StaticText20;
		wxStaticText* StaticText21;
		wxStaticText* StaticText22;
		wxStaticText* StaticText23;
		wxStaticText* StaticText24;
		wxStaticText* StaticText25;
		wxStaticText* StaticText26;
		wxStaticText* StaticText27;
		wxStaticText* StaticText28;
		wxStaticText* StaticText29;
		wxStaticText* StaticText2;
		wxStaticText* StaticText30;
		wxStaticText* StaticText31;
		wxStaticText* StaticText32;
		wxStaticText* StaticText33;
		wxStaticText* StaticText34;
		wxStaticText* StaticText35;
		wxStaticText* StaticText36;
		wxStaticText* StaticText37;
		wxStaticText* StaticText38;
		wxStaticText* StaticText39;
		wxStaticText* StaticText3;
		wxStaticText* StaticText40;
		wxStaticText* StaticText41;
		wxStaticText* StaticText42;
		wxStaticText* StaticText43;
		wxStaticText* StaticText44;
		wxStaticText* StaticText45;
		wxStaticText* StaticText46;
		wxStaticText* StaticText47;
		wxStaticText* StaticText48;
		wxStaticText* StaticText49;
		wxStaticText* StaticText4;
		wxStaticText* StaticText50;
		wxStaticText* StaticText51;
		wxStaticText* StaticText52;
		wxStaticText* StaticText53;
		wxStaticText* StaticText54;
		wxStaticText* StaticText55;
		wxStaticText* StaticText56;
		wxStaticText* StaticText57;
		wxStaticText* StaticText58;
		wxStaticText* StaticText59;
		wxStaticText* StaticText5;
		wxStaticText* StaticText60;
		wxStaticText* StaticText61;
		wxStaticText* StaticText62;
		wxStaticText* StaticText63;
		wxStaticText* StaticText64;
		wxStaticText* StaticText65;
		wxStaticText* StaticText66;
		wxStaticText* StaticText67;
		wxStaticText* StaticText68;
		wxStaticText* StaticText69;
		wxStaticText* StaticText6;
		wxStaticText* StaticText70;
		wxStaticText* StaticText71;
		wxStaticText* StaticText72;
		wxStaticText* StaticText73;
		wxStaticText* StaticText74;
		wxStaticText* StaticText75;
		wxStaticText* StaticText76;
		wxStaticText* StaticText77;
		wxStaticText* StaticText78;
		wxStaticText* StaticText79;
		wxStaticText* StaticText7;
		wxStaticText* StaticText80;
		wxStaticText* StaticText81;
		wxStaticText* StaticText82;
		wxStaticText* StaticText83;
		wxStaticText* StaticText84;
		wxStaticText* StaticText85;
		wxStaticText* StaticText86;
		wxStaticText* StaticText87;
		wxStaticText* StaticText88;
		wxStaticText* StaticText89;
		wxStaticText* StaticText8;
		wxStaticText* StaticText9;
		wxStaticText* tCar;
		wxStaticText* tDoor;
		wxStaticText* tElevator;
		wxStaticText* tFloor;
		wxTextCtrl* txtACPFloor;
		wxTextCtrl* txtAccelJerk;
		wxTextCtrl* txtAcceleration;
		wxTextCtrl* txtActiveCallDirection;
		wxTextCtrl* txtActiveCallFloor;
		wxTextCtrl* txtActiveDirection;
		wxTextCtrl* txtAlarm;
		wxTextCtrl* txtArrivalDelay;
		wxTextCtrl* txtAutoDoors;
		wxTextCtrl* txtAutoEnable;
		wxTextCtrl* txtBrakes;
		wxTextCtrl* txtCameraOffset;
		wxTextCtrl* txtDecelJerk;
		wxTextCtrl* txtDeceleration;
		wxTextCtrl* txtDepartureDelay;
		wxTextCtrl* txtDestFloor;
		wxTextCtrl* txtDestination;
		wxTextCtrl* txtDirection;
		wxTextCtrl* txtDistance;
		wxTextCtrl* txtDoorDirection;
		wxTextCtrl* txtDoorOrigin;
		wxTextCtrl* txtDoorSensor;
		wxTextCtrl* txtDoorSize;
		wxTextCtrl* txtDoorStopped;
		wxTextCtrl* txtDoorTimer;
		wxTextCtrl* txtDoorsOpen;
		wxTextCtrl* txtDownSpeed;
		wxTextCtrl* txtElevStart;
		wxTextCtrl* txtEnabled;
		wxTextCtrl* txtErrorOffset;
		wxTextCtrl* txtFloor;
		wxTextCtrl* txtFloorBeeps;
		wxTextCtrl* txtFloorSounds;
		wxTextCtrl* txtHeight;
		wxTextCtrl* txtInspectionSpeed;
		wxTextCtrl* txtInterlocks;
		wxTextCtrl* txtIsIdle;
		wxTextCtrl* txtIsMoving;
		wxTextCtrl* txtJerkRate;
		wxTextCtrl* txtLastChimeDirection;
		wxTextCtrl* txtLeveling;
		wxTextCtrl* txtLevelingOffset;
		wxTextCtrl* txtLevelingOpen;
		wxTextCtrl* txtLevelingSpeed;
		wxTextCtrl* txtLimitQueue;
		wxTextCtrl* txtManualGo;
		wxTextCtrl* txtManualMove;
		wxTextCtrl* txtManualSpeed;
		wxTextCtrl* txtMessageSounds;
		wxTextCtrl* txtMotor;
		wxTextCtrl* txtMoveElevator;
		wxTextCtrl* txtMusicOn;
		wxTextCtrl* txtMusicOnMove;
		wxTextCtrl* txtMusicPosition;
		wxTextCtrl* txtName;
		wxTextCtrl* txtNotified;
		wxTextCtrl* txtNotifyEarly;
		wxTextCtrl* txtNotifyLate;
		wxTextCtrl* txtNudgeMode;
		wxTextCtrl* txtNudgeTimer;
		wxTextCtrl* txtNumber;
		wxTextCtrl* txtOnFloor;
		wxTextCtrl* txtOpenOnStart;
		wxTextCtrl* txtOriginFloor;
		wxTextCtrl* txtParking;
		wxTextCtrl* txtParkingDelay;
		wxTextCtrl* txtParkingFloor;
		wxTextCtrl* txtPosition;
		wxTextCtrl* txtQueueDirection;
		wxTextCtrl* txtQueueLastDirection;
		wxTextCtrl* txtQueueLastDown;
		wxTextCtrl* txtQueueLastUp;
		wxTextCtrl* txtQueueResets;
		wxTextCtrl* txtQuickClose;
		wxTextCtrl* txtRate;
		wxTextCtrl* txtReOpen;
		wxTextCtrl* txtRecallAlternate;
		wxTextCtrl* txtRecallFloor;
		wxTextCtrl* txtShaft;
		wxTextCtrl* txtShaftDoorOrigin;
		wxTextCtrl* txtSkipFloorText;
		wxTextCtrl* txtSlowSpeed;
		wxTextCtrl* txtStop;
		wxTextCtrl* txtStopDistance;
		wxTextCtrl* txtTempDecel;
		wxTextCtrl* txtType;
		wxTextCtrl* txtUpSpeed;
		wxTextCtrl* txtWaitForDoors;
		wxTextCtrl* txtWaitForTimer;
		wxToggleButton* bACPMode;
		wxToggleButton* bDown;
		wxToggleButton* bDownPeak;
		wxToggleButton* bGoToggle;
		wxToggleButton* bIndService;
		wxToggleButton* bInsService;
		wxToggleButton* bUp;
		wxToggleButton* bUpPeak;
		//*)
		int last_elevator;
		int floor_number;

	private:

		SBS::SBS *Simcore;
		DebugPanel *debugpanel;
		int last_car;
		int last_door;
		int last_elevator_count;
		int last_car_count;
		int last_door_count;
		SBS::Elevator *elevator;
		SBS::ElevatorCar *car;
		SBS::ElevatorDoor *door;

		DECLARE_EVENT_TABLE()
};

}

#endif
