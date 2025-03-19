#include "octree_change_detection.h"

pcl::PointCloud<pcl::PointXYZRGB>::Ptr octree_change_detection::detection_change(pcl::PointCloud<pcl::PointXYZRGB>::Ptr & last_frame_pcd ,
                                                                               pcl::PointCloud<pcl::PointXYZRGB>::Ptr & current_frame_pcd ,
                                                                               pcl::PointCloud<pcl::PointXYZRGB>::Ptr & new_cloud,
                                                                               double resolution)
{
    srand ((unsigned int) time (NULL));

    pcl::PointCloud<pcl::PointXYZRGB>::Ptr newCloud(new pcl::PointCloud<pcl::PointXYZRGB>);


    // Instantiate octree-based point cloud change detection class
    pcl::octree::OctreePointCloudChangeDetector<pcl::PointXYZRGB> octree(resolution);

    // Add points from cloudA to octree
    octree.setInputCloud (last_frame_pcd);
    octree.addPointsFromInputCloud ();

    octree.switchBuffers();
    octree.setInputCloud(current_frame_pcd);
    octree.addPointsFromInputCloud();

    pcl::PointIndices::Ptr inliers (new::pcl::PointIndices());
    octree.getPointIndicesFromNewVoxels(inliers->indices);
     new_cloud.reset(new pcl::PointCloud<pcl::PointXYZRGB>);
    pcl::copyPointCloud(*current_frame_pcd,inliers->indices,*new_cloud);
    std::cout<<new_cloud->points.size()<<std::endl;

    return newCloud;
}

void octree_change_detection::view_changed(pcl::PointCloud<pcl::PointXYZRGB>::Ptr &cloud1,
                                           pcl::PointCloud<pcl::PointXYZRGB>::Ptr &cloud2,
                                           pcl::PointCloud<pcl::PointXYZRGB>::Ptr &new_cloud) {
    boost::shared_ptr<pcl::visualization::PCLVisualizer> pcl_viewer(new pcl::visualization::PCLVisualizer("new change"));
    pcl_viewer->setBackgroundColor(0,0,0);
    pcl_viewer->addPointCloud<pcl::PointXYZRGB>(cloud1,pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZRGB>(cloud1,0,255,0),"raw cloud1"); //green
    pcl_viewer->addPointCloud<pcl::PointXYZRGB>(cloud2,pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZRGB>(cloud2,255,0,0),"raw cloud2"); //red
    pcl_viewer->addPointCloud<pcl::PointXYZRGB>(new_cloud , pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZRGB>(new_cloud,0,0,255),"sampled cloud");//blue
    pcl_viewer->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 3, "raw cloud1");
    pcl_viewer->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 3, "raw cloud2");
    pcl_viewer->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 5, "sampled cloud");

    while (!pcl_viewer->wasStopped())
    {
        pcl_viewer->spinOnce(100);
        boost::this_thread::sleep(boost::posix_time::microseconds(100000));
    }
}

bool octree_change_detection::write_new_pcd(pcl::PointCloud<pcl::PointXYZRGB>::Ptr &new_cloud,
                                            std::string &pcd_save_name, std::string &pcd_file_path) {
    if (!boost::filesystem::exists(pcd_file_path) ||
        ((boost::filesystem::exists(pcd_file_path) && !boost::filesystem::is_directory(pcd_file_path))))
        boost::filesystem::create_directories(pcd_file_path);
    try {
        boost::format fmt_pcd("%s/%s.%s");
        pcl::io::savePCDFileASCII((fmt_pcd % pcd_file_path % pcd_save_name % "pcd").str(), *new_cloud);
        return true;
    } catch (pcl::IOException &e) {
        printf("error is %s \n", e.what());
        return false;
    }
}