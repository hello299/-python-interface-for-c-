include(FetchContent)

set(FETCHCONTENT_QUIET FALSE)

FetchContent_Declare(
        change_detection/pybind11
    URL https://github.com/pybind/pybind11/archive/v2.3.0.tar.gz
    )

FetchContent_GetProperties(change_detection/pybind11)

if(NOT pybind11_POPULATED)
    FetchContent_Populate(change_detection/pybind11)
    add_subdirectory(${pybind11_SOURCE_DIR} ${pybind11_BINARY_DIR})
endif()
