
#include "Matrix2x2.h"

#include <iostream>
#include <format>

#include "../ZMath.h"

Matrix2x2::Matrix2x2() {
    *this = identity();
}

Matrix2x2::Matrix2x2(const Matrix2x2 &_m) {
    m00 = _m.m00; m01 = _m.m01;
    m10 = _m.m10; m11 = _m.m11;
}

Matrix2x2::Matrix2x2(const float _m[2][2]) {
    m00 = _m[0][0]; m01 = _m[0][1];
    m10 = _m[1][0]; m11 = _m[1][1];
}

Matrix2x2::Matrix2x2(
    const float _m00, const float _m01,
    const float _m10, const float _m11
) {
    m00 = _m00; m01 = _m01;
    m10 = _m10; m11 = _m11;
}

Matrix2x2::Matrix2x2(const Vector2& _row0, const Vector2& _row1) {
    m00 = _row0.x; m01 = _row0.y;
    m10 = _row1.x; m11 = _row1.y;
}

[[nodiscard]] std::string Matrix2x2::toString() const {
    return std::format("{}, {},\n{}, {}", m00, m01, m10, m11);
}

[[nodiscard]] Vector2 Matrix2x2::getRow(const size_t _index) const {
    switch(_index) {
        case 0:
            return { m00, m01 };
        case 1:
            return { m10, m11 };
        default:
            throw std::out_of_range("Invalid row index.");
    }
}

[[nodiscard]] Vector2 Matrix2x2::getColumn(const size_t _index) const {
    switch(_index) {
        case 0:
            return { m00, m10 };
        case 1:
            return { m01, m11 };
        default:
            throw std::out_of_range("Invalid column index.");
    }
}

void Matrix2x2::setRow(const size_t _index, const Vector2& _row) {
    switch(_index) {
        case 0:
            m00 = _row.x; m01 = _row.y;
            break;
        case 1:
            m10 = _row.x; m11 = _row.y;
            break;
        default:
            throw std::out_of_range("Invalid row index.");
    }
}

void Matrix2x2::setColumn(const size_t _index, const Vector2& _column) {
    switch(_index) {
        case 0:
            m00 = _column.x; m10 = _column.y;
            break;
        case 1:
            m01 = _column.x; m11 = _column.y;
            break;
        default:
            throw std::out_of_range("Invalid row index.");
    }
}

[[nodiscard]] Matrix2x2 Matrix2x2::inverse() const {
    Matrix2x2 i = *this;
    i.invert();
    return i;
}

void Matrix2x2::invert() {
    if(determinant() == 0) {
        std::cout << "Determinant is zero, this matrix cannot be inverted." << std::endl;
        return;
    }

    const Matrix2x2 adjugate = {
        m11, -m01,
        -m10, m00
    };

    *this = adjugate / determinant();
}

[[nodiscard]] Matrix2x2 Matrix2x2::transposed() const {
    Matrix2x2 t = *this;
    t.transpose();
    return t;
}

void Matrix2x2::transpose() {
    *this = {
        m00, m10,
        m01, m11
    };
}

[[nodiscard]] float Matrix2x2::determinant() const {
    return m00 * m11 - m01 * m10;
}

float Matrix2x2::determinant(
    const float _m00, const float _m01,
    const float _m10, const float _m11
) {
    return _m00 * _m11 - _m01 * _m10;
}

Matrix2x2 Matrix2x2::zero() {
    return {
        0, 0,
        0, 0
    };
}

Matrix2x2 Matrix2x2::one() {
    return {
        1, 1,
        1, 1
    };
}

Matrix2x2 Matrix2x2::identity() {
    return {
        1, 0,
        0, 1
    };
}

void Matrix2x2::operator+=(const Matrix2x2& _m) {
    *this = *this + _m;
}
Matrix2x2 Matrix2x2::operator+(const Matrix2x2& _m) const {
    return {
        m00 + _m.m00, m01 + _m.m01,
        m10 + _m.m10, m11 + _m.m11
    };
}

void Matrix2x2::operator-=(const Matrix2x2& _m) {
    *this = *this - _m;
}
Matrix2x2 Matrix2x2::operator-(const Matrix2x2& _m) const {
    return {
        m00 - _m.m00, m01 - _m.m01,
        m10 - _m.m10, m11 - _m.m11
    };
}
Matrix2x2 Matrix2x2::operator-() const {
    return {
        -m00, -m01,
        -m10, -m11
    };
}

void Matrix2x2::operator*=(const Matrix2x2& _m) {
    *this = *this * _m;
}
Matrix2x2 Matrix2x2::operator*(const Matrix2x2& _m) const {
    return {
        m00 * _m.m00 + m01 * _m.m10,
        m00 * _m.m01 + m01 * _m.m11,

        m10 * _m.m00 + m11 * _m.m10,
        m10 * _m.m01 + m11 * _m.m11
    };
}

Vector2 Matrix2x2::operator*(const Vector2& _v) const {
    return {
        m00 * _v.x + m01 * _v.y,
        m10 * _v.x + m11 * _v.y
    };
}

void Matrix2x2::operator*=(const float _s) {
    *this = *this * _s;
}
Matrix2x2 Matrix2x2::operator*(const float _s) const {
    return {
        m00 * _s, m01 * _s,
        m10 * _s, m11 * _s
    };
}
Matrix2x2 operator*(const float _s, const Matrix2x2& _m) {
    return _m * _s;
}

void Matrix2x2::operator/=(const float _s) {
    *this = *this / _s;
}
Matrix2x2 Matrix2x2::operator/(const float _s) const {
    return {
        m00 / _s, m01 / _s,
        m10 / _s, m11 / _s
    };
}

bool Matrix2x2::operator==(const Matrix2x2& _m) const {
    return ZMath::isApproxEqual(m00, _m.m00) &&
           ZMath::isApproxEqual(m01, _m.m01) &&
           ZMath::isApproxEqual(m10, _m.m10) &&
           ZMath::isApproxEqual(m11, _m.m11);
}
bool Matrix2x2::operator!=(const Matrix2x2& _m) const {
    return !(*this == _m);
}

Vector2 Matrix2x2::operator[](const size_t _i) const {
    return getRow(_i);
}