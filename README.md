# Parallel Matrix Multiplication using Max-Sum Approach

This repository contains a parallel implementation of a matrix multiplication algorithm using the max-sum approach. It includes benchmarking examples from the [Parallel Programming course at Aalto University](https://ppc.cs.aalto.fi/). The goal is to demonstrate how matrix operations can be parallelized to improve performance.

## Features

- Parallel implementation of matrix multiplication using OpenMP.
- Benchmarking of performance on various matrix sizes.
- Example configurations and results based on coursework material.
- Instructions for compiling and linking OpenMP on macOS.
- Profiling performance using Gperftools.

## Prerequisites

- C++ compiler supporting OpenMP.
- CMake for building the project.
- (Optional) Gperftools for profiling and performance analysis.

For testing on macOS, I used the following Clang compiler version:

```bash
Apple clang version 14.0.3 (clang-1403.0.22.14.1) Target: arm64-apple-darwin22.6.0
```

## Installation and Setup

To set up the project locally, follow these steps:

1. Clone the repository:

   ```bash
   git clone <repository_url>
   cd <repository_folder>
   ```

2. Build the project using CMake:

   ```bash
   mkdir build
   cd build
   cmake ..
   make
   ```

### macOS Specific Setup: Linking OpenMP

If you are using macOS, additional steps are required to properly link OpenMP. Follow these instructions:

1. Ensure that OpenMP is installed via Homebrew:

   ```bash
   brew install libomp
   ```

2. Add the following commands to your CMake file to link OpenMP correctly:

   ```cmake
   set(LIMBO_PATH "/usr/local/opt/libomp")
   set(OpenMP_CXX_FLAG "-Xclang -fopenmp=libomp")
   set(OpenMP_CXX_INCLUDE_DIR "${LIMBO_PATH}/include")
   set(OpenMP_CXX_LIB_NAMES libomp)

   set(OpenMP_libomp_LIBRARY "${LIMBO_PATH}/lib/libomp.dylib")
   find_package(OpenMP COMPONENTS CXX REQUIRED)
   ```

   Useful resources:
   - [OpenMP linking issue on macOS](https://gist.github.com/scivision/16c2ca1dc250f54d34f1a1a35596f4a0)
   - [CMake Discourse: OpenMP and Clang on macOS](https://discourse.cmake.org/t/how-to-find-openmp-with-clang-on-macos/8860/9)
   - [CMake OpenMP on macOS](https://www.scivision.dev/cmake-openmp/)

### Benchmarking with Gperftools

Gperftools can be used for profiling your program to measure performance. On macOS, follow these steps:

1. Install Gperftools via Homebrew:

   ```bash
   brew install gperftools
   ```

2. Add linking flads to CMake file, note that this flags should be added at linking stage only

```cmake
add_link_options(-lprofiler -ltcmalloc -L/usr/local/lib)
```

2. Run your program with profiling enabled:

   ```bash
   LD_PRELOAD=/usr/local/lib/libprofiler.so CPUPROFILE=./main.prof CPUPROFILE_FREQUENCY=100000 ./main
   ```

3. Analyze the profiling data with `pprof`:

   ```bash
   pprof --text ./main main.prof
   ```

Useful links for Gperftools setup and usage:

- [Profiling with Gperftools](https://developer.ridgerun.com/wiki/index.php/Profiling_with_GPerfTools)
- [Gperftools Documentation](https://goog-perftools.sourceforge.net/doc/cpu_profiler.html)
