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

class PololuStepper
{
	public:
		PololuStepper(int _stepPin, int _dirPin, int _enablePin); //Constructor

		void setDir(short _dir);	//Bepaal Draairichting

		bool stepOn();				//Step Handmatig
									//(stepOff moet daarna komen)

		void stepOff();				//Concludeer Stap handmatig
									//(Moet na StepOn komen)

		//Beweeg een aantal stappen. (aantal kan negatief zijn)
		void autoStep(long amount, int _delay);

		//Beweeg naar doelpositie met gegegeven delay (in microseconden)
		void moveTo(long targetPos, int _delay);

		long position = 0;			//Positie

	private:
		short dir = 1;
		bool stepped = false;

		int stepPin;
		int dirPin;
		int enablePin;

};

#endif
