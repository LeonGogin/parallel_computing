#include <iostream>
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
        // #pragma omp parallel
        //         {
        //             int num_threads = omp_get_num_threads();
        //             std::cout << num_threads << std::endl;
        //         }

#pragma omp parallel for
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
