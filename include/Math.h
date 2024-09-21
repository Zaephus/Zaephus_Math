
#pragma once

#include <cmath>

#include <Quaternion.h>

#include <Matrices/Matrix2x2.h>
#include <Matrices/Matrix3x3.h>
#include <Matrices/Matrix4x4.h>

#include <Vectors/Vector2.h>
#include <Vectors/Vector2Int.h>
#include <Vectors/Vector3.h>
#include <Vectors/Vector3Int.h>
#include <Vectors/Vector4.h>
#include <Vectors/Vector4Int.h>

struct Math {

    static inline constexpr float pi = 3.14159265358979323846;

    static inline constexpr float e = 2.71828182845904523536;

    static inline constexpr float epsilon = 1.175494351E-38;
    static inline constexpr float doubleEpsilon = 2.2250738585072014E-308;

    static inline constexpr float rad2deg = 180.0f / pi;
    static inline constexpr float deg2rad = pi / 180.0f;
};