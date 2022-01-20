#pragma once

#include <SDL2/SDL.h>

#include "vector2.h"

namespace cookie
{
    struct Rect
    {
        float x, y;
        int w, h;

        Rect() = default;
        Rect(float x, float y, int w, int h);
        Rect(const Vector2 &pos, const Vector2 &size);

        bool CollideRect(float x, float y, int w, int h) const;
        bool CollideRect(const Rect &rect) const { return CollideRect(rect.x, rect.y, rect.w, rect.h); }

        bool CollidePoint(float x, float y) const;
        bool CollidePoint(const Vector2 &point) const { return CollidePoint(point.x, point.y); }

        void Move(const Vector2 &movement);

        operator SDL_Rect() const { return SDL_Rect{(int)x, (int)y, w, h}; }

        float right() const { return x + w; }
        void set_right(float value) { x = value - w; }

        float bottom() const { return y + h; }
        void set_bottom(float value) { y = value - h; }

        float centerx() const { return x + w / 2.0f; }
        void set_centerx(float value) { x = value - w / 2.0f; }

        float centery() const { return y + h / 2.0f; }
        void set_centery(float value) { y = value - h / 2.0f; }

        Vector2 center() const { return Vector2(centerx(), centery()); }
        void set_center(float x, float y);
        void set_center(const Vector2 &value) { set_center(value.x, value.y); }

        Vector2 pos() const { return Vector2(x, y); }
        void set_pos(float x, float y);
        void set_pos(const Vector2 &value) { set_pos(value.x, value.y); }

        Vector2 size() const { return Vector2(w, h); }
        void set_size(float w, float h);
        void set_size(const Vector2 &value) { set_size(value.x, value.y); }
    };
}