#include "SerialComm.h"

SerialComm::SerialComm(){
    Serial.begin(9600);
}

/* Command Syntax 
 * Start with "[" character
 * End with "]" character
 * Examples:
 * * * [grip]
 * * * [release]
*/

enum CmdState{
    GET_START,
    GET_BODY,
    ENDED
};


//Returns the length of the command received, or -1
//if a valid command was not provided
int SerialComm::getCmdIfAvailable(String &cmd){
    if(Serial.available() <= 0){
        return -1; //Nothing available, exit
    }

    //If data available, read it and return it
    int char_count = 0;
    char next_char;
    CmdState state = GET_START;
    while(Serial.available() > 0){ //Read all available data
        cmd += Serial.readString();
    }
    return char_count;
}
