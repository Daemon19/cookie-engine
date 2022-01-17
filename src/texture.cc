#include "texture.h"
#include "log.h"

#include <SDL2/SDL.h>
#include <stdexcept>

namespace cookie
{
    Texture::Texture(SDL_Texture *texture)
    {
        if (!Init(texture))
            throw std::runtime_error("Gagal membuat objek Texture");
    }

    Texture::Texture(SDL_Surface *surface, SDL_Renderer *renderer)
    {
        if (!Init(surface, renderer))
            throw std::runtime_error("Gagal membuat objek Texture");
    }

    Texture::~Texture()
    {
        if (texture_ != nullptr)
            SDL_DestroyTexture(texture_);
    }

    bool Texture::Init(SDL_Texture *texture)
    {
        texture_ = texture;
        if (texture_ == nullptr)
            log::SdlError("Gagal membuat tekstur : parameter texture tidak boleh NULL");
        return texture_ != nullptr;
    }

    bool Texture::Init(SDL_Surface *surface, SDL_Renderer *renderer)
    {
        texture_ = SDL_CreateTextureFromSurface(renderer, surface);
        if (texture_ == nullptr)
            log::SdlError("Gagal membuat tekstur dari permukaan");
        return texture_ != nullptr;
    }
}