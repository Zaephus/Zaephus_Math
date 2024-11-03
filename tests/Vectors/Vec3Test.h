
#pragma once

#include <chrono>
#include <iostream>
#include <string>
#include <format>
#include <vector>
#include <cmath>
#include <limits>

#include "../Time.h"

#include <source/ZMath.h>
#include <source/Vectors/Vector3.h>

using namespace std::chrono;

typedef std::chrono::high_resolution_clock Clock;

std::vector<Vector3> testVectors = {
    { 0.0f,  0.0f,  0.0f  },
    { 3.0f,  2.0f,  1.0f  },
    { 30.4f, 97.8f, 8.2f  },
    { 57.6f, 95.4f, 10.3f },
    { 80.0f, 30.1f, 11.7f },
    { 78.2f, 84.0f, 46.8f },
    { 52.1f, 83.4f, 8.6f  },
    { 97.4f, 94.0f, 1.3f  },
    { 76.8f, 47.8f, 12.1f },
    { 73.0f, 49.2f, 12.7f }
};

void magnitudeTest() {
    std::cout << "Starting Magnitude test!" << std::endl;

    std::vector<float> expectedAnswers = {
        0.000000000f,
        3.741657387f,
        102.7435643f,
        111.9151911f,
        86.27224351f,
        123.9414378f,
        98.71134687f,
        135.3678322f,
        91.26603969f,
        88.94340897f
    };

    for(int i = 0; i < testVectors.size(); i++) {
        auto startTime = Clock::now();
        const float mag = testVectors[i].magnitude();
        auto elapsedTime = Clock::now() - startTime;

        if(!ZMath::isRelativelyEqual(mag, expectedAnswers[i])) {
            std::cout << std::format("Failed test with vector {{{}}}! Expected result {}, got {}", testVectors[i].toString(), expectedAnswers[i], mag) << std::endl;
            continue;
        }

        std::cout << std::format("Success! Time elapsed: {}", elapsedTime) << std::endl;
    }

    std::cout << std::endl;
}

void squaredMagnitudeTest() {
    std::cout << "Starting SquaredMagnitude test!" << std::endl;

    std::vector<float> expectedAnswers = {
        0.000000000f,
        14.00000000f,
        10556.24000f,
        12525.01000f,
        7442.900000f,
        15361.48000f,
        9743.930000f,
        18324.45000f,
        8329.490000f,
        7910.930000f
    };

    for(int i = 0; i < testVectors.size(); i++) {
        auto startTime = Clock::now();
        const float mag = testVectors[i].squaredMagnitude();
        auto elapsedTime = Clock::now() - startTime;

        if(!ZMath::isRelativelyEqual(mag, expectedAnswers[i])) {
            std::cout << std::format("Failed test with vector {{{}}}! Expected result {}, got {}", testVectors[i].toString(), expectedAnswers[i], mag) << std::endl;
            continue;
        }

        std::cout << std::format("Success! Time elapsed: {}", elapsedTime) << std::endl;
    }

    std::cout << std::endl;
}

std::string normalizedTest(const Vector3& _v, const Vector3& _expectedResult) {
    return "Success";
}

std::string distanceTest(const Vector3& _v, const float& _expectedResult) {
    return "Success";
}

std::string dotProductTest(const Vector3& _a, const Vector3& _b, const float& _expectedResult) {
    return "Success";
}
std::string crossProductTest(const Vector3& _a, const Vector3& _b, const Vector3& _expectedResult) {
    return "Success";
}

std::string angleTest(const Vector3& _a, const Vector3& _b, const float& _expectedResult) {
    return "Success";
}

std::string additionTestCompound(const Vector3& _a, const Vector3& _b, const Vector3& _expectedResult) {
    return "Success";
}
std::string additionTest(const Vector3& _a, const Vector3& _b, const Vector3& _expectedResult) {
    return "Success";
}

std::string subtractionTestCompound(const Vector3& _a, const Vector3& _b, const Vector3& _expectedResult) {
    return "Success";
}
std::string subtractionTest(const Vector3& _a, const Vector3& _b, const Vector3& _expectedResult) {
    return "Success";
}
std::string negationTest(const Vector3& _v, const Vector3& _expectedResult) {
    return "Success";
}

std::string multiplicationTestCompound(const Vector3& _a, const Vector3& _b, const Vector3& _expectedResult) {
    return "Success";
}
std::string multiplicationTest(const Vector3& _a, const Vector3& _b, const Vector3& _expectedResult) {
    return "Success";
}

std::string divisionTestCompound(const Vector3& _a, const Vector3& _b, const Vector3& _expectedResult) {
    return "Success";
}
std::string divisionTest(const Vector3& _a, const Vector3& _b, const Vector3& _expectedResult) {
    return "Success";
}

int Vec3Test() {
    magnitudeTest();
    squaredMagnitudeTest();
    return 0;
}