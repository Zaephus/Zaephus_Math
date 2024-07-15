
#include <iostream>
#include <format>

#include <Math.h>

Vector4Int::Vector4Int() {
    *this = zero();
}
Vector4Int::Vector4Int(const int _x, const int _y, const int _z, const int _w) {
    x = _x;
    y = _y;
    z = _z;
    w = _w;
}
Vector4Int::Vector4Int(const Vector4Int& _v) {
    x = _v.x;
    y = _v.y;
    z = _v.z;
    w = _v.w;
}
Vector4Int::Vector4Int(const Vector3Int& _v) {
    x = _v.x;
    y = _v.y;
    z = _v.z;
    w = 0;
}
Vector4Int::Vector4Int(const Vector3Int& _v, const int _w) {
    x = _v.x;
    y = _v.y;
    z = _v.z;
    w = _w;
}

[[nodiscard]] std::string Vector4Int::toString() const {
    return std::format("{}, {}, {}, {}", x, y, z, w);
}

[[nodiscard]] float Vector4Int::magnitude() const {
    return (float)std::sqrt(x*x + y*y + z*z + w*w);
}
[[nodiscard]] int Vector4Int::squaredMagnitude() const {
    return x*x + y*y + z*z + w*w;
}

[[nodiscard]] Vector4Int Vector4Int::normalized() const {
    Vector4Int norm = Vector4Int(x, y, z, w);
    norm.normalize();
    return norm;
}
void Vector4Int::normalize() {
    *this /= (int)std::round(magnitude());
}

float Vector4Int::distance(const Vector4Int& _lhs, const Vector4Int& _rhs) {
    return (float)std::sqrt((_rhs.x - _lhs.x) * (_rhs.x - _lhs.x) + (_rhs.y - _lhs.y) * (_rhs.y - _lhs.y) + (_rhs.z - _lhs.z) * (_rhs.z - _lhs.z) + (_rhs.w - _lhs.w) * (_rhs.w - _lhs.w));
}

int Vector4Int::dot(const Vector4Int& _lhs, const Vector4Int& _rhs) {
    return _lhs.x * _rhs.x + _lhs.y * _rhs.y + _lhs.z * _rhs.z + _lhs.w * _rhs.w;
}

float Vector4Int::angle(const Vector4Int& _from, const Vector4Int& _to) {
    const float delta = (float)dot(_from, _to);
    return std::acos(delta / (_from.magnitude() * _to.magnitude()));
}

Vector4Int Vector4Int::zero() { return { 0, 0, 0, 0 }; }
Vector4Int Vector4Int::one()  { return { 1, 1, 1, 1 }; }

Vector4Int& Vector4Int::operator+=(const Vector4Int& _v) {
    *this = *this + _v;
    return *this;
}
Vector4Int operator+(const Vector4Int& _lhs, const Vector4Int& _rhs) {
    return {
        _lhs.x + _rhs.x,
        _lhs.y + _rhs.y,
        _lhs.z + _rhs.z,
        _lhs.w + _rhs.w
    };
}

Vector4Int& Vector4Int::operator-=(const Vector4Int& _v) {
    *this = *this + _v;
    return *this;
}
Vector4Int operator-(const Vector4Int& _lhs, const Vector4Int& _rhs) {
    return {
        _lhs.x - _rhs.x,
        _lhs.y - _rhs.y,
        _lhs.z - _rhs.z,
        _lhs.w - _rhs.w
    };
}
Vector4Int Vector4Int::operator-() {
    *this = -1 * *this;
    return *this;
}

Vector4Int& Vector4Int::operator*=(const int _s) {
    *this = *this * _s;
    return *this;
}
Vector4Int operator*(const Vector4Int& _v, const int _s) {
    return {
        _v.x * _s,
        _v.y * _s,
        _v.z * _s,
        _v.w * _s
    };
}
Vector4Int operator*(const int _s, const Vector4Int& _v) {
    return _v * _s;
}

Vector4Int& Vector4Int::operator/=(const int _s) {
    *this = *this / _s;
    return *this;
}
Vector4Int operator/(const Vector4Int& _v, const int _s) {
    return {
        _v.x / _s,
        _v.y / _s,
        _v.z / _s,
        _v.w / _s
    };
}

bool operator==(const Vector4Int& _lhs, const Vector4Int& _rhs) {
    return _lhs.x == _rhs.x && _lhs.y == _rhs.y && _lhs.z == _rhs.z && _lhs.w == _rhs.w;
}
bool operator!=(const Vector4Int& _lhs, const Vector4Int& _rhs) {
    return !(_lhs == _rhs);
}

int Vector4Int::operator[](const size_t _i) const {
    switch(_i) {
        case 0: return x;
        case 1: return y;
        case 2: return z;
        case 3: return w;
        default: throw std::out_of_range("Invalid index.");
    }
}