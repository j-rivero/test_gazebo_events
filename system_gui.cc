/*
 * Copyright (C) 2012 Open Source Robotics Foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
*/

#include <functional>
#include <gazebo/gui/GuiIface.hh>
#include <gazebo/rendering/rendering.hh>
#include <gazebo/gazebo.hh>

namespace gazebo
{
  class MyEventPlugin : public SystemPlugin
  {
    /////////////////////////////////////////////
    /// \brief Called after the plugin has been constructed.
    public: void Load(int /*_argc*/, char ** /*_argv*/)
    {
      this->_onAddEntityConnection =
          event::Events::ConnectAddEntity( [ this ]( auto added ) { onAddEntity( added ); }
        );
    }

    /////////////////////////////////////////////
    // \brief Called once after Load
    private: void Init()
    {
    }

    /////////////////////////////////////////////
    private: void onAddEntity( std::string added )
    {
      gzwarn << "Activated onAddEntity event with name: " << added << std::endl;
    }

    /// All the event connections.
    private: event::ConnectionPtr _onAddEntityConnection;
  };

  // Register this plugin with the simulator
  GZ_REGISTER_SYSTEM_PLUGIN(MyEventPlugin)
}
