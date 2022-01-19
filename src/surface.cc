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
        {
            throw std::runtime_error("Gagal membuat objek Surface");
        }
    }

    Surface::Surface(const std::string &file_path)
    {
        if (!Init(file_path))
        {
            throw std::runtime_error("Gagal membuat objek Surface");
        }
    }

    Surface::~Surface()
    {
        if (surface_ != nullptr)
        {
            SDL_FreeSurface(surface_);
        }
    }

    bool Surface::Init(SDL_Surface *surface)
    {
        surface_ = surface;
        if (surface_ == nullptr)
        {
            log::Error("Gagal membuat permukaan : parameter surface tidak boleh NULL");
        }
        return surface_ != nullptr;
    }

    bool Surface::Init(const std::string &file_path)
    {
        surface_ = IMG_Load(file_path.c_str());
        if (surface_ == nullptr)
        {
            log::SdlError("Gagal memuat gambar");
        }
        return surface_ != nullptr;
    }

    void Surface::get_rgb(int x, int y, Uint8 &r, Uint8 &g, Uint8 &b)
    {
        Uint32 px = get_pixel(x, y);
        SDL_GetRGB(px, surface_->format, &r, &g, &b);
    }

    void Surface::set_rgb(int x, int y, Uint8 r, Uint8 g, Uint8 b)
    {
        Uint32 mapped = SDL_MapRGB(surface_->format, r, g, b);
        set_pixel(x, y, mapped);
    }

    Uint32 Surface::get_pixel(int x, int y)
    {
        int bpp = surface_->format->BytesPerPixel;
        // p adalah lokasi pixel yang akan diberikan
        Uint8 *p = (Uint8 *)surface_->pixels + y * surface_->pitch + x * bpp;

        switch (bpp)
        {
        case 1:
            return *p;
            break;

        case 2:
            return *(Uint16 *)p;
            break;

        case 3:
            if (SDL_BYTEORDER == SDL_BIG_ENDIAN)
            {
                return p[0] << 16 | p[1] << 8 | p[2];
            }
            else
            {
                return p[0] | p[1] << 8 | p[2] << 16;
            }
            break;

        case 4:
            return *(Uint32 *)p;
            break;

        default:
            // Seharusnya tidak terjadi, tapi untuk mencegah peringatan
            return 0;
        }
    }

    void Surface::set_pixel(int x, int y, Uint32 pixel)
    {
        Uint32 *target_pixel = (Uint32 *)((Uint8 *)surface_->pixels +
                                          y * surface_->pitch +
                                          x * surface_->format->BytesPerPixel);
        *target_pixel = pixel;
    }
}