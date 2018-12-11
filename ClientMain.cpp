#include "ros/ros.h"
#include "ros_threads/ThreadsServer.h"
#include "ros_threads/Client.hpp"

int main(int argc, char **argv)
{
    /// initialize ROS
    ros::init(argc, argv, "threads_client");
    ros::NodeHandle n;
    ros::ServiceClient client = n.serviceClient<ros_threads::ThreadsServer>("time");
    ros::Rate rate(2.0);    // we want rate of every half a second
    Client clientObj(client);
    while (n.ok())
    {
        clientObj.callService();
        rate.sleep();
    }
}
