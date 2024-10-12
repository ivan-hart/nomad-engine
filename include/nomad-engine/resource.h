#ifndef RESOURCE_H
#define RESOURCE_H

#include <string>

class Resource
{
public:
    Resource(const std::string &id) : id(id) {}
    virtual ~Resource() = default;

    const std::string &getId() const { return id; }

    virtual bool load() = 0;
    virtual void unload() = 0;

protected:
    std::string id;
};

#endif