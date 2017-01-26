
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
		pololuStepper(int _stepPin, int _dirPin, int _enablePin);

    void setDir(short _dir);
    void stepOn();
    void stepOff();
    
		void autoStep(long amount); //Beweeg een aantal stappen in de gekozen richting (positief of negatief)
		void moveTo(long targetPos); //Beweeg naar doelpositie
		
		long position = 0; //Positie
		unsigned int period = 1000; //Periode per stem in microseconden

	private:
    int dir = 1;
		int stepPin;
		int dirPin;
		int enablePin;
};


#endif

