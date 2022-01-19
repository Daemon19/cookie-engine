#include <SDL2/SDL.h>
#include <iostream>
#include <string>

#include "log.h"

namespace cookie::log
{
    void Info(const std::string &message)
    {
        if (log_level > kInfo)
        {
            std::cout << "[INFO] " << message << std::endl;
        }
    }

    void Warn(const std::string &message)
    {
        if (log_level > kWarning)
        {
            std::cout << "[WARNING] " << message << std::endl;
        }
    }

    void Error(const std::string &message)
    {
        if (log_level > kError)
        {
            std::cout << "[ERROR] " << message << std::endl;
        }
    }

    void SdlError(const std::string &message)
    {
        const char *sdl_message = SDL_GetError();
        if (*sdl_message == '\0')
        {
            sdl_message = "Tidak terdapat SDL error";
        }
        Error(message + " : " + sdl_message);
    }
}