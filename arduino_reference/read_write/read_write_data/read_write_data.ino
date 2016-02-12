int start_blink = 0;

void setup(){
    Serial.begin(9600);
    pinMode(13, OUTPUT);
}

void blink(int times){
    for(int i = 0; i < times; i++){
        digitalWrite(13, HIGH);
        delay(1000);
        digitalWrite(13, LOW);
        delay(1000);
    }
}
void loop(){
    /*
    if(start_blink){
        blink(3);
        start_blink = 0;
    }
    else{
        char c;
        if(Serial.available() > 0){
            c = Serial.read();
            start_blink = 1; 
        }
    }
    */
    char c;
    if(Serial.available() > 0){
        c = Serial.read();
        if(c >= 'a' && c <= 'z'){
            c += 'A' - 'a';
        }
        else if(c >= 'A' && c <= 'Z'){
            c += 'a' - 'A';
        }
        Serial.print(c);
    }
}
