#pragma once

#include <SDL2/SDL.h>

namespace cookie
{
    struct Rect
    {
        float x, y;
        int w, h;

        Rect() = default;
        Rect(float x, float y, int w, int h);

        bool CollideRect(const Rect &other) const;

        operator SDL_Rect() const { return SDL_Rect{(int)x, (int)y, w, h}; }

        float right() const { return x + w; }
        float bottom() const { return y + h; }
    };
}