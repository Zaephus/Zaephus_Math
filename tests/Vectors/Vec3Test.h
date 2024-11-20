
#pragma once

#include <iostream>
#include <vector>

#include "../Time.h"
#include "../TestHelper.h"

#include <source/ZMath.h>
#include <source/Vectors/Vector3.h>

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
    std::cout << "Starting magnitude test!" << std::endl;

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
        auto startTime = Time::microseconds();
        const float mag = testVectors[i].magnitude();
        auto elapsedTime = Time::microseconds() - startTime;

        if(!ZMath::isRelativelyEqual(mag, expectedAnswers[i])) {
            printTestFailed(testVectors[i], expectedAnswers[i], mag);
            continue;
        }

        printTestSuccess(elapsedTime);
    }

    std::cout << std::endl;
}

void squaredMagnitudeTest() {
    std::cout << "Starting squared magnitude test!" << std::endl;

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
        auto startTime = Time::microseconds();
        const float mag = testVectors[i].squaredMagnitude();
        auto elapsedTime = Time::microseconds() - startTime;

        if(!ZMath::isRelativelyEqual(mag, expectedAnswers[i])) {
            printTestFailed(testVectors[i], expectedAnswers[i], mag);
            continue;
        }

        printTestSuccess(elapsedTime);
    }

    std::cout << std::endl;
}

void normalizedTest() {
    std::cout << "Starting normalized test!" << std::endl;

    std::vector<Vector3> expectedAnswers = {
        { 0.0f,         0.0f,         0.0f         },
        { 0.8017837257, 0.5345224838, 0.2672612419 },
        { 0.2958822794, 0.9518844384, 0.0798103517 },
        { 0.514675438,  0.8524311942, 0.0920339759 },
        { 0.9272970859, 0.3488955286, 0.1356171988 },
        { 0.6309431405, 0.6777394348, 0.3775976851 },
        { 0.5278015309, 0.8448876714, 0.0871227095 },
        { 0.7195210148, 0.6944042648, 0.0096034632 },
        { 0.8414959196, 0.5237435541, 0.1325794353 },
        { 0.8207465943, 0.5531607184, 0.1427874212 }
    };

    for(int i = 0; i < testVectors.size(); i++) {
        auto startTime = Time::microseconds();
        const Vector3 norm = testVectors[i].normalized();
        auto elapsedTime = Time::microseconds() - startTime;

        if(norm != expectedAnswers[i]) {
            printTestFailed(testVectors[i], expectedAnswers[i], norm);
            continue;
        }

        printTestSuccess(elapsedTime);
    }

    std::cout << std::endl;
}

void distanceTest() {
    std::cout << "Starting distance test!" << std::endl;

    for(int i = 0; i < testVectors.size(); i++) {
        int j = testVectors.size() - 1 - i;

        auto startTime = Time::microseconds();
        const float dist = Vector3::distance(testVectors[i], testVectors[j]);
        auto elapsedTime = Time::microseconds() - startTime;
    }

    std::cout << std::endl;
}

void dotProductTest() {
    std::cout << "Starting dot product test!" << std::endl;

    std::cout << std::endl;
}
void crossProductTest() {
    std::cout << "Starting cross product test!" << std::endl;

    std::cout << std::endl;
}

void angleTest() {
    std::cout << "Starting angle test!" << std::endl;

    std::cout << std::endl;
}

void additionTestCompound() {
    std::cout << "Starting compound addition test!" << std::endl;

    std::cout << std::endl;
}
void additionTest() {
    std::cout << "Starting addition test!" << std::endl;

    std::cout << std::endl;
}

void subtractionTestCompound() {
    std::cout << "Starting compound subtraction test!" << std::endl;

    std::cout << std::endl;
}
void subtractionTest() {
    std::cout << "Starting subtraction test!" << std::endl;

    std::cout << std::endl;
}
void negationTest() {
    std::cout << "Starting negation test!" << std::endl;

    std::cout << std::endl;
}

void multiplicationTestCompound() {
    std::cout << "Starting compound multiplication test!" << std::endl;

    std::cout << std::endl;
}
void multiplicationTest() {
    std::cout << "Starting multiplication test!" << std::endl;

    std::cout << std::endl;
}

void divisionTestCompound() {
    std::cout << "Starting compound division test!" << std::endl;

    std::cout << std::endl;
}
void divisionTest() {
    std::cout << "Starting division test!" << std::endl;

    std::cout << std::endl;
}

int Vec3Test() {
    magnitudeTest();
    squaredMagnitudeTest();
    normalizedTest();
    distanceTest();
    dotProductTest();
    crossProductTest();
    angleTest();
    additionTestCompound();
    additionTest();
    subtractionTestCompound();
    subtractionTest();
    negationTest();
    multiplicationTestCompound();
    multiplicationTest();
    divisionTestCompound();
    divisionTest();

    return 0;
}