#include "rect.h"

namespace cookie
{
    Rect::Rect(float x, float y, int w, int h)
        : x(x), y(y), w(w), h(h)
    {
    }

    bool Rect::CollideRect(const Rect &other) const
    {
        return (x < other.right() && right() > other.x &&
                y < other.bottom() && bottom() > other.y);
    }

    void Rect::Move(const Vector2 &movement)
    {
        set_pos(pos() + movement);
    }

    void Rect::set_pos(const Vector2 &value)
    {
        x = value.x;
        y = value.y;
    }

    void Rect::set_center(const Vector2 &value)
    {
        set_centerx(value.x);
        set_centery(value.y);
    }
}