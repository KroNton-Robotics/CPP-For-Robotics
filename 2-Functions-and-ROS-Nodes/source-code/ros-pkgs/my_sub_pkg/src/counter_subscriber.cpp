#include "ros/ros.h"
#include "std_msgs/Int32.h"

// Callback function to handle incoming messages
void counterCallback(const std_msgs::Int32::ConstPtr& msg)
{
    // Retrieve the integer value from the message
    int received_value = msg->data;

    // Multiply the received value by two
    int result = received_value * 2;

    // Log the result
    ROS_INFO("Received value: %d, Multiplied by two: %d", received_value, result);
}

int main(int argc, char **argv)
{
    // Initialize the ROS node
    ros::init(argc, argv, "counter_subscriber");

    // Create a NodeHandle
    ros::NodeHandle nh;

    // Create a Subscriber object and subscribe to the /counter topic
    ros::Subscriber sub = nh.subscribe("/counter", 1000, counterCallback);

    // Spin to keep the node alive and process incoming messages
    ros::spin();

    return 0;
}