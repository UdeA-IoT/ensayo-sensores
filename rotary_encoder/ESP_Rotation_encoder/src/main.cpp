#include <Arduino.h>

/* ---- Pines I/O ---- */

// Rotary encoder Encoder (I)
#define ENCODER_CLK 14
#define ENCODER_DT  12
#define ENCODER_SW  13
#define DEBUG 1


// Constantes
const char MAX_PUSH_TIME = 100;

// Variables aplicacion
unsigned char counter = 0;       // Brillo led integrado
int lastClk = HIGH;              // Valor anterior señal CLK
long int resetLastChanged = 0;   // cambio reset

/* ---- Inicialización ---- */
void setup() {
  // Inicializacion serial
  Serial.begin(115200);

  // Inicializacion I/O
  pinMode(LED_BUILTIN,OUTPUT);   
  pinMode(ENCODER_CLK, INPUT);
  pinMode(ENCODER_DT, INPUT);
  pinMode(ENCODER_SW, INPUT_PULLUP);

  // Impresion en el monitor serial
  #if DEBUG
    Serial.print("Counter: ");
    Serial.println(counter);      
  #endif

}

/* ---- Loop infinito ---- */
void loop() {
  // Chequeo del reset presionado por un tiempo mayor de MAX_PUSH_TIME 
  if (digitalRead(ENCODER_SW) == LOW && millis() - resetLastChanged > MAX_PUSH_TIME) {
    resetLastChanged = millis();
    counter = 0;
    #if DEBUG
      Serial.print("Counter [Reset]: ");
      Serial.println(counter);   
    #endif
    analogWrite(LED_BUILTIN,counter);   
  }

  // Actualizancion del brillo
  int newClk = digitalRead(ENCODER_CLK);
  if (newClk != lastClk) {
    // There was a change on the CLK pin
    lastClk = newClk;
    int dtValue = digitalRead(ENCODER_DT);    
    if (newClk == LOW && dtValue == HIGH) {
      // Aumento brillo
      counter++;
      #if DEBUG
        Serial.print("Counter [Up]: ");
        Serial.println(counter);
      #endif
    }
    if (newClk == LOW && dtValue == LOW) {
      // Disminución brillo
      counter--;
      #if DEBUG
        Serial.print("Counter [Down]: ");
        Serial.println(counter);
      #endif
    }
    analogWrite(LED_BUILTIN,counter);   
  }
}