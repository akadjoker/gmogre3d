#ifndef GMAPI_INSTANCE_ARRAY_HPP
#define GMAPI_INSTANCE_ARRAY_HPP
#include "Dll.hpp"
namespace gm
{
    /**@ingroup instances*/
    ///@{
    struct Instance;
    /**@brief An array of all the current instances in the game.*/
    class GMAPI_DLL InstanceArray
    {
    public:
        /**Gets the nth instance in the game.*/
        Instance *getIndex(int index);
        /**Gets the instance with the specified id, or null if no such instance
         * exists.
         */
        Instance *get(int id);
        /**Number of instances.*/
        int getCount();
    private:
        char _pad0000[0x68];
        int len;
        /**Array of pointers to instances.*/
        Instance **instances;
    };
    GMAPI_DLL extern InstanceArray *instanceArray;
    /**Shorthand for instanceArray->get(id)*/
    inline Instance* getInstance(int id)
    {
        return instanceArray->get(id);
    }
    /**Called by the gm::init method, to initialise the gm::instanceArray.
     * @internal
     */
    bool initInstanceArray();
    ///@}
}
#endif
