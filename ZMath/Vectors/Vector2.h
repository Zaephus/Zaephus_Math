
#pragma once

#include <functional>
#include <iosfwd>
#include <string>

namespace ZMath {
    struct Vector2 {
        float x = 0;
        float y = 0;

        Vector2();
        explicit Vector2(const float _x) : Vector2(_x, _x) {}
        Vector2(float _x, float _y);
        Vector2(const Vector2& _v);

        std::string toString() const;

        float magnitude() const;
        float squaredMagnitude() const;

        Vector2 normalized() const;
        void normalize();

        static float distance(const Vector2& _lhs, const Vector2& _rhs);

        static float dot(const Vector2& _lhs, const Vector2& _rhs);
        static float cross(const Vector2& _lhs, const Vector2& _rhs);

        static float angle(const Vector2& _from, const Vector2& _to);

        static Vector2 zero();
        static Vector2 one();
        static Vector2 right();
        static Vector2 left();
        static Vector2 up();
        static Vector2 down();

        void operator+=(const Vector2& _v);
        Vector2 operator+(const Vector2& _v) const;

        void operator-=(const Vector2& _v);
        Vector2 operator-(const Vector2& _v) const;
        Vector2 operator-() const;

        void operator*=(float _s);
        Vector2 operator*(float _s) const;

        void operator/=(float _s);
        Vector2 operator/(float _s) const;

        Vector2& operator=(const Vector2& _v) = default;

        bool operator==(const Vector2& _v) const;
        bool operator!=(const Vector2& _v) const;

        float operator[](size_t _i) const;
    };
}

template<>
struct std::hash<ZMath::Vector2> {
    size_t operator()(const ZMath::Vector2& _vector) const noexcept {
        size_t result = 0;

        result ^= std::hash<float>{}(_vector.x) + 0x9e3779b9 + (result << 6) + (result >> 2);
        result ^= std::hash<float>{}(_vector.y) + 0x9e3779b9 + (result << 6) + (result >> 2);

        return result;
    }
};