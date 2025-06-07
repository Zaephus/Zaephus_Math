
#pragma once

#include <iosfwd>
#include <string>

struct Vector3 {
    float x = 0;
    float y = 0;
    float z = 0;

    Vector3();
    explicit Vector3(const float _x) : Vector3(_x, _x, _x) {}
    Vector3(float _x, float _y, float _z);
    Vector3(const Vector3& _v);

    [[nodiscard]] std::string toString() const;

    [[nodiscard]] float magnitude() const;
    [[nodiscard]] float squaredMagnitude() const;

    [[nodiscard]] Vector3 normalized() const;
    void normalize();

    static float distance(const Vector3& _lhs, const Vector3& _rhs);

    static float dot(const Vector3& _lhs, const Vector3& _rhs);
    static Vector3 cross(const Vector3& _lhs, const Vector3& _rhs);

    static float angle(const Vector3& _from, const Vector3& _to);
    static float signedAngle(const Vector3& _from, const Vector3& _to);
    static float signedAngle(const Vector3& _from, const Vector3& _to, const Vector3& _axis);

    static Vector3 zero();
    static Vector3 one();
    static Vector3 right();
    static Vector3 left();
    static Vector3 up();
    static Vector3 down();
    static Vector3 forward();
    static Vector3 back();

    void operator+=(const Vector3& _v);
    Vector3 operator+(const Vector3& _v) const;

    void operator-=(const Vector3& _v);
    Vector3 operator-(const Vector3& _v) const;
    Vector3 operator-() const;

    void operator*=(float _s);
    Vector3 operator*(float _s) const;
    friend Vector3 operator*(float _s, const Vector3& _v);

    void operator/=(float _s);
    Vector3 operator/(float _s) const;

    Vector3& operator=(const Vector3& _v) = default;

    bool operator==(const Vector3& _v) const;
    bool operator!=(const Vector3& _v) const;

    float operator[](size_t _i) const;
};