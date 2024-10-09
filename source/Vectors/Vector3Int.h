
#pragma once

struct Vector3Int {

    int x = 0;
    int y = 0;
    int z = 0;

    Vector3Int();
    explicit Vector3Int(const int _x) : Vector3Int(_x, _x, _x) {}
    Vector3Int(int _x, int _y, int _z);
    Vector3Int(const Vector3Int& _v);

    [[nodiscard]] std::string toString() const;

    [[nodiscard]] float magnitude() const;
    [[nodiscard]] int squaredMagnitude() const;

    [[nodiscard]] Vector3Int normalized() const;
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

    Vector3Int& operator+=(const Vector3Int& _v);
    friend Vector3Int operator+(const Vector3Int& _lhs, const Vector3Int& _rhs);

    Vector3Int& operator-=(const Vector3Int& _v);
    friend Vector3Int operator-(const Vector3Int& _lhs, const Vector3Int& _rhs);
    Vector3Int operator-();

    Vector3Int& operator*=(int _s);
    friend Vector3Int operator*(const Vector3Int& _v, int _s);
    friend Vector3Int operator*(int _s, const Vector3Int& _v);

    Vector3Int& operator/=(int _s);
    friend Vector3Int operator/(const Vector3Int& _v, int _s);

    Vector3Int& operator=(const Vector3Int& _v) = default;

    friend bool operator==(const Vector3Int& _lhs, const Vector3Int& _rhs);
    friend bool operator!=(const Vector3Int& _lhs, const Vector3Int& _rhs);

    int operator[](size_t _i) const;

};