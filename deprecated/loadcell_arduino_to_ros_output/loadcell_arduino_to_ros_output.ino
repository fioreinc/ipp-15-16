// We will want to create a msg that contains a string primitive
// and the field type Float64. Example shown below:
/*  string first_name
 *  string last_name 
 *  float64 loadcell_data 
 *  
 */
// ROS allows us to use other msg files as a field type within a msg. 
// The previous iteration of the project used the 'ForceSensors' msg (consists of uints for each
// of the flexiforce sensors) as a field type for the Gripper output msg.
// Then within arduino we will have the following header:
// (name_of_ros_msg):: Float64 loadcell_data;
// (name_of_ros_msg):: String first_name;

#include <ros.h>
#include <HX711.h>
#include <std_msgs/Float64.h>
#include <std_msgs/String.h>
#define calibration_factor -7050.0 
#define DOUT  3
#define CLK  2

float absolute_measure; 
//char force[7] = "Force:";
//char pounds[5] = " lbs";
ros::NodeHandle nh;
std_msgs:: Float64 message;
//std_msgs:: String str_msg;
ros::Publisher chatter("chatter", &message);
//ros::Publisher text("text", &str_msg);
HX711 scale(DOUT, CLK);

void setup() {
  
   nh.initNode();
   nh.advertise(chatter);
  // nh.advertise(text);

   scale.set_scale(calibration_factor); //This value is obtained by using the SparkFun_HX711_Calibration sketch
   scale.tare();  //Assuming there is no weight on the scale at start up, reset the scale to 0
  
}

void loop() {

  //str_msg.data = force;
  //text.publish(&str_msg);
  
  //str_msg.data = pounds;
  
  absolute_measure = scale.get_units();
  message.data = abs(absolute_measure);
 /* message.data = scale.get_units(); */
  chatter.publish(&message);
  //text.publish(&str_msg);
  nh.spinOnce();
  delay(100);
  
}
