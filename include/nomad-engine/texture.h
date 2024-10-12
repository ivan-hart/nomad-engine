#ifndef TEXTURE_H
#define TEXTURE_H

#include "nomad-engine/resource.h"
#include <GL/glew.h>

class Texture : public Resource
{
public:
    Texture(const std::string &id, const std::string &filepath);
    ~Texture();

    bool load() override;
    void unload() override;

    GLuint getTextureId() const { return textureId; }

private:
    std::string filepath;
    GLuint textureId;
};

#endif
