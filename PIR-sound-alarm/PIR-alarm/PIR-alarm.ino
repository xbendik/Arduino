 /*  
    Arduino with PIR motion sensor
*/
 
int led = 13;                   // the pin where the LED is attached to
int sensor = 3;                 // the pin where the sensor is attached to
int activation = 0;             // variable to store the sensor status (value)
int piezoPin = 8;               //the pin where the Piezo buzzer is attached to
int noiseTime = 3000;           //time in ms for how log it will make the buzzer alarm
int noiseFreq = 3000;           //frequency for Piezo buzzer alarm
//int delayTime = noiseTime + 2;  

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
    tone(piezoPin, noiseFreq, noiseTime);  //make some noise
    
    delay(noiseTime);                // delay milliseconds 
    Serial.println("Reseting... Done!"); 
    digitalWrite(led, LOW);    // turn LED OFF
  }
  else{
    delay(1000);
    Serial.println("Motion NOT detected!"); 
  } 
}
