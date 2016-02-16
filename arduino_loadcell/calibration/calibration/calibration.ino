#include <HX711.h>
#define DOUT  3
#define CLK  2

HX711 scale(DOUT, CLK);

float calibration_factor = -7050; //-7050 worked for my 440lb max scale setup
float weight = 5.0;
float threshold = .1;

void get_calibration() {
  while (true) {
    scale.set_scale(calibration_factor); //Adjust to this calibration factor
    float measured = abs(scale.get_units());
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
    Serial.println(measured);
  }
}

void setup() {

  Serial.begin(9600);
  Serial.println("Load Cell Calibration Sketch");
  Serial.println("Place a known weight on scale");

  scale.set_scale();
  scale.tare();  //Reset the scale to 0

  long zero_factor = scale.read_average(); //Get a baseline reading
  Serial.print("Zero factor: "); //This can be used to remove the need to tare the scale. Useful in permanent scale projects.
  Serial.println(zero_factor);

  get_calibration();
  Serial.print(" calibration_factor: ");
  Serial.print(calibration_factor);
  Serial.println();
}

void loop() {

  Serial.print("Reading: ");
  Serial.print(abs(scale.get_units()), 10);           //absolute value of reading
  Serial.print(" lbs");
  Serial.println();
}
