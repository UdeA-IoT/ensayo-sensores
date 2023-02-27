/*macro definitions of magnetic pin and LED pin*/
#define MAGNECTIC_SWITCH 4
#define LED LED_BUILTIN //the on board LED of the Arduino or Seeeduino
 
void setup()
{
    pinsInit();
    Serial.begin(9600);
}
 
void loop() 
{
    if(isNearMagnet())//if the magnetic switch is near the magnet?
    {
        turnOnLED();
        Serial.println("Switch closed");
    }
    else
    {
        turnOffLED();
        Serial.println("Switch open");
    }
}


void pinsInit()
{
    pinMode(MAGNECTIC_SWITCH, INPUT);
    pinMode(LED,OUTPUT);
}

 
/*If the magnetic switch is near the magnet, it will return ture, */
/*otherwise it will return false                                */
boolean isNearMagnet()
{
    int sensorValue = digitalRead(MAGNECTIC_SWITCH);
    if(sensorValue == HIGH)//if the sensor value is HIGH?
    {
        return true;//yes,return ture
    }
    else
    {
        return false;//no,return false
    }
}

void turnOnLED()
{
    digitalWrite(LED,HIGH);
}

void turnOffLED()
{
    digitalWrite(LED,LOW);
}
