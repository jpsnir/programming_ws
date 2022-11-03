#include <iostream>
#include <ros/duration.h>
#include <ros/forwards.h>
#include <ros/init.h>
#include <ros/ros.h>
#include <string>
#include <vector>

int main(int argc, char * argv[]){
    ros::init(argc, argv, "param_server_test");
    ros::NodeHandlePtr pnh(new ros::NodeHandle("~"));
    ros::NodeHandlePtr pnh_pub(new ros::NodeHandle());
    for (int i = 0; i < 2; i ++ ){
        std::cout << " Ros is spinning. Node namespace : " << pnh->getNamespace()
        << std::endl;
        ros::spinOnce();
        ros::Duration(1).sleep();
    }

   if (ros::isInitialized()){
        std::string dummy_param_;
        bool exist = pnh_pub->hasParam("dummy");
        pnh_pub->getParam("/dummy", dummy_param_);
        std::cout << " Dummy parameter exists" << exist << "name: " <<
        dummy_param_ << std::endl;
        exist = pnh->hasParam("dummy");
        pnh->getParam("dummy", dummy_param_);
        std::cout << " Dummy parameter exists - private node handle" << exist << "name: " <<
        dummy_param_ << std::endl;
        std::cout << "All parameters from parameter server:" << std::endl;
        std::vector<std::string> param_names;
        pnh->getParamNames(param_names);
        for (auto name : param_names)
        std::cout << name << std:: endl;
        std::cout << "----------------------" << std::endl;
        pnh_pub->getParamNames(param_names);
        for (auto name : param_names)
        std::cout << name << std:: endl;
    }
    return 0;
}
