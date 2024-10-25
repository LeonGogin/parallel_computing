# Benchmarckiing tools

## Benchmarking with Valgring

1. Install Gperftools via Homebrew:

   ```bash
   brew tap LouisBrunner/valgrind
   brew install --HEAD LouisBrunner/valgrind/valgrind
   brew install gperftools
   ```

2. install Qcachegrind

```bash
brew install qcachegrind
```

3. Run cpu profiler

```bash
valgrind --tool=callgrind ./main 10000000
```

4. Run cache miss profiler

```bash
valgrind --tool=cachegrind ./main 10000000
```

## Benchmarking with Gperftools

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
