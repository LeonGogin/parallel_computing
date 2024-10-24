cmake_minimum_required(VERSION 3.5.0)
project(lesson_1 VERSION 0.1.0 LANGUAGES CXX)

# Add Catch2 library for test
find_package(Catch2 REQUIRED)

# Fix to include libomp correctly
set(OpenMP_CXX_FLAGS "-fopenmp")
find_package(OpenMP COMPONENTS CXX REQUIRED)

# Include Ctest anc Catch to generate test
include(CTest)
include(Catch)

# Add library target
add_library(lesson_lib STATIC src/lesson_lib.cpp)

# Add test target -> test target will be compiled as separate executable and will be used for tests
add_executable(test_cpp_lib test/test_cpp_lib.cpp)

# Add include path and link library for targest
# note that cpp_lib does not use any external library and does not need a include path
target_include_directories(test_cpp_lib PRIVATE "${CMAKE_CURRENT_LIST_DIR}/include")
target_link_libraries(test_cpp_lib PRIVATE Catch2::Catch2WithMain PRIVATE lesson_lib)
target_link_libraries(lesson_lib PRIVATE OpenMP::OpenMP_CXX utils)

# Set up properties fortargets
set_target_properties(test_cpp_lib lesson_lib PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED OFF
    CXX_EXTENSIONS OFF
)

if("${CMAKE_CXX_COMPILER_ID}" MATCHES "(GNU|Clang)")
    set_target_properties(test_cpp_lib lesson_lib PROPERTIES
        COMPILE_FLAGS "-Wall -Wextra -Wpedantic -Werror"
    )
endif()

# Generate tests
catch_discover_tests(test_cpp_lib)