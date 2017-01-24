// 
// 
// 

#include "PololuDriver.h"
#include "Arduino.h"

poluluStepper::poluluStepper(int _stepPin, int _dirPin, int _enablePin)
{
	stepPin = _stepPin;
	dirPin = _dirPin;
	enablePin = _enablePin;

	pinMode(stepPin, OUTPUT);
	pinMode(dirPin, OUTPUT);
	pinMode(enablePin, OUTPUT);
}
