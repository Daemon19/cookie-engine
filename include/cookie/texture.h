#pragma once

#include <SDL2/SDL.h>

namespace cookie
{
    class Texture
    {
    private:
        SDL_Texture *texture_ = nullptr;

    public:
        Texture() = default;
        Texture(const Texture &) = delete;

        Texture(SDL_Texture *texture);
        Texture(SDL_Surface *surface, SDL_Renderer *renderer);
        ~Texture();

        bool Init(SDL_Texture *texture);
        bool Init(SDL_Surface *surface, SDL_Renderer *renderer);

        operator SDL_Texture *() { return texture_; }
    };
}