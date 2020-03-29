 /*  
    Arduino with PIR motion sensor
*/
 
int led = D6;                   // the pin where the LED is attached to
int sensor = D7;                 // the pin where the sensor is attached to
int activation = 0;             // variable to store the sensor status (value)
int piezoPin = D8;               //the pin where the Piezo buzzer is attached to
int noiseTime = 3000;           //time in ms for how log it will make the buzzer alarm
int noiseFreq = 3000;           //frequency for Piezo buzzer alarm
//int delayTime = noiseTime + 2;  

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(led, OUTPUT);      // initalize LED as an output
  pinMode(sensor, INPUT);    // initialize sensor as an input
  Serial.begin(9600);        // initialize serial
}

void loop(){
  activation = digitalRead(sensor);   // read sensor value
  if (activation == HIGH) {           // check if the sensor is HIGH
    Serial.println("Motion detected!"); 
    digitalWrite(led, HIGH);    // turn LED ON
    digitalWrite(LED_BUILTIN, HIGH);
    tone(piezoPin, noiseFreq, noiseTime);  //make some noise
    
    delay(noiseTime);                // delay milliseconds 
    Serial.println("Turning off alarm... Done!"); 
    digitalWrite(led, LOW);    // turn LED OFF
    digitalWrite(LED_BUILTIN, LOW);
  }
  else{
    delay(100);
    Serial.println("Motion NOT detected!"); 
  } 
}
