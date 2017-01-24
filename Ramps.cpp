
/*
Ramps.ccp - Library voor de Ramps shield
Gemaakt door Brecht Ooms
*/

#include "Ramps.h"

Ramps::Ramps()
{
  pinMode(FAN_PIN, OUTPUT);
  pinMode(HEATER_0_PIN, OUTPUT);
  pinMode(HEATER_1_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);

  pinMode(X_STEP_PIN, OUTPUT);
  pinMode(X_DIR_PIN, OUTPUT);
  pinMode(X_ENABLE_PIN, OUTPUT);
  pinMode(X_MIN_PIN, INPUT_PULLUP);
  pinMode(X_MAX_PIN, INPUT_PULLUP);

  pinMode(Y_STEP_PIN, OUTPUT);
  pinMode(Y_DIR_PIN, OUTPUT);
  pinMode(Y_ENABLE_PIN, OUTPUT);
  pinMode(Y_MIN_PIN, INPUT_PULLUP);
  pinMode(Y_MAX_PIN, INPUT_PULLUP);

  pinMode(Z_STEP_PIN, OUTPUT);
  pinMode(Z_DIR_PIN, OUTPUT);
  pinMode(Z_ENABLE_PIN, OUTPUT);
  pinMode(Z_MIN_PIN, INPUT_PULLUP);
  pinMode(Z_MAX_PIN, INPUT_PULLUP);

  pinMode(E_STEP_PIN, OUTPUT);
  pinMode(E_DIR_PIN, OUTPUT);
  pinMode(E_ENABLE_PIN, OUTPUT);

  pinMode(Q_STEP_PIN, OUTPUT);
  pinMode(Q_DIR_PIN, OUTPUT);
  pinMode(Q_ENABLE_PIN, OUTPUT);

  digitalWrite(X_ENABLE_PIN, LOW);
  digitalWrite(Y_ENABLE_PIN, LOW);
  digitalWrite(Z_ENABLE_PIN, LOW);
  digitalWrite(E_ENABLE_PIN, LOW);
  digitalWrite(Q_ENABLE_PIN, LOW);

}

void Ramps::home()
{
	bool allhome;

	do
	{
		allhome = true;
		if (digitalRead(X_MIN_PIN))
		{
			motorX.step(-1);
			allhome = false;
		}
		if (digitalRead(Y_MIN_PIN))
		{
			motorY.step(-1);
			allhome = false;
		}
		if (digitalRead(Z_MIN_PIN))
		{
			motorZ.step(-1);
			allhome = false;
		}

	} while (allhome == false);
	
	motorX.position = 0;
	motorY.position = 0;
	motorZ.position = 0;

}




//LED aan (true) of LED uit (false)
void Ramps::led(bool On)
{
  if (On)
  {
    digitalWrite(LED_PIN, HIGH);
  }
  else
  {
    digitalWrite(LED_PIN, LOW);
  }
}


//heater (0 of 1) aansturen met PWM (byte)
void Ramps::heater(int heaterNum, byte value)
{
  if (heaterNum == 0)
  {
    analogWrite(HEATER_0_PIN, value);
  }
  else if (heaterNum == 1)
  {
    analogWrite(HEATER_1_PIN, value);
  }
}


//Fan aan (true) of fan uit (false)
void Ramps::fan(bool On)
{
	if (On)
	{
		digitalWrite(FAN_PIN, HIGH);
	}
	else
	{
		digitalWrite(FAN_PIN, LOW);
	}
}