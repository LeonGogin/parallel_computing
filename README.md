
<https://developer.ridgerun.com/wiki/index.php/Profiling_with_GPerfTools>
<https://goog-perftools.sourceforge.net/doc/cpu_profiler.html>

LD_PRELOAD=/usr/local/lib/libprofiler.so CPUPROFILE=./main.prof CPUPROFILE_FREQUENCY=100000 ./main

pprof --text ./main main.prof
