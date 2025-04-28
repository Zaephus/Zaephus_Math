
#pragma once

// #include <string>
// #include <format>

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

    [[nodiscard]] std::string toString() const;

    [[nodiscard]] float magnitude() const;
    [[nodiscard]] float squaredMagnitude() const;

    [[nodiscard]] Vector4 normalized() const;
    void normalize();

    static float distance(const Vector4& _lhs, const Vector4& _rhs);

    static float dot(const Vector4& _lhs, const Vector4& _rhs);

    static float angle(const Vector4& _from, const Vector4& _to);

    static Vector4 zero();
    static Vector4 one();

    Vector4& operator+=(const Vector4& _v);
    friend Vector4 operator+(const Vector4& _lhs, const Vector4& _rhs);

    Vector4& operator-=(const Vector4& _v);
    friend Vector4 operator-(const Vector4& _lhs, const Vector4& _rhs);
    Vector4 operator-();

    Vector4& operator*=(float _s);
    friend Vector4 operator*(const Vector4& _v, float _s);
    friend Vector4 operator*(float _s, const Vector4& _v);

    Vector4& operator/=(float _s);
    friend Vector4 operator/(const Vector4& _v, float _s);

    Vector4& operator=(const Vector4& _v) = default;

    friend bool operator==(const Vector4& _lhs, const Vector4& _rhs);
    friend bool operator!=(const Vector4& _lhs, const Vector4& _rhs);

    float operator[](size_t _i) const;

};

template<>
struct std::formatter<Vector4> {
    static constexpr auto parse(const std::format_parse_context& _ctx) {
        return _ctx.begin();
    }

    static auto format(const Vector4& _v, std::format_context& _ctx) {
        return std::format_to(_ctx.out(), "{}", _v.toString());
    }
};