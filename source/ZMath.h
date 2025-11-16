
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
        static T clamp(const T _value, const T _min, const T _max) {
            if(_value < _min) { return _min; }
            if(_value > _max) { return _max; }
            return _value;
        }

        static float clamp01(const float _value) {
            if(_value < 0.0f) { return 0.0f; }
            if(_value > 1.0f) { return 1.0f; }
            return _value;
        }

        template <typename T>
        static T smoothStep(const T _value, const T _min, const T _max) {
            T val = clamp((_value - _min) / (_max - _min), static_cast<T>(0.0f), static_cast<T>(1.0f));
            return val * val * (3.0f - 2.0f * val);
        }

        static float lerp(const float _a, const float _b, const float _t) {
            return _a + (_b - _a) * clamp01(_t);
        }

        static float lerpUnclamped(const float _a, const float _b, const float _t) {
            return _a + (_b - _a) * _t;
        }

        template <typename T>
        static bool isApproxEqual(T _a, T _b, float _epsilon = epsilon) {
            const float diff = std::abs(_a - _b);

            _a = std::abs(_a);
            _b = std::abs(_b);

            T largest = _b > _a ? _b : _a;

            return diff <= largest * _epsilon;
        }
};