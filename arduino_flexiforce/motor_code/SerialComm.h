#ifndef SERIAL_COMM_H
#define SERIAL_COMM_H

#define CMD_MAX_LEN 64

#include <Arduino.h>

class SerialComm{

    public:
        SerialComm();

        //void sendString(String str);
        int getCmdIfAvailable(String &cmd);

};

#endif
