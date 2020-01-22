/*  
    Arduino with PIR motion sensor
*/
 
int led = 13;                // the pin that the LED is atteched to
int sensor = 2;              // the pin that the sensor is atteched to
int activation = 0;                 // variable to store the sensor status (value)
int piezoPin = 8;            //pin for make sound on Piezo

void setup() {
  pinMode(led, OUTPUT);      // initalize LED as an output
  pinMode(sensor, INPUT);    // initialize sensor as an input
  Serial.begin(9600);        // initialize serial
}

void loop(){
  activation = digitalRead(sensor);   // read sensor value
  if (activation == HIGH) {           // check if the sensor is HIGH
    Serial.println("Motion detected!"); 
    digitalWrite(led, HIGH);    // turn LED ON
    tone(piezoPin, 3000, 2000);  //make some noise
    delay(2010);                // delay milliseconds 

    //turn off the LED on the end
    digitalWrite(led, LOW);    // turn LED ON
  } 
}
