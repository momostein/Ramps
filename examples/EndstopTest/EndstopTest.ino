#include "PololuDriver.h"
#include "Ramps.h"

Ramps ramps = Ramps();

void setup()
{
    Serial.begin(9600);

}

void loop()
{
    Serial.println(digitalRead(X_MIN_PIN));
    delay(15);
}
