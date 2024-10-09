
#include <iostream>
#include <format>

#include "../ZMath.h"

Vector2::Vector2() {
    *this = zero();
}

Vector2::Vector2(const float _x, const float _y) {
    x = _x;
    y = _y;
}

Vector2::Vector2(const Vector2& _v) {
    x = _v.x;
    y = _v.y;
}

[[nodiscard]] std::string Vector2::toString() const {
    return std::format("{}, {}", x, y);
}

[[nodiscard]] float Vector2::magnitude() const {
    return std::sqrt(x*x + y*y);
}

[[nodiscard]] float Vector2::squaredMagnitude() const {
    return x*x + y*y;
}

[[nodiscard]] Vector2 Vector2::normalized() const {
    Vector2 norm = Vector2(x, y);
    norm.normalize();
    return norm;
}

void Vector2::normalize() {
    *this /= magnitude();
}

float Vector2::distance(const Vector2& _lhs, const Vector2& _rhs) {
    return std::sqrt((_rhs.x - _lhs.x) * (_rhs.x - _lhs.x) + (_rhs.y - _lhs.y) * (_rhs.y - _lhs.y));
}

float Vector2::dot(const Vector2& _lhs, const Vector2& _rhs) {
    return _lhs.x * _rhs.x + _lhs.y * _rhs.y;
}

float Vector2::cross(const Vector2& _lhs, const Vector2& _rhs) {
    return _lhs.y * _rhs.x - _lhs.x * _rhs.y;
}

float Vector2::angle(const Vector2& _from, const Vector2& _to) {
    const float delta = dot(_from, _to);
    return std::acos(delta / (_from.magnitude() * _to.magnitude()));
}

Vector2 Vector2::zero()  { return { 0.0f,  0.0f }; }
Vector2 Vector2::one()   { return { 1.0f,  1.0f }; }
Vector2 Vector2::right() { return { 1.0f,  0.0f }; }
Vector2 Vector2::left()  { return { -1.0f, 0.0f }; }
Vector2 Vector2::up()    { return { 0.0f,  1.0f }; }
Vector2 Vector2::down()  { return { 0.0f, -1.0f }; }

Vector2& Vector2::operator+=(const Vector2& _v) {
    *this = *this + _v;
    return *this;
}
Vector2 operator+(const Vector2& _lhs, const Vector2& _rhs) {
    return {
        _lhs.x + _rhs.x,
        _lhs.y + _rhs.y
    };
}

Vector2& Vector2::operator-=(const Vector2& _v) {
    *this = *this - _v;
    return *this;
}
Vector2 operator-(const Vector2& _lhs, const Vector2& _rhs) {
    return {
        _lhs.x - _rhs.x,
        _lhs.y - _rhs.y
    };
}
Vector2 Vector2::operator-() {
    *this = -1 * *this;
    return *this;
}

Vector2& Vector2::operator*=(const float _s) {
    *this = *this * _s;
    return *this;
}
Vector2 operator*(const Vector2& _v, const float _s) {
    return {
        _v.x * _s,
        _v.y * _s
    };
}
Vector2 operator*(const float _s, const Vector2& _v) {
    return _v * _s;
}

Vector2& Vector2::operator/=(const float _s) {
    *this = *this / _s;
    return *this;
}
Vector2 operator/(const Vector2& _v, const float _s) {
    return {
        _v.x / _s,
        _v.y / _s
    };
}

bool operator==(const Vector2& _lhs, const Vector2& _rhs) {
    return _lhs.x == _rhs.x && _lhs.y == _rhs.y;
}
bool operator!=(const Vector2& _lhs, const Vector2& _rhs) {
    return !(_lhs == _rhs);
}

float Vector2::operator[](const size_t _i) const {
    switch(_i) {
        case 0: return x;
        case 1: return y;
        default: throw std::out_of_range("Invalid index.");
    }
}