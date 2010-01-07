/* 
    OgreNewt Library

    Ogre implementation of Newton Game Dynamics SDK

    OgreNewt basically has no license, you may use any or all of the library however you desire... I hope it can help you in any way.

        by Walaber
        some changes by melven

*/
#ifndef _INCLUDE_OGRENEWT_COLLISIONPRIMITIVES
#define _INCLUDE_OGRENEWT_COLLISIONPRIMITIVES


#include "OgreNewt_Prerequisites.h"
#include "OgreNewt_Collision.h"
#include "OgreNewt_MaterialID.h"


// OgreNewt namespace.  all functions and classes use this namespace.
namespace OgreNewt
{

    //! set of basic collision shapes
    namespace CollisionPrimitives
    {
        //! face-winding enum.
        enum _OgreNewtExport FaceWinding { FW_DEFAULT, FW_REVERSE };

        //! null collision (results in no collision)
        class _OgreNewtExport Null : public OgreNewt::Collision
        {
        public:
            //! constructor
            Null( const World* world );

            //! destructor
            ~Null() {}
        };


        //! standard primitive Box.
        class _OgreNewtExport Box : public OgreNewt::ConvexCollision
        {
        public:
            //! constructor
            /*!
                Create a 'blank' box collision object.  Can be used for CollisionSerializer::importCollision
                \param world pointer to the OgreNewt::World
            */
            Box(const World* world);

            //! constructor
            /*!
                \param world pointer to OgreNewt::World
                \param size vector representing width, height, depth
                \param id an id for this shape, can be received with collision->getUserId()
                \param orient orientation offset of the primitive
                \param pos position offset of the primitive
            */
            Box( const World* world, const Ogre::Vector3& size,  int id,
                const Ogre::Quaternion& orient = Ogre::Quaternion::IDENTITY, const Ogre::Vector3& pos = Ogre::Vector3::ZERO );

            //! destructor
            ~Box() {}
        };

        //! standard primitive Ellipsoid.  
        class _OgreNewtExport Ellipsoid : public OgreNewt::ConvexCollision
        {
        public:
            //! constructor
            /*!
                Create a 'blank' ellipsoid collision object. Can be used for CollisionSerializer::importCollision
                \param world pointer to the OgreNewt::World
            */
            Ellipsoid(const World* world);

            //! constructor
            /*!
                for a sphere, pass the same radius for all 3 axis.
                \param world pointer to OgreNewt::World
                \param size vector representing radius for all 3 axis
                \param id an id for this shape, can be received with collision->getUserId()
                \param orient orientation offset of the primitive
                \param pos position offset of the primitive
            */
            Ellipsoid(const World* world, const Ogre::Vector3& size, int id,
                const Ogre::Quaternion& orient = Ogre::Quaternion::IDENTITY, const Ogre::Vector3& pos = Ogre::Vector3::ZERO );

            //! destructor
            ~Ellipsoid() {}
        };

        //! standard primitive cylinder.
        class _OgreNewtExport Cylinder : public OgreNewt::ConvexCollision
        {
        public:
            //! constructor
            /*!
                Create a 'blank' cylinder collision object. Can be used for CollisionSerializer::importCollision
                \param world pointer to the OgreNewt::World
            */
            Cylinder(const World* world);

            //! constructor
            /*!
                default aligned along the local X axis (x=height).
                \param world pointer to OgreNewt::World
                \param radius radius of the cylinder (Y and Z axis)
                \param height height of the cylinder (X axis)
                \param id an id for this shape, can be received with collision->getUserId()
                \param orient orientation offset of the primitive
                \param pos position offset of the primitive
            */
            Cylinder( const World* world, Ogre::Real radius, Ogre::Real height, int id,
                const Ogre::Quaternion& orient = Ogre::Quaternion::IDENTITY, const Ogre::Vector3& pos = Ogre::Vector3::ZERO );

            //! destructor
            ~Cylinder() {}
        };

        //! standard primitive capsule.
        class _OgreNewtExport Capsule : public OgreNewt::ConvexCollision
        {
        public:
            //! constructor
            /*!
                Create a 'blank' capsule collision object. Can be used for CollisionSerializer::importCollision
                \param world pointer to the OgreNewt::World
            */
            Capsule(const World* world);

            //! constructor
            /*!
                default aligned along the local X axis (x=height).
                \param world pointer to OgreNewt::World
                \param radius radius of the capsule (Y and Z axis)
                \param height height of the capsule (X axis)
                \param id an id for this shape, can be received with collision->getUserId()
                \param orient orientation offset of the primitive
                \param pos position offset of the primitive
            */
            Capsule( const World* world, Ogre::Real radius, Ogre::Real height, int id,
                const Ogre::Quaternion& orient = Ogre::Quaternion::IDENTITY, const Ogre::Vector3& pos = Ogre::Vector3::ZERO );

            //! destructor
            ~Capsule() {}
        };

        //! standard primitive cone.
        class _OgreNewtExport Cone : public OgreNewt::ConvexCollision
        {
        public:
            //! constructor
            /*!
                Create a 'blank' cone collision object. Can be used for CollisionSerializer::importCollision
                \param world pointer to the OgreNewt::World
            */
            Cone(const World* world);

            //! constructor
            /*!
                default aligned along the local X axis (x=height).
                \param world pointer to OgreNewt::World
                \param radius radius of the cone (Y and Z axis)
                \param height height of the cone (X axis)
                \param id an id for this shape, can be received with collision->getUserId()
                \param orient orientation offset of the primitive
                \param pos position offset of the primitive
            */
            Cone( const World* world, Ogre::Real radius, Ogre::Real height, int id,
                const Ogre::Quaternion& orient = Ogre::Quaternion::IDENTITY, const Ogre::Vector3& pos = Ogre::Vector3::ZERO );

            //! destructor
            ~Cone() {}
        };

        //! filled-donut shape primitive.
        class _OgreNewtExport ChamferCylinder : public OgreNewt::ConvexCollision
        {
        public:
            //! constructor
            /*!
                Create a 'blank' chamferycylinder collision object. Can be used for CollisionSerializer::importCollision
                \param world pointer to the OgreNewt::World
            */
            ChamferCylinder(const World* world);

            //! constructor
            /*!
                default aligned along the local X axis (x=height).
                \param world pointer to OgreNewt::World
                \param radius radius of the chamfer cylinder (Y and Z axis)
                \param height height of the chamfer cylinder (X axis)
                \param id an id for this shape, can be received with collision->getUserId()
                \param orient orientation offset of the primitive
                \param pos position offset of the primitive
            */
            ChamferCylinder( const World* world, Ogre::Real radius, Ogre::Real height, int id,
                const Ogre::Quaternion& orient = Ogre::Quaternion::IDENTITY, const Ogre::Vector3& pos = Ogre::Vector3::ZERO );

            //! destructor
            ~ChamferCylinder() {}
        };  

        //! ConvexHull primitive
        /*!
             "wrap" around a set cloud of vertices.  a convex hull is the smallest possible convex shape that fully encloses all points supplied.
         */
        class _OgreNewtExport ConvexHull : public OgreNewt::ConvexCollision
        {
        public:
            //! constructor
            /*!
                Create a 'blank' convexhull collision object. Can be used for CollisionSerializer::importCollision
                \param world pointer to the OgreNewt::World
            */
            ConvexHull(const World* world);

            //! constructor
            /*!
                Overloaded constructor.  pass an Entity*, and it will use its vertex data. if it is attached to Node*, the collision
                will be scaled apperently (entity->getParentNode()->getScale()), but if the scale changes, you need to adopt your collision by yourself
                \param world pointer to the OgreNewt::World
                \param ent pointer to an Ogre::Entity
                \param id an id for this shape, can be received with collision->getUserId()
                \param orient orientation offset of the primitive
                \param pos position offset of the primitive
                \parem tolerance a tolerance passed to newton
                \param forceScale if set to something else then (0,0,0), the value of this argument will be used as scale instead of the parent-node's scale
            */
            ConvexHull( const World* world, Ogre::Entity* ent, int id,
                const Ogre::Quaternion& orient = Ogre::Quaternion::IDENTITY, const Ogre::Vector3& pos = Ogre::Vector3::ZERO, Ogre::Real tolerance = 0.001f , const Ogre::Vector3& forceScale = Ogre::Vector3::ZERO);

            /*!
                Overloaded constructor.  pass a pointer to an array of vertices and the hull will be made from that.
                \param world pointer to the OgreNewt::World
                \param verts pointer to an array of Ogre::Vector3's that contain vertex position data
                \param vertcount number ot vetices in the array
                \param id an id for this shape, can be received with collision->getUserId()
                \param orient orientation offset of the primitive
                \param pos position offset of the primitive
                \param tolerance a tolerance passed to newton
            */
            ConvexHull( const World* world, const Ogre::Vector3* verts, int vertcount,int id,
                const Ogre::Quaternion& orient = Ogre::Quaternion::IDENTITY, const Ogre::Vector3& pos = Ogre::Vector3::ZERO, Ogre::Real tolerance = 0.001f );

            //! destructor
            ~ConvexHull() {}
        };

        



        //! TreeCollision - complex polygonal collision
        /*!
            TreeCollision objects are general polygon collision objects.  TreeCollision objects have a requirement that their mass must = 0 (aka are have infinite mass)
        */
        class _OgreNewtExport TreeCollision : public OgreNewt::Collision
        {
        public:
            //! constructor
            /*!
                Create a 'blank' tree collision object.  Can be used for manual TreeCollision creation, or to be used with TreeCollisionSerializer::importTreeCollision
                \param world pointer to the OgreNewt::World
            */
            TreeCollision( const World* world);

            //! constructor
            /*!
                Create a tree collision object.
                \param world pointer to the OgreNewt::World
                \param ent pointer to an Ogre::Entitiy, if it is attached to a node, the scale of the parent node is used
                \param optimize bool whether you want to optimize the collision or not.
                \param id an id for this shape, can be received with collision->getUserId()
            */
            TreeCollision( const World* world, Ogre::Entity* ent, bool optimize, int id, FaceWinding fw = FW_DEFAULT );

            //! constructor
            /*!
                build a TreeCollision from vertice and index information.  This can be used with the dotScene scene manager
                for building TreeCollision objects from each mesh in the scene.
                \param world pointer to OgreNewt::World
                \param numVertices number of vertices passed in the array.
                \param numIndices number of indices passed in the array.
                \param vertices pointer to array of vertices (positions only).
                \param indices pointer to array of indices.
                \param optimize bool whether you want to optimize the collision or not.
                \param id an id for this shape, can be received with collision->getUserId()
            */
            TreeCollision( const World* world, int numVertices, int numIndices, const float *vertices, const int *indices, bool optimize, int id, FaceWinding fw = FW_DEFAULT); 

            //! constructor
            /*!
                build a TreeCollision from vertice and index information.  This can be used with the ogre Paging Landscape SceneManager,
                or other custom solutions.
                \param world pointer to OgreNewt::World
                \param numVertices number of vertices in the array.
                \param vertices pointer to array of Ogre::Vector3 vertices (positions only)
                \param indexData pointer to Ogre::IndexData for the mesh
                \param optimize bool whether you want to optimize the collision or not.
                \param id an id for this shape, can be received with collision->getUserId()
            */
            TreeCollision( const World* world, int numVertices, Ogre::Vector3* vertices, Ogre::IndexData* indexData, bool optimize, int id, FaceWinding fw = FW_DEFAULT);

            //! destructor
            virtual ~TreeCollision() {}

            //! start a tree collision creation
            void start(int id);

            //! add a poly to the tree collision
            /*!
                Add a single poly to the tree collision.
                \param polys pointer to an array of 3 Vector3D objects representing the global position of each poly.
                \param ID and identifier to assign to this poly, that can be retrieved later upon collision detection.
            */
            void addPoly( Ogre::Vector3* polys, unsigned int ID );

            //! finish the tree collision
            void finish( bool optimize );

            //! set RayCastCallback active/disabled
            /*!
                \param active true = Callback active; false = Callback disabled 
            */
            void setRayCastCallbackactive(bool active = true)
            {
                setRayCastCallbackactive( active, m_col );
            }

            //! used internally
            static float _CDECL newtonRayCastCallback(float distance, float* normal, int faceId, void* userData);

        private:
            static void setRayCastCallbackactive( bool active , const NewtonCollision *col );

        };

        ////////////////////////////////////////////////////////
        //! TreeCollision created by parsing a tree of SceneNodes, adding collision data of all meshes.
        /*!
            Users can inherit this class, and inherit the "getID" function to perform their own filtering on the
            IDs to pass to Newton.  IDs are useful during collision callbacks to determine which part of the world
            is being hit.

            By default, the ID is set to an incrementing integer.
        */
        class _OgreNewtExport TreeCollisionSceneParser : public TreeCollision
        {
        public:
            TreeCollisionSceneParser( OgreNewt::World* world );

            ~TreeCollisionSceneParser() {}

            //! parse the scene.
            void parseScene( Ogre::SceneNode* startNode, int id, bool optimize = true, FaceWinding fw = FW_DEFAULT );

        protected:

            //! this is a user-inherited function that lets you filter which Entities will be added to the treeCollision.
            /*!
                return true to add this entity, return false to ignore it.
                You can also change the face winding on an entity-by-entity basis by changing the fw variable from within the filter.
            */
            virtual bool entityFilter( const Ogre::SceneNode* currentNode, const Ogre::Entity* currentEntity, FaceWinding& fw ) { return true; }

            //! user inherit-able function, allows customization of the ID to be assigned to this group of polygons.
            virtual unsigned int getID( const Ogre::SceneNode* currentNode, const Ogre::Entity* currentEntity, unsigned int currentSubMesh ) { return count++; }

        private:
            //! recursive function to parse a single scene node.
            void _parseNode( Ogre::SceneNode* node, const Ogre::Quaternion& curOrient, const Ogre::Vector3& curPos, const Ogre::Vector3& curScale, FaceWinding fw );


            static int count;
        };

        ////////////////////////////////////////////////////////
        //  COMPOUND COLLISION!

        //! create a compound from several collision pieces.
        class _OgreNewtExport CompoundCollision : public OgreNewt::Collision
        {
        public:
            //! constructor
            /*!
            Create a 'blank' ellipsoid compoundcollision object. Can be used for CollisionSerializer::importCollision
            \param world pointer to the OgreNewt::World
            */
            CompoundCollision(const World* world);

            //! constructor
            /*!
                creates a compound collision object made from an array of simple primitive parts.  can be used to make very complex
                collision shapes.
                \param world pointer to the OgreNewt::World
                \param col_array std::vector of pointers to existing collision objects.
                \param id an id for this shape, can be received with collision->getUserId()
            */
            CompoundCollision( const World* world, std::vector<OgreNewt::CollisionPtr> col_array, int id );

            //! destructor
            ~CompoundCollision() {}
        };


        ////////////////////////////////////////////////////////
        // supplemental primitives built from convex hulls
        ////////////////////////////////////////////////////////

        //! Pyramid primitive
        /*!
            4-sided base, comes to a single point. base is aligned on XZ plane. made from Convex Hull internally.  supplied as part of the
            OgreNewt library, but not a built-in function of Newton istelf.
        */
        class _OgreNewtExport Pyramid : public OgreNewt::ConvexCollision
        {
        public:
            //! constructor
            /*!
            Create a 'blank' ellipsoid collision object. Can be used for CollisionSerializer::importCollision
            \param world pointer to the OgreNewt::World
            */
            Pyramid(const World* world);

            //! constructor
            /*!
                \param world pointer to the OgreNewt::World
                \param size Ogre::Vector3 size.
                \param id an id for this shape, can be received with collision->getUserId()
                \param orient orientation offset of the primitive
                \param pos position offset of the primitive
                \param tolerance a tolerance passed to newton
            */
            Pyramid( const World* world, const Ogre::Vector3& size, int id,
                const Ogre::Quaternion& orient = Ogre::Quaternion::IDENTITY, const Ogre::Vector3& pos = Ogre::Vector3::ZERO, Ogre::Real tolerance = 0.001f );

            //! destructor
            ~Pyramid() {}
        };



    }   // end namespace CollisionPrimitives

}// end namespace OgreNewt

#endif  // _INCLUDE_OGRENEWT_COLLISIONPRIMITIVES

