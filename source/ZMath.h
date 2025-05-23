
#pragma once

#include <cmath>

#include "Quaternion.h"

#include "Matrices/Matrix2x2.h"
#include "Matrices/Matrix3x3.h"
#include "Matrices/Matrix4x4.h"

#include "Vectors/Vector2.h"
#include "Vectors/Vector2Int.h"
#include "Vectors/Vector3.h"
#include "Vectors/Vector3Int.h"
#include "Vectors/Vector4.h"
#include "Vectors/Vector4Int.h"

class ZMath {

    public:

        static constexpr float pi = 3.14159265358979323846;

        static constexpr float e = 2.71828182845904523536;

        static constexpr float epsilon = 1.0E-6;
        static constexpr double doubleEpsilon = 2.2250738585072014E-308;

        static constexpr float rad2deg = 180.0f / pi;
        static constexpr float deg2rad = pi / 180.0f;

        template <typename T>
        static bool isApproxEqual(T _a, T _b, float _epsilon = epsilon) {
            const float diff = std::abs(_a - _b);

            _a = std::abs(_a);
            _b = std::abs(_b);

            T largest = _b > _a ? _b : _a;

            return diff <= largest * _epsilon;
        }

};