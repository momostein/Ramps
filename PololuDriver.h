/*
PololuDriver.h - Library voor de DRV8825 Stepper Driver
Gemaakt door Brecht Ooms
*/

#ifndef _POLOLUDRIVER_h
#define _POLOLUDRIVER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class pololuStepper
{
	public:
		pololuStepper(int _stepPin, int _dirPin, int _enablePin, int _period);
		
		void Step(int direction);
		
		int position = 0;
		int period;

	private:
		int stepPin;
		int dirPin;
		int enablePin;
};


#endif

