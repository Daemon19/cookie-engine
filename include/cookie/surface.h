#pragma once

#include <SDL2/SDL.h>
#include <string>

namespace cookie
{
    class Surface
    {
    private:
        SDL_Surface *surface_ = nullptr;

    public:
        Surface() = default;
        Surface(const Surface &) = delete;

        Surface(SDL_Surface *surface);
        Surface(const std::string &file_path);
        ~Surface();

        bool Init(SDL_Surface *surface);
        bool Init(const std::string &file_path);

        operator SDL_Surface *() { return surface_; }

        int w() const { return surface_->w; }
        int h() const { return surface_->h; }
    };
}