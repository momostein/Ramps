// 
// 
// 

#include "PololuDriver.h"
#include "Arduino.h"

pololuStepper::pololuStepper(int _stepPin, int _dirPin, int _enablePin, int _period)
{
	stepPin = _stepPin;
	dirPin = _dirPin;
	enablePin = _enablePin;

	pinMode(stepPin, OUTPUT);
	pinMode(dirPin, OUTPUT);
	pinMode(enablePin, OUTPUT);
}

void pololuStepper::Step(int direction)
{

}
