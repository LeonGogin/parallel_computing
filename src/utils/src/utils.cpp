#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>
#include <string>

namespace save_results
{

    struct Measurment
    {
        std::string implementation_version;
        int matrix_dimension;
        int parallelism;
        double average_execution_time;

        std::string csv_header{"version, d, n_treads, average_execution_time"};

        // Measurment(std::string a, int b, int c, double d)
        //     : implementation_version{a},
        //       matrix_dimension{b},
        //       parallelism{c},
        //       average_execution_time{d}
        // {
        // }

        friend std::ostream &operator<<(std::ostream &out, const Measurment &e)
        {
            out << e.implementation_version << ", " << e.matrix_dimension << ", " << e.parallelism << ", " << e.average_execution_time;
            return out;
        }
    };

    namespace fs = std::filesystem;

    void write_csv(const std::vector<Measurment> results,
                   fs::path path)
    {
        path /= "output.csv";

        std::ofstream outputfile;
        outputfile.open(path.c_str());

        outputfile << results[0].csv_header << std::endl;
        for (const auto &i : results)
        {
            outputfile << i << std::endl;
        }
        outputfile.close();
    }
}