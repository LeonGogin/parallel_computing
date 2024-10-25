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
   ```

2. Build the project using CMake:

   ```bash
   mkdir build
   cd build
   cmake ..
   make
   ```
