#include "resource_manager.h"

void ResourceManager::unloadAll()
{
    for (auto &pair : resources)
    {
        pair.second->unload();
    }
    resources.clear();
}
