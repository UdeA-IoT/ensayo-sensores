#include <Wire.h>
#include <SparkFunDS1307RTC.h>

#define SQW_INPUT_PIN 2   // Input pin to read SQW
#define SQW_OUTPUT_PIN 13 // LED to indicate SQW's state

void setup() {
  Serial.begin(9600);
  digitalWrite(SQW_OUTPUT_PIN, digitalRead(SQW_INPUT_PIN));
  rtc.begin(); // Call rtc.begin() to initialize the library
  rtc.autoTime();
}

void loop() {
  static int8_t lastSecond = -1;
  // Call rtc.update() to update all rtc.seconds(), rtc.minutes(),
  // etc. return functions.
  rtc.update();
  printTime();
  delay(1000);
}

void printTime() {
  if(rtc.date() < 10) {
    Serial.print('0'); // Print leading '0' for date
  }
  Serial.print(String(rtc.date()) + "/");        // Print date
  if(rtc.month() < 10) {
    Serial.print('0'); // Print leading '0' for month
  }
  Serial.print(String(rtc.month()) + "/");       // Print month
  Serial.print("20"+ String(rtc.year()) + " - ");        // Print year
  
  
  Serial.print(String(rtc.hour()) + ":"); // Print hour
  if (rtc.minute() < 10)
    Serial.print('0'); // Print leading '0' for minute
  Serial.print(String(rtc.minute()) + ":"); // Print minute
  if (rtc.second() < 10)
    Serial.print('0'); // Print leading '0' for second
  Serial.print(String(rtc.second())); // Print second

  if (rtc.is12Hour()) // If we're in 12-hour mode
  {
    // Use rtc.pm() to read the AM/PM state of the hour
    if (rtc.pm()) Serial.print(" PM"); // Returns true if PM
    else Serial.print(" AM");
  }
  Serial.print(" | ");
  Serial.println(rtc.dayStr()); // Print day string
}
