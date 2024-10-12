#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

#include <unordered_map>
#include <memory>
#include <string>
#include "resource.h"

class ResourceManager
{
public:
    ResourceManager() = default;
    ~ResourceManager() = default;

    template <typename T>
    std::shared_ptr<T> load(const std::string &id, const std::string &filepath);

    template <typename T>
    std::shared_ptr<T> get(const std::string &id);

    void unloadAll();

private:
    std::unordered_map<std::string, std::shared_ptr<Resource>> resources;
};

template <typename T>
std::shared_ptr<T> ResourceManager::load(const std::string &id, const std::string &filepath)
{
    auto it = resources.find(id);
    if (it != resources.end())
    {
        return std::dynamic_pointer_cast<T>(it->second);
    }

    auto resource = std::make_shared<T>(id, filepath);
    if (resource->load())
    {
        resources[id] = resource;
        return resource;
    }
    return nullptr;
}

template <typename T>
std::shared_ptr<T> ResourceManager::get(const std::string &id)
{
    auto it = resources.find(id);
    if (it != resources.end())
    {
        return std::dynamic_pointer_cast<T>(it->second);
    }
    return nullptr;
}

#endif