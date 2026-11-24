
#pragma once

#include <iosfwd>
#include <string>


namespace ZMath {
    struct Vector3;
    
    struct Vector4 {
        float x = 0;
        float y = 0;
        float z = 0;
        float w = 0;

        Vector4();
        explicit Vector4(const float _x) : Vector4(_x, _x, _x, _x) {}
        Vector4(float _x, float _y, float _z, float _w);
        Vector4(const Vector4& _v);
        explicit Vector4(const Vector3& _v);
        Vector4(const Vector3& _v, float _w);

        std::string toString() const;

        float magnitude() const;
        float squaredMagnitude() const;

        Vector4 normalized() const;
        void normalize();

        static float distance(const Vector4& _lhs, const Vector4& _rhs);

        static float dot(const Vector4& _lhs, const Vector4& _rhs);

        static float angle(const Vector4& _from, const Vector4& _to);

        static Vector4 zero();
        static Vector4 one();

        void operator+=(const Vector4& _v);
        Vector4 operator+(const Vector4& _v) const;

        void operator-=(const Vector4& _v);
        Vector4 operator-(const Vector4& _v) const;
        Vector4 operator-() const;

        void operator*=(float _s);
        Vector4 operator*(float _s) const;

        void operator/=(float _s);
        Vector4 operator/(float _s) const;

        Vector4& operator=(const Vector4& _v) = default;

        bool operator==(const Vector4& _v) const;
        bool operator!=(const Vector4& _v) const;

        float operator[](size_t _i) const;
    };
}

template<>
struct std::hash<ZMath::Vector4> {
    size_t operator()(const ZMath::Vector4& _vector) const noexcept {
        size_t result = 0;

        result ^= std::hash<float>{}(_vector.x) + 0x9e3779b9 + (result << 6) + (result >> 2);
        result ^= std::hash<float>{}(_vector.y) + 0x9e3779b9 + (result << 6) + (result >> 2);
        result ^= std::hash<float>{}(_vector.z) + 0x9e3779b9 + (result << 6) + (result >> 2);
        result ^= std::hash<float>{}(_vector.w) + 0x9e3779b9 + (result << 6) + (result >> 2);

        return result;
    }
};