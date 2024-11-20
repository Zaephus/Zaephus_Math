
#pragma once

#include <iostream>
#include <vector>

#include "Time.h"
#include "TestHelper.h"

#include <source/ZMath.h>
#include <source/Quaternion.h>

std::vector<Quaternion> testQuaternions = {
    { 0.0f, 0.0f, 0.0f, 0.0f },
    { 4.0f, 3.0f, 2.0f, 1.0f },
    { 5.0f, 5.0f, 5.0f, 5.0f },
    { 1.2f, 2.4f, 4.8f, 9.6f },
    { 111.0f, 222.0f, 333.0f, 444.0f },
    { -18.7f, -5.0f, 3.0f, 0.3f }
};

void multiplicationTest() {
    std::cout << "Starting multiplication test!" << std::endl;

    std::vector<Quaternion> expectedAnswers = {
        { 0.0f, 0.0f, 0.0f, 0.0f },
        { 2442.0f, 444.0f, 1776.0f, -1332.0f },
        { -52.0f, -132.0f, 85.0f, 105.0f }
    };

    for(int i = 0; i < testQuaternions.size() / 2; i++) {
        int j = i + testQuaternions.size() / 2;

        auto startTime = Time::microseconds();
        const Quaternion q = testQuaternions[i] * testQuaternions[j];
        auto elapsedTime = Time::microseconds() - startTime;

        if(q !=  expectedAnswers[i]) {
            printTestFailed(testQuaternions[i], expectedAnswers[i], q);
            continue;
        }

        printTestSuccess(elapsedTime);
    }
}

int QuaternionTest() {
    multiplicationTest();

    return 0;
}