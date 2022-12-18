#include "common_interface/msg/trajectory.hpp"
//#include "common_interface/msg/TrajectoryPoint.hpp"
#include <nav_msgs/msg/path.hpp>

namespace TrajectoryGenerator
{
  common_interface::msg::Trajectory generate(const nav_msgs::msg::Path::SharedPtr path)
  {
    // Initialize the trajectory message
    common_interface::msg::Trajectory trajectory;
    trajectory.header = path->header;

    // Iterate through the path points and add them to the trajectory
    for (const auto &point : path->poses)
    {
      common_interface::msg::TrajectoryPoint tp;
      tp.pose = point.pose;
      trajectory.points.push_back(tp);
    }

    return trajectory;
  }
}

