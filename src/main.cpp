#include <iostream>
#include <array>
#include <vector>
#include <string>
#include "lesson_lib.h"
#include "utils.h"

int main()
{
    double execTime{0};
    constexpr int n = 500;
    constexpr int n_trial = 1;

    std::vector<save_results::Measurment> res;
    save_results::Measurment tmp_res{};

    std::array<float, n * n> d{
        utils::generateRandomFloats<n * n>(1.5, 5.5)};
    std::array<float, n * n> r;

    for (int i = 0; i < n_trial; ++i)
    {
        execTime += utils::funcTime<utils::ms>(V0::step, r.begin(), d.begin(), n);
    }

    tmp_res.implementation_version = "V0";
    tmp_res.matrix_dimension = n;
    tmp_res.parallelism = 1;
    tmp_res.average_execution_time = execTime / n_trial;
    res.push_back(tmp_res);

    std::cout << "V0" << std::endl;
    std::cout << "Average execution time of function: " << execTime / n_trial << " milliseconds" << std::endl;

    execTime = 0;
    for (int i = 0; i < n_trial; ++i)
    {
        execTime += utils::funcTime<utils::ms>(V1::step, r.begin(), d.begin(), n);
    }

    tmp_res.implementation_version = "V1";
    tmp_res.matrix_dimension = n;
    tmp_res.parallelism = 4;
    tmp_res.average_execution_time = execTime / n_trial;
    res.push_back(tmp_res);
    std::cout << "V1" << std::endl;
    std::cout << "Average execution time: " << execTime / n_trial << " milliseconds" << std::endl;

    save_results::write_csv(res);

    // for (int i = 0; i < n; ++i)
    // {
    //     for (int j = 0; j < n; ++j)
    //     {
    //         std::cout << r[i * n + j] << " ";
    //     }
    //     std::cout << "\n";
    // }
    return 1;
}