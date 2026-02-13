
#pragma once

#include <string>

struct Vector3;
struct Vector4;
struct Quaternion;

struct Matrix4x4 {
    float m00{}, m01{}, m02{}, m03{};
    float m10{}, m11{}, m12{}, m13{};
    float m20{}, m21{}, m22{}, m23{};
    float m30{}, m31{}, m32{}, m33{};

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

    [[nodiscard]] Vector4 getRow(unsigned int _index) const;
    [[nodiscard]] Vector4 getColumn(unsigned int _index) const;

    void setRow(unsigned int _index, const Vector4& _row);
    void setColumn(unsigned int _index, const Vector4& _column);

    [[nodiscard]] std::string toString() const;

    [[nodiscard]] Matrix4x4 inverse() const;
    void invert();

    [[nodiscard]] Matrix4x4 transposed() const;
    void transpose();

    [[nodiscard]] float determinant() const;
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
    friend Matrix4x4 operator*(float _s, const Matrix4x4& _m);

    void operator/=(float _s);
    Matrix4x4 operator/(float _s) const;

    Matrix4x4& operator=(const Matrix4x4& _m) = default;

    bool operator==(const Matrix4x4& _m) const;
    bool operator!=(const Matrix4x4& _m) const;

    Vector4 operator[](unsigned int _i) const;
};