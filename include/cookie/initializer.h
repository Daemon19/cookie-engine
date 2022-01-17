#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

namespace cookie
{
    class Initializer
    {
    private:
        static Initializer instance_;

    public:
        enum SdlFlag : Uint32
        {
            kInitVideo = SDL_INIT_VIDEO,
            kInitAudio = SDL_INIT_AUDIO
        };

        enum ImgFlag
        {
            kInitJpg = IMG_INIT_JPG,
            kInitPng = IMG_INIT_PNG,
        };

        ~Initializer();

        bool static InitSdl(SdlFlag flags);
        bool static InitSdlImage(ImgFlag flags);

    private:
        Initializer() {}
    };
}