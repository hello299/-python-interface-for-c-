cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_FLAGS "-O3")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

project(octree)

include_directories("${CMAKE_SOURCE_DIR}/change_detection/include")
include_directories("${CMAKE_SOURCE_DIR}/python_change_Detection")

file (GLOB SOURCE_FILES "change_detection/src/*.cpp")
file (GLOB HEADER_FILES "change_detection/include/*.h")
file (GLOB PYTHON_FILES "python_change_Detection/*.cpp" "python_change_Detection/*.hpp")

# Set up such that XCode organizes the files
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_FILES} ${HEADER_FILES} ${PYTHON_FILES} )
add_subdirectory(thirdparty/pybind11)
pybind11_add_module(octree
        ${SOURCE_FILES}
        ${HEADER_FILES}
        ${PYTHON_FILES}
        )
set(CMAKE_VERBOSE_MAKEFILE ON)
find_package(PCL REQUIRED)
find_package(Boost REQUIRED COMPONENTS thread filesystem system)
include_directories(
        ${PCL_INCLUDE_DIRS}
        ${Boost_INCLUDE_DIRS}
)
link_directories(
        ${PCL_LIBRARY_DIRS}
        ${Boost_LIBRARIES}
)
target_link_libraries(octree PUBLIC ${PCL_LIBRARIES} ${Boost_LIBRARIES})
set(PYTHON_LIBRARY_DIR "/usr/local/lib/python3.8")
set(PYTHON_EXECUTABLE "/usr/bin/python3.8")
install(TARGETS octree
        COMPONENT python
        LIBRARY DESTINATION "${PYTHON_LIBRARY_DIR}"
        )
