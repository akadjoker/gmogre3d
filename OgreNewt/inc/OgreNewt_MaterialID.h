/* 
    OgreNewt Library

    Ogre implementation of Newton Game Dynamics SDK

    OgreNewt basically has no license, you may use any or all of the library however you desire... I hope it can help you in any way.

        by Walaber
        some changes by melven

*/
#ifndef _INCLUDE_OGRENEWT_MATERIALID
#define _INCLUDE_OGRENEWT_MATERIALID


#include "OgreNewt_Prerequisites.h"

// OgreNewt namespace.  all functions and classes use this namespace.
namespace OgreNewt
{


//! represents a material
class _OgreNewtExport MaterialID
{
public:

    //! constructor
    /*!
        \param world pointer to the OgreNewt;;World
    */
    MaterialID( const World* world );

    //! destructor
    ~MaterialID();

    //! get Newton-assigned material ID.
    int getID() const { return id; }

protected:

    friend class OgreNewt::World;

    /*!
        Overloaded constructor, sets the internal ID manually.  should not be used by the end-user.
    */
    MaterialID( const World* world, int ID );

private:
    int id;
    const OgreNewt::World* m_world;

};



}   // end NAMESPACE OgreNewt

#endif
// _INCLUDE_OGRENEWT_MATERIALID

