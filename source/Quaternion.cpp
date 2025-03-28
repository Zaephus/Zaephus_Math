
#include <iostream>
#include <format>
#include <stdexcept>

#include "ZMath.h"

Quaternion::Quaternion() {
    *this = identity();
}
Quaternion::Quaternion(const Quaternion& _q) {
    x = _q.x;
    y = _q.y;
    z = _q.z;
    w = _q.w;
}
Quaternion::Quaternion(const float _x, const float _y, const float _z, const float _w) {
    x = _x;
    y = _y;
    z = _z;
    w = _w;
}

[[nodiscard]] std::string Quaternion::toString() const {
    return std::format("{}, {}, {}, {}", x, y, z, w);
}

[[nodiscard]] float Quaternion::magnitude() const {
    return dot(*this, *this);
}

void Quaternion::normalize() {
    const float mag = magnitude();
    if(mag == 0) {
        *this = identity(); // TODO: Why set this to identity here?
        std::cout << "Magnitude of quaternion was zero!" << std::endl;
        return;
    }
    *this /= mag;
}

[[nodiscard]] Quaternion Quaternion::normalized() const {
    Quaternion norm = Quaternion(x, y, z, w);
    norm.normalize();
    return norm;
}

void Quaternion::invert() {
    float mag = magnitude();
    *this = conjugate() / (mag * mag);
}

[[nodiscard]] Quaternion Quaternion::inverse() const {
    Quaternion inverse = Quaternion(x, y, z, w);
    inverse.invert();
    return inverse;
}

[[nodiscard]] Quaternion Quaternion::conjugate() const {
    return { -x, -y, -z, w };
}

[[nodiscard]] Vector3 Quaternion::toEuler() const {
    return toEuler(*this);
}

Vector3 Quaternion::toEuler(const Quaternion& _q) {

    float x = 0;
    const float y = std::asin(2 * (_q.w * _q.y - _q.x * _q.z));
    float z;

    if(y == ZMath::pi * 0.5f) {
        z = -2 * std::atan2(_q.x, _q.w);
    }
    else if(y == -ZMath::pi * 0.5f) {
        z = 2 * std::atan2(_q.x, _q.w);
    }
    else {
        x = std::atan2(2 * (_q.w * _q.x + _q.y * _q.z), _q.w * _q.w - _q.x * _q.x - _q.y * _q.y + _q.z * _q.z);
        z = std::atan2(2 * (_q.w * _q.z + _q.x * _q.y), _q.w * _q.w + _q.x * _q.x - _q.y * _q.y - _q.z * _q.z);
    }

    return Vector3(x, y, z) * ZMath::rad2deg;

}

Quaternion Quaternion::fromEuler(const float _xDeg, const float _yDeg, const float _zDeg) {
    const float x = _xDeg * ZMath::deg2rad;
    const float y = _yDeg * ZMath::deg2rad;
    const float z = _zDeg * ZMath::deg2rad;
    return {
        std::sin(x * 0.5f) * std::cos(y * 0.5f) * std::cos(z * 0.5f) - std::cos(x * 0.5f) * std::sin(y * 0.5f) * std::sin(z * 0.5f),
        std::cos(x * 0.5f) * std::sin(y * 0.5f) * std::cos(z * 0.5f) - std::sin(x * 0.5f) * std::cos(y * 0.5f) * std::sin(z * 0.5f),
        std::cos(x * 0.5f) * std::cos(y * 0.5f) * std::sin(z * 0.5f) - std::sin(x * 0.5f) * std::sin(y * 0.5f) * std::cos(z * 0.5f),
        std::cos(x * 0.5f) * std::cos(y * 0.5f) * std::cos(z * 0.5f) - std::sin(x * 0.5f) * std::sin(y * 0.5f) * std::sin(z * 0.5f)
    };
}

Quaternion Quaternion::fromEuler(const Vector3& _eulerDeg) {
    return fromEuler(_eulerDeg.x, _eulerDeg.y, _eulerDeg.z);
}

Quaternion Quaternion::fromAxisAngle(const Vector3& _axis, const float _angleRad) {
    const Vector3 axis = _axis.normalized();
    float axisComponent = std::sin(_angleRad * 0.5f);
    return {
        axis.x * axisComponent,
        axis.y * axisComponent,
        axis.z * axisComponent,
        std::cos(_angleRad * 0.5f)
    };
}

float Quaternion::dot(const Quaternion& _lhs, const Quaternion& _rhs) {
    return _lhs.x * _rhs.x + _lhs.y * _rhs.y + _lhs.z * _rhs.z + _lhs.w * _rhs.w;
}

float Quaternion::angleBetween(const Quaternion& _lhs, const Quaternion& _rhs) {
    const float d = dot(_lhs, _rhs);
    return std::acos(d / (_lhs.magnitude() * _rhs.magnitude()));
}

Quaternion Quaternion::identity() { return { 0.0f, 0.0f, 0.0f, 1.0f }; }

Quaternion& Quaternion::operator+=(const Quaternion& _q) {
    *this = *this + _q;
    return *this;
}
Quaternion operator+(const Quaternion& _lhs, const Quaternion& _rhs) {
    return {
        _lhs.x + _rhs.x,
        _lhs.y + _rhs.y,
        _lhs.z + _rhs.z,
        _lhs.w + _rhs.w
    };
}

Quaternion& Quaternion::operator-=(const Quaternion& _q) {
    *this = *this - _q;
    return *this;
}
Quaternion operator-(const Quaternion& _lhs, const Quaternion& _rhs) {
    return {
        _lhs.x - _rhs.x,
        _lhs.y - _rhs.y,
        _lhs.z - _rhs.z,
        _lhs.w - _rhs.w
    };
}
Quaternion Quaternion::operator-() {
    *this = -1 * *this;
    return *this;
}

Quaternion Quaternion::operator*=(const Quaternion& _q) {
    *this = *this * _q;
    return *this;
}
Quaternion operator*(const Quaternion& _a, const Quaternion& _b) {
//    float w1, w2;
//    float x1, x2;
//    float y1, y2;
//    float z1, z2;
//    float x, y, z, w;
//
//    z = w1 * x2 + x1 * w2 + y1 * z2 - z1 * y2;
//    x = w1 * y2 - x1 * z2 + y1 * w2 + z1 * x2;
//    y = w1 * z2 + x1 * y2 - y1 * x2 + z1 * w2;
//    w = w1 * w2 - x1 * x2 - y1 * y2 - z1 * z2;
//
//    float test = w * x * y * z;
    return {
        _a.w * _b.x + _a.x * _b.w + _a.y * _b.z - _a.z * _b.y,
        _a.w * _b.y - _a.x * _b.z + _a.y * _b.w + _a.z * _b.x,
        _a.w * _b.z + _a.x * _b.y - _a.y * _b.x + _a.z * _b.w,
        _a.w * _b.w - _a.x * _b.x - _a.y * _b.y - _a.z * _b.z
    };
}

Vector3 operator*(const Quaternion& _q, const Vector3& _v) {
    const Quaternion rotInverse = { -_q.x, -_q.y, -_q.z, _q.w };
    const Quaternion vecQ = { _v.x, _v.y, _v.z, 0.0f };

    const Quaternion result = _q * vecQ * rotInverse;

    return { result.x , result.y, result.z };
}

Quaternion& Quaternion::operator*=(const float _s) {
    *this = *this * _s;
    return *this;
}
Quaternion operator*(const Quaternion& _q, const float _s) {
    return{
        _q.x * _s,
        _q.y * _s,
        _q.z * _s,
        _q.w * _s
    };
}
Quaternion operator*(const float _s, const Quaternion& _q) {
    return _q * _s;
}

Quaternion& Quaternion::operator/=(const float _s) {
    this->x /= _s;
    this->y /= _s;
    this->z /= _s;
    this->w /= _s;
    return *this;
}
Quaternion operator/(const Quaternion& _q, const float _s) {
    return {
        _q.x / _s,
        _q.y / _s,
        _q.z / _s,
        _q.w / _s
    };
}

bool operator==(const Quaternion& _lhs, const Quaternion& _rhs) {
    return ZMath::isRelativelyEqual(_lhs.x, _rhs.x) && ZMath::isRelativelyEqual(_lhs.y, _rhs.y) && ZMath::isRelativelyEqual(_lhs.z, _rhs.z) && ZMath::isRelativelyEqual(_lhs.w, _rhs.w);
}
bool operator!=(const Quaternion& _lhs, const Quaternion& _rhs) {
    return !(_lhs == _rhs);
}

float Quaternion::operator[](const size_t _i) const {
    switch(_i) {
        case 0:
            return x;
        case 1:
            return y;
        case 2:
            return z;
        case 3:
            return w;
        default:
            throw std::out_of_range("Invalid index.");
    }
}