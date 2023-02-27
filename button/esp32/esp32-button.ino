// URL: https://arduinomodules.info/ky-004-key-switch-module/

/* Pines */
const int led = LED_BUILTIN; // Define the LED pin
const int buttonPin = 23;    // P23 (GPIO23)
int val;                     // Define a numeric variable

void setup() {
	pinMode(led,OUTPUT);
	pinMode(buttonPin,INPUT);
}

void loop() {
	val = digitalRead(buttonPin); // check the state of the button
	if(val==HIGH) { 
		// if button is pressed, turn LED on
		digitalWrite(led,HIGH);
	}
	else {
		// if button is released, turn LED off
		digitalWrite(led,LOW);
	}
}