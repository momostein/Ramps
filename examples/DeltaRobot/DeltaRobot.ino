/*
	Example voor een delta robot of -printer
	Door Brecht Ooms
*/

#include "DeltaRamps.h"
#include "Measurements.h"

DeltaRamps deltaRamps(STEPS_MM);

void setup()
{
	Serial.begin(9600);
	deltaRamps.home();
}

void loop()
{
	Serial.print(deltaRamps.convertToCart(point_t(4,5,6)).x);
	Serial.print(deltaRamps.convertToCart(point_t(4,5,6)).y);
	Serial.print(deltaRamps.convertToCart(point_t(4,5,6)).z);

}
