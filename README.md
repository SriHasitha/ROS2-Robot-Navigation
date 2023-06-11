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
   git clone https://github.com/your-username/your-repository.git

