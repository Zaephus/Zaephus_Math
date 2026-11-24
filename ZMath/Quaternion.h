
#pragma once

#include <iosfwd>
#include <string>

namespace ZMath {
    struct Vector3;
    struct Vector4;
    struct Matrix4x4;

    struct Quaternion {
        float x = 0;
        float y = 0;
        float z = 0;
        float w = 0;

        Quaternion();
        explicit Quaternion(const float _x) : Quaternion(_x, _x, _x, _x) {}
        Quaternion(const Quaternion& _q);
        explicit Quaternion(const Matrix4x4& _m);
        Quaternion(float _x, float _y, float _z, float _w);

        std::string toString() const;

        float magnitude() const;

        void normalize();
        Quaternion normalized() const;

        void invert();
        Quaternion inverse() const;

        Quaternion conjugate() const;

        Vector3 toEuler() const;
        static Vector3 toEuler(const Quaternion& _q);

        static Quaternion fromEuler(float _xDeg, float _yDeg, float _zDeg);
        static Quaternion fromEuler(const Vector3& _eulerDeg);

        static Quaternion fromAxisAngle(const Vector3& _axis, float _angleRad);

        static float dot(const Quaternion& _lhs, const Quaternion& _rhs);

        static float angleBetween(const Quaternion& _lhs, const Quaternion& _rhs);

        static Quaternion identity();

        void operator+=(const Quaternion& _q);
        Quaternion operator+(const Quaternion& _q) const;

        void operator-=(const Quaternion& _q);
        Quaternion operator-(const Quaternion& _q) const;
        Quaternion operator-() const;

        void operator*=(const Quaternion& _q);
        Quaternion operator*(const Quaternion& _q) const;

        Vector3 operator*(const Vector3& _v) const;

        void operator*=(float _s);
        Quaternion operator*(float _s) const;

        void operator/=(float _s);
        Quaternion operator/(float _s) const;

        Quaternion& operator=(const Quaternion& _v) = default;

        bool operator==(const Quaternion& _q) const;
        bool operator!=(const Quaternion& _q) const;

        float operator[](size_t _i) const;
    };
}

template<>
struct std::hash<ZMath::Quaternion> {
    size_t operator()(const ZMath::Quaternion& _quaternion) const noexcept {
        size_t result = 0;

        result ^= std::hash<float>{}(_quaternion.x) + 0x9e3779b9 + (result << 6) + (result >> 2);
        result ^= std::hash<float>{}(_quaternion.y) + 0x9e3779b9 + (result << 6) + (result >> 2);
        result ^= std::hash<float>{}(_quaternion.z) + 0x9e3779b9 + (result << 6) + (result >> 2);
        result ^= std::hash<float>{}(_quaternion.w) + 0x9e3779b9 + (result << 6) + (result >> 2);
        return result;
    }
};