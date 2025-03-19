#include <pybind11/pybind11.h>

namespace py = pybind11;

void Init_OctreeChangeDetection(py::module &);

namespace octree_change_detection{
    PYBIND11_MODULE(octree, model){
        model.doc() = "for the library of octree change detection";
        Init_OctreeChangeDetection(model);
    }
}
