#include <ros/ros.h>
#include "std_msgs/String.h"
#include "msg.h"
class Talker
{
public:
    Talker()
    {
        pub = n.advertise<std_msgs::String>("chatter", 1000);
    }

    void publishMessage()
    {

        msg.data = lib::msg();
        pub.publish(msg);
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
    std_msgs::String msg;
    ros::Rate loop_rate{1};
};

int main(int argc, char **argv)
{
    ros::init(argc, argv, "talker");
    Talker talker;
    talker.run();
    return 0;
}
