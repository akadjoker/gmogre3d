// Ogre 2d: a small wrapper for 2d Graphics Programming in Ogre.
/*
   Wrapper for 2d Graphics in the Ogre 3d engine.

   Coded by H. Hernán Moraldo from Moraldo Games
   www.hernan.moraldo.com.ar/pmenglish/field.php

   Thanks for the Cegui team as their rendering code in Ogre gave me
   fundamental insight on the management of hardware buffers in Ogre.

   --------------------

   Copyright (c) 2006 Horacio Hernan Moraldo

   This software is provided 'as-is', without any express or
   implied warranty. In no event will the authors be held liable
   for any damages arising from the use of this software.

   Permission is granted to anyone to use this software for any
   purpose, including commercial applications, and to alter it and
   redistribute it freely, subject to the following restrictions:

   1. The origin of this software must not be misrepresented; you
   must not claim that you wrote the original software. If you use
   this software in a product, an acknowledgment in the product
   documentation would be appreciated but is not required.

   2. Altered source versions must be plainly marked as such, and
   must not be misrepresented as being the original software.

   3. This notice may not be removed or altered from any source
   distribution.

*/
#ifndef __OGRE2D_MAIN_FILE
#define __OGRE2D_MAIN_FILE

#include <Ogre.h>
#include <OgreRenderQueueListener.h>

#include <string>
#include <list>
#include <vector>


struct Ogre2dSprite
{
   double x1, y1, x2, y2;// sprite coordinates
   double tx1, ty1, tx2, ty2;// texture coordinates
   Ogre::ResourceHandle texHandle;// texture handle
};

struct VertexChunk {
   Ogre::ResourceHandle texHandle;
   unsigned int vertexCount;
};

class Ogre2dManager:public Ogre::RenderQueueListener
{
private:
   Ogre::SceneManager* sceneMan;

   Ogre::uint8 targetQueue;
   bool afterQueue;
public:
   Ogre2dManager();
   virtual ~Ogre2dManager();

   /// Initializes this 2d Manager
   /** and registers it as the render queue listener.*/
   void init(Ogre::SceneManager* sceneMan, Ogre::uint8 targetQueue, bool afterQueue);
   /// Finishes Ogre 2d Manager
   void end();

   /// Called by Ogre, for being a render queue listener
   virtual void renderQueueStarted(
      Ogre::uint8 queueGroupId, const Ogre::String &invocation, bool &skipThisInvocation);
   /// Called by Ogre, for being a render queue listener
   virtual void renderQueueEnded(
      Ogre::uint8 queueGroupId, const Ogre::String &invocation, bool &repeatThisInvocation);


   /// Buffers a sprite to be sent to the screen at render time.
   /**
      Sprite coordinates are in screen space: top left pixel is (-1, 1), and bottom right
      is (1, -1). The texture space, instead, ranges from (0, 0) to (1, 1).

      /param textureName Name of the texture to use in this sprite (remember: texture
      name, not material name!). The texture has to be already loaded by Ogre for this
      to work.
      /param x1 x coordinate for the top left point in the sprite.
      /param y1 y coordinate for the top left point in the sprite.
      /param x2 x coordinate for the bottom right point in the sprite.
      /param y2 y coordinate for the bottom right point in the sprite.
      /param tx1 u coordinate for the texture, in the top left point of the sprite.
      /param ty1 v coordinate for the texture, in the top left point of the sprite.
      /param tx2 u coordinate for the texture, in the bottom right point of the sprite.
      /param ty2 u coordinate for the texture, in the bottom right point of the sprite.
   */
   void spriteBltFull(std::string textureName, double x1, double y1, double x2, double y2, double tx1=0, double ty1=0, double tx2=1, double ty2=1);

private:
   /// Render all the 2d data stored in the hardware buffers.
   void renderBuffer();
   /// Create a new hardware buffer
   /**
   /param size Vertex count for the new hardware buffer.
   */
   void createHardwareBuffer(unsigned int size);
   /// Destroy the hardware buffer
   void destroyHardwareBuffer();
   /// Set Ogre for rendering
   void prepareForRender();

   // ogre specifics
   Ogre::RenderOperation renderOp;
   Ogre::HardwareVertexBufferSharedPtr hardwareBuffer;

   // sprite buffer
   //std::vector<Ogre2dSprite> sprites;
};


#endif // __OGRE2D_MAIN_FILE 
