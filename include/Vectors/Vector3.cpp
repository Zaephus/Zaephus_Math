
#include <iostream>
#include <format>

#include <Math.h>

Vector3::Vector3() {
    *this = zero();
}
Vector3::Vector3(const float _x, const float _y, const float _z) {
    x = _x;
    y = _y;
    z = _z;
}
Vector3::Vector3(const Vector3& _v) {
    x = _v.x;
    y = _v.y;
    z = _v.z;
}

[[nodiscard]] std::string Vector3::toString() const {
    return std::format("{}, {}, {}", x, y, z);
}

[[nodiscard]] float Vector3::magnitude() const {
    return std::sqrt(x*x + y*y + z*z);
}
[[nodiscard]] float Vector3::squaredMagnitude() const {
    return x*x + y*y + z*z;
}

[[nodiscard]] Vector3 Vector3::normalized() const {
    Vector3 norm = Vector3(x, y, z);
    norm.normalize();
    return norm;
}
void Vector3::normalize() {
    *this /= magnitude();
}

float Vector3::distance(const Vector3& _lhs, const Vector3& _rhs) {
    return std::sqrt((_rhs.x - _lhs.x) * (_rhs.x - _lhs.x) + (_rhs.y - _lhs.y) * (_rhs.y - _lhs.y) + (_rhs.z - _lhs.z) * (_rhs.z - _lhs.z));
}

float Vector3::dot(const Vector3& _lhs, const Vector3& _rhs) {
    return _lhs.x * _rhs.x + _lhs.y * _rhs.y + _lhs.z * _rhs.z;
}

Vector3 Vector3::cross(const Vector3& _lhs, const Vector3& _rhs) {
    return {
        _lhs.y * _rhs.z - _lhs.z * _rhs.y,
        _lhs.z * _rhs.x - _lhs.x * _rhs.z,
        _lhs.x * _rhs.y - _lhs.y * _rhs.x
    };
}

float Vector3::angle(Vector3 const& _from, Vector3 const& _to) {
    const float delta = dot(_from, _to);
    return std::acos(delta / (_from.magnitude() * _to.magnitude()));
}
Vector3 Vector3::zero()    { return { 0.0f,  0.0f,  0.0f  }; }
Vector3 Vector3::one()     { return { 1.0f,  1.0f,  1.0f  }; }
Vector3 Vector3::right()   { return { 1.0f,  0.0f,  0.0f  }; }
Vector3 Vector3::left()    { return { -1.0f, 0.0f,  0.0f  }; }
Vector3 Vector3::up()      { return { 0.0f,  1.0f,  0.0f  }; }
Vector3 Vector3::down()    { return { 0.0f,  -1.0f, 0.0f  }; }
Vector3 Vector3::forward() { return { 0.0f,  0.0f,  1.0f  }; }
Vector3 Vector3::back()    { return { 0.0f,  0.0f,  -1.0f }; }

Vector3& Vector3::operator+=(const Vector3& _v) {
    *this = *this + _v;
    return *this;
}
Vector3 operator+(const Vector3& _lhs, const Vector3& _rhs) {
    return {
        _lhs.x + _rhs.x,
        _lhs.y + _rhs.y,
        _lhs.z + _rhs.z
    };
}

Vector3& Vector3::operator-=(const Vector3& _v) {
    *this = *this - _v;
    return *this;
}
Vector3 operator-(const Vector3& _lhs, const Vector3& _rhs) {
    return {
        _lhs.x - _rhs.x,
        _lhs.y - _rhs.y,
        _lhs.z - _rhs.z
    };
}
Vector3 Vector3::operator-() {
    *this = -1 * *this;
    return *this;
}

Vector3& Vector3::operator*=(const float _s) {
    *this = *this * _s;
    return *this;
}
Vector3 operator*(const Vector3& _v, const float _s) {
    return {
        _v.x * _s,
        _v.y * _s,
        _v.z * _s
    };
}
Vector3 operator*(const float _s, const Vector3& _v) {
    return _v * _s;
}

Vector3& Vector3::operator/=(const float _s) {
    *this = *this / _s;
    return *this;
}
Vector3 operator/(const Vector3& _v, const float _s) {
    return {
        _v.x / _s,
        _v.y / _s,
        _v.z / _s
    };
}

bool operator==(const Vector3& _lhs, const Vector3& _rhs) {
    return _lhs.x == _rhs.x && _lhs.y == _rhs.y && _lhs.z == _rhs.z;
}
bool operator!=(const Vector3& _lhs, const Vector3& _rhs) {
    return !(_lhs == _rhs);
}

float Vector3::operator[](const size_t _i) const {
    switch(_i) {
        case 0: return x;
        case 1: return y;
        case 2: return z;
        default: throw std::out_of_range("Invalid index.");
    }
}