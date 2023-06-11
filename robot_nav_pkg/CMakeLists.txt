cmake_minimum_required(VERSION 3.8)
project(robot_nav_pkg)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(nav2_msgs REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_action REQUIRED)

# Add the executable target for the action client
add_executable(goal_cancel_client src/goal_cancel_client.cpp)
ament_target_dependencies(goal_cancel_client rclcpp rclcpp_action nav2_msgs)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

# Install the executable
install(TARGETS
  goal_cancel_client
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
