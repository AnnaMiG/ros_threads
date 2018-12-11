#ifndef CLIENT_HPP
#define CLIENT_HPP
#include "ros/ros.h"
#include "ros_threads/ThreadsServer.h"


class Client
{
private:
    ros_threads::ThreadsServer srv;
public:
    Client(ros::ServiceClient client);
    void callService();
    ros::ServiceClient client;
};

#endif /// CLIENT_HPP 
