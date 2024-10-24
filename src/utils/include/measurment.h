#if !defined(MEASURMENT)
#define MEASURMENT
#include <filesystem>
#include <string>

namespace Measurment
{

    struct Measurment
    {
        std::string implementation_version;
        int matrix_dimension;
        int parallelism;
        double average_execution_time;
        std::string csv_header{"version, d, n_treads, average_execution_time"};

        Measurment(std::string &&a, int b, int c, double d)
            : implementation_version{std::move(a)},
              matrix_dimension{b},
              parallelism{c},
              average_execution_time{d}
        {
        }
        friend std::ostream &operator<<(std::ostream &out, const Measurment &e)
        {
            out << e.implementation_version << ", " << e.matrix_dimension << ", " << e.parallelism << ", " << e.average_execution_time;
            return out;
        }
    };
}

#endif