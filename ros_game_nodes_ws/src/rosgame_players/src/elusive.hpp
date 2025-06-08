//--------------------------------------------------------------------//
//University of Málaga
//MAPIR Research Group - Machine Perception and Intelligent Robotics
//--------------------------------------------------------------------//
#include "rclcpp/rclcpp.hpp"
#include "jsoncpp/json/json.h"
#include "std_msgs/msg/int32.hpp"
#include "std_msgs/msg/string.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "sensor_msgs/msg/laser_scan.hpp"
#include "rosgame_bridge/srv/rosgame_register.hpp"

class Warrior : public rclcpp::Node
{
public:
    Warrior();
    ~Warrior();

    std::string robot_name="-1";

    // Función para procesar el sensor láser.
    void process_laser_info(const sensor_msgs::msg::LaserScan::SharedPtr msg);
    
    // Función para procesar la información de la escena.
    void process_scene_info(const std_msgs::msg::String::SharedPtr msg);
    
    // Función para implementar la navegación autónoma: evitación de obstáculos, huida de enemigos, etc.
    
    std::tuple<double, double, double, double> autonomous_navigation(double nearest_obstacle_distance);
    
    // Función para publicar comandos de velocidad.
    
    void publish_vel(double linear, double angular);
    
    //puedes añadir mas funciones si lo crees oportuno

    //PUBLICADORES
    //============
    // Publicador para enviar comandos de movimiento.
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr pub1_;

    // Publicador para enviar comandos de posición.
    //rclcpp::Publisher<rosgame_msgs::msg::RosgamePoint>::SharedPtr pub2_;

    //SUBSCRIPTORES
    //============
    // Subscripción al topic del sensor láser.
    rclcpp::Subscription<sensor_msgs::msg::LaserScan>::SharedPtr sub1_;
    
    // Subscripción al topic con la información de la escena.
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr sub2_;

    


private:
    // Variables de estado del robot. Puedes añadir las que necesites
    float battery;
    float pos_x, pos_y, gamma;
    bool autopilot_enabled = false, hammer_enabled = false, shield_enabled = false;
    
    //Id code for our robot. 
    
    std::string warrior_nick ="";
    
    // Información de la escena.
    std::vector<std::vector<float>> skills_pos_array;
    std::vector<std::vector<float>> chargers_pos_array;
    std::vector<std::vector<float>> players_pos_array;

    // Variables auxiliares.
    // cualquier otra variable que puedas necesitar
};