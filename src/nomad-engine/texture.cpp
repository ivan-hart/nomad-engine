#include "texture.h"
#include <SDL2/SDL_image.h>
#include <iostream>

Texture::Texture(const std::string& id, const std::string& filepath)
    : Resource(id), filepath(filepath), textureId(0) {}

Texture::~Texture() {
    unload();
}

bool Texture::load() {
    SDL_Surface* surface = IMG_Load(filepath.c_str());
    if (!surface) {
        std::cerr << "Failed to load texture: " << filepath << std::endl;
        return false;
    }

    glGenTextures(1, &textureId);
    glBindTexture(GL_TEXTURE_2D, textureId);

    int mode = GL_RGB;
    if (surface->format->BytesPerPixel == 4) {
        mode = GL_RGBA;
    }

    glTexImage2D(GL_TEXTURE_2D, 0, mode, surface->w, surface->h, 0, mode, GL_UNSIGNED_BYTE, surface->pixels);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    SDL_FreeSurface(surface);
    return true;
}

void Texture::unload() {
    if (textureId != 0) {
        glDeleteTextures(1, &textureId);
        textureId = 0;
    }
}
