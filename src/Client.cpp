#include "ros/ros.h"
#include "ros_threads/ThreadsServer.h"
#include "std_msgs/String.h"
#include "ros_threads/Client.hpp"


/**
 * this class creates the client code
 */
Client::Client(ros::ServiceClient cl)
:client(cl)
{
ros_threads::ThreadsServer srv;
}
    /**
     * This function listens to the server and finds the difference between the response_time
     * taken from the server and the current unix_time_nanosec computed from the ros clock
     * The variable count is used because we want the difference to be printed every second
     * but the callService function is called every half a second. the variable count takes
     * the values 0 and 1 alternately and only prints the difference when its value is 0.
     * @param the client
     */
    void Client::callService()
    {
        /// current time
        ROS_INFO("Current Time: * %lf *", ros::Time::now().toSec());
        int count = 0;
        if(count == 0)
        {
            srv.request.D = rand() % 6;    // send as a request a random number
            if(client.call(srv))
            {
                ROS_INFO_STREAM("Time received:" << srv.response.T);
            }
            else
            {
                ROS_ERROR("Service not called");
            }
            //client.call(srv) ? ROS_INFO_STREAM("Time received:" << srv.response.T) : ROS_ERROR("Service not called");
            ROS_INFO("Time Difference: * %lf *", ros::Time::now().toSec() - std::stod(srv.response.T,NULL));
            count = 1;
        }
        else count = 0;
    }





