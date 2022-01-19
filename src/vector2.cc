#include "vector2.h"

namespace cookie
{
    Vector2::Vector2(float x, float y)
        : x(x), y(y)
    {
    }

    Vector2 Vector2::operator+(const Vector2 &other) const
    {
        return Vector2(x + other.x, y + other.y);
    }

    Vector2 Vector2::operator-(const Vector2 &other) const
    {
        return Vector2(x - other.x, y - other.y);
    }

    Vector2 Vector2::operator*(float scalar) const
    {
        return Vector2(x * scalar, y * scalar);
    }

    Vector2 Vector2::operator/(float scalar) const
    {
        return Vector2(x / scalar, y / scalar);
    }
}

std::ostream &operator<<(std::ostream &stream, const cookie::Vector2 &vector)
{
    stream << "<Vector2(" << vector.x << ", " << vector.y << ")>";
    return stream;
}