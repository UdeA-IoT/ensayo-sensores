/*!
 * \brief DS1307 RTC set get time example for Arduino
 * \details
 *    Source:         https://github.com/Erriez/ErriezDS1307
 *    Documentation:  https://erriez.github.io/ErriezDS1307
 */

#include <Wire.h>
#include <ErriezDS1307.h>

// Create RTC object
ErriezDS1307 rtc;


void setup()
{
    // Initialize serial port
    delay(500);
    Serial.begin(115200);
    /*
    while (!Serial) {
        ;
    }
    */
    Serial.println(F("\nErriez DS1307 set get time example"));

    // Initialize I2C
    Wire.begin();
    Wire.setClock(100000);

    // Initialize RTC
    while (!rtc.begin()) {
        Serial.println(F("RTC not found"));
        delay(3000);
    }

    // Set square wave out pin
    // SquareWaveDisable, SquareWave1Hz, SquareWave4096Hz, SquareWave8192Hz, SquareWave32768Hz
    rtc.setSquareWave(SquareWaveDisable);

    // Set new time 12:00:00
    if (!rtc.setTime(12, 0, 0)) {
        Serial.println(F("Set time failed"));
    }
}

void loop()
{
    uint8_t hour;
    uint8_t min;
    uint8_t sec;

    // Get time from RTC
    if (!rtc.getTime(&hour, &min, &sec)) {
        Serial.println(F("Get time failed"));
    } else {
        // Print time
        Serial.print(hour);
        Serial.print(F(":"));
        if (min < 10) {
            Serial.print(F("0"));
        }
        Serial.print(min);
        Serial.print(F(":"));
        if (sec < 10) {
            Serial.print(F("0"));
        }
        Serial.println(sec);
    }

    // Wait a second
    delay(1000);
}
