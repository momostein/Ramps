/*
	Example voor een delta robot of -printer
	Door Brecht Ooms
*/

#include "DeltaRamps.h"
#include "Measurements.h"

DeltaRamps deltaRamps(STEPS_MM, TOWER_RADIUS, TOWER_HEIGHT, ARM_LENGHT, PIVOT_OFFSET, TOOL_OFFSET);

void setup()
{
	Serial.begin(9600);
	deltaRamps.home();
}

void loop()
{
	Serial.println(deltaRamps.convertToCart(point_t(4,5,6)).x);
	Serial.println(deltaRamps.convertToCart(point_t(4,5,6)).y);
	Serial.println(deltaRamps.convertToCart(point_t(4,5,6)).z);
	delay(1000);
}
