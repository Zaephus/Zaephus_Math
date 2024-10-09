
#pragma once

struct Vector2Int {

    int x = 0;
    int y = 0;

    Vector2Int();
    explicit Vector2Int(const int _x) : Vector2Int(_x, _x) {}
    Vector2Int(int _x, int _y);
    Vector2Int(const Vector2Int& _v);

    [[nodiscard]] std::string toString() const;

    [[nodiscard]] float magnitude() const;
    [[nodiscard]] int squaredMagnitude() const;

    [[nodiscard]] Vector2Int normalized() const;
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

    Vector2Int& operator+=(const Vector2Int& _v);
    friend Vector2Int operator+(const Vector2Int& _lhs, const Vector2Int& _rhs);

    Vector2Int& operator-=(const Vector2Int& _v);
    friend Vector2Int operator-(const Vector2Int& _lhs, const Vector2Int& _rhs);
    Vector2Int operator-();

    Vector2Int& operator*=(int _s);
    friend Vector2Int operator*(const Vector2Int& _v, int _s);
    friend Vector2Int operator*(int _s, const Vector2Int& _v);

    Vector2Int& operator/=(int _s);
    friend Vector2Int operator/(const Vector2Int& _v, int _s);

    Vector2Int& operator=(const Vector2Int& _v) = default;

    friend bool operator==(const Vector2Int& _lhs, const Vector2Int& _rhs);
    friend bool operator!=(const Vector2Int& _lhs, const Vector2Int& _rhs);

    int operator[](size_t _i) const;

};