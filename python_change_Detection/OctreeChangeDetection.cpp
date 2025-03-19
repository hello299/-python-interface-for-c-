#include "../change_detection/include/octree_change_detection.h"
#include <pcl-1.10/pcl/point_cloud.h>
#include <pcl-1.10/pcl/point_types.h>
#include <pybind11/pybind11.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <pcl/filters/extract_indices.h>
#include <pcl/visualization/cloud_viewer.h>
#include <pcl/octree/octree_pointcloud_changedetector.h>
#include <pybind11/stl.h>

namespace py = pybind11;

void Init_OctreeChangeDetection(py::module & model)
{
    py::class_<octree_change_detection>(model,"OctreeChangeDetection")
            .def("detection_change",py::overload_cast<pcl::PointCloud<pcl::PointXYZRGB>::Ptr &,
                                    pcl::PointCloud<pcl::PointXYZRGB>::Ptr & ,
                                    pcl::PointCloud<pcl::PointXYZRGB>::Ptr & ,
                                    double >(&octree_change_detection::detection_change),
                                    py::arg("last_frame_pcd"),
                                    py::arg("current_frame_pcd"),
                                    py::arg("new_cloud"),
                                    py::arg("resolution")= 0.1)
            .def("view_changed",py::overload_cast<pcl::PointCloud<pcl::PointXYZRGB>::Ptr & ,
                                pcl::PointCloud<pcl::PointXYZRGB>::Ptr & ,
                                pcl::PointCloud<pcl::PointXYZRGB>::Ptr & >(&octree_change_detection::view_changed),
                                                                             py::arg("cloud1"),
                                                                             py::arg("cloud2"),
                                                                             py::arg("new_cloud"))
            .def("write_new_pcd",py::overload_cast<pcl::PointCloud<pcl::PointXYZRGB>::Ptr & ,
                                                    std::string & ,
                                                    std::string & >(&octree_change_detection::write_new_pcd),
                                                     py::arg("new_cloud"),
                                                     py::arg("pcd_save_name"),
                                                     py::arg("pcd_file_path"));
}