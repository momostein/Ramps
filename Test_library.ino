#include "PololuDriver.h"
#include "Ramps.h"

Ramps ramps = Ramps();

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
	  ramps.motorX.step(1);
	  ramps.motorY.step(1);
	  ramps.motorZ.step(1);
	  ramps.motorE.step(1);
	  ramps.motorQ.step(1);
  }
  else
  {
	  ramps.motorX.step(-1);
	  ramps.motorY.step(-1);
	  ramps.motorZ.step(-1);
	  ramps.motorE.step(-1);
	  ramps.motorQ.step(-1);
  }

  if (millis() % 20000 < 10000)
  {
	  ramps.motorX.period = 1000;
	  ramps.motorY.period = 1000;
	  ramps.motorZ.period = 1000;
	  ramps.motorE.period = 1000;
	  ramps.motorQ.period = 1000;

  }
  else
  {
	  ramps.motorX.period = 500;
	  ramps.motorY.period = 500;
	  ramps.motorZ.period = 500;
	  ramps.motorE.period = 500;
	  ramps.motorQ.period = 500;
  }
}
