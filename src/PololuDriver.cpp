/*
    PololuDriver.ccp - Library voor de DRV8825 Stepper Driver
    Gemaakt door Brecht Ooms
*/

#include "PololuDriver.h"
#include "Arduino.h"

//Constructor
PololuStepper::PololuStepper(int _stepPin, int _dirPin, int _enablePin)
{
	stepPin = _stepPin;
	dirPin = _dirPin;
	enablePin = _enablePin;

	pinMode(stepPin, OUTPUT);
	pinMode(dirPin, OUTPUT);
	pinMode(enablePin, OUTPUT);

	digitalWrite(enablePin, LOW);
}

//Stel richting handmatig in
void PololuStepper::setDir(short _dir)
{
  	if (_dir > 0)
  	{
    	dir = 1;
    	digitalWrite(dirPin, LOW);
  	}
  	else if (_dir < 0)
  	{
    	dir = -1;
    	digitalWrite(dirPin, HIGH);
  	}
}

//Step Handmatig (Step off moet volgen na een bepaalde vertraging)
bool PololuStepper::stepOn()
{
	if (!stepped)
	{
		position += dir;
		digitalWrite(stepPin, HIGH);
		stepped = true;

		return true;
	}
	else
	{
		return false;
	}
}

//Concludeer Stap handmatig (Moet na StepOn komen)
void PololuStepper::stepOff()
{
	if (stepped)
	{
		digitalWrite(stepPin, LOW);
		stepped = false;
	}
}

//Beweeg een aantal stappen in de gekozen richting (positief of negatief)
//en met de gegeven delay (in microseconden)
void PololuStepper::autoStep(long amount, int _delay)
{
	setDir(constrain(amount, -1, 1));

	//Het kan gebeuren dat iemand stepOff is vergeten
	//en dan klopt de positie niet meer.
	if (stepped)
	{
		stepOff();
	}

	while (!(amount == 0))
	{
		stepOn();
		delayMicroseconds(_delay);
		stepOff();

		amount -= dir;
	}
}

//Beweeg naar doelpositie met gegegeven delay (in microseconden)
void PololuStepper::moveTo(long targetPos, int _delay)
{
	autoStep(targetPos - position, _delay);
}
