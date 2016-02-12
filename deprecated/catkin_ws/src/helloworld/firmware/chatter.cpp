#include <ros.h>
#include <std_msgs/String.h>
#include <helloworld/TestMsg.h>

#include <Arduino.h>

ros::NodeHandle nh;

std_msgs::String str_msg;
ros::Publisher chatter("chatter", &str_msg);

char hello[13] = "hello world!";

void setup(){
    nh.initNode();
    nh.advertise(chatter);
    pinMode(13, OUTPUT);
}

void loop(){
    str_msg.data = hello;
    chatter.publish(&str_msg);
    nh.spinOnce();
}
