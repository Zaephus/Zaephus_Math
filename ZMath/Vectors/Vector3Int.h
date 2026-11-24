
#pragma once

#include <iosfwd>
#include <string>

namespace ZMath {
    struct Vector3Int {
        int x = 0;
        int y = 0;
        int z = 0;

        Vector3Int();
        explicit Vector3Int(const int _x) : Vector3Int(_x, _x, _x) {}
        Vector3Int(int _x, int _y, int _z);
        Vector3Int(const Vector3Int& _v);

        std::string toString() const;

        float magnitude() const;
        int squaredMagnitude() const;

        Vector3Int normalized() const;
        void normalize();

        static float distance(const Vector3Int& _lhs, const Vector3Int& _rhs);

        static int dot(const Vector3Int& _lhs, const Vector3Int& _rhs);
        static Vector3Int cross(const Vector3Int& _lhs, const Vector3Int& _rhs);

        static float angle(Vector3Int const& _from, Vector3Int const& _to);

        static Vector3Int zero();
        static Vector3Int one();
        static Vector3Int right();
        static Vector3Int left();
        static Vector3Int up();
        static Vector3Int down();
        static Vector3Int forward();
        static Vector3Int back();

        void operator+=(const Vector3Int& _v);
        Vector3Int operator+(const Vector3Int& _v) const;

        void operator-=(const Vector3Int& _v);
        Vector3Int operator-(const Vector3Int& _v) const;
        Vector3Int operator-() const;

        void operator*=(int _s);
        Vector3Int operator*(int _s) const;

        void operator/=(int _s);
        Vector3Int operator/(int _s) const;

        Vector3Int& operator=(const Vector3Int& _v) = default;

        bool operator==(const Vector3Int& _v) const;
        bool operator!=(const Vector3Int& _v) const;

        int operator[](size_t _i) const;
    };
}

template<>
struct std::hash<ZMath::Vector3Int> {
    size_t operator()(const ZMath::Vector3Int& _vector) const noexcept {
        size_t result = 0;

        result ^= std::hash<int>{}(_vector.x) + 0x9e3779b9 + (result << 6) + (result >> 2);
        result ^= std::hash<int>{}(_vector.y) + 0x9e3779b9 + (result << 6) + (result >> 2);
        result ^= std::hash<int>{}(_vector.z) + 0x9e3779b9 + (result << 6) + (result >> 2);

        return result;
    }
};