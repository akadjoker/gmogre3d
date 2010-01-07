/* 
    OgreNewt Library

    Ogre implementation of Newton Game Dynamics SDK

    OgreNewt basically has no license, you may use any or all of the library however you desire... I hope it can help you in any way.

        by Walaber
        some changes by melven

*/

#ifndef _INCLUDE_OGRENEWT_BODYINAABBITERATOR
#define _INCLUDE_OGRENEWT_BODYINAABBITERATOR


#include "OgreNewt_Prerequisites.h"

// OgreNewt namespace.  all functions and classes use this namespace.
namespace OgreNewt
{


//! Iterate through all bodies in a specific AABB in the world.
/*!
    this class is an easy way to loop through all bodies in an AABB in the world, performing some kind of action.
    if you want to iterate through all bodies, use the world->getFirstBody and body->getNext functions.
    You can access this class via World::getBodyInAABBIterator()
*/
class _OgreNewtExport BodyInAABBIterator
{
public:
    //! function to be called for all bodies
    /*!
        This function will be called for every body iterated.  you can put any functionality you might want inside this function.
    */
    typedef boost::function<void(const Body*, void* userdata)> IteratorCallback;

    //! perform an iteration
    /*!
        will call the provided function for all bodies in the world.
        \param callback pointer to a function to be used
        \warning you cannot call this functions from different threads at the same time
    */
    void go( const Ogre::AxisAlignedBox &aabb, IteratorCallback callback, void* userdata) const;
    template <class c> void go( const Ogre::AxisAlignedBox &aabb, boost::function<void(c*, Body*)> callback, c* instancedClassPointer ) const
    {
        go ( aabb, boost::bind(callback, instancedClassPointer, _1) );
    }

protected:
    friend class OgreNewt::World;
    //! this function must only be used by an instance of the OgreNewt::World class
    BodyInAABBIterator(const OgreNewt::World* world);

    const OgreNewt::World*          m_world;
    mutable IteratorCallback        m_callback;

private:
    //! this function is declared private, so nobody can use it!
    BodyInAABBIterator() {}

    //! this function is declared private, so nobody can use it!
    BodyInAABBIterator(const BodyInAABBIterator&) {}

    //! this function is declared private, so nobody can use it!
    const BodyInAABBIterator& operator=(const BodyInAABBIterator& a) { return a; } // actually this function must *not* be called...

    static void _CDECL newtonIterator( const NewtonBody* body, void* userdata);
};


}   // end NAMESPACE OgreNewt

#endif  // _INCLUDE_OGRENEWT_BODYINAABBITERATOR

