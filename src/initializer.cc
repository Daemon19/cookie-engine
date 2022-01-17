#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "initializer.h"
#include "log.h"

namespace cookie
{
    Initializer Initializer::instance_;

    Initializer::~Initializer()
    {
        IMG_Quit();
        SDL_Quit();
    }

    bool Initializer::InitSdl(SdlFlag flags)
    {
        if (SDL_Init(flags) < 0)
        {
            log::SdlError("Gagal menginisialisasi SDL");
            return false;
        }
        return true;
    }

    bool Initializer::InitSdlImage(ImgFlag flags)
    {
        if (IMG_Init(flags) == 0)
        {
            log::SdlError("Gagal menginisialisasi SDL_image");
            return false;
        }
        return true;
    }
}