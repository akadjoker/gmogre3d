/*
--------------------------------------------------------------------------------
GMOgre3D - Wrapper of the OGRE 3D library for Game Maker

Copyright (C) 2009 Robert Geiman
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

#ifndef GMOGRE_MOVEABLE_TEXT_H
#define GMOGRE_MOVEABLE_TEXT_H


class MovableText : public Ogre::MovableObject, public Ogre::Renderable
{
   /******************************** MovableText data ****************************/
public:
   enum HorizontalAlignment    {H_LEFT, H_CENTER};
   enum VerticalAlignment      {V_BELOW, V_ABOVE, V_CENTER};

protected:
   Ogre::String          mFontName;
   Ogre::String          mType;
   Ogre::String          mName;
   Ogre::String          mCaption;
   HorizontalAlignment mHorizontalAlignment;
   VerticalAlignment   mVerticalAlignment;

   Ogre::ColourValue     mColor;
   Ogre::RenderOperation mRenderOp;
   Ogre::AxisAlignedBox  mAABB;
   Ogre::LightList       mLList;

   Ogre::Real            mCharHeight;
   Ogre::Real            mSpaceWidth;

   bool            mNeedUpdate;
   bool            mUpdateColors;
   bool            mOnTop;

   Ogre::Real            mTimeUntilNextToggle;
   Ogre::Real            mRadius;

   Ogre::Vector3            mGlobalTranslation;
   Ogre::Vector3            mLocalTranslation;

   Ogre::Camera          *mpCam;
   Ogre::RenderWindow    *mpWin;
   Ogre::Font            *mpFont;
   Ogre::MaterialPtr     mpMaterial;
   Ogre::MaterialPtr     mpBackgroundMaterial;

   /******************************** public methods ******************************/
public:
   MovableText(const Ogre::String &name, const Ogre::String &caption, const Ogre::String &fontName, Ogre::Real charHeight, const Ogre::ColourValue &color = Ogre::ColourValue::White);
   virtual ~MovableText();

   // Set settings
   void    setFontName(const Ogre::String &fontName);
   void    setCaption(const Ogre::String &caption);
   void    setColor(const Ogre::ColourValue &color);
   void    setCharacterHeight(Ogre::Real height);
   void    setSpaceWidth(Ogre::Real width);
   void    setTextAlignment(const HorizontalAlignment& horizontalAlignment, const VerticalAlignment& verticalAlignment);
   void    setGlobalTranslation( Ogre::Vector3 trans );
   void    setLocalTranslation( Ogre::Vector3 trans );
   void    showOnTop(bool show=true);

   // Get settings
   const   Ogre::String          &getFontName() const {return mFontName;}
   const   Ogre::String          &getCaption() const {return mCaption;}
   const   Ogre::ColourValue     &getColor() const {return mColor;}

   Ogre::Real    getCharacterHeight() const {return mCharHeight;}
   Ogre::Real    getSpaceWidth() const {return mSpaceWidth;}
   Ogre::Vector3    getGlobalTranslation() const {return mGlobalTranslation;}
   Ogre::Vector3    getLocalTranslation() const {return mLocalTranslation;}
   bool    getShowOnTop() const {return mOnTop;}
   Ogre::AxisAlignedBox          GetAABB(void) { return mAABB; }

   /******************************** protected methods and overload **************/
protected:

   // from MovableText, create the object
   void    _setupGeometry();
   void    _updateColors();

   // from MovableObject
   void    getWorldTransforms(Ogre::Matrix4 *xform) const;
   Ogre::Real    getBoundingRadius(void) const {return mRadius;};
   Ogre::Real    getSquaredViewDepth(const Ogre::Camera *cam) const {return 0;};
   void visitRenderables(Ogre::Renderable::Visitor* visitor,  bool debugRenderables = false);
   const   Ogre::Quaternion        &getWorldOrientation(void) const;
   const   Ogre::Vector3           &getWorldPosition(void) const;
   const   Ogre::AxisAlignedBox    &getBoundingBox(void) const {return mAABB;};
   const   Ogre::String            &getName(void) const {return mName;};
   const   Ogre::String            &getMovableType(void) const {static Ogre::String movType = "MovableText"; return movType;};

   void    _notifyCurrentCamera(Ogre::Camera *cam);
   void    _updateRenderQueue(Ogre::RenderQueue* queue);

   // from renderable
   void    getRenderOperation(Ogre::RenderOperation &op);
   const   Ogre::MaterialPtr       &getMaterial(void) const {assert(!mpMaterial.isNull());return mpMaterial;};
   const   Ogre::LightList         &getLights(void) const {return mLList;};
};

#endif
