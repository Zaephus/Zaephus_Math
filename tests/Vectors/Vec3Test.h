
#pragma once

#include <iostream>
#include <string>
#include <format>
#include <vector>
#include <cmath>

#include <source/ZMath.h>
#include <source/Vectors/Vector3.h>

class Vec3Test {

    public:
        static int runTests() {
            std::string output = magnitudeTest({3.0f, 2.0f, 1.0f}, 3.741657386773f);
            if(output != "Success")
            {
                std::cerr << output << std::endl;
                return 1;
            }
            std::cout << "All tests passed!" << std::endl;
            return 0;
        }

    private:
        std::vector<Vector3> testVectors = {
            { 3.1,  67.8, 18.7 },
            { 42.1, 59.0, 17.5 },
            { 30.4, 97.8, 8.2  },
            { 57.6, 95.4, 10.3 },
            { 80.0, 30.1, 11.7 },
            { 78.2, 84.0, 46.8 },
            { 52.1, 83.4, 8.6  },
            { 97.4, 94.0, 1.3  },
            { 76.8, 47.8, 12.1 },
            { 73.0, 49.2, 12.7 }
        };

        static std::string magnitudeTest(const Vector3& _v, const float& _expectedResult) {
            float mag = _v.magnitude();
            if(mag == _expectedResult) {
                return "Success";
            }
            else {
                return std::format("Failed! Expected result {}, got {}", _expectedResult, mag);
            }
        }
        static std::string squaredMagnitudeTest(const Vector3& _v, const float& _expectedResult) {
            return "Success";
        }

        static std::string normalizedTest(const Vector3& _v, const Vector3& _expectedResult) {
            return "Success";
        }

        static std::string distanceTest(const Vector3& _v, const float& _expectedResult) {
            return "Success";
        }

        static std::string dotProductTest(const Vector3& _a, const Vector3& _b, const float& _expectedResult) {
            return "Success";
        }
        static std::string crossProductTest(const Vector3& _a, const Vector3& _b, const Vector3& _expectedResult) {
            return "Success";
        }

        static std::string angleTest(const Vector3& _a, const Vector3& _b, const float& _expectedResult) {
            return "Success";
        }

        static std::string additionTestCompound(const Vector3& _a, const Vector3& _b, const Vector3& _expectedResult) {
            return "Success";
        }
        static std::string additionTest(const Vector3& _a, const Vector3& _b, const Vector3& _expectedResult) {
            return "Success";
        }

        static std::string subtractionTestCompound(const Vector3& _a, const Vector3& _b, const Vector3& _expectedResult) {
            return "Success";
        }
        static std::string subtractionTest(const Vector3& _a, const Vector3& _b, const Vector3& _expectedResult) {
            return "Success";
        }
        static std::string negationTest(const Vector3& _v, const Vector3& _expectedResult) {
            return "Success";
        }

        static std::string multiplicationTestCompound(const Vector3& _a, const Vector3& _b, const Vector3& _expectedResult) {
            return "Success";
        }
        static std::string multiplicationTest(const Vector3& _a, const Vector3& _b, const Vector3& _expectedResult) {
            return "Success";
        }

        static std::string divisionTestCompound(const Vector3& _a, const Vector3& _b, const Vector3& _expectedResult) {
            return "Success";
        }
        static std::string divisionTest(const Vector3& _a, const Vector3& _b, const Vector3& _expectedResult) {
            return "Success";
        }
};