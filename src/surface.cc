#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdexcept>
#include <string>

#include "log.h"
#include "surface.h"

namespace cookie
{
    Surface::Surface(SDL_Surface *surface)
    {
        if (!Init(surface))
            throw std::runtime_error("Gagal membuat objek Surface");
    }

    Surface::Surface(const std::string &file_path)
    {
        if (!Init(file_path))
            throw std::runtime_error("Gagal membuat objek Surface");
    }

    Surface::~Surface()
    {
        if (surface_ != nullptr)
            SDL_FreeSurface(surface_);
    }

    bool Surface::Init(SDL_Surface *surface)
    {
        surface_ = surface;
        if (surface_ == nullptr)
            log::Error("Gagal membuat permukaan : parameter surface tidak boleh NULL");
        return surface_ != nullptr;
    }

    bool Surface::Init(const std::string &file_path)
    {
        surface_ = IMG_Load(file_path.c_str());
        if (surface_ == nullptr)
            log::SdlError("Gagal memuat gambar");
        return surface_ != nullptr;
    }
}