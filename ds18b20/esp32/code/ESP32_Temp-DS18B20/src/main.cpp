#include <Arduino.h>

/*
Nombre: montaje1.ino
Autor: IoT UdeA
Descripción: Aplicación que pone a parpadear un led con un periodo 
             1 segundo y muestra el numero de parpadeos 
             en la terminal serial 
Conexiones: No se emplean elementos externos por lo tanto no hay
*/

/* Librerias*/
#include <OneWire.h>
#include <DallasTemperature.h>

/* Constantes */
#define SERIAL_SPEED 9600


/* Comunicacion */
// Data wire is plugged into pin 2 on the ESP32
#define ONE_WIRE_BUS 2

/* Entradas */

/* Salidas */
const int ledPin =  LED_BUILTIN; //(GPIO2 - D2)

/* Variables de la aplicacion */

// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);
// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature sensor_DS18B20(&oneWire);

/* Funcion setup: Configuracion */
void setup(void) {
  // start serial port
  Serial.begin(9600);
  Serial.println("Dallas Temperature IC Control Library Demo");
  // Start up the library
  sensor_DS18B20.begin(); // IC Default 9 bit. If you have troubles consider upping it 12. Ups the delay giving the IC more time to process the temperature measurement
}


/* Funcion loop: Logica del programa */
void loop(void) { 
  // call sensors.requestTemperatures() to issue a global temperature 
  // request to all devices on the bus
  Serial.print("Requesting temperatures... ");
  sensor_DS18B20.requestTemperatures(); // Send the command to get temperatures
  float T = sensor_DS18B20.getTempCByIndex(0);
  Serial.print("DONE ");

  Serial.print("Temperature for Device is: ");
  Serial.println(T); // Why "byIndex"? You can have more than one IC on the same bus. 0 refers to the first IC on the wire
  delay(500);
}