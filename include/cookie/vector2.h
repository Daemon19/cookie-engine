#pragma once

#include <iostream>

namespace cookie
{
    struct Vector2
    {
        float x, y;

        Vector2() = default;
        Vector2(float x, float y);

        Vector2 operator+(const Vector2 &other) const;
        Vector2 operator-(const Vector2 &other) const;
        Vector2 operator*(float scalar) const;
        Vector2 operator/(float scalar) const;

        void operator+=(const Vector2 &other) { *this = *this + other; }
        void operator-=(const Vector2 &other) { *this = *this - other; }
        void operator*=(float scalar) { *this = *this * scalar; }
        void operator/=(float scalar) { *this = *this / scalar; }
    };
}

std::ostream &operator<<(std::ostream &stream, const cookie::Vector2 &vector);