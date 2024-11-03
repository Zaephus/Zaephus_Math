
#pragma once

#include <chrono>
class Time {

    private:
        typedef std::chrono::high_resolution_clock tClock;

    public:
        static long long int milliseconds() {
            return std::chrono::duration_cast<std::chrono::milliseconds>(tClock::now().time_since_epoch()).count();
        }
        static long long int microseconds() {
            return std::chrono::duration_cast<std::chrono::milliseconds>(tClock::now().time_since_epoch()).count();
        }
        static long long int nanoseconds() {
            return std::chrono::duration_cast<std::chrono::milliseconds>(tClock::now().time_since_epoch()).count();
        }
};