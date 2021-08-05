/*                                                      
  Smoothing

  Reads repeatedly from an analog input, calculating a running average and
  printing it to the computer. Keeps ten readings in an array and continually
  averages them.

  The circuit:
  - analog sensor (potentiometer will do) attached to analog input 0

  created 22 Apr 2007
  by David A. Mellis  <dam@mellis.org>
  modified 9 Apr 2012
  by Tom Igoe

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Smoothing
*/

// Define the number of samples to keep track of. The higher the number, the
// more the readings will be smoothed, but the slower the output will respond to
// the input. Using a constant rather than a normal variable lets us use this
// value to determine the size of the readings array.
const int numReadings = 10;

int average = 0;                // the average

void setup() {
  // initialize serial communication with computer:
  Serial.begin(9600);
}

int ReadSens_and_Condition(int sensorPin){ 
  int i;
  int sval = 0;

  for (i = 0; i < 10; i++){
    sval = sval + analogRead(sensorPin);    // sensor on analog pin 0
  }

  sval = sval / 10;    // average
//  sval = sval / 4;    // scale to 8 bits (0 - 255)             
  return sval;
}

void loop() {
  average = ReadSens_and_Condition(2);
  Serial.println(average);
  delay(1);        // delay in between reads for stability
}
