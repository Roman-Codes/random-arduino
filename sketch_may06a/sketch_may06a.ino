
// These constants won't change. They're used to give names to the pins used:
const int redSensorPin = A0;  // Analog input pin that the potentiometer is attached to
const int greenSensorPin = A1;
const int blueSensorPin = A2;

int redValue = 0;        // value read from the pot
int greenValue = 0;
int blueValue = 0;

int outputRedValue = 0;
int outputGreenValue = 0;
int outputBlueValue = 0;

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
}

void loop() {
  // read the analog in value:
  redValue = analogRead(redSensorPin);
  greenValue = analogRead(greenSensorPin);
  blueValue = analogRead(blueSensorPin);
  // map it to the range of the analog out:
  outputRedValue = map(redValue, 0, 1023, 0, 255);
  outputGreenValue = map(greenValue, 0, 1023, 0, 255);
  outputBlueValue = map(blueValue, 0, 1023, 0, 255);
  // change the analog out value:

  // print the results to the Serial Monitor:
  Serial.print("RGB LED Value = (");
  Serial.print(outputRedValue);
  Serial.print(", ");
  Serial.print(outputGreenValue);
  Serial.print(", ");
  Serial.print(outputBlueValue);
  Serial.println(")");

  // wait 2 milliseconds before the next loop for the analog-to-digital
  // converter to settle after the last reading:
  delay(5);
}
