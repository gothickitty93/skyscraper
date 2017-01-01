/* $Id$ */

/*
	Skyscraper 1.11 Alpha - Action Viewer
	Copyright (C)2003-2017 Ryan Thoryk
	http://www.skyscrapersim.com
	http://sourceforge.net/projects/skyscraper
	Contact - ryan@skyscrapersim.com

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

#ifndef ACTIONVIEWER_H
#define ACTIONVIEWER_H

//(*Headers(ActionViewer)
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/listbox.h>
//*)

namespace Skyscraper {

class ActionViewer: public wxDialog
{
	public:

		ActionViewer(DebugPanel* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~ActionViewer();

		//(*Declarations(ActionViewer)
		wxTextCtrl* tType;
		wxTextCtrl* tParameters;
		wxStaticText* StaticText1;
		wxStaticText* StaticText3;
		wxListBox* ActionList;
		wxTextCtrl* tCommand;
		wxTextCtrl* tName;
		wxStaticText* StaticText4;
		wxButton* bDelete;
		wxButton* bRun;
		wxStaticText* StaticText5;
		wxStaticText* StaticText2;
		wxButton* bOK;
		wxTextCtrl* tParentName;
		//*)
		void Loop();

	protected:

		//(*Identifiers(ActionViewer)
		static const long ID_ActionList;
		static const long ID_bDelete;
		static const long ID_bRun;
		static const long ID_bOK;
		static const long ID_STATICTEXT1;
		static const long ID_tName;
		static const long ID_STATICTEXT2;
		static const long ID_tParentName;
		static const long ID_STATICTEXT3;
		static const long ID_tType;
		static const long ID_STATICTEXT4;
		static const long ID_tCommand;
		static const long ID_STATICTEXT5;
		static const long ID_tParameters;
		//*)

	private:

		//(*Handlers(ActionViewer)
		void On_bRun_Click(wxCommandEvent& event);
		void On_bOK_Click(wxCommandEvent& event);
		void On_ActionList_Select(wxCommandEvent& event);
		void On_bDelete_Click(wxCommandEvent& event);
		//*)
		SBS::SBS *Simcore;
		DebugPanel *panel;
		int lastcount;

		DECLARE_EVENT_TABLE()
};

}

#endif
