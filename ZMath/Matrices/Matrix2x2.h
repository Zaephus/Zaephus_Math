
#pragma once

#include <iosfwd>
#include <string>

namespace ZMath {
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

        Vector2 getRow(size_t _index) const;
        Vector2 getColumn(size_t _index) const;

        void setRow(size_t _index, const Vector2& _row);
        void setColumn(size_t _index, const Vector2& _column);

        std::string toString() const;

        Matrix2x2 inverse() const;
        void invert();

        Matrix2x2 transposed() const;
        void transpose();

        float determinant() const;
        static float determinant(
            float _m00, float _m01,
            float _m10, float _m11
        );

        static Matrix2x2 zero();
        static Matrix2x2 one();
        static Matrix2x2 identity();

        void operator+=(const Matrix2x2& _m);
        Matrix2x2 operator+(const Matrix2x2& _m) const;

        void operator-=(const Matrix2x2& _m);
        Matrix2x2 operator-(const Matrix2x2& _m) const;
        Matrix2x2 operator-() const;

        void operator*=(const Matrix2x2& _m);
        Matrix2x2 operator*(const Matrix2x2& _m) const;

        Vector2 operator*(const Vector2& _v) const;

        void operator*=(float _s);
        Matrix2x2 operator*(float _s) const;

        void operator/=(float _s);
        Matrix2x2 operator/(float _s) const;

        Matrix2x2& operator=(const Matrix2x2& _m) = default;

        bool operator==(const Matrix2x2& _m) const;
        bool operator!=(const Matrix2x2& _m) const;

        Vector2 operator[](size_t _i) const;
    };
}

template<>
struct std::hash<ZMath::Matrix2x2> {
    size_t operator()(const ZMath::Matrix2x2& _matrix) const noexcept {
        size_t result = 0;

        result ^= std::hash<float>{}(_matrix.m00) + 0x9e3779b9 + (result << 6) + (result >> 2);
        result ^= std::hash<float>{}(_matrix.m01) + 0x9e3779b9 + (result << 6) + (result >> 2);

        result ^= std::hash<float>{}(_matrix.m10) + 0x9e3779b9 + (result << 6) + (result >> 2);
        result ^= std::hash<float>{}(_matrix.m11) + 0x9e3779b9 + (result << 6) + (result >> 2);

        return result;
    }
};