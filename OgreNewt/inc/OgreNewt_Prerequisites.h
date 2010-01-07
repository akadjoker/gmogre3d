/* 
    OgreNewt Library

    Ogre implementation of Newton Game Dynamics SDK

    OgreNewt basically has no license, you may use any or all of the library however you desire... I hope it can help you in any way.

        by Walaber
        some changes by melven

*/


#ifndef __INCLUDE_OGRENEWT_PREREQ__
#define __INCLUDE_OGRENEWT_PREREQ__

#ifdef __APPLE__
#    include <Carbon/Carbon.h>
#   include <Ogre/OgreVector3.h>
#   include <Ogre/OgreQuaternion.h>
#   include <Ogre/OgreMovableObject.h>
#   include <Ogre/OgreRenderable.h>
#   include <Ogre/OgreNode.h>
#   include <Ogre/OgreFrameListener.h>
#   ifndef OGRENEWT_NO_OGRE_ANY
#       include <Ogre/OgreAny.h>
#   endif
#else
#include <OgreVector3.h>
#include <OgreQuaternion.h>
#include <OgreMovableObject.h>
#include <OgreRenderable.h>
#include <OgreNode.h>
#include <OgreFrameListener.h>
#   ifndef OGRENEWT_NO_OGRE_ANY
#       include <OgreAny.h>
#   endif
#endif

#include <Newton.h>
#include <boost/function.hpp>
#include <boost/bind.hpp>
#ifndef OGRENEWT_NO_COLLISION_SHAREDPTR
#   include <boost/shared_ptr.hpp>
#endif

#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
#   define _CDECL _cdecl
#   if defined( _OGRENEWT_EXPORTS ) && defined( _OGRENEWT_DYNAMIC )
#       define _OgreNewtExport __declspec( dllexport )
#   elif defined( _OGRENEWT_DYNAMIC )
#       define _OgreNewtExport __declspec( dllimport )
#   else
#       define _OgreNewtExport
#   endif
#else // Linux / Mac OSX etc
#   define _OgreNewtExport
#   define _CDECL
#endif





#ifdef OGRENEWT_NO_COLLISION_SHAREDPTR
#warning "the option OGRENEWT_NO_COLLISION_SHAREDPTR is set"
#endif

#ifdef OGRENEWT_NO_OGRE_ANY
//#warning "the option OGRENEWT_NO_OGRE_ANY is set"
#endif

namespace OgreNewt
{
    class World;
    class MaterialID;
    class Joint;
    class Contact;
    class MaterialPair;
    class Body;
    class Collision;
    class CollisionSerializer;
    class ConvexCollision;
    class Debugger;


    //! helper class: OgreNewt-classes can derive from this class to implement a destructor-callback
    /*!
     * Consider the following example:
     * You delete a body thats part of joint, so newton deletes the joint, then you could still have a pointer to that joint. Using this pointer will fail,
     * thats why you need a way to get to know, when an object gets deleted...
     */
    template<class DerivedClass>
    class _DestructorCallback
    {
        public:
            //! destructor callback
            /*!
             * This function is called, when the object is destroyed. It's only argument is a pointer to the instance currently destroyed
             * @warning the pointer to the destroyed class instance is already invalid (the class is already destroyed!)
             */
            typedef boost::function<void(DerivedClass*)> DestructorCallbackFunction;

            //! constructor
            _DestructorCallback() : m_callback(NULL) {}

            //! destructor
            virtual ~_DestructorCallback()
            {
                if( m_callback )
                    m_callback((DerivedClass*)(this));
            }

            //! remove any destructor callback
            void removeDestructorCallback() {m_callback = NULL;}

            //! set the destructor callback
            /*!
             *
             * This specifies a custom callback that's called when this class is destroyed. If you are using a standard non-member function,
             * or a static member function, you can simply pass a pointer to the function here.. like this:
             *      setDestructorCallback( &myCallbackFunction );
             *
             * If you want to bind to a class member, you also need to pass a pointer to the class itself, using the boost::bind system, like so:
             *      setDestructorCallback( boost::bind( &MyClass::myCallback, (MyClass*)classInstance, _1 ) );  (from outside the class) or:
             *      setDestructorCallback( boost::bind( &MyClass::myCallback, this, _1 ) );  (from inside the class).
             *
             * You can also use:
             *      setDestructorCallback<>( &MyClass::myCallback, (MyClass*)classInstance );  (from outside the class) or:
             *      setDestructorCallback<>( &MyClass::myCallback, this );  (from inside the class).
             * Note: Notice the "<>" after the function name.
             *
             */
            void setDestructorCallback( DestructorCallbackFunction fun ) { m_callback = fun; }
            template<class c> void setDestructorCallback( boost::function<void(c*, DerivedClass*)> callback, c *instancedClassPointer )
            {
                setDestructorCallback( boost::bind(callback, instancedClassPointer, _1) );
            }
        private:
            DestructorCallbackFunction m_callback;

    };
}

#endif 

