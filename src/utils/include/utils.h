#if !defined(UTILS)
#define UTILS
#include <random>
#include <chrono>
#include <filesystem>
#include <utility>
#include <iostream>
#include <vector>
#include "measurment.h"

#define timeNow() std::chrono::high_resolution_clock::now()

namespace utils
{
    // Function to generate an array of random floats
    template <typename T>
    void generate_random_floats(T *d, int n, float min, float max)
    {
        // Random number generation setup
        // Seed generator
        std::random_device rd;
        // Mersenne Twister engine
        std::mt19937 gen(rd());
        // Uniform distribution
        std::uniform_real_distribution<T> dist(min, max);

        // Fill the array with random floats
        for (int i = 0; i < n; i++)
        {
            d[i] = dist(gen); // Generate a random float
        }
    }

    using TimeVar = std::chrono::high_resolution_clock::time_point;
    using ns = std::chrono::nanoseconds;
    using mcs = std::chrono::microseconds;
    using ms = std::chrono::milliseconds;

    template <typename units, typename F, typename... Args>
    double funcTime(F func, Args &&...args)
    {
        TimeVar t1 = timeNow();
        func(std::forward<Args>(args)...);
        return std::chrono::duration_cast<units>(timeNow() - t1).count();
    }

    // namespace fs = std::filesystem;

    void write_csv(const std::vector<Measurment::Measurment> &);
}

#endif