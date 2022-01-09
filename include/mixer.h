#include <SDL_mixer.h>

namespace cookie::mixer
{
    inline bool SetPanning(int channel, Uint8 left, Uint8 right)
    {
        return Mix_SetPanning(channel, left, right);
    }
}