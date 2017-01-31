#include "PololuDriver.h"
#include "Ramps.h"

Ramps ramps = Ramps();

void setup()
{
    Serial.begin(9600);

}

void loop()
{
    Serial.print("Min X Y Z: ")
    Serial.print(digitalRead(X_MIN_PIN));
    Serial.print(digitalRead(Y_MIN_PIN));
    Serial.print(digitalRead(Z_MIN_PIN));

    Serial.print("Max X Y Z: ")
    Serial.print(digitalRead(X_MAX_PIN));
    Serial.print(digitalRead(Y_MAX_PIN));
    Serial.print(digitalRead(Z_MAX_PIN));

    delay(15);
}
