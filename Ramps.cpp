
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

  pinMode(Y_STEP_PIN, OUTPUT);
  pinMode(Y_DIR_PIN, OUTPUT);
  pinMode(Y_ENABLE_PIN, OUTPUT);

  pinMode(Z_STEP_PIN, OUTPUT);
  pinMode(Z_DIR_PIN, OUTPUT);
  pinMode(Z_ENABLE_PIN, OUTPUT);

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


