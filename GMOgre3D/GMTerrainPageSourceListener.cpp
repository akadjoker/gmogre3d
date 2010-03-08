/*
--------------------------------------------------------------------------------
GMOgre3D - Wrapper of the OGRE 3D library for Game Maker

Copyright (C) 2010 Robert Geiman
<robgeiman@gmail.com>

This program is free software; you can redistribute it and/or modify it under
the terms of the GNU Lesser General Public License as published by the Free Software
Foundation; either version 2 of the License, or (at your option) any later
version.

This program is distributed in the hope that it will be useful, but WITHOUT
ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License along with
this program; if not, write to the Free Software Foundation, Inc., 59 Temple
Place - Suite 330, Boston, MA 02111-1307, USA, or go to
http://www.gnu.org/copyleft/lesser.txt.
--------------------------------------------------------------------------------
*/

#include "stdafx.h"
#include "GMTerrainPageSourceListener.h"
#include "OgreTerrainSceneManager.h"
#include "GMAPI.h"


class TerrainVectorCalculator
{
public:
   size_t pagex_;
   size_t pagez_;
   int pageSize_;
   Ogre::Vector3 scale_;
   Ogre::Real* heightData_;

   Ogre::Vector3 v(int x, int z)
   {
      return scale_ * Ogre::Vector3(pagex_ * pageSize_ + x, heightData_[pageSize_ * z + x], pagez_ * pageSize_ + z);
   }       
};


GMTerrainPageSourceListener::GMTerrainPageSourceListener()
:  m_polys()
{
   Ogre::TerrainPageSourceListenerManager::getSingleton().addListener(this);
}


GMTerrainPageSourceListener::~GMTerrainPageSourceListener()
{
   Ogre::TerrainPageSourceListenerManager::getSingleton().removeListener(this);
}


void GMTerrainPageSourceListener::pageConstructed(Ogre::TerrainSceneManager* manager, size_t pagex, size_t pagez, Ogre::Real* heightData)
{
   TerrainVectorCalculator terrainCalc;
   terrainCalc.pagex_ = pagex;
   terrainCalc.pagez_ = pagez;
   terrainCalc.pageSize_ = manager->getPageSize();
   terrainCalc.scale_ = manager->getScale();
   terrainCalc.heightData_ = heightData;

   int polyId = 0;
   for (int z = 0; z < manager->getPageSize()-1; z++)
   {
      for (int x = 0; x < manager->getPageSize()-1; x++)
      {
         Ogre::Vector3 va[3];

         va[0] = terrainCalc.v(x, z);
         va[1] = terrainCalc.v(x, z+1);
         va[2] = terrainCalc.v(x+1, z);
         m_polys.push_back(va[0]);
         m_polys.push_back(va[1]);
         m_polys.push_back(va[2]);

         va[0] = terrainCalc.v(x+1, z);
         va[1] = terrainCalc.v(x, z+1);
         va[2] = terrainCalc.v(x+1, z+1);
         m_polys.push_back(va[0]);
         m_polys.push_back(va[1]);
         m_polys.push_back(va[2]);
      }
   }
}


std::vector<Ogre::Vector3> &GMTerrainPageSourceListener::GetPolys()
{
   return m_polys;
}
