/*
	Scalable Building Simulator - Door Object
	The Skyscraper Project - Version 1.12 Alpha
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

#include "globals.h"
#include "sbs.h"
#include "manager.h"
#include "mesh.h"
#include "floor.h"
#include "elevatorcar.h"
#include "shaft.h"
#include "stairs.h"
#include "texture.h"
#include "sound.h"
#include "door.h"

namespace SBS {

Door::Door(Object *parent, DynamicMesh *wrapper, const std::string &name, const std::string &open_sound, const std::string &close_sound, bool open_state, const std::string &texture, Real thickness, int direction, Real speed, Real CenterX, Real CenterZ, Real width, Real height, Real voffset, Real tw, Real th) : Object(parent), DoorLock(this, direction)
{
	//creates a door
	//wall cuts must be performed by the calling (parent) function

	//direction table:
	//1 = faces left, opens left
	//2 = faces left, opens right
	//3 = faces right, opens right
	//4 = faces right, opens left
	//5 = faces front, opens front
	//6 = faces front, opens back
	//7 = faces back, opens back
	//8 = faces back, opens front

	//set up SBS object
	SetValues("Door", name, false);

	is_enabled = true;
	int Direction = direction;

	DoorDirection = false;
	if (direction == 3 || direction == 4 || direction == 7 || direction == 8)
		DoorDirection = true;

	OpenDirection = false;
	if (direction == 2 || direction == 3 || direction == 6 || direction == 7)
		OpenDirection = true;

	OpenState = false;
	IsMoving = false;
	Real x1 = 0, z1 = 0, x2 = 0, z2 = 0;
	OpenDoor = false;
	OpenSound = open_sound;
	CloseSound = close_sound;
	Speed = speed;
	sound = 0;
	door_changed = false; //needs to be implemented
	previous_open = false; //needs to be implemented

	//set speed to default value if invalid
	if (Speed <= 0)
		Speed = sbs->GetConfigFloat("Skyscraper.SBS.DoorSpeed", 75.0);

	if (Speed <= 0)
		Speed = 75;

	Ogre::Vector3 position;

	//set origin to location of the door's hinge/pivot point and set up door coordinates
	if (Direction == 1 || Direction == 2)
	{
		position = Ogre::Vector3(CenterX, voffset, CenterZ - (width / 2)); //front
		x1 = 0;
		x2 = 0;
		z1 = 0;
		z2 = width;
	}
	if (Direction == 3 || Direction == 4)
	{
		position = Ogre::Vector3(CenterX, voffset, CenterZ + (width / 2)); //back
		x1 = 0;
		x2 = 0;
		z1 = -width;
		z2 = 0;
	}
	if (Direction == 5 || Direction == 6)
	{
		position = Ogre::Vector3(CenterX + (width / 2), voffset, CenterZ); //right
		x1 = -width;
		x2 = 0;
		z1 = 0;
		z2 = 0;
	}
	if (Direction == 7 || Direction == 8)
	{
		position = Ogre::Vector3(CenterX - (width / 2), voffset, CenterZ); //left
		x1 = 0;
		x2 = width;
		z1 = 0;
		z2 = 0;
	}

	bool Clockwise = true;
	if (Direction == 1 || Direction == 3 || Direction == 5 || Direction == 7)
		Clockwise = false;

	//Create mesh
	DoorMesh = new MeshObject(this, name, wrapper);
	Move(position);

	//create sound object
	if (open_sound != "" || close_sound != "")
		sound = new Sound(this, "DoorSound", true);

	//create door
	sbs->DrawWalls(true, true, true, true, true, true);
	sbs->GetTextureManager()->ResetTextureMapping(true);
	if (Direction == 1 || Direction == 2 || Direction == 5 || Direction == 6)
		sbs->GetTextureManager()->SetTextureFlip(0, 1, 0, 0, 0, 0); //flip texture on rear side of door
	if (Direction == 3 || Direction == 4 || Direction == 7 || Direction == 8)
		sbs->GetTextureManager()->SetTextureFlip(1, 0, 0, 0, 0, 0); //flip texture on rear side of door

	Wall *wall;
	wall = DoorMesh->CreateWallObject(name);
	sbs->AddWallMain(wall, name, texture, thickness, x1, z1, x2, z2, height, height, 0, 0, tw, th, false);
	sbs->ResetWalls();
	sbs->GetTextureManager()->ResetTextureMapping();

	//open door on startup (without sound) if specified
	if (open_state == true)
		Open(position, false, true);
}

Door::~Door()
{
	//destructor

	if (sound)
	{
		sound->parent_deleting = true;
		delete sound;
	}
	sound = 0;

	if (DoorMesh)
	{
		DoorMesh->parent_deleting = true;
		delete DoorMesh;
	}
	DoorMesh = 0;

	//unregister from parent
	if (sbs->FastDelete == false)
	{
		if (parent_deleting == false)
		{
			std::string type = GetParent()->GetType();

			if (type == "ElevatorCar")
				static_cast<ElevatorCar*>(GetParent())->RemoveDoor(this);
			else if (type == "Floor")
				static_cast<Floor*>(GetParent())->RemoveDoor(this);
			else if (type == "Shaft Level")
				static_cast<Shaft::Level*>(GetParent())->RemoveDoor(this);
			else if (type == "Stairwell Level")
				static_cast<Stairwell::Level*>(GetParent())->RemoveDoor(this);
			else if (type == "DoorManager")
				sbs->GetDoorManager()->RemoveDoor(this);
		}
	}
}

bool Door::Open(Ogre::Vector3 &position, bool playsound, bool force)
{
	//position is the camera position, used to check if the door is locked
	//if force is true, locking/position check will be bypassed

	Report("Opening");

	EnableLoop(true);

	if (force == false)
	{
		//check lock state
		if (IsLocked(position) == true)
			return ReportError("Is locked");
	}

	OpenDoor = true;

	if (playsound == true && sound)
	{
		sound->Load(OpenSound);
		sound->Play();
	}

	OpenState = false;
	IsMoving = true;

	return true;
}

void Door::Close(bool playsound)
{
	Report("Closing");

	EnableLoop(true);

	OpenDoor = false;

	if (playsound == true && sound)
	{
		sound->Load(CloseSound);
		sound->Play();
	}

	OpenState = true;
	IsMoving = true;
}

bool Door::IsOpen()
{
	return OpenState;
}

void Door::Enabled(bool value)
{
	if (is_enabled == value)
		return;

	DoorMesh->Enabled(value);
	is_enabled = value;
}

void Door::Loop()
{
	if (IsMoving == true)
		MoveDoor();
	else
		EnableLoop(false);
}

void Door::MoveDoor()
{
	//door movement callback function
}

void Door::ClickDoor(Ogre::Vector3 &position)
{
	//code that runs when a user clicks on a door

	//open and close doors
	if (IsOpen() == false)
	{
		if (IsMoving == false)
			Open(position);
		else
			Close();
	}
	else
	{
		if (IsMoving == false)
			Close();
		else
			Open(position);
	}
}

void Door::OnClick(Ogre::Vector3 &position, bool shift, bool ctrl, bool alt, bool right)
{
	if (right == false)
	{
		//toggle lock status if ctrl and shift are pressed
		if (ctrl == true && shift == true)
			ToggleLock(position);
		else
			ClickDoor(position);
	}
}

void Door::Report(const std::string &message)
{
	//general reporting function
	Object::Report("Door " + GetName() + ": " + message);
}

bool Door::ReportError(const std::string &message)
{
	//general error reporting function
	return Object::ReportError("Door " + GetName() + ": " + message);
}

bool Door::GetDoorChanged()
{
	return door_changed;
}

bool Door::GetPreviousOpen()
{
	return previous_open;
}

}
