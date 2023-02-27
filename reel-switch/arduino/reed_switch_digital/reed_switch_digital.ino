const int REED_PIN = 2; // Pin connected from the sensor
const int LED_PIN = 13;   // LED pin - active-high
int  proximity =  0;      // variable to  store  the value  coming  from  the sensor

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  proximity = digitalRead(REED_PIN); // Read the state of the switch
  if (proximity == LOW) // If the pin reads low, the switch is closed.
  {
    Serial.println("Switch closed");
    digitalWrite(LED_PIN, HIGH); // Turn the LED on
  }
  else
  {
    Serial.println("Switch Open");
    digitalWrite(LED_PIN, LOW); // Turn the LED off
  }
}
