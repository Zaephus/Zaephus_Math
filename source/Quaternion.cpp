
#include "Quaternion.h"

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
Quaternion::Quaternion(const Matrix4x4& _m) {
    const float trace = _m.m00 + _m.m11 + _m.m22;
    float temp[4];

    std::cout << "Trace: " << trace << std::endl;
    if(trace > 0.0f) {
        float s = std::sqrt(trace + 1.0f);
        temp[3] = s * 0.5f;
        s = 0.5f / s;

        temp[0] = (_m.m21 - _m.m12) * s;
        temp[1] = (_m.m02 - _m.m20) * s;
        temp[2] = (_m.m10 - _m.m01) * s;
    }
    else {
        const int i = _m.m00 < _m.m11
                ? (_m.m11 < _m.m22 ? 2 : 1)
                : (_m.m00 < _m.m22 ? 2 : 0);
        const int j = (i + 1) % 3;
        const int k = (i + 2) % 3;

        float s = std::sqrt(_m[i][i] - _m[j][j] - _m[k][k] + 1.0f);
        temp[i] = s * 0.5f;
        s = 0.5f / s;

        temp[3] = (_m[k][j] - _m[j][k]) * s;
        temp[j] = (_m[j][i] + _m[i][j]) * s;
        temp[k] = (_m[k][i] + _m[i][k]) * s;
    }

    x = temp[0];
    y = temp[1];
    z = temp[2];
    w = temp[3];
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
    const float mag = magnitude();
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
    const float axisComponent = std::sin(_angleRad * 0.5f);
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

void Quaternion::operator+=(const Quaternion& _q) {
    *this = *this + _q;
}
Quaternion Quaternion::operator+(const Quaternion& _q) const {
    return {
        x + _q.x,
        y + _q.y,
        z + _q.z,
        w + _q.w
    };
}

void Quaternion::operator-=(const Quaternion& _q) {
    *this = *this - _q;
}
Quaternion Quaternion::operator-(const Quaternion& _q) const {
    return {
        x - _q.x,
        y - _q.y,
        z - _q.z,
        w - _q.w
    };
}
Quaternion Quaternion::operator-() const {
    return {
        -x,
        -y,
        -z,
        -w
    };
}

void Quaternion::operator*=(const Quaternion& _q) {
    *this = *this * _q;
}
Quaternion Quaternion::operator*(const Quaternion& _q) const {
    return {
        w * _q.x + x * _q.w + y * _q.z - z * _q.y,
        w * _q.y - x * _q.z + y * _q.w + z * _q.x,
        w * _q.z + x * _q.y - y * _q.x + z * _q.w,
        w * _q.w - x * _q.x - y * _q.y - z * _q.z
    };
}

Vector3 Quaternion::operator*(const Vector3& _v) const {
    const Quaternion rotInverse = { -x, -y, -z, w };
    const Quaternion vecQ = { _v.x, _v.y, _v.z, 0.0f };

    const Quaternion result = *this * vecQ * rotInverse;

    return { result.x , result.y, result.z };
}

void Quaternion::operator*=(const float _s) {
    *this = *this * _s;
}
Quaternion Quaternion::operator*(const float _s) const {
    return{
        x * _s,
        y * _s,
        z * _s,
        w * _s
    };
}
Quaternion operator*(const float _s, const Quaternion& _q) {
    return _q * _s;
}

void Quaternion::operator/=(const float _s) {
    *this = *this / _s;
}
Quaternion Quaternion::operator/(const float _s) const {
    return {
        x / _s,
        y / _s,
        z / _s,
        w / _s
    };
}

bool Quaternion::operator==(const Quaternion& _q) const {
    return ZMath::isApproxEqual(x, _q.x) &&
           ZMath::isApproxEqual(y, _q.y) &&
           ZMath::isApproxEqual(z, _q.z) &&
           ZMath::isApproxEqual(w, _q.w);
}
bool Quaternion::operator!=(const Quaternion& _q) const {
    return !(*this == _q);
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