//#include <SoftwareSerial.h>

//SoftwareSerial XBee(2, 3); // RX, TX

int data_received = 0;
void setup()
{
    // Set up both ports at 9600 baud. This value is most important
    // for the XBee. Make sure the baud rate matches the config
    // setting of your XBee.
    //XBee.begin(9600);
    Serial.begin(9600);
    pinMode(13, OUTPUT);
}

void blink(){
    digitalWrite(13, HIGH);
    delay(500);
    digitalWrite(13, LOW);
    delay(500);
}

char convertCase(char c){
    if(c >= 'a' && c <= 'z'){
        return c + ('A' - 'a');
    }
    else if(c >= 'A' && c <= 'Z'){
        return c + ('a' - 'A');
    }
}

void loop()
{
 /*
    char c;
    while (Serial.available() > 0) {
        c = Serial.read();
        c = convertCase(c);
        Serial.write(c);
   }

 */

    Serial.println("I see you");
    delay(500);
    
   
/*
    if(data_received){
        blink();
        data_received = 0;
    }
*/
}

