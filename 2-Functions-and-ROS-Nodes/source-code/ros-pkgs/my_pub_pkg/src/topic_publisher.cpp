#include <ros/ros.h>
#include <std_msgs/Int32.h>

int main(int argc, char** argv) {

    // Initialize the ROS node
    ros::init(argc, argv, "topic_publisher");

    // Create a NodeHandle object
    ros::NodeHandle nh;

    // Create a publisher object that will publish to the 'counter' topic
    ros::Publisher pub = nh.advertise<std_msgs::Int32>("counter", 1000);

    // Set the loop rate to 2 Hz (2 times per second)
    ros::Rate loop_rate(2);

    // Initialize the counter message with an integer value
    std_msgs::Int32 count;
    count.data = 0;

    // Main loop to continuously publish messages
    while (ros::ok())
    {
        // Publish the counter message to the topic
        pub.publish(count);

        // Allow ROS to process callbacks
        ros::spinOnce();

        // Sleep to maintain the loop rate (2 Hz)
        loop_rate.sleep();

        // Increment the counter value
        ++count.data;
    }

    return 0;
}
