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

struct point_t
{
	double x;
	double y;
	double z;
	point_t(double _x, double _y, double _z)
	{
		x = _x;
		y = _y;
		z = _z;
	};
};


class DeltaRamps: public Ramps
{
	public:
		DeltaRamps(int _stepsmm);

		void home();

		void moveToDelta(point_t target, double stepSize);

		point_t convertToAxes(point_t point);
		point_t convertToCart(point_t point);

		point_t getPosition();

		point_t position = point_t(0,0,0);
	private:

		int stepsmm;
};


#endif
