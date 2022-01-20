#include "rect.h"

namespace cookie
{
    Rect::Rect(float x, float y, int w, int h)
        : x(x), y(y), w(w), h(h)
    {
    }

    Rect::Rect(const Vector2 &pos, const Vector2 &size)
        : Rect(pos.x, pos.y, size.x, size.y)
    {
    }

    bool Rect::CollideRect(float x, float y, int w, int h) const
    {
        return (this->x < x + w && right() > x &&
                this->y < y + h && bottom() > y);
    }

    bool Rect::CollidePoint(float x, float y) const
    {
        return (this->x < x && right() > x &&
                this->y < y && bottom() > y);
    }

    void Rect::Move(const Vector2 &movement)
    {
        set_pos(pos() + movement);
    }

    void Rect::set_pos(float x, float y)
    {
        this->x = x;
        this->y = y;
    }

    void Rect::set_center(float x, float y)
    {
        set_centerx(x);
        set_centery(y);
    }

    void Rect::set_size(float w, float h)
    {
        this->w = w;
        this->h = h;
    }
}