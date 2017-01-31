#include "PololuDriver.h"
#include "Ramps.h"

Ramps ramps = Ramps();

void setup()
{
    Serial.begin(9600);
    Serial.println(ramps.motorX.position);
    ramps.home();
}

void loop()
{
    ramps.motorX.autoStep(50000,50);
    Serial.println(ramps.motorX.position);
    delay(500);

    ramps.motorX.autoStep(-50000,50);
    Serial.println(ramps.motorX.position);
    delay(500);

}
