
#include "Vector2.h"

#include <format>

#include "../ZMath.h"

Vector2 Vector2::zero  = { 0.0f,  0.0f };
Vector2 Vector2::one   = { 1.0f,  1.0f };
Vector2 Vector2::right = { 1.0f,  0.0f };
Vector2 Vector2::left  = { -1.0f, 0.0f };
Vector2 Vector2::up    = { 0.0f,  1.0f };
Vector2 Vector2::down  = { 0.0f, -1.0f };

Vector2::Vector2() {
    *this = zero;
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
    const float mag = magnitude();
    if(mag == 0.0f) { return; }

    *this /= mag;
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

void Vector2::operator+=(const Vector2& _v) {
    *this = *this + _v;
}
Vector2 Vector2::operator+(const Vector2& _v) const {
    return {
        x + _v.x,
        y + _v.y
    };
}

void Vector2::operator-=(const Vector2& _v) {
    *this = *this - _v;
}
Vector2 Vector2::operator-(const Vector2& _v) const {
    return {
        x - _v.x,
        y - _v.y
    };
}
Vector2 Vector2::operator-() const {
    return {
        -x,
        -y
    };
}

void Vector2::operator*=(const float _s) {
    *this = *this * _s;
}
Vector2 Vector2::operator*(const float _s) const {
    return {
        x * _s,
        y * _s
    };
}

void Vector2::operator/=(const float _s) {
    *this = *this / _s;
}
Vector2 Vector2::operator/(const float _s) const {
    return {
        x / _s,
        y / _s
    };
}

bool Vector2::operator==(const Vector2& _v) const {
    return ZMath::isRelativelyEqual(x, _v.x) && ZMath::isRelativelyEqual(y, _v.y);
}
bool Vector2::operator!=(const Vector2& _v) const {
    return !(*this == _v);
}

float Vector2::operator[](const size_t _i) const {
    switch(_i) {
        case 0: return x;
        case 1: return y;
        default: throw std::out_of_range("Invalid index.");
    }
}