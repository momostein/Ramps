/*
    DeltaRamps.h - Library voor een Deltarobot of -printer met een Ramps shield
    Gemaakt door Brecht Ooms
*/

#ifndef _DeltaRamps_h
#define _DeltaRamps_h

#include "Ramps.h"
#include "PololuDriver.h"

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

class DeltaRamps: public Ramps
{
	public:
		DeltaRamps();

		void moveto(long targetX, long targetY, long targetZ, int _delay);
};

#endif
