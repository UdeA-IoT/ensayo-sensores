#include <Arduino.h>

/* ---- Pines I/O ---- */

// Inputs
#define SHOCK_SW  22            // Shock switch module (Elegoo)

// Outputs
#define ALARM LED_BUILTIN       // ESP32 Led

#define DEBUG 1

// Variables aplicacion
int sensor_status = 0;

/* ---- Inicialización ---- */
void setup() {
  // Inicializacion serial
  Serial.begin(19200);

  // Inicializacion I/O
  pinMode(ALARM,OUTPUT);   
  pinMode(SHOCK_SW, INPUT);

  // Impresion en el monitor serial
  #if DEBUG
    Serial.println("Shock example -> OK");      
  #endif

}

/* ---- Loop infinito ---- */
void loop() {
  sensor_status = digitalRead(SHOCK_SW); // read and assign the value of digital interface 3 to val
	if(sensor_status == HIGH) {    
    // Vibracion
		digitalWrite(ALARM, HIGH);
    #if DEBUG
      Serial.println("Vibracion detectada: Pum...");
    #endif
	}
	else {
		digitalWrite(ALARM, LOW);
    #if DEBUG
      Serial.println("No se detecta vibracion: zzz..."); 
    #endif
	}
}

