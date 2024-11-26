
#pragma once

#include <cstddef>
#include <string>
#include <format>

struct Vector2;

struct Matrix2x2 {

    float m00 = 0, m01 = 0;
    float m10 = 0, m11 = 0;

    Matrix2x2();
    Matrix2x2(const Matrix2x2& _m);
    explicit Matrix2x2(const float _m[2][2]);
    Matrix2x2(
        float _m00, float _m01,
        float _m10, float _m11
    );
    Matrix2x2(const Vector2& _row0, const Vector2& _row1);

    [[nodiscard]] Vector2 getRow(size_t _index) const;
    [[nodiscard]] Vector2 getColumn(size_t _index) const;

    void setRow(size_t _index, const Vector2& _row);
    void setColumn(size_t _index, const Vector2& _column);

    [[nodiscard]] std::string toString() const;

    [[nodiscard]] Matrix2x2 inverse() const;
    void invert();

    [[nodiscard]] Matrix2x2 transposed() const;
    void transpose();

    [[nodiscard]] float determinant() const;
    static float determinant(
        float _m00, float _m01,
        float _m10, float _m11
    );

    static Matrix2x2 zero();

    static Matrix2x2 one();

    static Matrix2x2 identity();

    Matrix2x2& operator+=(const Matrix2x2& _m);
    friend Matrix2x2 operator+(const Matrix2x2& _lhs, const Matrix2x2& _rhs);

    Matrix2x2& operator-=(const Matrix2x2& _m);
    friend Matrix2x2 operator-(const Matrix2x2& _lhs, const Matrix2x2& _rhs);
    Matrix2x2 operator-();

    Matrix2x2 operator*=(const Matrix2x2& _m);
    friend Matrix2x2 operator*(const Matrix2x2& _lhs, const Matrix2x2& _rhs);

    friend Vector2 operator*(const Matrix2x2& _m, const Vector2& _v);

    Matrix2x2& operator*=(float _s);
    friend Matrix2x2 operator*(const Matrix2x2& _m, float _s);
    friend Matrix2x2 operator*(float _s, const Matrix2x2& _m);

    Matrix2x2& operator/=(float _s);
    friend Matrix2x2 operator/(const Matrix2x2& _m, float _s);

    Matrix2x2& operator=(const Matrix2x2& _m) = default;

    friend bool operator==(const Matrix2x2& _lhs, const Matrix2x2& _rhs);
    friend bool operator!=(const Matrix2x2& _lhs, const Matrix2x2& _rhs);

    Vector2 operator[](size_t _i) const;

};

template<>
struct std::formatter<Matrix2x2> {
    constexpr auto parse(std::format_parse_context& _ctx) {
        return _ctx.begin();
    }

    auto format(const Matrix2x2& _v, std::format_context& _ctx) const {
        return std::format_to(_ctx.out(), "{}", _v.toString());
    }
};