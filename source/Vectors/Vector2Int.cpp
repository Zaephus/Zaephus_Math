
#include <iostream>
#include <format>

#include "../ZMath.h"

Vector2Int::Vector2Int() {
    *this = zero();
}

Vector2Int::Vector2Int(const int _x, const int _y) {
    x = _x;
    y = _y;
}

Vector2Int::Vector2Int(const Vector2Int& _v) {
    x = _v.x;
    y = _v.y;
}

[[nodiscard]] std::string Vector2Int::toString() const {
    return std::format("{}, {}", x, y);
}

[[nodiscard]] float Vector2Int::magnitude() const {
    return (float)std::sqrt(x*x + y*y);
}

[[nodiscard]] int Vector2Int::squaredMagnitude() const {
    return x*x + y*y;
}

[[nodiscard]] Vector2Int Vector2Int::normalized() const {
    Vector2Int norm = Vector2Int(x, y);
    norm.normalize();
    return norm;
}

void Vector2Int::normalize() {
    *this /= (int)std::round(magnitude());
}

float Vector2Int::distance(const Vector2Int& _lhs, const Vector2Int& _rhs) {
    return (float)std::sqrt((_rhs.x - _lhs.x) * (_rhs.x - _lhs.x) + (_rhs.y - _lhs.y) * (_rhs.y - _lhs.y));
}

int Vector2Int::dot(const Vector2Int& _lhs, const Vector2Int& _rhs) {
    return _lhs.x * _rhs.x + _lhs.y * _rhs.y;
}

int Vector2Int::cross(const Vector2Int& _lhs, const Vector2Int& _rhs) {
    return _lhs.y * _rhs.x - _lhs.x * _rhs.y;
}

float Vector2Int::angle(const Vector2Int& _from, const Vector2Int& _to) {
    const float delta = (float)dot(_from, _to);
    return std::acos(delta / (_from.magnitude() * _to.magnitude()));
}

Vector2Int Vector2Int::zero()  { return { 0,  0 }; }
Vector2Int Vector2Int::one()   { return { 1,  1 }; }
Vector2Int Vector2Int::right() { return { 1,  0 }; }
Vector2Int Vector2Int::left()  { return { -1, 0 }; }
Vector2Int Vector2Int::up()    { return { 0,  1 }; }
Vector2Int Vector2Int::down()  { return { 0, -1 }; }

Vector2Int& Vector2Int::operator+=(const Vector2Int& _v) {
    *this = *this + _v;
    return *this;
}
Vector2Int operator+(const Vector2Int& _lhs, const Vector2Int& _rhs) {
    return {
        _lhs.x + _rhs.x,
        _lhs.y + _rhs.y
    };
}

Vector2Int& Vector2Int::operator-=(const Vector2Int& _v) {
    *this = *this - _v;
    return *this;
}
Vector2Int operator-(const Vector2Int& _lhs, const Vector2Int& _rhs) {
    return {
        _lhs.x - _rhs.x,
        _lhs.y - _rhs.y
    };
}
Vector2Int Vector2Int::operator-() {
    *this = -1 * *this;
    return *this;
}

Vector2Int& Vector2Int::operator*=(const int _s) {
    *this = *this * _s;
    return *this;
}
Vector2Int operator*(const Vector2Int& _v, const int _s) {
    return {
        _v.x * _s,
        _v.y * _s
    };
}
Vector2Int operator*(const int _s, const Vector2Int& _v) {
    return _v * _s;
}

Vector2Int& Vector2Int::operator/=(const int _s) {
    *this = *this / _s;
    return *this;
}
Vector2Int operator/(const Vector2Int& _v, const int _s) {
    return {
        _v.x / _s,
        _v.y / _s
    };
}

bool operator==(const Vector2Int& _lhs, const Vector2Int& _rhs) {
    return ZMath::isRelativelyEqual(_lhs.x, _rhs.x) && ZMath::isRelativelyEqual(_lhs.y, _rhs.y);
}
bool operator!=(const Vector2Int& _lhs, const Vector2Int& _rhs) {
    return !(_lhs == _rhs);
}

int Vector2Int::operator[](const size_t _i) const {
    switch(_i) {
        case 0: return x;
        case 1: return y;
        default: throw std::out_of_range("Invalid index.");
    }
}