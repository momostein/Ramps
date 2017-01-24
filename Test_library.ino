#include "PololuDriver.h"
#include "Ramps.h"

Ramps ramps = Ramps();

void setup()
{

}

void loop ()
{

  if (millis() % 1000 < 500)
  {
    ramps.led(true);
  }
  else
  {
    ramps.led(false);
  }

  if (millis() % 1000 < 300)
  {
    ramps.heater(0, 255);
    ramps.heater(1, 0);
	ramps.fan(false);
  }	
  else if (millis() % 1000 < 600)
  {
    ramps.heater(0, 0);
    ramps.heater(1, 255);
	ramps.fan(false);
  }
  else
  {
    ramps.heater(0, 0);
    ramps.heater(1, 0);
	ramps.fan(true);
  }

  if (millis() % 10000 < 5000)
  {
    digitalWrite(X_DIR_PIN    , HIGH);
    digitalWrite(Y_DIR_PIN    , HIGH);
    digitalWrite(Z_DIR_PIN    , HIGH);
    digitalWrite(E_DIR_PIN    , HIGH);
    digitalWrite(Q_DIR_PIN    , HIGH);
  }
  else
  {
    digitalWrite(X_DIR_PIN    , LOW);
    digitalWrite(Y_DIR_PIN    , LOW);
    digitalWrite(Z_DIR_PIN    , LOW);
    digitalWrite(E_DIR_PIN    , LOW);
    digitalWrite(Q_DIR_PIN    , LOW);
  }

  digitalWrite(X_STEP_PIN    , HIGH);
  digitalWrite(Y_STEP_PIN    , HIGH);
  digitalWrite(Z_STEP_PIN    , HIGH);
  digitalWrite(E_STEP_PIN    , HIGH);
  digitalWrite(Q_STEP_PIN    , HIGH);
  delay(1);

  digitalWrite(X_STEP_PIN    , LOW);
  digitalWrite(Y_STEP_PIN    , LOW);
  digitalWrite(Z_STEP_PIN    , LOW);
  digitalWrite(E_STEP_PIN    , LOW);
  digitalWrite(Q_STEP_PIN    , LOW);
}
