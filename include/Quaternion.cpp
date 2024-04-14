
#include <iostream>
#include <format>
#include <stdexcept>

#include <Math.h>

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
        return;
    }
    *this /= mag;
}

[[nodiscard]] Quaternion Quaternion::normalized() const {
    Quaternion norm = Quaternion(x, y, z, w);
    norm.normalize();
    return norm;
}

[[nodiscard]] Vector3 Quaternion::toEuler() const {
    return toEuler(*this);
}

Vector3 Quaternion::toEuler(const Quaternion& _q) {

    float x = 0;
    const float y = std::asin(2 * (_q.w * _q.y - _q.x * _q.z));
    float z;

    if(y == Math::pi * 0.5f) {
        z = -2 * std::atan2(_q.x, _q.w);
    }
    else if(y == -Math::pi * 0.5f) {
        z = 2 * std::atan2(_q.x, _q.w);
    }
    else {
        x = std::atan2(2 * (_q.w * _q.x + _q.y * _q.z), _q.w * _q.w - _q.x * _q.x - _q.y * _q.y + _q.z * _q.z);
        z = std::atan2(2 * (_q.w * _q.z + _q.x * _q.y), _q.w * _q.w + _q.x * _q.x - _q.y * _q.y - _q.z * _q.z);
    }

    return Vector3(x, y, z) * Math::rad2deg;

}

Quaternion Quaternion::fromEuler(const float _xDeg, const float _yDeg, const float _zDeg) {
    return {
        std::sin(_xDeg * 0.5f) * std::cos(_yDeg * 0.5f) * std::cos(_zDeg * 0.5f) - std::cos(_xDeg * 0.5f) * std::sin(_yDeg * 0.5f) * std::sin(_zDeg * 0.5f),
        std::cos(_xDeg * 0.5f) * std::sin(_yDeg * 0.5f) * std::cos(_zDeg * 0.5f) - std::sin(_xDeg * 0.5f) * std::cos(_yDeg * 0.5f) * std::sin(_zDeg * 0.5f),
        std::cos(_xDeg * 0.5f) * std::cos(_yDeg * 0.5f) * std::sin(_zDeg * 0.5f) - std::sin(_xDeg * 0.5f) * std::sin(_yDeg * 0.5f) * std::cos(_zDeg * 0.5f),
        std::cos(_xDeg * 0.5f) * std::cos(_yDeg * 0.5f) * std::cos(_zDeg * 0.5f) - std::sin(_xDeg * 0.5f) * std::sin(_yDeg * 0.5f) * std::sin(_zDeg * 0.5f)
    };
}

Quaternion Quaternion::fromEuler(const Vector3& _eulerDeg) {
    const Vector3 euler = _eulerDeg * Math::deg2rad;
    return fromEuler(euler.x, euler.y, euler.z);
}

Quaternion Quaternion::fromAxisAngle(const Vector3& _axis, const float _angleRad) {
    const Vector3 axis = _axis.normalized();
    return {
        axis.x * std::sin(_angleRad * 0.5f),
        axis.y * std::sin(_angleRad * 0.5f),
        axis.z * std::sin(_angleRad * 0.5f),
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
Quaternion operator*(const Quaternion& _lhs, const Quaternion& _rhs) {
    return {
        _lhs.w * _rhs.x + _lhs.x * _rhs.w + _lhs.y * _rhs.z - _lhs.z * _rhs.y,
        _lhs.w * _rhs.y + _lhs.y * _rhs.w + _lhs.z * _rhs.x - _lhs.x * _rhs.z,
        _lhs.w * _rhs.z + _lhs.z * _rhs.w + _lhs.x * _rhs.y - _lhs.y * _rhs.x,
        _lhs.w * _rhs.w - _lhs.x * _rhs.x - _lhs.y * _rhs.y - _lhs.z * _rhs.z
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
    return _lhs.x == _rhs.x && _lhs.y == _rhs.y && _lhs.z == _rhs.z && _lhs.w == _rhs.w;
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