/*
	Example voor een delta robot of -printer
	Door Brecht Ooms
*/

#include "DeltaRamps.h"
#include "Measurements.h"

DeltaRamps deltaRamps = DeltaRamps(	STEPS_MM, BASE_SIDE, TOWER_HEIGHT,
									ARM_LENGHT, PLATFORM_SIDE, TOOL_OFFSET);

void setup()
{
	Serial.begin(9600);
	deltaRamps.home(100);
}

void loop()
{
	point_t point = deltaRamps.convertToAxes(point_t(0,150,50));

	Serial.print(point.x);
	Serial.print(" ");
	Serial.print(point.y);
	Serial.print(" ");
	Serial.println(point.z);

	point = deltaRamps.convertToCart(point);

	Serial.print(point.x);
	Serial.print(" ");
	Serial.print(point.y);
	Serial.print(" ");
	Serial.println(point.z);

	delay(1000);
}
