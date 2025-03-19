#include <iostream>
#include <vector>
#include <pcl/point_cloud.h>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include "octree_change_detection.h"
#include "rclcpp/rclcpp.hpp"

int main() {
    pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud_1 (new pcl::PointCloud<pcl::PointXYZRGB>);
    pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud_2 (new pcl::PointCloud<pcl::PointXYZRGB>);
    std::string pcd_file_path = "/change_detection_ws/src/change_detection/data/";
    std::string full_pcd_path = std::getenv("HOME") + pcd_file_path ;
    std::string pcd_data_path_1 = "000069.pcd";
    std::string pcd_data_path_2 = "000071.pcd";
    std::string full_pad_path_1 = full_pcd_path + pcd_data_path_1 ;
    std::string full_pad_path_2 = full_pcd_path + pcd_data_path_2 ;

    if ((pcl::io::loadPCDFile<pcl::PointXYZRGB> (full_pad_path_1, *cloud_1) == -1) ||
        (pcl::io::loadPCDFile<pcl::PointXYZRGB> (full_pad_path_2, *cloud_2) == -1)) //* load the file
    {
        PCL_ERROR ("Couldn't read file pcd \n");
        return (-1);
    pcl::PointCloud<pcl::PointXYZRGB>::Ptr new_cloud (new pcl::PointCloud<pcl::PointXYZRGB>);
    octree_change_detection ocd;
    ocd.detection_change(cloud_1,cloud_2,new_cloud);
    ocd.view_changed(cloud_1,cloud_2,new_cloud);
    return 0;
}
