
#include <iostream>
#include <format>

#include "../ZMath.h"

Vector3Int::Vector3Int() {
    *this = zero();
}
Vector3Int::Vector3Int(const int _x, const int _y, const int _z) {
    x = _x;
    y = _y;
    z = _z;
}
Vector3Int::Vector3Int(const Vector3Int& _v) {
    x = _v.x;
    y = _v.y;
    z = _v.z;
}

[[nodiscard]] std::string Vector3Int::toString() const {
    return std::format("{}, {}, {}", x, y, z);
}

[[nodiscard]] float Vector3Int::magnitude() const {
    return (float)std::sqrt(x*x + y*y + z*z);
}
[[nodiscard]] int Vector3Int::squaredMagnitude() const {
    return x*x + y*y + z*z;
}

[[nodiscard]] Vector3Int Vector3Int::normalized() const {
    Vector3Int norm = Vector3Int(x, y, z);
    norm.normalize();
    return norm;
}
void Vector3Int::normalize() {
    *this /= (int)std::round(magnitude());
}

float Vector3Int::distance(const Vector3Int& _lhs, const Vector3Int& _rhs) {
    return (float)std::sqrt((_rhs.x - _lhs.x) * (_rhs.x - _lhs.x) + (_rhs.y - _lhs.y) * (_rhs.y - _lhs.y) + (_rhs.z - _lhs.z) * (_rhs.z - _lhs.z));
}

int Vector3Int::dot(const Vector3Int& _lhs, const Vector3Int& _rhs) {
    return _lhs.x * _rhs.x + _lhs.y * _rhs.y + _lhs.z * _rhs.z;
}

Vector3Int Vector3Int::cross(const Vector3Int& _lhs, const Vector3Int& _rhs) {
    return {
        _lhs.y * _rhs.z - _lhs.z * _rhs.y,
        _lhs.z * _rhs.x - _lhs.x * _rhs.z,
        _lhs.x * _rhs.y - _lhs.y * _rhs.x
    };
}

float Vector3Int::angle(Vector3Int const& _from, Vector3Int const& _to) {
    const float delta = (float)dot(_from, _to);
    return std::acos(delta / (_from.magnitude() * _to.magnitude()));
}

Vector3Int Vector3Int::zero()    { return { 0,  0,  0  }; }
Vector3Int Vector3Int::one()     { return { 1,  1,  1  }; }
Vector3Int Vector3Int::right()   { return { 1,  0,  0  }; }
Vector3Int Vector3Int::left()    { return { -1, 0,  0  }; }
Vector3Int Vector3Int::upVector()      { return { 0,  1,  0  }; }
Vector3Int Vector3Int::down()    { return { 0,  -1, 0  }; }
Vector3Int Vector3Int::forward() { return { 0,  0,  1  }; }
Vector3Int Vector3Int::back()    { return { 0,  0,  -1 }; }

Vector3Int& Vector3Int::operator+=(const Vector3Int& _v) {
    *this = *this + _v;
    return *this;
}
Vector3Int operator+(const Vector3Int& _lhs, const Vector3Int& _rhs) {
    return {
        _lhs.x + _rhs.x,
        _lhs.y + _rhs.y,
        _lhs.z + _rhs.z
    };
}

Vector3Int& Vector3Int::operator-=(const Vector3Int& _v) {
    *this = *this - _v;
    return *this;
}
Vector3Int operator-(const Vector3Int& _lhs, const Vector3Int& _rhs) {
    return {
        _lhs.x - _rhs.x,
        _lhs.y - _rhs.y,
        _lhs.z - _rhs.z
    };
}
Vector3Int Vector3Int::operator-() {
    *this = -1 * *this;
    return *this;
}

Vector3Int& Vector3Int::operator*=(const int _s) {
    *this = *this * _s;
    return *this;
}
Vector3Int operator*(const Vector3Int& _v, const int _s) {
    return {
        _v.x * _s,
        _v.y * _s,
        _v.z * _s
    };
}
Vector3Int operator*(const int _s, const Vector3Int& _v) {
    return _v * _s;
}

Vector3Int& Vector3Int::operator/=(const int _s) {
    *this = *this / _s;
    return *this;
}
Vector3Int operator/(const Vector3Int& _v, const int _s) {
    return {
        _v.x / _s,
        _v.y / _s,
        _v.z / _s
    };
}

bool operator==(const Vector3Int& _lhs, const Vector3Int& _rhs) {
    return ZMath::isRelativelyEqual(_lhs.x, _rhs.x) && ZMath::isRelativelyEqual(_lhs.y, _rhs.y) && ZMath::isRelativelyEqual(_lhs.z, _rhs.z);
}
bool operator!=(const Vector3Int& _lhs, const Vector3Int& _rhs) {
    return !(_lhs == _rhs);
}

int Vector3Int::operator[](const size_t _i) const {
    switch(_i) {
        case 0: return x;
        case 1: return y;
        case 2: return z;
        default: throw std::out_of_range("Invalid index.");
    }
}