# cmake_minimum_required(VERSION <specify CMake version here>)
cmake_minimum_required(VERSION 3.5)
project(octree)

EXECUTE_PROCESS( COMMAND uname -m COMMAND tr -d '\n' OUTPUT_VARIABLE ARCH )
message( STATUS "Architecture: ${ARCH}" )
# c_standard c99
if (NOT CMAKE_C_STANDARD)
    set(CMAKE_C_STANDARD 99)
endif ()
# default c++ 14
if (NOT CMAKE_CXX_STANDARD)
    set(CMAKE_CXX_STANDARD 14)
endif ()
set(CMAKE_BUILD_TYPE "Release")

set(CMAKE_CXX_FLAGS_RELEASE "-O3 -Wall -g -pthread ")

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()


find_package(PCL REQUIRED)
find_package(Boost REQUIRED COMPONENTS thread filesystem system)
find_package(OpenCV REQUIRED)

include_directories(
        include
        ${PCL_INCLUDE_DIRS}
        ${OpenCV_INCLUDE_DIRS}
        ${Boost_INCLUDE_DIRS}
)
link_directories(
        ${PCL_LIBRARY_DIRS}
        ${Boost_LIBRARIES}
        )

file(GLOB_RECURSE SRC_LIST
        src/octree_change_detection.cpp
        )
        
set(PROJECT_SOURCE_DIR "src")
set(PROJECT_INCLUDE_DIR "include")

set(SOURCE_FILES
    ${PROJECT_INCLUDE_DIR}/octree_change_detection.h
    ${PROJECT_SOURCE_DIR}/octree_change_detection.cpp
)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_FILES})

# Add library
add_library(octree SHARED ${SOURCE_FILES})

# Include directories
target_include_directories(octree PRIVATE include)

# Install
install(TARGETS octree DESTINATION lib)

# Install the headers
install(FILES include/octree_change_detection DESTINATION include)

# Create base directory
install(DIRECTORY include DESTINATION include)

#-- Install configuration: "Debug"
#-- Installing: /usr/local/lib/liboctree.so
#-- Installing: /usr/local/include/octree_change_detection
#-- Installing: /usr/local/include/include
#-- Installing: /usr/local/include/include/octree_change_detection
#-- Installing: /usr/local/include/include/octree_change_detection.h