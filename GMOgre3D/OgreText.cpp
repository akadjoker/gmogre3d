#include "stdafx.h"
#include "OgreText.h"
#include <OgreFontManager.h>


unsigned int OgreText::m_initialized = 0;

OgreText::OgreText()
{
   m_overlay_mgr = Ogre::OverlayManager::getSingletonPtr();

   if (m_initialized == 0)
   {
      m_panel = static_cast<Ogre::OverlayContainer*>(m_overlay_mgr->createOverlayElement("Panel", "OgreTextGUI"));

      // Users can change metrics, but we default to pixels
      m_panel->setMetricsMode(Ogre::GMM_PIXELS);

      m_panel->setPosition(0, 0);
      m_panel->setDimensions(1.0f, 1.0f);

      overlay = m_overlay_mgr->create("OgreTextOverlay");
      overlay->add2D(m_panel);
   }

   m_initialized++;

   Ogre::String element_name = "OgreTextElement" + Ogre::StringConverter::toString(m_initialized);

   m_text_area = static_cast<Ogre::TextAreaOverlayElement*>(m_overlay_mgr->createOverlayElement("TextArea", element_name));

   m_text_area->setDimensions(1.0f, 1.0f);

   // Users can change metrics, but we default to pixels.  Note this comes AFTER
   // the setDimensions because want the text area to fill the screen, then user
   // can just specify placement of text on the screen.
   m_text_area->setMetricsMode(Ogre::GMM_PIXELS);

   m_panel = static_cast<Ogre::OverlayContainer*>(m_overlay_mgr->getOverlayElement("OgreTextGUI"));
   m_panel->addChild(m_text_area);

   overlay = m_overlay_mgr->getByName("OgreTextOverlay");
   overlay->show();
}


OgreText::~OgreText()
{
   Ogre::String element_name = "OgreTextElement" + Ogre::StringConverter::toString(m_initialized);
   m_overlay_mgr->destroyOverlayElement(element_name);
   
   m_initialized--;
   
   if (m_initialized == 0)
   {
      m_overlay_mgr->destroyOverlayElement("OgreTextGUI");
      m_overlay_mgr->destroy("OgreTextOverlay");
   }
}


void OgreText::SetFont(Ogre::String font_name, Ogre::Real height)
{
   m_text_area->setFontName(font_name);
   m_text_area->setCharHeight(height);
}


void OgreText::SetCaption(char *txt)
{
   m_text_area->setCaption(txt);
}
	
	
void OgreText::SetCaption(Ogre::String txt)
{
   m_text_area->setCaption(txt);
}


void OgreText::SetMetrics(double type)
{
   m_text_area->setMetricsMode(static_cast<Ogre::GuiMetricsMode>((int)type));
}


void OgreText::SetPosition(double x, double y)
{
   m_text_area->setPosition(x, y);
}


void OgreText::SetColor(Ogre::ColourValue color)
{
   m_text_area->setColour(color);
}


void OgreText::SetAlignment(Ogre::TextAreaOverlayElement::Alignment align)
{
   m_text_area->setAlignment(align);
}


double OgreText::GetWidth()
{
   Ogre::FontPtr font = Ogre::FontManager::getSingleton().getByName(m_text_area->getFontName());

   // Font needs to be loaded in order to calculate string width!
   if (!font->isLoaded())
      font->load();

   std::string text = m_text_area->getCaption();
   int fontSize = Ogre::StringConverter::parseUnsignedInt(font->getParameter("size"));
   double textWidth = 0.0;

   for (Ogre::String::iterator i = text.begin(); i < text.end(); i++)
   {   
      if (*i == 0x0020)
         textWidth += font->getGlyphAspectRatio(0x0030);
      else
         textWidth += font->getGlyphAspectRatio(*i);
   }
   textWidth *= fontSize;

   return textWidth;
}


double OgreText::GetHeight()
{
   Ogre::FontPtr font = Ogre::FontManager::getSingleton().getByName(m_text_area->getFontName());

   return Ogre::StringConverter::parseUnsignedInt(font->getParameter("size"));
}
