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
		DeltaRamps(int _stepsmm, double _towerRadius, _towerHeight, double _armLenght, double _pivotOffset, double _toolOffset);

		void home();

		void moveToDelta(point_t target, double stepSize, int delay);

		point_t convertToAxes(point_t point);
		point_t convertToCart(point_t point);

		point_t getPosition();

	private:
		int stepsmm;

		//positions of the three struts (axes) with the z coördinate being the height of the 0 point.
		point_t strutX;
		point_t strutY;
		point_t strutZ;

		double armLenght; //length of the arms

		double pivotOffset; //distance from the pivot points of the arms to the center of the effector
		double toolOffset; //height of the effector
};


#endif
