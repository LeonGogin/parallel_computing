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
gcc-13.2 Target: x86_64-apple-darwin22
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
