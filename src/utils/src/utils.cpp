#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>
#include <string>
#include "measurment.h"

namespace utils
{
    namespace fs = std::filesystem;

    void write_csv(const std::vector<Measurment::Measurment> &results)
    {
        fs::path path = "/Users/l/Documents/programm/c++/mpi/log/";
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