#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>
#include <string>

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