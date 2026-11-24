
#pragma once

#include "Constants.h"

namespace ZMath {
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
    static bool isApproxEqual(T _a, T _b, float _epsilon = EPSILON) {
        const float diff = std::abs(_a - _b);

        _a = std::abs(_a);
        _b = std::abs(_b);

        T largest = _b > _a ? _b : _a;

        return diff <= largest * _epsilon;
    }
}