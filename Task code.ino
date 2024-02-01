const int pir_sensor_interrupt = 3;  // PIR sensor connected to pin 3
const int led_pin = 5;               // LED connected to digital pin 5
volatile int motion_Detected = 0;    // Flag indicating motion detection
void setup() {
  Serial.begin(9600);
  Serial.println("This task is for interrupt function");
  
  pinMode(led_pin, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(pir_sensor_interrupt), motionInterrupt, HIGH);
}
void loop() {
}
void motionInterrupt() {
  int motion = digitalRead(pir_sensor_interrupt);

  Serial.print("PIR Sensor Value: ");
  Serial.println(motion);

  if (motion == HIGH) {
    digitalWrite(led_pin, HIGH);  // Turn on the LED
    Serial.println("Motion is detected!");
    delay(100);  // Adjust this delay as needed
    digitalWrite(led_pin, LOW);   // Turn off the LED
    motionDetected = 0;           // Reset the flag
  } else {
     Optional: Serial.println("Motion not detected");
  }
}
