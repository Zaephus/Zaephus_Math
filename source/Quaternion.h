
#pragma once

#include <iosfwd>

struct Vector3;
struct Vector4;

struct Quaternion {
    float x = 0;
    float y = 0;
    float z = 0;
    float w = 0;

    Quaternion();
    explicit Quaternion(const float _x) : Quaternion(_x, _x, _x, _x) {}
    Quaternion(const Quaternion& _q);
    Quaternion(float _x, float _y, float _z, float _w);

    [[nodiscard]] std::string toString() const;

    [[nodiscard]] float magnitude() const;

    void normalize();
    [[nodiscard]] Quaternion normalized() const;

    void invert();
    [[nodiscard]] Quaternion inverse() const;

    [[nodiscard]] Quaternion conjugate() const;

    [[nodiscard]] Vector3 toEuler() const;
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

    Vector4 operator*(const Vector4& _v) const;
    Vector3 operator*(const Vector3& _v) const;

    void operator*=(float _s);
    Quaternion operator*(float _s) const;
    friend Quaternion operator*(float _s, const Quaternion& _q);

    void operator/=(float _s);
    Quaternion operator/(float _s) const;

    Quaternion& operator=(const Quaternion& _v) = default;

    bool operator==(const Quaternion& _q) const;
    bool operator!=(const Quaternion& _q) const;

    float operator[](size_t _i) const;
};