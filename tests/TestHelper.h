
#pragma once

#include <iostream>
#include <format>

template <typename T>
static void printTestFailed(T _item, T _expectedResult, T _result) {
    std::cout << std::format("\tFailed test with vector {{ {} }}! Expected result {}, got {}", _item, _expectedResult, _result) << std::endl;
}

template <typename T, typename R>
static void printTestFailed(T _item, R _expectedResult, R _result) {
    std::cout << std::format("\tFailed test with vector {{ {} }}! Expected result {}, got {}", _item, _expectedResult, _result) << std::endl;
}

template <typename T>
static void printTestSuccess(T _timeElapsed) {
    std::cout << std::format("\tSuccess! Time elapsed: {}", _timeElapsed) << std::endl;
}