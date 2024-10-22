#if !defined(UTILS)
#define UTILS
#include <random>
#include <chrono>
#include <filesystem>
#include <utility>
#include <iostream>
#include <vector>

namespace utils
{
    // Function to generate an array of random floats
    template <std::size_t N>
    std::array<float, N> generateRandomFloats(float min, float max)
    {
        std::array<float, N> randomFloats;

        // Random number generation setup
        std::random_device rd;                                // Seed generator
        std::mt19937 gen(rd());                               // Mersenne Twister engine
        std::uniform_real_distribution<float> dist(min, max); // Uniform distribution

        // Fill the array with random floats
        for (auto &num : randomFloats)
        {
            num = dist(gen); // Generate a random float
        }

        return randomFloats;
    }

    using TimeVar = std::chrono::high_resolution_clock::time_point;
    using ns = std::chrono::nanoseconds;
    using ms = std::chrono::milliseconds;

#define timeNow() std::chrono::high_resolution_clock::now()

    template <typename units, typename F, typename... Args>
    double funcTime(F func, Args &&...args)
    {
        TimeVar t1 = timeNow();
        func(std::forward<Args>(args)...);
        return std::chrono::duration_cast<units>(timeNow() - t1).count();
    }
}

namespace save_results
{

    struct Measurment
    {
        std::string implementation_version;
        int matrix_dimension;
        int parallelism;
        double average_execution_time;
        std::string csv_header;

        // Measurment(std::string a, int b, int c, double d);
    };

    namespace fs = std::filesystem;

    void write_csv(std::vector<Measurment>, fs::path = "/Users/l/Documents/programm/c++/mpi/log/");
}

#endif