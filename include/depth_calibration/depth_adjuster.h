#ifndef DEPTH_CALIBRATION_DEPTH_ADJUSTER_H_
#define DEPTH_CALIBRATION_DEPTH_ADJUSTER_H_

#include <boost/thread/mutex.hpp>
#include <ros/ros.h>
#include <nodelet/nodelet.h>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/Image.h>
#include <sensor_msgs/CameraInfo.h>

namespace depth_calibration
{

class DepthAdjuster : public nodelet::Nodelet
{
public:
  virtual void onInit();

  virtual void apply_calibration_cb(const sensor_msgs::ImageConstPtr& depth_msg);
  virtual void relay_camera_info(const sensor_msgs::CameraInfoConstPtr& depth_msg);

protected:
  virtual void load_calibration();

  ros::Subscriber sub_depth_raw_;
  ros::Publisher pub_calibrated_depth_raw_;

  cv::Mat depth_multiplier_correction_;
  boost::mutex multiplier_mutex_;

  ros::Subscriber sub_camera_info_;
  ros::Publisher pub_camera_info_relay_;
};

} //end namespace

#endif /* DEPTH_CALIBRATION_DEPTH_ADJUSTER_H_ */
