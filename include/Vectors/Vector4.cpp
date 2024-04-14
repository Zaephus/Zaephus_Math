
#include <iostream>
#include <format>

#include <Math.h>

Vector4::Vector4() {
    *this = zero();
}
Vector4::Vector4(const float _x, const float _y, const float _z, const float _w) {
    x = _x;
    y = _y;
    z = _z;
    w = _w;
}
Vector4::Vector4(const Vector4& _v) {
    x = _v.x;
    y = _v.y;
    z = _v.z;
    w = _v.w;
}
Vector4::Vector4(const Vector3& _v) {
    x = _v.x;
    y = _v.y;
    z = _v.z;
    w = 0;
}
Vector4::Vector4(const Vector3& _v, const float _w) {
    x = _v.x;
    y = _v.y;
    z = _v.z;
    w = _w;
}

[[nodiscard]] std::string Vector4::toString() const {
    return std::format("{}, {}, {}, {}", x, y, z, w);
}

[[nodiscard]] float Vector4::magnitude() const {
    return std::sqrt(x*x + y*y + z*z + w*w);
}
[[nodiscard]] float Vector4::squaredMagnitude() const {
    return x*x + y*y + z*z + w*w;
}

[[nodiscard]] Vector4 Vector4::normalized() const {
    Vector4 norm = Vector4(x, y, z, w);
    norm.normalize();
    return norm;
}
void Vector4::normalize() {
    *this /= magnitude();
}

float Vector4::distance(const Vector4& _lhs, const Vector4& _rhs) {
    return std::sqrt((_rhs.x - _lhs.x) * (_rhs.x - _lhs.x) + (_rhs.y - _lhs.y) * (_rhs.y - _lhs.y) + (_rhs.z - _lhs.z) * (_rhs.z - _lhs.z) + (_rhs.w - _lhs.w) * (_rhs.w - _lhs.w));
}

float Vector4::dot(const Vector4& _lhs, const Vector4& _rhs) {
    return _lhs.x * _rhs.x + _lhs.y * _rhs.y + _lhs.z * _rhs.z + _lhs.w * _rhs.w;
}

float Vector4::angle(const Vector4& _from, const Vector4& _to) {
    const float delta = dot(_from, _to);
    return std::acos(delta / (_from.magnitude() * _to.magnitude()));
}

Vector4 Vector4::zero() { return { 0.0f, 0.0f, 0.0f, 0.0f }; }
Vector4 Vector4::one()  { return { 1.0f, 1.0f, 1.0f, 1.0f }; }

Vector4& Vector4::operator+=(const Vector4& _v) {
    *this = *this + _v;
    return *this;
}
Vector4 operator+(const Vector4& _lhs, const Vector4& _rhs) {
    return {
        _lhs.x + _rhs.x,
        _lhs.y + _rhs.y,
        _lhs.z + _rhs.z,
        _lhs.w + _rhs.w
    };
}

Vector4& Vector4::operator-=(const Vector4& _v) {
    *this = *this + _v;
    return *this;
}
Vector4 operator-(const Vector4& _lhs, const Vector4& _rhs) {
    return {
        _lhs.x - _rhs.x,
        _lhs.y - _rhs.y,
        _lhs.z - _rhs.z,
        _lhs.w - _rhs.w
    };
}
Vector4 Vector4::operator-() {
    *this = -1 * *this;
    return *this;
}

Vector4& Vector4::operator*=(const float _s) {
    *this = *this * _s;
    return *this;
}
Vector4 operator*(const Vector4& _v, const float _s) {
    return {
        _v.x * _s,
        _v.y * _s,
        _v.z * _s,
        _v.w * _s
    };
}
Vector4 operator*(const float _s, const Vector4& _v) {
    return _v * _s;
}

Vector4& Vector4::operator/=(const float _s) {
    *this = *this / _s;
    return *this;
}
Vector4 operator/(const Vector4& _v, const float _s) {
    return {
        _v.x / _s,
        _v.y / _s,
        _v.z / _s,
        _v.w / _s
    };
}

bool operator==(const Vector4& _lhs, const Vector4& _rhs) {
    return _lhs.x == _rhs.x && _lhs.y == _rhs.y && _lhs.z == _rhs.z && _lhs.w == _rhs.w;
}
bool operator!=(const Vector4& _lhs, const Vector4& _rhs) {
    return !(_lhs == _rhs);
}

float Vector4::operator[](const size_t _i) const {
    switch(_i) {
        case 0: return x;
        case 1: return y;
        case 2: return z;
        case 3: return w;
        default: throw std::out_of_range("Invalid index.");
    }
}