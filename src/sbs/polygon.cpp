/*
	Scalable Building Simulator - Polygon Object
	The Skyscraper Project - Version 1.12 Alpha
	Copyright (C)2004-2024 Ryan Thoryk
	https://www.skyscrapersim.net
	https://sourceforge.net/projects/skyscraper/
	Contact - ryan@skyscrapersim.net

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
#include "dynamicmesh.h"
#include "triangle.h"
#include "mesh.h"
#include "polymesh.h"
#include "texture.h"
#include "polygon.h"

namespace SBS {

Polygon::Polygon(Object *parent, const std::string &name, MeshObject *meshwrapper, GeometrySet &geometry, std::vector<Triangle> &triangles, Matrix3 &tex_matrix, Vector3 &tex_vector, const std::string &material, Plane &plane) : ObjectBase(parent)
{
	mesh = meshwrapper;
	t_matrix = tex_matrix;
	t_vector = tex_vector;
	this->material = material;
	this->plane = plane;
	this->geometry = geometry;
	this->triangles = triangles;
	SetName(name);

	vertex_count = 0;
	for (size_t i = 0; i < geometry.size(); i++)
	{
		vertex_count += geometry[i].size();
	}

	mesh->ResetPrepare();

	sbs->PolygonCount++;

	//register texture usage
	if (material != "")
		sbs->GetTextureManager()->IncrementTextureUsage(material);
}

Polygon::~Polygon()
{
	if (material != "" && sbs->FastDelete == false)
		sbs->GetTextureManager()->DecrementTextureUsage(material);

	mesh->ResetPrepare();

	sbs->PolygonCount--;
}

void Polygon::GetTextureMapping(Matrix3 &tm, Vector3 &tv)
{
	//return texture mapping matrix and vector
	tm = t_matrix;
	tv = t_vector;
}

void Polygon::Move(const Vector3 &position, Real speed)
{
	/*bool dynamic = mesh->UsingDynamicBuffers();

	int submesh = mesh->GetPolyMesh()->FindMatchingSubMesh(material);

	if (submesh == -1)
		return;

	for (size_t i = 0; i < index_extents.size(); i++)
	{
		int min = index_extents[i].min;
		int max = index_extents[i].max;

		for (int index = min; index <= max; index++)
		{
			PolyMesh::Geometry &data = mesh->GetPolyMesh()->Submeshes[submesh].MeshGeometry[index];
			data.vertex += sbs->ToRemote(position * speed);

			//update vertices in render buffer, if using dynamic buffers
			if (dynamic == true)
				mesh->MeshWrapper->UpdateVertices(mesh, material, index, true);
		}
	}*/
}

Plane Polygon::GetAbsolutePlane()
{
	//convert to an absolute plane
	Plane plane2(this->plane.normal, sbs->ToRemote(mesh->GetPosition()));
	return Plane(this->plane.normal, -(this->plane.d + plane2.d));
}

Vector2 Polygon::GetExtents(int coord)
{
	//returns the extents of a polygon
	//coord must be either 1 (for x), 2 (for y) or 3 (for z)

	//return 0,0 if coord value is out of range
	if (coord < 1 || coord > 3)
		return Vector2(0, 0);

	//get polygon extents
	PolyArray poly;
	for (size_t i = 0; i < geometry.size(); i++)
	{
		for (size_t j = 0; j < geometry[i].size(); j++)
		{
			poly.push_back(geometry[i][j].vertex);
		}
	}

	Vector2 extents = sbs->GetExtents(poly, coord);

	return extents;
}

void Polygon::ChangeHeight(Real newheight)
{
	/*bool dynamic = mesh->UsingDynamicBuffers();

	Vector2 extents = GetExtents(2);

	//modify polygon data
	int submesh = mesh->GetPolyMesh()->FindMatchingSubMesh(material);

	if (submesh == -1)
		return;

	for (size_t i = 0; i < index_extents.size(); i++)
	{
		unsigned int min = index_extents[i].min;
		unsigned int max = index_extents[i].max;

		for (unsigned int index = min; index <= max; index++)
		{
			PolyMesh::Geometry &data = mesh->GetPolyMesh()->Submeshes[submesh].MeshGeometry[index];
			if (data.vertex.y == sbs->ToRemote(extents.y))
			{
				data.vertex.y = sbs->ToRemote(extents.x + newheight);

				//update vertices in render buffer, if using dynamic buffers
				if (dynamic == true)
					mesh->MeshWrapper->UpdateVertices(mesh, material, index, true);
			}
		}
	}*/
}

bool Polygon::ReplaceTexture(const std::string &oldtexture, const std::string &newtexture)
{
	//replace material named oldtexture with newtexture

	if (oldtexture == newtexture)
		return false;

	if (material == oldtexture)
	{
		bool result = mesh->GetDynamicMesh()->ChangeTexture(oldtexture, newtexture, mesh);

		if (result == false)
			return false;

		material = newtexture;
		sbs->GetTextureManager()->DecrementTextureUsage(oldtexture);
		sbs->GetTextureManager()->IncrementTextureUsage(newtexture);
		//mesh->ResetPrepare();
		return true;
	}
	return false;
}

bool Polygon::ChangeTexture(const std::string &texture, bool matcheck)
{
	//changes a texture
	//if matcheck is true, exit if old and new textures are the same

	if (matcheck == true)
	{
		if (material == texture)
			return false;
	}
	sbs->GetTextureManager()->DecrementTextureUsage(material);
	material = texture;
	sbs->GetTextureManager()->IncrementTextureUsage(texture);
	//mesh->ResetPrepare();
	return true;
}

Vector3 Polygon::GetVertex(int index)
{
	int offset = 0;
	for (size_t i = 0; i < geometry.size(); i++)
	{
		for (size_t j = 0; j < geometry[i].size(); j++)
		{
			if (index == offset + j)
				return geometry[i][j].vertex;
		}
		offset += geometry[i].size();
	}
	return Vector3::ZERO;
}

}
