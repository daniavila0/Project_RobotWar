//--------------------------------------------------------------------//
//University of Málaga
//MAPIR Research Group - Machine Perception and Intelligent Robotics
//--------------------------------------------------------------------//

#include "warrior.hpp"

Warrior::Warrior(): Node ("robot_warrior")
{
    warrior_nick = "UsuarioRosgame";
    int cont = 0;

    // Se crea un cliente de servicio y una solicitud para lanzar el servicio.
    auto client = create_client<rosgame_bridge::srv::RosgameRegister>("register_service");
    
    auto request = std::make_shared<rosgame_bridge::srv::RosgameRegister::Request>();
    request -> username = warrior_nick;
    
    // Se espera a que el servicio esté disponible.
    bool service_available = false;
    while(!service_available && rclcpp::ok())
    {
        if (client->wait_for_service(std::chrono::seconds(5)))
        {   service_available = true;   }
        else
        {   RCLCPP_INFO(this->get_logger(), "Service not available. Retrying...");  }
    }
    
    // Se llama al servicio hasta que la respuesta sea diferente a "-1". Este valor indica que ya existe un jugador registrado con el nombre de usuario proporcionado.
    RCLCPP_INFO(this->get_logger(), "Esta llegando el siguiene robot_name: '%s'",robot_name.c_str());
    while (robot_name == "-1" && rclcpp::ok())
    {   
        auto future = client->async_send_request(request);
        if (rclcpp::spin_until_future_complete(this->get_node_base_interface(), future) == rclcpp::FutureReturnCode::SUCCESS)
        {
            auto response = future.get();
            robot_name = response->robot_name;

            if (robot_name == "-1")
            {
                RCLCPP_WARN(this->get_logger(), "Username already exists. Calling the service again...");
                warrior_nick= warrior_nick + std::to_string(cont);
                request -> username = warrior_nick;
                cont = cont + 1;
            }
            else
            {   
                // Se definen los publicadores y suscriptores necesarios.
                pub1_ = create_publisher<geometry_msgs::msg::Twist>( "/" + robot_name + "/cmd_vel", 10 );
                //pub2_ = create_publisher<rosgame_msgs::msg::RosgamePoint>( "/" + robot_name + "/goal_x_y", 10 );
                sub1_ = create_subscription<sensor_msgs::msg::LaserScan>( "/" + robot_name + "/laser_scan", 10, std::bind(&Warrior::process_laser_info, this, std::placeholders::_1));
                sub2_ = create_subscription<std_msgs::msg::String>( "/" + robot_name + "/scene_info", 10, std::bind(&Warrior::process_scene_info, this, std::placeholders::_1));
                RCLCPP_INFO(this->get_logger(), "Player registered. Starting simulation.");           
            }
        }
    }




}

Warrior::~Warrior()
{
     RCLCPP_ERROR(this->get_logger(), "Game over for [%s]", warrior_nick.c_str());
}

void Warrior::process_laser_info(const sensor_msgs::msg::LaserScan::SharedPtr msg)
{
    //Aquí tu código cada vez que recibas información del láser
}


void Warrior::process_scene_info(const std_msgs::msg::String::SharedPtr msg)
{
       RCLCPP_INFO(this->get_logger(), "Processing scene data");

    Json::CharReaderBuilder reader;
    Json::Value JsonSceneData;
    std::istringstream jsonStream(msg->data);
    Json::parseFromStream(reader, jsonStream, &JsonSceneData, nullptr);

    // Obtener la batería
    if (JsonSceneData.isMember("Battery")) {
        battery = JsonSceneData["Battery"].asFloat();
    } else {
        RCLCPP_WARN(this->get_logger(), "No se encontró el campo 'Battery' en el JSON");
    }

    // Obtener la pose del robot
    if (JsonSceneData.isMember("Pose") && JsonSceneData["Pose"].isArray() && JsonSceneData["Pose"].size() == 3) {
        pos_x = JsonSceneData["Pose"][0].asFloat();
        pos_y = JsonSceneData["Pose"][1].asFloat();
        gamma = JsonSceneData["Pose"][2].asFloat();
    } else {
        RCLCPP_WARN(this->get_logger(), "No se encontró una 'Pose' válida");
    }

    // Obtener habilidades
    if (JsonSceneData["Skill"].isObject()) {
        hammer_enabled = JsonSceneData["Skill"]["Hammer"].asBool();
        shield_enabled = JsonSceneData["Skill"]["Shield"].asBool();
    } else {
        RCLCPP_WARN(this->get_logger(), "No se encontró el objeto 'Skill' en el JSON");
    }

    

    // Los array del FOV quedan vacios 
    skills_pos_array.clear();
    chargers_pos_array.clear();
    players_pos_array.clear();

    
    // DEBUGGING
    
    RCLCPP_INFO(this->get_logger(), "Msg: '%s'", msg->data.c_str());

    RCLCPP_INFO(this->get_logger(), "Battery level: '%f'", battery);

    RCLCPP_INFO(this->get_logger(), "Is the hammer enabled? '%s'", (hammer_enabled ? "True" : "False"));
    RCLCPP_INFO(this->get_logger(), "Is the shield enabled? '%s'", (shield_enabled ? "True" : "False"));
    /*
    if (!skills_pos_array.empty())
    {
        RCLCPP_INFO(this->get_logger(), "Skills Positions Array:");
        for (const auto &skill_pos : skills_pos_array)
        {   RCLCPP_INFO(this->get_logger(), "[X] = '%f', [Y] = '%f'", skill_pos[0], skill_pos[1]);  }
    }
    */
    RCLCPP_INFO(this->get_logger(), "Robot Pose: [X] = '%f', [Y] = '%f', [GAMMA] = '%f'", pos_x, pos_y, gamma);
    
}


