#include <rclcpp/rclcpp.hpp>
#include <trajectory_generator.hpp>

class TrajectoryNode : public rclcpp::Node
{
public:
  TrajectoryNode()
  : Node("trajectory_node")
  {
    // Subscribe to the "path" topic
    path_sub_ = this->create_subscription<nav_msgs::msg::Path>("path",10,
      std::bind(&TrajectoryNode::path_callback, this, std::placeholders::_1));

 

    // Advertise the "trajectory" topic
    trajectory_pub_ = this->create_publisher<common_interface::msg::Trajectory>("trajectory", 10);
  }

private:
  void path_callback(const nav_msgs::msg::Path::SharedPtr msg)
  {
    // Generate the trajectory using the path and the trajectory generator library
    auto trajectory = TrajectoryGenerator::generate(msg);

    // Publish the trajectory on the "trajectory" topic
    trajectory_pub_->publish(trajectory);
  }

  rclcpp::Subscription<nav_msgs::msg::Path>::SharedPtr path_sub_;
  rclcpp::Publisher<common_interface::msg::Trajectory>::SharedPtr trajectory_pub_;
};

int main(int argc, char *argv[])
{
  // Initialize the ROS2 node
  rclcpp::init(argc, argv);

  // Create the node and spin it
  rclcpp::spin(std::make_shared<TrajectoryNode>());

  // Shutdown the ROS2 node
  rclcpp::shutdown();

  return 0;
}

