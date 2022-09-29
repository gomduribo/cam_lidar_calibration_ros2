// Copyright 2016 Open Source Robotics Foundation, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
/*
#include "sensor_msgs/msg"
*/
using std::placeholders::_1;

class MinimalSubscriber : public rclcpp::Node
{
public:
  MinimalSubscriber()
  : Node("minimal_subscriber")
  {
    subscription_ = this->create_subscription<std_msgs::msg::String>(
      "topic", 10, std::bind(&MinimalSubscriber::topic_callback, this, _1));
  }

private:
  void topic_callback(const std_msgs::msg::String::SharedPtr msg) const
  {
    RCLCPP_INFO(this->get_logger(), "I heard: '%s'", msg->data.c_str());
  }
//   void callback_depth_image_d435 (const sensor_msgs::msg::PointCloud2::SharedPtr point_cloud2_msgs)
//  {

//    pcl::PointCloud<pcl::PointXYZ> point_cloud;
//    pcl::fromROSMsg(*point_cloud2_msgs, point_cloud);     

//    BOOST_FOREACH(const pcl::PointXYZ& pt, point_cloud.points)
//    {          
//        std::cout  << "x: " << pt.x <<"\n";
//        std::cout  << "y: " << pt.y <<"\n";
//        std::cout  << "z: " << pt.z <<"\n";
//        std::cout << "---------" << "\n";
//    }
//  }
  rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MinimalSubscriber>());
  rclcpp::shutdown();
  return 0;
}
