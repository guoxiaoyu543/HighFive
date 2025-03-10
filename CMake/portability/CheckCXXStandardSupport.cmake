#
# Basic check for C++ compiler startndard support
#

include(CheckCXXCompilerFlag)

# Set flags for older CMake
if(${CMAKE_VERSION} VERSION_LESS 3.10)
    if (CMAKE_CXX_COMPILER_ID MATCHES "(GNU|Clang|AppleClang|Intel|PGI|XL)")
        set(CMAKE_CXX11_STANDARD_COMPILE_OPTION "-std=c++11")
        set(CMAKE_CXX14_STANDARD_COMPILE_OPTION "-std=c++14")
        set(CMAKE_CXX17_STANDARD_COMPILE_OPTION "-std=c++17")
    elseif(CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
        set(CMAKE_CXX11_STANDARD_COMPILE_OPTION "/std:c++11")
        set(CMAKE_CXX14_STANDARD_COMPILE_OPTION "/std:c++14")
        set(CMAKE_CXX17_STANDARD_COMPILE_OPTION "/std:c++17")
    endif()
endif()

check_cxx_compiler_flag("${CMAKE_CXX11_STANDARD_COMPILE_OPTION}" COMPILER_SUPPORTS_CXX11)
check_cxx_compiler_flag("${CMAKE_CXX14_STANDARD_COMPILE_OPTION}" COMPILER_SUPPORTS_CXX14)
check_cxx_compiler_flag("${CMAKE_CXX17_STANDARD_COMPILE_OPTION}" COMPILER_SUPPORTS_CXX17)
