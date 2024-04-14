
#pragma once

#include <cmath>

#include <Quaternion.h>

#include <Matrices/Matrix2x2.h>
#include <Matrices/Matrix3x3.h>
#include <Matrices/Matrix4x4.h>

#include <Vectors/Vector2.h>
#include <Vectors/Vector3.h>
#include <Vectors/Vector4.h>

struct Math {

    static inline constexpr double pi = 3.14159265358979323846;

    static inline constexpr double e = 2.71828182845904523536;

    static inline constexpr float epsilon = 1.175494351E-38;
    static inline constexpr double doubleEpsilon = 2.2250738585072014E-308;

    static inline constexpr double rad2deg = 180 / pi;
    static inline constexpr double deg2rad = pi / 180;

};