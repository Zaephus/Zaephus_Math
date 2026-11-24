
#pragma once

#include <iosfwd>
#include <string>

namespace ZMath {
    struct Vector2Int {
        int x = 0;
        int y = 0;

        Vector2Int();
        explicit Vector2Int(const int _x) : Vector2Int(_x, _x) {}
        Vector2Int(int _x, int _y);
        Vector2Int(const Vector2Int& _v);

        std::string toString() const;

        float magnitude() const;
        int squaredMagnitude() const;

        Vector2Int normalized() const;
        void normalize();

        static float distance(const Vector2Int& _lhs, const Vector2Int& _rhs);

        static int dot(const Vector2Int& _lhs, const Vector2Int& _rhs);
        static int cross(const Vector2Int& _lhs, const Vector2Int& _rhs);

        static float angle(const Vector2Int& _from, const Vector2Int& _to);

        static Vector2Int zero();
        static Vector2Int one();
        static Vector2Int right();
        static Vector2Int left();
        static Vector2Int up();
        static Vector2Int down();

        void operator+=(const Vector2Int& _v);
        Vector2Int operator+(const Vector2Int& _v) const;

        void operator-=(const Vector2Int& _v);
        Vector2Int operator-(const Vector2Int& _v) const;
        Vector2Int operator-() const;

        void operator*=(int _s);
        Vector2Int operator*(int _s) const;

        void operator/=(int _s);
        Vector2Int operator/(int _s) const;

        Vector2Int& operator=(const Vector2Int& _v) = default;

        bool operator==(const Vector2Int& _v) const;
        bool operator!=(const Vector2Int& _v) const;

        int operator[](size_t _i) const;
    };
}

template<>
struct std::hash<ZMath::Vector2Int> {
    size_t operator()(const ZMath::Vector2Int& _vector) const noexcept {
        size_t result = 0;

        result ^= std::hash<int>{}(_vector.x) + 0x9e3779b9 + (result << 6) + (result >> 2);
        result ^= std::hash<int>{}(_vector.y) + 0x9e3779b9 + (result << 6) + (result >> 2);

        return result;
    }
};