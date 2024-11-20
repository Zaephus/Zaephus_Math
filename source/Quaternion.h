
#pragma once

#include <string>

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

    Quaternion& operator+=(const Quaternion& _q);
    friend Quaternion operator+(const Quaternion& _lhs, const Quaternion& _rhs);

    Quaternion& operator-=(const Quaternion& _q);
    friend Quaternion operator-(const Quaternion& _lhs, const Quaternion& _rhs);
    Quaternion operator-();

    Quaternion operator*=(const Quaternion& _q);
    friend Quaternion operator*(const Quaternion& _lhs, const Quaternion& _rhs);

    friend Vector4 operator*(const Quaternion& _q, const Vector4& _v);
    friend Vector3 operator*(const Quaternion& _q, const Vector3& _v);

    Quaternion& operator*=(float _s);
    friend Quaternion operator*(const Quaternion& _v, float _s);
    friend Quaternion operator*(float _s, const Quaternion& _v);

    Quaternion& operator/=(float _s);
    friend Quaternion operator/(const Quaternion& _v, float _s);

    Quaternion& operator=(const Quaternion& _v) = default;

    friend bool operator==(const Quaternion& _lhs, const Quaternion& _rhs);
    friend bool operator!=(const Quaternion& _lhs, const Quaternion& _rhs);

    float operator[](size_t _i) const;

};

template<>
struct std::formatter<Quaternion> {
    constexpr auto parse(std::format_parse_context& _ctx) {
        return _ctx.begin();
    }

    auto format(const Quaternion& _v, std::format_context& _ctx) const {
        return std::format_to(_ctx.out(), "{}", _v.toString());
    }
};