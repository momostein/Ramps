#include "PololuDriver.h"
#include "Ramps.h"

Ramps ramps = Ramps();

void setup()
{
	Serial.begin(9600);
	Serial.println("started...");
	ramps.home(100);
	delay(500);
}

void loop()
{
	ramps.moveTo(30000, 20000, 10000, 30);
	delay(500);
	ramps.moveTo(10000, 30000, 20000, 30);
	delay(500);
	ramps.moveTo(20000, 10000, 30000, 30);
	delay(500);
}
