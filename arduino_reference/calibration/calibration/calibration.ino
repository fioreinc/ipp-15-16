#include <HX711.h>
#define DOUT  3
#define CLK  2

HX711 scale(DOUT, CLK);

float calibration_factor = -7050; //-7050 worked for my 440lb max scale setup
float weight = 5.0;
float threshold = .5;

enum states_e{
    AWAITING_CMD,
    READING_DATA
} states_t;

enum states_e curr_state;



void get_calibration() {
    while (true) {
        scale.set_scale(calibration_factor); //Adjust to this calibration factor
        float measured = fabs(scale.get_units());
        if ( abs(measured - weight) < threshold) {
            break;
        }
        else {
            if (measured < weight) {
                calibration_factor += 10;
            }
            else {
                calibration_factor -= 10;
            }
        }
    }
    Serial.print("Calibration Factor Found: ");
    Serial.println(calibration_factor);
}

void read_data(){
  Serial.print(fabs(scale.get_units()), 3);           //absolute value of reading
  Serial.print(" lbs\n");
}

void execute_cmd(){
    const char start_char = '[';
    const char end_char = ']';
    char c;
    String cmd = "";
    while(!Serial.available()); //Wait until there is data available
    while(Serial.read() != start_char); //Ignore all characters that aren't the start char
    while(1){ //Read until we reach the end char
        if(Serial.available()){
            if((c = Serial.read()) != end_char){
                cmd += c;
            }
            else{
                break;//We've found our command
            }
        }
    }

    if(cmd == "init_scale"){
        Serial.println("Searching for calibration factor");
        get_calibration();
    }
    if(cmd == "read_data"){
        curr_state = READING_DATA;
    }
    if(cmd == "tare_scale"){
        tare_scale();
    }
        

}

void tare_scale(){
    scale.set_scale();
    scale.tare();  //Reset the scale to 0
}

void setup() {
    //Set up the serial port baud rate
    Serial.begin(9600);
    curr_state = AWAITING_CMD;
    tare_scale();
    Serial.println("[ready]");
}



void loop() {
    switch(curr_state){
        case AWAITING_CMD:
            execute_cmd();
            break;
        case READING_DATA:
            read_data();
            break;
    }

}
