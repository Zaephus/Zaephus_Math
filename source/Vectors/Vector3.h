
#pragma once

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

    static float angle(Vector3 const& _from, Vector3 const& _to);

    static Vector3 zero();
    static Vector3 one();
    static Vector3 right();
    static Vector3 left();
    static Vector3 up();
    static Vector3 down();
    static Vector3 forward();
    static Vector3 back();

    Vector3& operator+=(const Vector3& _v);
    friend Vector3 operator+(const Vector3& _lhs, const Vector3& _rhs);

    Vector3& operator-=(const Vector3& _v);
    friend Vector3 operator-(const Vector3& _lhs, const Vector3& _rhs);
    Vector3 operator-();

    Vector3& operator*=(float _s);
    friend Vector3 operator*(const Vector3& _v, float _s);
    friend Vector3 operator*(float _s, const Vector3& _v);

    Vector3& operator/=(float _s);
    friend Vector3 operator/(const Vector3& _v, float _s);

    Vector3& operator=(const Vector3& _v) = default;

    friend bool operator==(const Vector3& _lhs, const Vector3& _rhs);
    friend bool operator!=(const Vector3& _lhs, const Vector3& _rhs);

    float operator[](size_t _i) const;
};

template<>
struct std::formatter<Vector3> {
    constexpr auto parse(std::format_parse_context& _ctx) {
        return _ctx.begin();
    }

    auto format(const Vector3& _v, std::format_context& _ctx) const {
        return std::format_to(_ctx.out(), "{}", _v.toString());
    }
};