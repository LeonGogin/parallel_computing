#include <iostream>
#include <array>
#include <vector>
#include <string>
#include "lesson_lib.h"
#include "utils.h"
#include "measurment.h"

template <typename T>
void run_experiments(int n_trials, std::vector<int> &problem_dimensions, std::vector<Measurment::Measurment> &res)
{

    double execTime{0};

    for (const int &n : problem_dimensions)
    {
        auto *r = new float[n * n];
        auto *d = new float[n * n];

        utils::generate_random_floats<float>(d, n * n, 1.5, 5.5);

        // zero version
        for (int i = 0; i < n_trials; ++i)
        {
            execTime += utils::funcTime<T>(V0::step, r, d, n);
        }
        res.emplace_back("V0", n, 1, execTime / n_trials);

        // first version
        execTime = 0;
        for (int i = 0; i < n_trials; ++i)
        {
            execTime += utils::funcTime<T>(V1::step, r, d, n);
        }

        res.emplace_back("V1", n, 4, execTime / n_trials);

        delete[] r;
        delete[] d;
    }
}

int main()
{

    constexpr int n_trial = 10;
    std::vector<Measurment::Measurment> res;
    std::vector<int> problem_dimensions;
    for (int i = 10; i < 510; i += 10)
    {
        problem_dimensions.push_back(i);
    }

    run_experiments<utils::mcs>(n_trial, problem_dimensions, res);

    utils::write_csv(res);

    return 1;
}