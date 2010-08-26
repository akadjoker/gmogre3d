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

#ifndef GMOGRE_TEXTURE_H
#define GMOGRE_TEXTURE_H

#include "GMOgre3D.h"


static Ogre::String tex_name;
static Ogre::String tex_group;
static Ogre::String tex_text;
static Ogre::String tex_font_name;
static double tex_type;


GMFN char *GetTextureByName(char *name)
{
   // This is just a convienence function to allow users to use the same
   // standard for retrieving script objects (fonts, materials, overlay, etc)
   // the same way.  In this case the ID really IS the name, but for other
   // script types it may be an actual object pointer.

   return name;
}


GMFN double CreateTexture1(char *name, char *group, double type)
{
   tex_name = name;
   tex_group = group;
   tex_type = type;

   return TRUE;
}


GMFN char *CreateTexture2(double width, double height, double depth, double num_mips, double pixel_format, double usage = Ogre::TU_DEFAULT)
{
   TRY
      Ogre::TextureManager::getSingleton().createManual(tex_name, tex_group, static_cast<Ogre::TextureType>((int)tex_type), (Ogre::uint)width, (Ogre::uint)height, (Ogre::uint)num_mips, static_cast<Ogre::PixelFormat>((int)pixel_format), static_cast<Ogre::TextureUsage>((int)usage));
   CATCH("CreateTexture")

   return const_cast<char*>(tex_name.c_str());
}


GMFN double DestroyTexture(char *name)
{
   Ogre::TextureManager::getSingleton().remove(name);

   return TRUE;
}


GMFN double LoadTexture(char *name)
{
   Ogre::TexturePtr tex = Ogre::TextureManager::getSingleton().getByName(name);
   
   if (tex.isNull())
      return FALSE;
   
   tex->load();

   return TRUE;
}


GMFN double UnloadTexture(char *name)
{
   Ogre::TexturePtr tex = Ogre::TextureManager::getSingleton().getByName(name);
   
   if (tex.isNull())
      return FALSE;
   
   tex->unload();

   return TRUE;
}


GMFN double CopyTexture(char *source_name, char *dest_name)
{
   Ogre::TexturePtr src_tex = Ogre::TextureManager::getSingleton().getByName(source_name);
   
   if (src_tex.isNull())
      return FALSE;

   Ogre::TexturePtr dest_tex = Ogre::TextureManager::getSingleton().getByName(dest_name);
   
   if (dest_tex.isNull())
      return FALSE;

   TRY
      Ogre::Texture *src = src_tex.getPointer();
      Ogre::Texture *dst = dest_tex.getPointer();

      dst->getBuffer()->blit(src->getBuffer());
   CATCH("CopyTexture")

   return TRUE;
}


GMFN double SaveTextureToFile(char *name, char *filename)
{
   Ogre::TexturePtr tex = Ogre::TextureManager::getSingleton().getByName(name);

   if (tex.isNull())
      return FALSE;

   Ogre::HardwarePixelBufferSharedPtr readbuffer;
   readbuffer = tex->getBuffer(0, 0);
   readbuffer->lock(Ogre::HardwareBuffer::HBL_NORMAL );
   const Ogre::PixelBox &readrefpb = readbuffer->getCurrentLock();	
   Ogre::uchar *readrefdata = static_cast<Ogre::uchar*>(readrefpb.data);		

   Ogre::Image img;
   img = img.loadDynamicImage(readrefdata, tex->getWidth(), tex->getHeight(), tex->getFormat());	
   img.save(filename);

   readbuffer->unlock();

   return TRUE;
}


GMFN double CreateTextureViewport(char *name)
{
   Ogre::TexturePtr tex = Ogre::TextureManager::getSingleton().getByName(name);

   if (tex.isNull())
      return NULL;

   Ogre::RenderTexture *render_tex = NULL;
   Ogre::Viewport *view = NULL;

   TRY
      render_tex = tex->getBuffer()->getRenderTarget();

      if (render_tex == NULL)
         return NULL;

      view = render_tex->addViewport(NULL);

      if (view == NULL)
         return NULL;

      view->setBackgroundColour(Ogre::ColourValue(0.0f, 0.0f, 0.0f));
   CATCH("CreateTextureViewport")

   return ConvertToGMPointer(view);
}


GMFN double GetTextureViewport(char *name, double index)
{
   Ogre::TexturePtr tex = Ogre::TextureManager::getSingleton().getByName(name);

   if (tex.isNull())
      return NULL;

   Ogre::RenderTexture *render_tex = tex->getBuffer()->getRenderTarget();

   if (render_tex == NULL)
      return NULL;

   Ogre::Viewport *view = render_tex->getViewport((unsigned short)index);

   if (view == NULL)
      return NULL;

   return ConvertToGMPointer(view);
}


GMFN double SaveTextureRendererContentsToFile(char *name, char *filename)
{
   Ogre::TexturePtr tex = Ogre::TextureManager::getSingleton().getByName(name);

   if (tex.isNull())
      return NULL;

   Ogre::RenderTexture *render_tex = tex->getBuffer()->getRenderTarget();

   if (render_tex == NULL)
      return NULL;

   render_tex->update();
   render_tex->writeContentsToFile(filename);

   return TRUE;
}


GMFN double GetTextureWidth(char *name)
{
   Ogre::TexturePtr tex = Ogre::TextureManager::getSingleton().getByName(name);
   
   if (tex.isNull())
      return 0;

   return tex->getWidth();
}


GMFN double GetTextureHeight(char *name)
{
   Ogre::TexturePtr tex = Ogre::TextureManager::getSingleton().getByName(name);
   
   if (tex.isNull())
      return 0;

   return tex->getHeight();
}


GMFN double SetTextureFSAA(char *name, double fsaa, double fsaa_hint)
{
   Ogre::TexturePtr tex = Ogre::TextureManager::getSingleton().getByName(name);
   
   if (tex.isNull())
      return NULL;

   Ogre::String fsaa_hint_value;

   if (fsaa_hint == 1)
      fsaa_hint_value = "Quality";

   tex->setFSAA((Ogre::uint)fsaa, fsaa_hint_value);

   return TRUE;
}


GMFN double WriteTextToTexture1(char *name, char *text, char *font_name)
{
   tex_name = name;
   tex_text = text;
   tex_font_name = font_name;

   return TRUE;
}


GMFN double WriteTextToTexture2(double left, double top, double right, double bottom, double clr, double alpha, double justify, double wordwrap)
{
	using namespace Ogre;

   Ogre::TexturePtr destTexture = Ogre::TextureManager::getSingleton().getByName(tex_name);
   
   if (destTexture.isNull())
      return FALSE;

   Ogre::ResourcePtr font_ptr = Ogre::FontManager::getSingleton().getByName(tex_font_name);
   
   if (font_ptr.isNull())
      return FALSE;

   Ogre::Font *font = (Ogre::Font *)font_ptr.getPointer();

   String str = tex_text;

   Image::Box destRectangle((size_t)left, (size_t)top, (size_t)right, (size_t)bottom);

   Ogre::ColourValue color = Ogre::ColourValue(GetRedFromGMColor(clr), GetGreenFromGMColor(clr), GetBlueFromGMColor(clr), (float)alpha);

	if (destTexture->getHeight() < destRectangle.bottom)
		destRectangle.bottom = destTexture->getHeight();
	if (destTexture->getWidth() < destRectangle.right)
		destRectangle.right = destTexture->getWidth();

	if (!font->isLoaded())
		font->load();

	TexturePtr fontTexture = (TexturePtr) TextureManager::getSingleton().getByName(font->getMaterial()->getTechnique(0)->getPass(0)->getTextureUnitState(0)->getTextureName());
	
	HardwarePixelBufferSharedPtr fontBuffer = fontTexture->getBuffer();
	HardwarePixelBufferSharedPtr destBuffer = destTexture->getBuffer();

	PixelBox destPb = destBuffer->lock(destRectangle,HardwareBuffer::HBL_NORMAL);
	
        // The font texture buffer was created write only...so we cannot read it back :o). One solution is to copy the buffer  instead of locking it. (Maybe there is a way to create a font texture which is not write_only ?)
        
        // create a buffer
        size_t nBuffSize = fontBuffer->getSizeInBytes();
        uint8* buffer = (uint8*)calloc(nBuffSize, sizeof(uint8)); 
        
        // create pixel box using the copy of the buffer
        PixelBox fontPb(fontBuffer->getWidth(), fontBuffer->getHeight(),fontBuffer->getDepth(), fontBuffer->getFormat(), buffer);          
        fontBuffer->blitToMemory(fontPb);

	uint8* fontData = static_cast<uint8*>( fontPb.data );
	uint8* destData = static_cast<uint8*>( destPb.data );

	const size_t fontPixelSize = PixelUtil::getNumElemBytes(fontPb.format);
	const size_t destPixelSize = PixelUtil::getNumElemBytes(destPb.format);

	const size_t fontRowPitchBytes = fontPb.rowPitch * fontPixelSize;
	const size_t destRowPitchBytes = destPb.rowPitch * destPixelSize;

	Box *GlyphTexCoords;
	GlyphTexCoords = OGRE_NEW Box[str.size()];

	Font::UVRect glypheTexRect;
	size_t charheight = 0;
	size_t charwidth = 0;

	for(unsigned int i = 0; i < str.size(); i++)
	{
		if ((str[i] != '\t') && (str[i] != '\n') && (str[i] != ' '))
		{
			glypheTexRect = font->getGlyphTexCoords(str[i]);
			GlyphTexCoords[i].left = (size_t)(glypheTexRect.left * fontTexture->getSrcWidth());
			GlyphTexCoords[i].top = (size_t)(glypheTexRect.top * fontTexture->getSrcHeight());
			GlyphTexCoords[i].right = (size_t)(glypheTexRect.right * fontTexture->getSrcWidth());
			GlyphTexCoords[i].bottom = (size_t)(glypheTexRect.bottom * fontTexture->getSrcHeight());

			if (GlyphTexCoords[i].getHeight() > charheight)
				charheight = GlyphTexCoords[i].getHeight();
			if (GlyphTexCoords[i].getWidth() > charwidth)
				charwidth = GlyphTexCoords[i].getWidth();
		}

	}	

	size_t cursorX = 0;
	size_t cursorY = 0;
	size_t lineend = destRectangle.getWidth();
	bool carriagreturn = true;
	for (unsigned int strindex = 0; strindex < str.size(); strindex++)
	{
		switch(str[strindex])
		{
		case ' ': cursorX += charwidth;  break;
		case '\t':cursorX += charwidth * 3; break;
		case '\n':cursorY += charheight; carriagreturn = true; break;
		default:
			{
				//wrapping
				if ((cursorX + GlyphTexCoords[strindex].getWidth()> lineend) && !carriagreturn )
				{
					cursorY += charheight;
					carriagreturn = true;
				}
				
				//justify
				if (carriagreturn)
				{
					size_t l = strindex;
					size_t textwidth = 0;	
					size_t wordwidth = 0;

					while( (l < str.size() ) && (str[l] != '\n)'))
					{		
						wordwidth = 0;

						switch (str[l])
						{
						case ' ': wordwidth = charwidth; ++l; break;
						case '\t': wordwidth = charwidth *3; ++l; break;
						case '\n': l = str.size();
						}
						
						if ((wordwrap > 0.001))
                  {
							while((l < str.size()) && (str[l] != ' ') && (str[l] != '\t') && (str[l] != '\n'))
							{
								wordwidth += GlyphTexCoords[l].getWidth();
								++l;
							}
                  }
						else
							{
								wordwidth += GlyphTexCoords[l].getWidth();
								l++;
							}
	
						if ((textwidth + wordwidth) <= destRectangle.getWidth())
							textwidth += (wordwidth);
						else
							break;
					}

					if ((textwidth == 0) && (wordwidth > destRectangle.getWidth()))
						textwidth = destRectangle.getWidth();

					switch ((int)justify)
					{
					case 2:	cursorX = (destRectangle.getWidth() - textwidth)/2;
							lineend = destRectangle.getWidth() - cursorX;
							break;

					case 1:	cursorX = (destRectangle.getWidth() - textwidth);
							lineend = destRectangle.getWidth();
							break;

					default:	cursorX = 0;
							lineend = textwidth;
							break;
					}

					carriagreturn = false;
				}

				//abort - net enough space to draw
				if ((cursorY + charheight) > destRectangle.getHeight())
					goto stop;

				//draw pixel by pixel
				for (size_t i = 0; i < GlyphTexCoords[strindex].getHeight(); i++ )
					for (size_t j = 0; j < GlyphTexCoords[strindex].getWidth(); j++)
					{
 						float alpha = color.a * (fontData[(i + GlyphTexCoords[strindex].top) * fontRowPitchBytes + (j + GlyphTexCoords[strindex].left) * fontPixelSize + 1 ] / 255.0f);
 						float invalpha = 1.0f - (float)alpha;
 						size_t offset = (i + cursorY) * destRowPitchBytes + (j + cursorX) * destPixelSize;
  						ColourValue pix;
 						PixelUtil::unpackColour(&pix,destPb.format,&destData[offset]);
 						pix = (pix * invalpha) + (color * alpha);
 						PixelUtil::packColour(pix,destPb.format,&destData[offset]);
  					}
 
				cursorX += GlyphTexCoords[strindex].getWidth();
			}//default
		}//switch
	}//for

stop:
	delete[] GlyphTexCoords;

	destBuffer->unlock();
	
        // Free the memory allocated for the buffer
        free(buffer); buffer = 0;

   return TRUE;
}

#endif
