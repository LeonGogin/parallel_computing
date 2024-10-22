cmake_minimum_required(VERSION 3.5.0)
project(mpi_test VERSION 0.1.0 LANGUAGES C CXX)

# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}/bin")
set(LESSON_1 "${CMAKE_CURRENT_LIST_DIR}/src/lesson_1")
set(UTILS_PATH "${CMAKE_CURRENT_LIST_DIR}/src/utils")

# add compile flag
add_compile_options(-O3 -march=native)

# add linking flag for profiling fith gperftools
# add_link_options(-lprofiler -ltcmalloc -L/usr/local/lib)
add_subdirectory(${LESSON_1})
add_subdirectory(${UTILS_PATH})

# include Ctest to be able use tests from src/cpp_lib/test
# include(CTest)
add_executable(main "${CMAKE_CURRENT_LIST_DIR}/src/main.cpp")
target_include_directories(main PRIVATE "${LESSON_1}/include" "${UTILS_PATH}/include")
target_link_libraries(main PRIVATE lesson_lib utils)

set_target_properties(main PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED OFF
    CXX_EXTENSIONS OFF
)

if("${CMAKE_CXX_COMPILER_ID}" MATCHES "(GNU|Clang)")
    set_target_properties(main PROPERTIES
        COMPILE_FLAGS "-Wall -Wextra -Wpedantic -Werror"
    )
endif()