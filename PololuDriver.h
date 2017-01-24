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

class poluluStepper
{
	public:
		poluluStepper(int _stepPin, int _dirPin, int _enablePin);

	private:
		int stepPin;
		int dirPin;
		int enablePin;
};


#endif

