#include <SDL2/SDL.h>

#include "initializer.h"
#include "log.h"

namespace cookie
{
    Initializer Initializer::instance_;

    Initializer::~Initializer()
    {
        SDL_Quit();
    }

    bool Initializer::InitSdl(Uint32 flags)
    {
        if (SDL_Init(flags) < 0)
        {
            log::SdlError("Gagal menginisialisasi SDL");
            return false;
        }
        return true;
    }
}