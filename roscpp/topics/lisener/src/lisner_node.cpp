#include <ros/ros.h>
#include "std_msgs/String.h"

class Subscriber
{
public:
    Subscriber()
    {
        sub = n.subscribe("chatter", 1000, &Subscriber::callback, this);
    }

    void callback(const std_msgs::String::ConstPtr &msg)
    {
        ROS_INFO("I heard: [%s]", msg->data.c_str());
    }

private:
    ros::NodeHandle n;
    ros::Subscriber sub;
};

int main(int argc, char **argv)
{

    int32_t ret = 0;
    try
    {
        ros::init(argc, argv, "subscriber");
        Subscriber sub;

        ros::spin();
        ros::shutdown();
        if (ros::ok())
        {
            throw std::runtime_error{"Could not shutdown rclcpp"};
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what();
        ret = __LINE__;
    }
    catch (...)
    {
        std::cerr << "Unknown error occured";
        ret = __LINE__;
    }

    return ret;
}
