
#include <iostream>
#include <format>

#include "../ZMath.h"


Matrix4x4::Matrix4x4() {
    *this = identity();
}

Matrix4x4::Matrix4x4(const Matrix4x4 &_m) {
    m00 = _m.m00; m01 = _m.m01; m02 = _m.m02; m03 = _m.m03;
    m10 = _m.m10; m11 = _m.m11; m12 = _m.m12; m13 = _m.m13;
    m20 = _m.m20; m21 = _m.m21; m22 = _m.m22; m23 = _m.m23;
    m30 = _m.m30; m31 = _m.m31; m32 = _m.m32; m33 = _m.m33;
}

Matrix4x4::Matrix4x4(const float _m[4][4]) {
    m00 = _m[0][0]; m01 = _m[1][0]; m02 = _m[2][0]; m03 = _m[3][0];
    m10 = _m[0][1]; m11 = _m[1][1]; m12 = _m[2][1]; m13 = _m[3][1];
    m20 = _m[0][2]; m21 = _m[1][2]; m22 = _m[2][2]; m23 = _m[3][2];
    m30 = _m[0][3]; m31 = _m[1][3]; m32 = _m[2][3]; m33 = _m[3][3];
}

Matrix4x4::Matrix4x4(
    const float _m00, const float _m01, const float _m02, const float _m03,
    const float _m10, const float _m11, const float _m12, const float _m13,
    const float _m20, const float _m21, const float _m22, const float _m23,
    const float _m30, const float _m31, const float _m32, const float _m33
) {
    m00 = _m00; m01 = _m01; m02 = _m02; m03 = _m03;
    m10 = _m10; m11 = _m11; m12 = _m12; m13 = _m13;
    m20 = _m20; m21 = _m21; m22 = _m22; m23 = _m23;
    m30 = _m30; m31 = _m31; m32 = _m32; m33 = _m33;
}

Matrix4x4::Matrix4x4(const Vector4& _row0, const Vector4& _row1, const Vector4& _row2, const Vector4& _row3) {
    m00 = _row0.x; m01 = _row0.y; m02 = _row0.z; m03 = _row0.w;
    m10 = _row1.x; m11 = _row1.y; m12 = _row1.z; m13 = _row1.w;
    m20 = _row2.x; m21 = _row2.y; m22 = _row2.z; m23 = _row2.w;
    m30 = _row3.x; m31 = _row3.y; m32 = _row3.z; m33 = _row3.w;
}

[[nodiscard]] Vector4 Matrix4x4::getRow(const size_t _index) const {
    switch(_index) {
        case 0:
            return { m00, m01, m02, m03 };
        case 1:
            return { m10, m11, m12, m13 };
        case 2:
            return { m20, m21, m22, m23 };
        case 3:
            return { m30, m31, m32, m33 };
        default:
            throw std::out_of_range("Invalid row index.");
    }
}

[[nodiscard]] Vector4 Matrix4x4::getColumn(const size_t _index) const {
    switch(_index) {
        case 0:
            return { m00, m10, m20, m30 };
        case 1:
            return { m01, m11, m21, m31 };
        case 2:
            return { m02, m12, m22, m32 };
        case 3:
            return { m03, m13, m23, m33 };
        default:
            throw std::out_of_range("Invalid column index.");
    }
}

void Matrix4x4::setRow(const size_t _index, const Vector4& _row) {
    switch(_index) {
        case 0:
            m00 = _row.x; m01 = _row.y; m02 = _row.z; m03 = _row.w;
            break;
        case 1:
            m10 = _row.x; m11 = _row.y; m12 = _row.z; m13 = _row.w;
            break;
        case 2:
            m20 = _row.x; m21 = _row.y; m22 = _row.z; m23 = _row.w;
            break;
        case 3:
            m30 = _row.x; m31 = _row.y; m32 = _row.z; m33 = _row.w;
            break;
        default:
            throw std::out_of_range("Invalid row index.");
    }
}

void Matrix4x4::setColumn(const size_t _index, const Vector4& _column) {
    switch(_index) {
        case 0:
            m00 = _column.x; m10 = _column.y; m20 = _column.z; m30 = _column.w;
            break;
        case 1:
            m01 = _column.x; m11 = _column.y; m21 = _column.z; m31 = _column.w;
            break;
        case 2:
            m02 = _column.x; m12 = _column.y; m22 = _column.z; m32 = _column.w;
            break;
        case 3:
            m03 = _column.x; m13 = _column.y; m23 = _column.z; m33 = _column.w;
            break;
        default:
            throw std::out_of_range("Invalid row index.");
    }
}

[[nodiscard]] std::string Matrix4x4::toString() const {
    return std::format("{}, {}, {}, {},\n{}, {}, {}, {},\n{}, {}, {}, {},\n{}, {}, {}, {}", m00, m01, m02, m03, m10, m11, m12, m13, m20, m21, m22, m23, m30, m31, m32, m33);
}

[[nodiscard]] Matrix4x4 Matrix4x4::inverse() const {
    Matrix4x4 i = *this;
    i.invert();
    return i;
}

void Matrix4x4::invert() {

    if(determinant() == 0) {
        std::cout << "Determinant is zero, this matrix cannot be inverted." << std::endl;
        return;
    }

    float a00 = Matrix3x3::determinant(
        m11, m12, m13,
        m21, m22, m23,
        m31, m32, m33
    );
    float a01 = Matrix3x3::determinant(
        m10, m12, m13,
        m20, m22, m23,
        m30, m32, m33
    );
    float a02 = Matrix3x3::determinant(
        m10, m11, m13,
        m20, m21, m23,
        m30, m31, m33
    );
    float a03 = Matrix3x3::determinant(
        m10, m11, m12,
        m20, m21, m22,
        m30, m31, m32
    );
    float a10 = Matrix3x3::determinant(
        m01, m02, m03,
        m21, m22, m23,
        m31, m32, m33
    );
    float a11 = Matrix3x3::determinant(
        m00, m02, m03,
        m20, m22, m23,
        m30, m32, m33
    );
    float a12 = Matrix3x3::determinant(
        m00, m01, m03,
        m20, m21, m23,
        m30, m31, m33
    );
    float a13 = Matrix3x3::determinant(
        m00, m01, m02,
        m20, m21, m22,
        m30, m31, m32
    );
    float a20 = Matrix3x3::determinant(
        m01, m02, m03,
        m11, m12, m13,
        m31, m32, m33
    );
    float a21 = Matrix3x3::determinant(
        m00, m02, m03,
        m10, m12, m13,
        m30, m32, m33
    );
    float a22 = Matrix3x3::determinant(
        m00, m01, m03,
        m10, m11, m13,
        m30, m31, m33
    );
    float a23 = Matrix3x3::determinant(
        m00, m01, m02,
        m10, m11, m12,
        m30, m31, m32
    );
    float a30 = Matrix3x3::determinant(
        m01, m02, m03,
        m11, m12, m13,
        m21, m22, m23
    );
    float a31 = Matrix3x3::determinant(
        m00, m02, m03,
        m10, m12, m13,
        m20, m22, m23
    );
    float a32 = Matrix3x3::determinant(
        m00, m01, m03,
        m10, m11, m13,
        m20, m21, m23
    );
    float a33 = Matrix3x3::determinant(
        m00, m01, m02,
        m10, m11, m12,
        m20, m21, m22
    );

    Matrix4x4 adjugate = {
        a00, -a01, a02, -a03,
        -a10, a11, -a12, a13,
        a20, -a21, a22, -a23,
        -a30, a31, -a32, a33
    };
    adjugate.transpose();

    *this = adjugate / determinant();

}

[[nodiscard]] Matrix4x4 Matrix4x4::transposed() const {
    Matrix4x4 t = *this;
    t.transpose();
    return t;
}

void Matrix4x4::transpose() {
    *this = {
        m00, m10, m20, m30,
        m01, m11, m21, m31,
        m02, m12, m22, m32,
        m03, m13, m23, m33
    };
}

[[nodiscard]] float Matrix4x4::determinant() const {
    const float d1 = m11*m22*m33 + m12*m23*m31 + m13*m21*m32 - m13*m22*m31 - m12*m21*m33 - m11*m23*m32;
    const float d2 = m01*m22*m33 + m02*m23*m31 + m03*m21*m32 - m03*m22*m31 - m02*m21*m33 - m01*m23*m32;
    const float d3 = m01*m12*m33 + m02*m13*m31 + m03*m11*m32 - m03*m12*m31 - m02*m11*m33 - m01*m13*m32;
    const float d4 = m01*m12*m23 + m02*m13*m21 + m03*m11*m33 - m03*m12*m21 - m02*m11*m23 - m01*m13*m22;

    return m00*d1 - m10*d2 + m20*d3 - m30*d4;
}

float Matrix4x4::determinant(
    const float _m00, const float _m01, const float _m02, const float _m03,
    const float _m10, const float _m11, const float _m12, const float _m13,
    const float _m20, const float _m21, const float _m22, const float _m23,
    const float _m30, const float _m31, const float _m32, const float _m33
) {
    const float d1 = _m11*_m22*_m33 + _m12*_m23*_m31 + _m13*_m21*_m32 - _m13*_m22*_m31 - _m12*_m21*_m33 - _m11*_m23*_m32;
    const float d2 = _m01*_m22*_m33 + _m02*_m23*_m31 + _m03*_m21*_m32 - _m03*_m22*_m31 - _m02*_m21*_m33 - _m01*_m23*_m32;
    const float d3 = _m01*_m12*_m33 + _m02*_m13*_m31 + _m03*_m11*_m32 - _m03*_m12*_m31 - _m02*_m11*_m33 - _m01*_m13*_m32;
    const float d4 = _m01*_m12*_m23 + _m02*_m13*_m21 + _m03*_m11*_m33 - _m03*_m12*_m21 - _m02*_m11*_m23 - _m01*_m13*_m22;

    return _m00*d1 - _m10*d2 + _m20*d3 - _m30*d4;
}

Matrix4x4 Matrix4x4::scaleMatrix(const Vector3& _v) {
    return {
        _v.x, 0, 0, 0,
        0, _v.y, 0, 0,
        0, 0, _v.z, 0,
        0, 0, 0, 1
    };
}

Matrix4x4 Matrix4x4::translateMatrix(const Vector3& _v) {
    return {
        1, 0, 0, _v.x,
        0, 1, 0, _v.y,
        0, 0, 1, _v.z,
        0, 0, 0, 1
    };
}

Matrix4x4 Matrix4x4::rotateMatrix(const Quaternion& _q) {

    if(_q == Quaternion(0, 0, 0, 0)) { // TODO: Use Quaternion::zero?
        return identity();
    }

    return {
        _q.w * _q.w + _q.x * _q.x - _q.y * _q.y - _q.z * _q.z,
        2 * _q.x * _q.y - 2 * _q.w * _q.z,
        2 * _q.x * _q.z + 2 * _q.w * _q.y,
        0.0f,

        2 * _q.x * _q.y + 2 * _q.w * _q.z,
        _q.w * _q.w - _q.x * _q.x + _q.y * _q.y - _q.z * _q.z,
        2 * _q.y * _q.z - 2 * _q.w * _q.x,
        0.0f,

        2 * _q.x * _q.z - 2 * _q.w * _q.y,
        2 * _q.y * _q.z + 2 * _q.w * _q.x,
        _q.w * _q.w - _q.x * _q.x - _q.y * _q.y + _q.z * _q.z,
        0.0f,

        0.0f,
        0.0f,
        0.0f,
        1.0f
    };
}

Matrix4x4 Matrix4x4::zero() {
    return {
        0, 0, 0, 0,
        0, 0, 0, 0,
        0, 0, 0, 0,
        0, 0, 0, 0
    };
}

Matrix4x4 Matrix4x4::one() {
    return {
        1, 1, 1, 1,
        1, 1, 1, 1,
        1, 1, 1, 1,
        1, 1, 1, 1
    };
}

Matrix4x4 Matrix4x4::identity() {
    return {
        1, 0, 0, 0,
        0, 1, 0, 0,
        0, 0, 1, 0,
        0, 0, 0, 1
    };
}

Matrix4x4& Matrix4x4::operator+=(const Matrix4x4& _m) {
    *this = *this + _m;
    return *this;
}
Matrix4x4 operator+(const Matrix4x4& _lhs, const Matrix4x4& _rhs) {
    return {
        _lhs.m00 + _rhs.m00, _lhs.m01 + _rhs.m01, _lhs.m02 + _rhs.m02, _lhs.m03 + _rhs.m03,
        _lhs.m10 + _rhs.m10, _lhs.m11 + _rhs.m11, _lhs.m12 + _rhs.m12, _lhs.m13 + _rhs.m13,
        _lhs.m20 + _rhs.m20, _lhs.m21 + _rhs.m21, _lhs.m22 + _rhs.m22, _lhs.m23 + _rhs.m23,
        _lhs.m30 + _rhs.m30, _lhs.m31 + _rhs.m31, _lhs.m32 + _rhs.m32, _lhs.m33 + _rhs.m33,
    };
}

Matrix4x4& Matrix4x4::operator-=(const Matrix4x4& _m) {
    *this = *this - _m;
    return *this;
}
Matrix4x4 operator-(const Matrix4x4& _lhs, const Matrix4x4& _rhs) {
    return {
        _lhs.m00 - _rhs.m00, _lhs.m01 - _rhs.m01, _lhs.m02 - _rhs.m02, _lhs.m03 - _rhs.m03,
        _lhs.m10 - _rhs.m10, _lhs.m11 - _rhs.m11, _lhs.m12 - _rhs.m12, _lhs.m13 - _rhs.m13,
        _lhs.m20 - _rhs.m20, _lhs.m21 - _rhs.m21, _lhs.m22 - _rhs.m22, _lhs.m23 - _rhs.m23,
        _lhs.m30 - _rhs.m30, _lhs.m31 - _rhs.m31, _lhs.m32 - _rhs.m32, _lhs.m33 - _rhs.m33,
    };
}
Matrix4x4& Matrix4x4::operator-() {
    *this = -1 * *this;
    return *this;
}

Matrix4x4& Matrix4x4::operator*=(const Matrix4x4& _m) {
    *this = *this * _m;
    return *this;
}
Matrix4x4 operator*(const Matrix4x4& _lhs, const Matrix4x4& _rhs) {
    return {
        _lhs.m00 * _rhs.m00 + _lhs.m01 * _rhs.m10 + _lhs.m02 * _rhs.m20 + _lhs.m03 * _rhs.m30,
        _lhs.m00 * _rhs.m01 + _lhs.m01 * _rhs.m11 + _lhs.m02 * _rhs.m21 + _lhs.m03 * _rhs.m31,
        _lhs.m00 * _rhs.m02 + _lhs.m01 * _rhs.m12 + _lhs.m02 * _rhs.m22 + _lhs.m03 * _rhs.m32,
        _lhs.m00 * _rhs.m03 + _lhs.m01 * _rhs.m13 + _lhs.m02 * _rhs.m23 + _lhs.m03 * _rhs.m33,

        _lhs.m10 * _rhs.m00 + _lhs.m11 * _rhs.m10 + _lhs.m12 * _rhs.m20 + _lhs.m13 * _rhs.m30,
        _lhs.m10 * _rhs.m01 + _lhs.m11 * _rhs.m11 + _lhs.m12 * _rhs.m21 + _lhs.m13 * _rhs.m31,
        _lhs.m10 * _rhs.m02 + _lhs.m11 * _rhs.m12 + _lhs.m12 * _rhs.m22 + _lhs.m13 * _rhs.m32,
        _lhs.m10 * _rhs.m03 + _lhs.m11 * _rhs.m13 + _lhs.m12 * _rhs.m23 + _lhs.m13 * _rhs.m33,

        _lhs.m20 * _rhs.m00 + _lhs.m21 * _rhs.m10 + _lhs.m22 * _rhs.m20 + _lhs.m23 * _rhs.m30,
        _lhs.m20 * _rhs.m01 + _lhs.m21 * _rhs.m11 + _lhs.m22 * _rhs.m21 + _lhs.m23 * _rhs.m31,
        _lhs.m20 * _rhs.m02 + _lhs.m21 * _rhs.m12 + _lhs.m22 * _rhs.m22 + _lhs.m23 * _rhs.m32,
        _lhs.m20 * _rhs.m03 + _lhs.m21 * _rhs.m13 + _lhs.m22 * _rhs.m23 + _lhs.m23 * _rhs.m33,

        _lhs.m30 * _rhs.m00 + _lhs.m31 * _rhs.m10 + _lhs.m32 * _rhs.m20 + _lhs.m33 * _rhs.m30,
        _lhs.m30 * _rhs.m01 + _lhs.m31 * _rhs.m11 + _lhs.m32 * _rhs.m21 + _lhs.m33 * _rhs.m31,
        _lhs.m30 * _rhs.m02 + _lhs.m31 * _rhs.m12 + _lhs.m32 * _rhs.m22 + _lhs.m33 * _rhs.m32,
        _lhs.m30 * _rhs.m03 + _lhs.m31 * _rhs.m13 + _lhs.m32 * _rhs.m23 + _lhs.m33 * _rhs.m33
    };
}

Vector4 operator*(const Matrix4x4& _m, const Vector4& _v) {
    return {
        _m.m00 * _v.x + _m.m01 * _v.y + _m.m02 * _v.z + _m.m03 * _v.w,
        _m.m10 * _v.x + _m.m11 * _v.y + _m.m12 * _v.z + _m.m13 * _v.w,
        _m.m20 * _v.x + _m.m21 * _v.y + _m.m22 * _v.z + _m.m23 * _v.w,
        _m.m30 * _v.x + _m.m31 * _v.y + _m.m32 * _v.z + _m.m33 * _v.w
    };
}

Vector3 operator*(const Matrix4x4& _m, const Vector3& _v) {
    Vector4 v(_v, 1.0f);
    v = _m * v;
    return { v.x, v.y, v.z };
}

Matrix4x4& Matrix4x4::operator*=(const float _s) {
    *this = *this * _s;
    return *this;
}
Matrix4x4 operator*(const Matrix4x4& _m, const float _s) {
    return {
        _m.m00 * _s, _m.m01 * _s, _m.m02 * _s, _m.m03 * _s,
        _m.m10 * _s, _m.m11 * _s, _m.m12 * _s, _m.m13 * _s,
        _m.m20 * _s, _m.m21 * _s, _m.m22 * _s, _m.m23 * _s,
        _m.m30 * _s, _m.m31 * _s, _m.m32 * _s, _m.m33 * _s
    };
}
Matrix4x4 operator*(const float _s, const Matrix4x4& _m) {
    return _m * _s;
}

Matrix4x4& Matrix4x4::operator/=(const float _s) {
    *this = *this / _s;
    return *this;
}
Matrix4x4 operator/(const Matrix4x4& _m, const float _s) {
    return {
        _m.m00 / _s, _m.m01 / _s, _m.m02 / _s, _m.m03 / _s,
        _m.m10 / _s, _m.m11 / _s, _m.m12 / _s, _m.m13 / _s,
        _m.m20 / _s, _m.m21 / _s, _m.m22 / _s, _m.m23 / _s,
        _m.m30 / _s, _m.m31 / _s, _m.m32 / _s, _m.m33 / _s
    };
}

bool operator==(const Matrix4x4& _lhs, const Matrix4x4& _rhs) {
    for(size_t x = 0; x < 4; x++) {
        for(size_t y = 0; y < 4; y++) {
            if(!ZMath::isRelativelyEqual(_lhs[x][y], _rhs[x][y])) {
                return false;
            }
        }
    }
    return true;
}
bool operator!=(const Matrix4x4& _lhs, const Matrix4x4& _rhs) {
    return !(_lhs == _rhs);
}

Vector4 Matrix4x4::operator[](const size_t _i) const {
    return getRow(_i);
}