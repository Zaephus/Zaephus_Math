
#pragma once

#include <iosfwd>
#include <string>

namespace ZMath {
    struct Vector3;

    struct Matrix3x3 {
        float m00 = 0, m01 = 0, m02 = 0;
        float m10 = 0, m11 = 0, m12 = 0;
        float m20 = 0, m21 = 0, m22 = 0;

        Matrix3x3();
        Matrix3x3(const Matrix3x3& _m);
        explicit Matrix3x3(const float _m[3][3]);
        Matrix3x3(
            float _m00, float _m01, float _m02,
            float _m10, float _m11, float _m12,
            float _m20, float _m21, float _m22
        );
        Matrix3x3(const Vector3& _row0, const Vector3& _row1, const Vector3& _row2);

        Vector3 getRow(size_t _index) const;
        Vector3 getColumn(size_t _index) const;

        void setRow(size_t _index, const Vector3& _row);
        void setColumn(size_t _index, const Vector3& _column);

        std::string toString() const;

        Matrix3x3 inverse() const;
        void invert();

        Matrix3x3 transposed() const;
        void transpose();

        float determinant() const;
        static float determinant(
            float _m00, float _m01, float _m02,
            float _m10, float _m11, float _m12,
            float _m20, float _m21, float _m22
        );

        static Matrix3x3 zero();
        static Matrix3x3 one();
        static Matrix3x3 identity();

        void operator+=(const Matrix3x3& _m);
        Matrix3x3 operator+(const Matrix3x3& _m) const;

        void operator-=(const Matrix3x3& _m);
        Matrix3x3 operator-(const Matrix3x3& _m) const;
        Matrix3x3 operator-() const;

        void operator*=(const Matrix3x3& _m);
        Matrix3x3 operator*(const Matrix3x3& _m) const;

        Vector3 operator*(const Vector3& _v) const;

        void operator*=(float _s);
        Matrix3x3 operator*(float _s) const;

        void operator/=(float _s);
        Matrix3x3 operator/(float _s) const;

        Matrix3x3& operator=(const Matrix3x3& _m) = default;

        bool operator==(const Matrix3x3& _m) const;
        bool operator!=(const Matrix3x3& _m) const;

        Vector3 operator[](size_t _i) const;
    };
}

template<>
struct std::hash<ZMath::Matrix3x3> {
    size_t operator()(const ZMath::Matrix3x3& _matrix) const noexcept {
        size_t result = 0;

        result ^= std::hash<float>{}(_matrix.m00) + 0x9e3779b9 + (result << 6) + (result >> 2);
        result ^= std::hash<float>{}(_matrix.m01) + 0x9e3779b9 + (result << 6) + (result >> 2);
        result ^= std::hash<float>{}(_matrix.m02) + 0x9e3779b9 + (result << 6) + (result >> 2);

        result ^= std::hash<float>{}(_matrix.m10) + 0x9e3779b9 + (result << 6) + (result >> 2);
        result ^= std::hash<float>{}(_matrix.m11) + 0x9e3779b9 + (result << 6) + (result >> 2);
        result ^= std::hash<float>{}(_matrix.m12) + 0x9e3779b9 + (result << 6) + (result >> 2);

        result ^= std::hash<float>{}(_matrix.m20) + 0x9e3779b9 + (result << 6) + (result >> 2);
        result ^= std::hash<float>{}(_matrix.m21) + 0x9e3779b9 + (result << 6) + (result >> 2);
        result ^= std::hash<float>{}(_matrix.m22) + 0x9e3779b9 + (result << 6) + (result >> 2);

        return result;
    }
};