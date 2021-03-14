// Copyright 2021 Open Source Robotics Foundation, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef IGNITION_ROS2_CONTROL__IGNITION_ROS2_CONTROL_PLUGIN_HPP_
#define IGNITION_ROS2_CONTROL__IGNITION_ROS2_CONTROL_PLUGIN_HPP_

#include <memory>

#include "ignition/gazebo/System.hh"

namespace ignition_ros2_control
{
// Forward declarations.
class IgnitionROS2ControlPluginPrivate;

class IgnitionROS2ControlPlugin
  : public ignition::gazebo::System,
  public ignition::gazebo::ISystemConfigure,
  public ignition::gazebo::ISystemUpdate
{
  /// \brief Constructor

public:
  IgnitionROS2ControlPlugin();

  /// \brief Destructor

public:
  ~IgnitionROS2ControlPlugin() override = default;

  // Documentation inherited

public:
  void Configure(
    const ignition::gazebo::Entity & _entity,
    const std::shared_ptr<const sdf::Element> & _sdf,
    ignition::gazebo::EntityComponentManager & _ecm,
    ignition::gazebo::EventManager & _eventMgr) override;

  // Documentation inherited

public:
  void Update(
    const ignition::gazebo::UpdateInfo & _info,
    ignition::gazebo::EntityComponentManager & _ecm) override;

  /// \brief Private data pointer.

private:
  std::unique_ptr<IgnitionROS2ControlPluginPrivate> dataPtr;
};
}  // namespace ignition_ros2_control

#endif  // IGNITION_ROS2_CONTROL__IGNITION_ROS2_CONTROL_PLUGIN_HPP_