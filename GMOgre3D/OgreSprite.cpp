#include "stdafx.h"
#include "OgreSprite.h"


Ogre::String GenerateUniqueSpriteName()
{
   static unsigned int index = 0;
   static Ogre::String base_name = "GMSprite";

   // If for some unholy reason we've created over 4,294,967,295 instances
   // we ensure that we don't reuse an existing instance name
   if (index == 0)
      base_name += "_";

   return base_name + Ogre::StringConverter::toString(index++);
}


OgreSprite::OgreSprite()
{
   m_overlay_mgr = Ogre::OverlayManager::getSingletonPtr();

   m_panel = static_cast<Ogre::OverlayContainer*>(m_overlay_mgr->createOverlayElement("Panel", GenerateUniqueSpriteName()));

   // Users can change metrics, but we default to pixels
   m_panel->setMetricsMode(Ogre::GMM_PIXELS);

   m_panel->setPosition(0, 0);
   m_panel->setDimensions(1.0f, 1.0f);

   m_overlay = m_overlay_mgr->create(GenerateUniqueSpriteName());
   m_overlay->add2D(m_panel);
   m_overlay->show();
}


OgreSprite::~OgreSprite()
{
   m_overlay_mgr->destroyOverlayElement(m_panel);
   m_overlay_mgr->destroy(m_overlay);
}


void OgreSprite::SetMaterial(Ogre::String mat_name)
{
   m_panel->setMaterialName(mat_name);
}


void OgreSprite::SetMetrics(double type)
{
   m_panel->setMetricsMode(static_cast<Ogre::GuiMetricsMode>((int)type));
}


void OgreSprite::SetDimensions(double width, double height)
{
   m_panel->setDimensions(width, height);
}


void OgreSprite::SetPosition(double x, double y)
{
   m_panel->setPosition(x, y);
}


void OgreSprite::Rotate(double degrees)
{
   m_overlay->rotate(Ogre::Degree(degrees));
}


void OgreSprite::SetScale(double x, double y)
{
   m_overlay->setScale(x, y);
}


void OgreSprite::Show()
{
   m_overlay->show();
}


void OgreSprite::Hide()
{
   m_overlay->hide();
}
