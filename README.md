# ROS2-Robot-Navigation
The goal of this project is to,
- navigate a turtlebot using Rviz2, and 
- develop a navigation system for the robot using ROS 2 and Nav2 to cancel goals to the navigation stack.

This repository contains the code and configuration files for the ROS2 package.

## Terms
- Nav2
- ROS2 action client
- /navigate_to_pose
- /bt_navigator
- /rviz

## Understanding
When navigating the turtlebot using Rviz2,
- **/rviz** node has an action client and acts as an action client node. It sends navigation goals for action **/navigate_to_pose** with action type **nav2msgs/action/NavigateToPose**. 
- The **/bt_navigator** node has an action server for the **/navigate_to_pose** action and acts as an action server node. It receives the navigation goals, executes the action and sends back feedback and result.

The new ROS2 package is created to create a new action client additional to Rviz for cancelling the navigation goals. Thus making it in total 2 action client nodes - **/rviz** and **/nav2_send_goal**.

## Getting Started

### Prerequisites

- ROS2: Make sure you have ROS2 installed on your system. Refer to the official ROS2 documentation for installation instructions.

### Installation

1. Clone the repository:

   ```bash
   git clone https://github.com/SriHasitha/ROS2-Robot-Navigation.git
   
2. Build the package:
   ```bash
   colcon build

## Usage

1. Set environment variables for Gazebo:

   ```bash
   export TURTLEBOT3_MODEL=waffle
   export GAZEBO_MODEL_PATH=$GAZEBO_MODEL_PATH:/opt/ros/humble/share/turtlebot3_gazebo/models

2. Launch the ROS2 navigation stack:
 
   ```bash
   ros2 launch nav2_bringup tb3_simulation_launch.py headless:=False
   
3. Set the initial start position for the turtlebot using '2D Pose Estimate' button on Rviz.
4. Navigate the robot to a specific location using 'Nav2 Goal' button on Rviz.
5. Run the package action client to cancel the navigation goal:

   ```bash
   ros2 run robot_nav_pkg goal_cancel_client



   

