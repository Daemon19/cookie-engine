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
}