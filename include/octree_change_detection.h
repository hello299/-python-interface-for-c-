#ifndef OCTREE_OCTREE_CHANGE_DETECTION_H
#define OCTREE_OCTREE_CHANGE_DETECTION_H

#include <pcl/octree/octree.h>
#include <pcl/octree/octree_pointcloud_changedetector.h>

#include <pcl/point_types.h>
#include <pcl/octree/octree_pointcloud_changedetector.h>
#include <pcl/filters/passthrough.h>
#include <pcl/point_cloud.h>

#include <pcl/visualization/cloud_viewer.h>
#include <pcl/io/pcd_io.h>
#include <pcl/filters/extract_indices.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <boost/thread/thread.hpp>
#include <boost/filesystem.hpp>
#include <boost/format.hpp>
#include <iostream>
#include <vector>
#include <ctime>
using namespace pcl;
class octree_change_detection
{
private:
    /* data */
public:
    octree_change_detection() = default;
    ~octree_change_detection() = default;
    pcl::PointCloud<pcl::PointXYZRGB>::Ptr detection_change(pcl::PointCloud<pcl::PointXYZRGB>::Ptr & last_frame_pcd ,
                                                          pcl::PointCloud<pcl::PointXYZRGB>::Ptr & current_frame_pcd ,
                                                          pcl::PointCloud<pcl::PointXYZRGB>::Ptr & new_cloud,
                                                          double resolution= 0.1);
    void view_changed(pcl::PointCloud<pcl::PointXYZRGB>::Ptr & cloud1 , pcl::PointCloud<pcl::PointXYZRGB>::Ptr & cloud2,pcl::PointCloud<pcl::PointXYZRGB>::Ptr & new_cloud);
    bool write_new_pcd(pcl::PointCloud<pcl::PointXYZRGB>::Ptr & new_cloud ,std::string & pcd_save_name ,std::string &pcd_file_path);
};


#endif //OCTREE_OCTREE_CHANGE_DETECTION_H