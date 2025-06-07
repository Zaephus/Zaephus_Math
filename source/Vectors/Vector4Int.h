
#pragma once

#include <iosfwd>
#include <string>

struct Vector3Int;

struct Vector4Int {
    int x = 0;
    int y = 0;
    int z = 0;
    int w = 0;

    Vector4Int();
    explicit Vector4Int(const int _x) : Vector4Int(_x, _x, _x, _x) {}
    Vector4Int(int _x, int _y, int _z, int _w);
    Vector4Int(const Vector4Int& _v);
    explicit Vector4Int(const Vector3Int& _v);
    Vector4Int(const Vector3Int& _v, int _w);

    [[nodiscard]] std::string toString() const;

    [[nodiscard]] float magnitude() const;
    [[nodiscard]] int squaredMagnitude() const;

    [[nodiscard]] Vector4Int normalized() const;
    void normalize();

    static float distance(const Vector4Int& _lhs, const Vector4Int& _rhs);

    static int dot(const Vector4Int& _lhs, const Vector4Int& _rhs);

    static float angle(const Vector4Int& _from, const Vector4Int& _to);

    static Vector4Int zero();
    static Vector4Int one();

    void operator+=(const Vector4Int& _v);
    Vector4Int operator+(const Vector4Int& _v) const;

    void operator-=(const Vector4Int& _v);
    Vector4Int operator-(const Vector4Int& _v) const;
    Vector4Int operator-() const;

    void operator*=(int _s);
    Vector4Int operator*(int _s) const;
    friend Vector4Int operator*(int _s, const Vector4Int& _v);

    void operator/=(int _s);
    Vector4Int operator/(int _s) const;

    Vector4Int& operator=(const Vector4Int& _v) = default;

    bool operator==(const Vector4Int& _v) const;
    bool operator!=(const Vector4Int& _v) const;

    int operator[](size_t _i) const;
};