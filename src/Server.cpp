#include "ros/ros.h"
#include "ros_threads/ThreadsServer.h"
#include "string"

/**
 * This function implements the server. it computes the current time
 * taken from the ros clock. if the number D received from the request
 * is between 0 and 3 it sleeps for D seconds otherwise it sends a
 * response immediately
 * @param pointers to the request and response of the server
 * @return true if the service was called correctly
 */

bool time(ros_threads::ThreadsServer::Request &req, ros_threads::ThreadsServer::Response &res)
{
    /**
     * The message sent must be type string so we convert the time of
     * type double to type string
     */
    if (req.D < 3 and req.D > 0) ros::Duration(req.D).sleep();    //sleep for D seconds
    res.T = std::to_string(ros::Time::now().toSec());
    ROS_INFO_STREAM("Sending back response: " << res.T);
    return true;
}

/// main ROS loop and Service call
int main (int argc, char **argv)
{
    ros::init(argc, argv, "threads_server");
    ros::NodeHandle n;
    ros::ServiceServer service = n.advertiseService("time", time);
    ROS_INFO("Ready for request");
    ros::spin();

    return 0;
}



