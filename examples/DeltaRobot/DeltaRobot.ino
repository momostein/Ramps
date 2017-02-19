/*
	Example voor een delta robot of -printer
	Door Brecht Ooms
*/

#include "DeltaRamps.h"
#include "Measurements.h"

DeltaRamps deltaRamps = DeltaRamps(STEPS_MM, TOWER_RADIUS, TOWER_HEIGHT, ARM_LENGHT, PIVOT_OFFSET, TOOL_OFFSET);

void setup()
{
	Serial.begin(9600);
	deltaRamps.home();
}

void loop()
{
	Serial.print(deltaRamps.convertToAxes(point_t(0,0,20)).x);
	Serial.print(" ");
	Serial.print(deltaRamps.convertToCart(point_t(0,0,20)).y);
	Serial.print(" ");
	Serial.println(deltaRamps.convertToCart(point_t(0,0,20)).z);
	delay(1000);
}
