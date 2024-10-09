
#pragma once

struct Vector2 {

    float x = 0;
    float y = 0;

    Vector2();
    explicit Vector2(const float _x) : Vector2(_x, _x) {}
    Vector2(float _x, float _y);
    Vector2(const Vector2& _v);

    [[nodiscard]] std::string toString() const;

    [[nodiscard]] float magnitude() const;
    [[nodiscard]] float squaredMagnitude() const;

    [[nodiscard]] Vector2 normalized() const;
    void normalize();

    static float distance(const Vector2& _lhs, const Vector2& _rhs);

    static float dot(const Vector2& _lhs, const Vector2& _rhs);
    static float cross(const Vector2& _lhs, const Vector2& _rhs);

    static float angle(const Vector2& _from, const Vector2& _to);

    static Vector2 zero();
    static Vector2 one();
    static Vector2 right();
    static Vector2 left();
    static Vector2 up();
    static Vector2 down();

    Vector2& operator+=(const Vector2& _v);
    friend Vector2 operator+(const Vector2& _lhs, const Vector2& _rhs);

    Vector2& operator-=(const Vector2& _v);
    friend Vector2 operator-(const Vector2& _lhs, const Vector2& _rhs);
    Vector2 operator-();

    Vector2& operator*=(float _s);
    friend Vector2 operator*(const Vector2& _v, float _s);
    friend Vector2 operator*(float _s, const Vector2& _v);

    Vector2& operator/=(float _s);
    friend Vector2 operator/(const Vector2& _v, float _s);

    Vector2& operator=(const Vector2& _v) = default;

    friend bool operator==(const Vector2& _lhs, const Vector2& _rhs);
    friend bool operator!=(const Vector2& _lhs, const Vector2& _rhs);

    float operator[](size_t _i) const;

};