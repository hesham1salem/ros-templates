#include <ros/ros.h>
#include "std_msgs/String.h"
#include "msg.h"
class Talker_lisner
{
public:
    Talker_lisner()
    {
        pub = n.advertise<std_msgs::String>("chatter", 1000);
        sub = n.subscribe("chatter", 1000, &Talker_lisner::callback, this);
    }

    void publishMessage()
    {

        msg.data = lib::msg();
        pub.publish(msg);
    }
    void callback(const std_msgs::String::ConstPtr &msg)
    {
        ROS_INFO("I heard: [%s]", msg->data.c_str());
    }
    void run()
    {
        while (ros::ok())
        {
            publishMessage();
            loop_rate.sleep();
        }
    }

private:
    ros::NodeHandle n;
    ros::Publisher pub;
    ros::Subscriber sub;
    std_msgs::String msg;
    ros::Rate loop_rate{1};
};

int main(int argc, char **argv)
{
    int32_t ret = 0;
    try
    {
        ros::init(argc, argv, "Talker_lisner");
        Talker_lisner _Talker_lisner;
        _Talker_lisner.run();
        ros::shutdown();

        if (ros::ok())
        {
            throw std::runtime_error{"Could not shutdown roscpp"};
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