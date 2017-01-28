#include "PololuDriver.h"
#include "Ramps.h"

Ramps ramps = Ramps();

int microseconds = 1000;

void setup()
{

}

void loop ()
{

    if (millis() % 1000 < 500)
    {
        ramps.led(true);
    }
    else
    {
        ramps.led(false);
    }

    if (millis() % 1000 < 300)
    {
        ramps.heater(0, 255);
        ramps.heater(1, 0);
        ramps.fan(false);
    }
    else if (millis() % 1000 < 600)
    {
        ramps.heater(0, 0);
        ramps.heater(1, 255);
        ramps.fan(false);
    }
    else
    {
        ramps.heater(0, 0);
        ramps.heater(1, 0);
        ramps.fan(true);
    }

    if (millis() % 10000 < 5000)
    {
  	    ramps.motorX.setDir(1);
  	    ramps.motorY.setDir(1);
  	    ramps.motorZ.setDir(1);
  	    ramps.motorE.setDir(1);
  	    ramps.motorQ.setDir(1);
    }
    else
    {
	    ramps.motorX.setDir(-1);
	    ramps.motorY.setDir(-1);
	    ramps.motorZ.setDir(-1);
	    ramps.motorE.setDir(-1);
	    ramps.motorQ.setDir(-1);
    }

    if (millis() % 4000 < 2000)
    {
  	    microseconds = 500;
    }
    else
    {
        microseconds = 250;
    }

    ramps.motorX.stepOn();
    ramps.motorY.stepOn();
    ramps.motorZ.stepOn();
    ramps.motorE.stepOn();
    ramps.motorQ.stepOn();

    delayMicroseconds(microseconds);

    ramps.motorX.stepOff();
    ramps.motorY.stepOff();
    ramps.motorZ.stepOff();
    ramps.motorE.stepOff();
    ramps.motorQ.stepOff();
}
