const int pir_sensor = 2;  
const int led_pin = 6;     
volatile int motionDetected = 0;  // Flag indicating motion detection
void setup() {
  pinMode(led_pin, OUTPUT);
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(pir_sensor), motionInterrupt, HIGH);
  Serial.println("This is for task interrupt function");
}

void loop() {
  if (motionDetected == 1) {
    digitalWrite(led_pin, HIGH);  // Turning the LED 
    Serial.println("Motion is detected!");
    delay(1000);
    motionDetected = 0; 
  } else {
    Serial.println("Motion not detected");
    digitalWrite(led_pin, LOW);  // Turning the LED off
  }
  delay(500);
}

void motionInterrupt() {
  motionDetected = 1;  // Set the flag when motion is detected
}
