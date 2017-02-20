/*
	Example voor een delta robot of -printer
	Door Brecht Ooms
*/

#include "DeltaRamps.h"
#include "Measurements.h"

DeltaRamps deltaRamps = DeltaRamps(STEPS_MM, BASE_SIDE, TOWER_HEIGHT, ARM_LENGHT, PLATFORM_SIDE, TOOL_OFFSET);

void setup()
{
	Serial.begin(9600);
	deltaRamps.home();
	delay(250);
	deltaRamps.moveToDelta(point_t(0,0,20), 2, 30);
	delay(250);
}

void loop()
{

	deltaRamps.moveToDelta(point_t(0,100,20), 2, 30);
	delay(500);
	deltaRamps.moveToDelta(point_t(0,-100,20), 2, 30);
	delay(500);
	deltaRamps.moveToDelta(point_t(0,0,20), 2, 30);
	delay(1000);

	deltaRamps.moveToDelta(point_t(100,0,20), 2, 30);
	delay(500);
	deltaRamps.moveToDelta(point_t(-100,0,20), 2, 30);
	delay(500);

	deltaRamps.moveToDelta(point_t(0,0,50), 2, 30);
	delay(1000);

}
