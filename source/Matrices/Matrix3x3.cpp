
#include "Matrix3x3.h"

#include <iostream>
#include <format>

#include "../ZMath.h"

Matrix3x3::Matrix3x3() {
    *this = identity();
}

Matrix3x3::Matrix3x3(const Matrix3x3 &_m) {
    m00 = _m.m00; m01 = _m.m01; m02 = _m.m02;
    m10 = _m.m10; m11 = _m.m11; m12 = _m.m12;
    m20 = _m.m20; m21 = _m.m21; m22 = _m.m22;
}

Matrix3x3::Matrix3x3(const float _m[3][3]) {
    m00 = _m[0][0]; m01 = _m[0][1]; m02 = _m[0][2];
    m10 = _m[1][0]; m11 = _m[1][1]; m12 = _m[1][2];
    m20 = _m[2][0]; m21 = _m[2][1]; m22 = _m[2][2];
}

Matrix3x3::Matrix3x3(
    const float _m00, const float _m01, const float _m02,
    const float _m10, const float _m11, const float _m12,
    const float _m20, const float _m21, const float _m22
) {
    m00 = _m00; m01 = _m01; m02 = _m02;
    m10 = _m10; m11 = _m11; m12 = _m12;
    m20 = _m20; m21 = _m21; m22 = _m22;
}

Matrix3x3::Matrix3x3(const Vector3& _row0, const Vector3& _row1, const Vector3& _row2) {
    m00 = _row0.x; m01 = _row0.y; m02 = _row0.z;
    m10 = _row1.x; m11 = _row1.y; m12 = _row1.z;
    m20 = _row2.x; m21 = _row2.y; m22 = _row2.z;
}

[[nodiscard]] Vector3 Matrix3x3::getRow(const size_t _index) const {
    switch(_index) {
        case 0:
            return { m00, m01, m02 };
        case 1:
            return { m10, m11, m12 };
        case 2:
            return { m20, m21, m22 };
        default:
            throw std::out_of_range("Invalid row index.");
    }
}

[[nodiscard]] Vector3 Matrix3x3::getColumn(const size_t _index) const {
    switch(_index) {
        case 0:
            return { m00, m10, m20 };
        case 1:
            return { m01, m11, m21 };
        case 2:
            return { m02, m12, m22 };
        default:
            throw std::out_of_range("Invalid column index.");
    }
}

void Matrix3x3::setRow(const size_t _index, const Vector3& _row) {
    switch(_index) {
        case 0:
            m00 = _row.x; m01 = _row.y; m02 = _row.z;
            break;
        case 1:
            m10 = _row.x; m11 = _row.y; m12 = _row.z;
            break;
        case 2:
            m20 = _row.x; m21 = _row.y; m22 = _row.z;
            break;
        default:
            throw std::out_of_range("Invalid row index.");
    }
}

void Matrix3x3::setColumn(const size_t _index, const Vector3& _column) {
    switch(_index) {
        case 0:
            m00 = _column.x; m10 = _column.y; m20 = _column.z;
            break;
        case 1:
            m01 = _column.x; m11 = _column.y; m21 = _column.z;
            break;
        case 2:
            m02 = _column.x; m12 = _column.y; m22 = _column.z;
            break;
        default:
            throw std::out_of_range("Invalid row index.");
    }
}

[[nodiscard]] std::string Matrix3x3::toString() const {
    return std::format("{}, {}, {},\n{}, {}, {},\n{}, {}, {}", m00, m01, m02, m10, m11, m12, m20, m21, m22);
}

[[nodiscard]] Matrix3x3 Matrix3x3::inverse() const {
    Matrix3x3 i = *this;
    i.invert();
    return i;
}

void Matrix3x3::invert() {

    if(determinant() == 0) {
        std::cout << "Determinant is zero, this matrix cannot be inverted." << std::endl;
        return;
    }

    const float a00 = m11*m22 - m12*m21;
    const float a01 = m10*m22 - m12*m20;
    const float a02 = m10*m21 - m11*m20;

    const float a10 = m01*m22 - m02*m21;
    const float a11 = m00*m22 - m02*m20;
    const float a12 = m00*m21 - m01*m20;

    const float a20 = m01*m12 - m02*m11;
    const float a21 = m00*m12 - m02*m10;
    const float a22 = m00*m11 - m01*m10;

    Matrix3x3 adjugate = {
        a00, -a01, a02,
        -a10, a11, -a12,
        a20, -a21, a22
    };
    adjugate.transpose();

    *this = adjugate / determinant();

}

[[nodiscard]] Matrix3x3 Matrix3x3::transposed() const {
    Matrix3x3 t = *this;
    t.transpose();
    return t;
}

void Matrix3x3::transpose() {
    *this = {
        m00, m10, m20,
        m01, m11, m21,
        m02, m12, m22
    };
}

[[nodiscard]] float Matrix3x3::determinant() const {
    const float d1 = m11*m22 - m12*m21;
    const float d2 = m10*m22 - m12*m20;
    const float d3 = m10*m21 - m11*m20;

    return m00*d1 - m01*d2 + m02*d3;
}

float Matrix3x3::determinant(
    const float _m00, const float _m01, const float _m02,
    const float _m10, const float _m11, const float _m12,
    const float _m20, const float _m21, const float _m22
) {
    const float d1 = _m11*_m22 - _m12*_m21;
    const float d2 = _m10*_m22 - _m12*_m20;
    const float d3 = _m10*_m21 - _m11*_m20;

    return _m00*d1 - _m01*d2 + _m02*d3;
}

Matrix3x3 Matrix3x3::zero() {
    return {
        0, 0, 0,
        0, 0, 0,
        0, 0, 0
    };
}

Matrix3x3 Matrix3x3::one() {
    return {
        1, 1, 1,
        1, 1, 1,
        1, 1, 1
    };
}

Matrix3x3 Matrix3x3::identity() {
    return {
        1, 0, 0,
        0, 1, 0,
        0, 0, 1
    };
}

void Matrix3x3::operator+=(const Matrix3x3& _m) {
    *this = *this + _m;
}
Matrix3x3 Matrix3x3::operator+(const Matrix3x3& _m) const {
    return {
        m00 + _m.m00, m01 + _m.m01, m02 + _m.m02,
        m10 + _m.m10, m11 + _m.m11, m12 + _m.m12,
        m20 + _m.m20, m21 + _m.m21, m22 + _m.m22
    };
}

void Matrix3x3::operator-=(const Matrix3x3& _m) {
    *this = *this - _m;
}
Matrix3x3 Matrix3x3::operator-(const Matrix3x3& _m) const {
    return {
        m00 - _m.m00, m01 - _m.m01, m02 - _m.m02,
        m10 - _m.m10, m11 - _m.m11, m12 - _m.m12,
        m20 - _m.m20, m21 - _m.m21, m22 - _m.m22
    };
}
Matrix3x3 Matrix3x3::operator-() const {
    return {
        -m00, -m01, -m02,
        -m10, -m11, -m12,
        -m20, -m21, -m22
    };
}

void Matrix3x3::operator*=(const Matrix3x3& _m) {
    *this = *this * _m;
}
Matrix3x3 Matrix3x3::operator*(const Matrix3x3& _m) const {
    return {
        m00 * _m.m00 + m01 * _m.m10 + m02 * _m.m20,
        m00 * _m.m01 + m01 * _m.m11 + m02 * _m.m21,
        m00 * _m.m02 + m01 * _m.m12 + m02 * _m.m22,

        m10 * _m.m00 + m11 * _m.m10 + m12 * _m.m20,
        m10 * _m.m01 + m11 * _m.m11 + m12 * _m.m21,
        m10 * _m.m02 + m11 * _m.m12 + m12 * _m.m22,

        m20 * _m.m00 + m21 * _m.m10 + m22 * _m.m20,
        m20 * _m.m01 + m21 * _m.m11 + m22 * _m.m21,
        m20 * _m.m02 + m21 * _m.m12 + m22 * _m.m22
    };
}

Vector3 Matrix3x3::operator*(const Vector3& _v) const {
    return {
        m00 * _v.x + m01 * _v.y + m02 * _v.z,
        m10 * _v.x + m11 * _v.y + m12 * _v.z,
        m20 * _v.x + m21 * _v.y + m22 * _v.z
    };
}

void Matrix3x3::operator*=(const float _s) {
    *this = *this * _s;
}
Matrix3x3 Matrix3x3::operator*(const float _s) const {
    return {
        m00 * _s, m01 * _s, m02 * _s,
        m10 * _s, m11 * _s, m12 * _s,
        m20 * _s, m21 * _s, m22 * _s
    };
}
Matrix3x3 operator*(const float _s, const Matrix3x3& _m) {
    return _m * _s;
}

void Matrix3x3::operator/=(const float _s) {
    *this = *this / _s;
}
Matrix3x3 Matrix3x3::operator/(const float _s) const {
    return {
        m00 / _s, m01 / _s, m02 / _s,
        m10 / _s, m11 / _s, m12 / _s,
        m20 / _s, m21 / _s, m22 / _s
    };
}

bool Matrix3x3::operator==(const Matrix3x3& _m) const {
    return ZMath::isApproxEqual(m00, _m.m00) &&
           ZMath::isApproxEqual(m01, _m.m01) &&
           ZMath::isApproxEqual(m02, _m.m02) &&
           ZMath::isApproxEqual(m10, _m.m10) &&
           ZMath::isApproxEqual(m11, _m.m11) &&
           ZMath::isApproxEqual(m12, _m.m12) &&
           ZMath::isApproxEqual(m20, _m.m20) &&
           ZMath::isApproxEqual(m21, _m.m21) &&
           ZMath::isApproxEqual(m22, _m.m22);
}
bool Matrix3x3::operator!=(const Matrix3x3& _m) const {
    return !(*this == _m);
}

Vector3 Matrix3x3::operator[](const size_t _i) const {
    return getRow(_i);
}