#ifndef SERIAL_COMM_H
#define SERIAL_COMM_H

#include <Arduino.h>

class SerialComm{

    public:
        SerialComm();

        String getBlockingCmd();
        void sendString(String str);
};

#endif
