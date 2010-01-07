#ifndef _INCLUDE_OGRE_STDAFX_
#define _INCLUDE_OGRE_STDAFX_


#ifdef _MSC_VER
	#include <Ogre.h>
	#include <OgreRoot.h>
	#include <OgreVector3.h>
	#include <OgreQuaternion.h>
	#include <OgreMovableObject.h>
	#include <OgreRenderable.h>
	#include <OgreNode.h>
	#include <OgreFrameListener.h>
	#include <OgreEntity.h>
	#include <OgreSubMesh.h>
	#include <OgreSceneNode.h>
	#include <OgreLogManager.h>
	#include <OgreStringConverter.h>
	#include <OgreRenderWindow.h>
	#include <OgreSceneNode.h>
	#include <OgreSceneManager.h>
	#include <OgreManualObject.h>
	#include <OgreFontManager.h>
	#include <OgreMaterialManager.h>
	#include <OgreCamera.h>
	#include <OgreHardwareBufferManager.h>

	#ifndef OGRENEWT_NO_OGRE_ANY
		#include <OgreAny.h>
	#endif

	#ifdef _DEBUG
		#include <OgreLogManager.h>
		#include <OgreStringConverter.h>
	#endif

	#include <Newton.h>
	#include <dVector.h>
	#include <dMatrix.h>
	#include <dQuaternion.h>
	#include <NewtonCustomJoint.h>

	#include <boost/function.hpp>
	#include <boost/bind.hpp>

	#ifndef OGRENEWT_NO_COLLISION_SHAREDPTR
	#   include <boost/shared_ptr.hpp>
	#endif

#endif

#endif
