#include <iostream>
#include <fstream>
#include <filesystem>
#include <limits>
#include <omp.h>
#include <vector>
#include <string>

namespace V0
{
    void step(float *r, const float *d, int n)
    // n denotes the number of nodes
    // d contains the input
    // r will contain the result
    // cost of the edge from node i to node j is stored in d[n*i + j] --> we use flat matrix with row major
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                float v = std::numeric_limits<float>::infinity();
                for (int k = 0; k < n; ++k)
                {
                    float x = d[n * i + k];
                    float y = d[n * k + j];
                    float z = x + y;
                    v = std::min(v, z);
                }
                r[n * i + j] = v;
            }
        }
    }

}
namespace V1
{
    void step(float *r, const float *d, int n)
    // n denotes the number of nodes
    // d contains the input
    // r will contain the result
    // cost of the edge from node i to node j is stored in d[n*i + j] --> we use flat matrix with row major
    {
#pragma omp parallel for num_threads(4)
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                float v = std::numeric_limits<float>::infinity();
                for (int k = 0; k < n; ++k)
                {
                    float x = d[n * i + k];
                    float y = d[n * k + j];
                    float z = x + y;
                    v = std::min(v, z);
                }
                r[n * i + j] = v;
            }
        }
    }

}

namespace save_results
{
    namespace fs = std::filesystem;

    void write_csv(std::vector<std::string> versions,
                   std::vector<double> ex_time,
                   fs::path path)
    {
        path /= "output.csv";

        auto v = versions.begin();
        auto t = ex_time.begin();

        std::ofstream outputfile;
        outputfile.open(path.c_str());

        outputfile << "func_version, average_execution_time_ms" << std::endl;
        while (v < versions.end() && t < ex_time.end())
        {
            outputfile << *v << ", " << *t << std::endl;
            std::cout << *v << ", " << *t << std::endl;

            ++v;
            ++t;
        }
        outputfile.close();
    }
}