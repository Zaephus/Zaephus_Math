
#pragma once

#include <string>

namespace ZMath {
    struct Vector3;
    struct Vector4;
    struct Quaternion;

    struct Matrix4x4 {
        float m00 = 0, m01 = 0, m02 = 0, m03 = 0;
        float m10 = 0, m11 = 0, m12 = 0, m13 = 0;
        float m20 = 0, m21 = 0, m22 = 0, m23 = 0;
        float m30 = 0, m31 = 0, m32 = 0, m33 = 0;

        Matrix4x4();
        Matrix4x4(const Matrix4x4& _m);
        explicit Matrix4x4(const float _m[4][4]);
        Matrix4x4(
            float _m00, float _m01, float _m02, float _m03,
            float _m10, float _m11, float _m12, float _m13,
            float _m20, float _m21, float _m22, float _m23,
            float _m30, float _m31, float _m32, float _m33
        );
        Matrix4x4(const Vector4& _row0, const Vector4& _row1, const Vector4& _row2, const Vector4& _row3);

        Vector4 getRow(unsigned int _index) const;
        Vector4 getColumn(unsigned int _index) const;

        void setRow(unsigned int _index, const Vector4& _row);
        void setColumn(unsigned int _index, const Vector4& _column);

        std::string toString() const;

        Matrix4x4 inverse() const;
        void invert();

        Matrix4x4 transposed() const;
        void transpose();

        void flipX();
        void flipY();
        void flipZ();

        float determinant() const;
        static float determinant(
            float _m00, float _m01, float _m02, float _m03,
            float _m10, float _m11, float _m12, float _m13,
            float _m20, float _m21, float _m22, float _m23,
            float _m30, float _m31, float _m32, float _m33
        );

        static Matrix4x4 scaleMatrix(const Vector3& _v);
        static Matrix4x4 translateMatrix(const Vector3& _v);
        static Matrix4x4 rotateMatrix(const Quaternion& _q);

        static Matrix4x4 zero();
        static Matrix4x4 one();
        static Matrix4x4 identity();

        void operator+=(const Matrix4x4& _m);
        Matrix4x4 operator+(const Matrix4x4& _m) const;

        void operator-=(const Matrix4x4& _m);
        Matrix4x4 operator-(const Matrix4x4& _m) const;
        Matrix4x4 operator-() const;

        void operator*=(const Matrix4x4& _m);
        Matrix4x4 operator*(const Matrix4x4& _m) const;

        Vector4 operator*(const Vector4& _v) const;
        Vector3 operator*(const Vector3& _v) const;

        void operator*=(float _s);
        Matrix4x4 operator*(float _s) const;

        void operator/=(float _s);
        Matrix4x4 operator/(float _s) const;

        Matrix4x4& operator=(const Matrix4x4& _m) = default;

        bool operator==(const Matrix4x4& _m) const;
        bool operator!=(const Matrix4x4& _m) const;

        Vector4 operator[](unsigned int _i) const;
    };
}

template<>
struct std::hash<ZMath::Matrix4x4> {
    size_t operator()(const ZMath::Matrix4x4& _matrix) const noexcept {
        size_t result = 0;

        result ^= std::hash<float>{}(_matrix.m00) + 0x9e3779b9 + (result << 6) + (result >> 2);
        result ^= std::hash<float>{}(_matrix.m01) + 0x9e3779b9 + (result << 6) + (result >> 2);
        result ^= std::hash<float>{}(_matrix.m02) + 0x9e3779b9 + (result << 6) + (result >> 2);
        result ^= std::hash<float>{}(_matrix.m03) + 0x9e3779b9 + (result << 6) + (result >> 2);

        result ^= std::hash<float>{}(_matrix.m10) + 0x9e3779b9 + (result << 6) + (result >> 2);
        result ^= std::hash<float>{}(_matrix.m11) + 0x9e3779b9 + (result << 6) + (result >> 2);
        result ^= std::hash<float>{}(_matrix.m12) + 0x9e3779b9 + (result << 6) + (result >> 2);
        result ^= std::hash<float>{}(_matrix.m13) + 0x9e3779b9 + (result << 6) + (result >> 2);

        result ^= std::hash<float>{}(_matrix.m20) + 0x9e3779b9 + (result << 6) + (result >> 2);
        result ^= std::hash<float>{}(_matrix.m21) + 0x9e3779b9 + (result << 6) + (result >> 2);
        result ^= std::hash<float>{}(_matrix.m22) + 0x9e3779b9 + (result << 6) + (result >> 2);
        result ^= std::hash<float>{}(_matrix.m23) + 0x9e3779b9 + (result << 6) + (result >> 2);

        result ^= std::hash<float>{}(_matrix.m30) + 0x9e3779b9 + (result << 6) + (result >> 2);
        result ^= std::hash<float>{}(_matrix.m31) + 0x9e3779b9 + (result << 6) + (result >> 2);
        result ^= std::hash<float>{}(_matrix.m32) + 0x9e3779b9 + (result << 6) + (result >> 2);
        result ^= std::hash<float>{}(_matrix.m33) + 0x9e3779b9 + (result << 6) + (result >> 2);

        return result;
    }
};