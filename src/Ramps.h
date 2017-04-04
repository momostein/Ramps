/*
    Ramps.h - Library voor de Ramps shield
    Gemaakt door Brecht Ooms
*/

#ifndef _Ramps_h
#define _Ramps_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#include "PololuDriver.h"

#define X_STEP_PIN         54
#define X_DIR_PIN          55
#define X_ENABLE_PIN       38
#define X_MIN_PIN           3
#define X_MAX_PIN           2

#define Y_STEP_PIN         60
#define Y_DIR_PIN          61
#define Y_ENABLE_PIN       56
#define Y_MIN_PIN          14
#define Y_MAX_PIN          15

#define Z_STEP_PIN         46
#define Z_DIR_PIN          48
#define Z_ENABLE_PIN       62
#define Z_MIN_PIN          18
#define Z_MAX_PIN          19

#define E_STEP_PIN         26
#define E_DIR_PIN          28
#define E_ENABLE_PIN       24

#define Q_STEP_PIN         36
#define Q_DIR_PIN          34
#define Q_ENABLE_PIN       30

#define SDPOWER            -1
#define SDSS               53
#define LED_PIN            13

#define FAN_PIN            9

#define PS_ON_PIN          12
#define KILL_PIN           -1

#define HEATER_0_PIN       10	//PWM PIN!
#define HEATER_1_PIN       8	//PWM PIN!
#define TEMP_0_PIN         13	// Analoge numering
#define TEMP_1_PIN         14	// Analoge numering

class Ramps
{
	public: //Public functies en variabelen

		//Constructor
		Ramps();

		//Beweeg Motors X, Y en Z naar hun Home positie
		void home(int _delay);

		//LED aan (true) of LED uit (false)
		void led(bool On);

		//heater (0 of 1) aansturen met PWM (byte)
		void heater(int heaterNum, byte value);

		//Fan aan (true) of fan uit (false)
		void fan(bool On);

		//Beweeg naar gegeven positie met bresenhams lijn algoritme
		void moveTo(long targetX, long targetY, long targetZ, int _delay);

		//declareren van motors
		PololuStepper motorX = PololuStepper(	X_STEP_PIN, X_DIR_PIN,
												X_ENABLE_PIN);
		PololuStepper motorY = PololuStepper(	Y_STEP_PIN, Y_DIR_PIN,
												Y_ENABLE_PIN);
		PololuStepper motorZ = PololuStepper(	Z_STEP_PIN, Z_DIR_PIN,
												Z_ENABLE_PIN);
		PololuStepper motorE = PololuStepper(	E_STEP_PIN, E_DIR_PIN,
												E_ENABLE_PIN);
		PololuStepper motorQ = PololuStepper(	Q_STEP_PIN, Q_DIR_PIN,
												Q_ENABLE_PIN);

	private: //Private functies en variabelen

};

#endif
