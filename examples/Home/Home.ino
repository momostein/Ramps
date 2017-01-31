#include "PololuDriver.h"
#include "Ramps.h"

Ramps ramps = Ramps();

void setup()
{
    Serial.begin(9600);
    Serial.println(ramps.motorX.position);

}

void loop()
{
    ramps.moveTo(-10000,0,0,50);
    Serial.println(ramps.motorX.position);
    delay(500);
    ramps.moveTo(0,0,0,50);
    delay(500);
    Serial.println(ramps.motorX.position);
}
