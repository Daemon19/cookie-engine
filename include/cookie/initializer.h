#pragma once

#include <SDL2/SDL.h>

namespace cookie
{
    class Initializer
    {
    private:
        static Initializer instance_;

    public:
        enum InitFlag
        {
            kInitVideo = SDL_INIT_VIDEO,
            kInitAudio = SDL_INIT_AUDIO
        };

        ~Initializer();

        bool static InitSdl(Uint32 flags);

    private:
        Initializer() {}
    };
}