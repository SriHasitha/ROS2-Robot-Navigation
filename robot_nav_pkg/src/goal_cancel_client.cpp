#include <memory>
#include <chrono>
#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"
#include "nav2_msgs/action/navigate_to_pose.hpp"
#include "rclcpp/time.hpp"

using namespace std::chrono_literals;
using std::placeholders::_1;
using std::placeholders::_2;

class Nav2Client : public rclcpp::Node
{
public:
  using NavigateToPose = nav2_msgs::action::NavigateToPose;
  using GoalHandleNavigateToPose = rclcpp_action::ClientGoalHandle<NavigateToPose>;
  rclcpp_action::Client<NavigateToPose>::SharedPtr client_ptr_;

  explicit Nav2Client(): Node("nav2_send_goal")
  {
    // Create the action client
    this->client_ptr_  = rclcpp_action::create_client<NavigateToPose>(this, "navigate_to_pose");
  }

  void cancelGoals()
  {
    // Check if the action server is available
    if (!this->client_ptr_->wait_for_action_server())
    {
      RCLCPP_INFO(get_logger(), "Action server not available");
      return;
    }
    // Send the cancel goal request
    auto cancel_future = client_ptr_->async_cancel_all_goals();
    auto cancel_result = cancel_future.wait_for(std::chrono::seconds(1));

    if (cancel_result == std::future_status::ready)
    {
      RCLCPP_INFO(get_logger(), "Cancel goal request sent successfully");
    }
    else
    {
      RCLCPP_INFO(get_logger(), "Failed to send cancel goal request");
    }
  }
};

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<Nav2Client>();
  node->cancelGoals();
  rclcpp::spin_some(node->get_node_base_interface());
  rclcpp::shutdown();
  return 0;
}