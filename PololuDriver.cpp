
/*
PololuDriver.ccp - Library voor de DRV8825 Stepper Driver
Gemaakt door Brecht Ooms
*/

#include "PololuDriver.h"
#include "Arduino.h"

//(STEP aansluiting, DIR aansluiting, ENABLE aansluiting)
pololuStepper::pololuStepper(int _stepPin, int _dirPin, int _enablePin)
{
	stepPin = _stepPin;
	dirPin = _dirPin;
	enablePin = _enablePin;

	pinMode(stepPin, OUTPUT);
	pinMode(dirPin, OUTPUT);
	pinMode(enablePin, OUTPUT);

	digitalWrite(enablePin, LOW);
}


//Beweeg een aantal stappen in de gekozen richting (positief of negatief)
void pololuStepper::step(long amount)
{
	while (amount != 0)
	if (amount > 0)
	{
		digitalWrite(dirPin, LOW);

		digitalWrite(stepPin, HIGH);
		delayMicroseconds(period / 2);

		digitalWrite(stepPin, LOW);
		delayMicroseconds(period / 2);

		position++;
		amount--;
	}
	else if (amount < 0)
	{
		digitalWrite(dirPin, HIGH);

		digitalWrite(stepPin, HIGH);
		delayMicroseconds(period / 2);

		digitalWrite(stepPin, LOW);
		delayMicroseconds(period / 2);

		position--;
		amount++;
	}
}

void pololuStepper::moveTo(long targetPos)
{
	step(targetPos - position);
}
