/*
	Example voor een deltarobot of -printer
	Door Brecht Ooms
*/

#include "DeltaRamps.h"
#include "Measurements.h"

DeltaRamps deltaRamps = DeltaRamps(	STEPS_MM, BASE_SIDE, TOWER_HEIGHT,
									ARM_LENGHT, PLATFORM_SIDE, TOOL_OFFSET);

void setup()
{
	deltaRamps.home(100,point_t(0,0,150));
	delay(250);
}

void loop()
{
	deltaRamps.moveToDelta(point_t(0,125,150), 30);
	delay(500);
	deltaRamps.moveToDelta(point_t(0,-125,150), 30);
	delay(500);
	deltaRamps.moveToDelta(point_t(0,0,150), 30);
	delay(1000);

	deltaRamps.moveToDelta(point_t(125,0,150), 30);
	delay(500);
	deltaRamps.moveToDelta(point_t(-125,0,150), 30);
	delay(500);
	deltaRamps.moveToDelta(point_t(0,0,150), 30);
	delay(1000);

}
