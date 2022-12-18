#ifndef TRAJECTORY_GENERATOR_HPP
#define TRAJECTORY_GENERATOR_HPP

#include <common_interface/msg/trajectory.hpp>
#include <nav_msgs/msg/path.hpp>

namespace TrajectoryGenerator
{
  common_interface::msg::Trajectory generate(const nav_msgs::msg::Path::SharedPtr path);
}

#endif

