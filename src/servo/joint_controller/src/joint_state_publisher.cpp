#include <ros/ros.h>
#include <tf/transform_listener.h>
#include <geometry_msgs/Twist.h>
#include <nav_msgs/Odometry.h>
#include <geometry_msgs/Quaternion.h>
#include <geometry_msgs/Vector3.h>
#include <ros/console.h>
#include <geometry_msgs/Pose.h>
#include <sensor_msgs/Imu.h>
#include <tf/transform_datatypes.h>

// Message publication
#include <std_msgs/MultiArrayLayout.h>
#include <std_msgs/MultiArrayDimension.h>
#include <std_msgs/Float32MultiArray.h>
#include <std_msgs/Float64.h>
#include <std_msgs/Float64.h>
#include <sstream>
#include <math.h>

using namespace std;
float thetha;

    // publisher declaration
ros::Publisher shoulder_roll_joint;

void OrientationCallback(const sensor_msgs::Imu::ConstPtr& msg)
{
  float quatx= msg->orientation.x;
  float quaty= msg->orientation.y;
  float quatz= msg->orientation.z;
  float quatw= msg->orientation.w;
  thetha=3*asin(2*(quatw*quaty-quatz*quatx));
}



int main(int argc, char** argv)
{
    ros::init(argc, argv, "strt_script");
    ros::NodeHandle nh;

    // publisher declaration

    shoulder_roll_joint = nh.advertise<std_msgs::Float64>("/servo/joint1_position_controller/command", 1);
    ros::Subscriber sub= nh.subscribe("/mavros/imu/data",1000,OrientationCallback); //For eg the publisher for servo data is /mavros/imu/data

    ros::Rate rate(50.0); // frequency of operation

    while (ros::ok())
    {
        std_msgs::Float64 Joint0;

        Joint0.data = thetha;

        shoulder_roll_joint.publish(Joint0);


        ros::spinOnce();
        rate.sleep();
    }
    return 0;

}
