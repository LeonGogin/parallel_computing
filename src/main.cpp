#include <iostream>
#include <array>
#include <vector>
#include <string>
#include "lesson_lib.h"
#include "utils.h"
#include "measurment.h"

int main()
{
    double execTime{0};
    constexpr int n = 500;
    constexpr int n_trial = 1;

    std::vector<Measurment::Measurment> res;

    std::array<float, n * n> d{
        utils::generateRandomFloats<n * n>(1.5, 5.5)};
    std::array<float, n * n> r;

    for (int i = 0; i < n_trial; ++i)
    {
        execTime += utils::funcTime<utils::ms>(V0::step, r.begin(), d.begin(), n);
    }

    res.emplace_back("V0", n, 1, execTime / n_trial);

    std::cout << "V0" << std::endl;
    std::cout << "Average execution time of function: " << execTime / n_trial << " milliseconds" << std::endl;

    execTime = 0;
    for (int i = 0; i < n_trial; ++i)
    {
        execTime += utils::funcTime<utils::ms>(V1::step, r.begin(), d.begin(), n);
    }
    
    res.emplace_back("V1", n, 4, execTime / n_trial);
    std::cout << "V1" << std::endl;
    std::cout << "Average execution time: " << execTime / n_trial << " milliseconds" << std::endl;

    utils::write_csv(res);

    return 1;
}