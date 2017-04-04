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
	point_t()
	{
		x = 0;
		y = 0;
		z = 0;
	};

	double length()
	{
		return sqrt(pow(x,2) + pow(y,2) + pow(z,2));
	};

};

inline point_t operator+(const point_t &a, const point_t &b)
{
	return point_t(a.x + b.x, a.y + b.y, a.z + b.z);
};
inline point_t operator-(const point_t &a, const point_t &b)
{
	return point_t(a.x - b.x, a.y - b.y, a.z - b.z);
};

inline point_t operator/(const point_t &p,const double &n)
{
	return point_t(p.x / n, p.y / n, p.z / n);
};
inline point_t operator/(const double &n, const point_t &p)
{
	return point_t(n / p.x, n / p.y, n / p.z);
};

inline point_t operator*(const point_t &p,const double &n)
{
	return point_t( p.x * n, p.y * n, p.z * n);
};
inline point_t operator*(const double &n, const point_t &p)
{
	return point_t(n * p.x, n * p.y, n * p.z);
};

class DeltaRamps: public Ramps
{
	public:
		DeltaRamps(	int _stepsmm, double _baseSide, double _towerHeight,
					double _armLenght, double _platformSide,
					double _nozzleOffset);

		void home(int _delay);
		void home(int _delay, point_t target);
		void moveToDelta(point_t target, int delay);

		point_t convertToAxes(point_t point);



		point_t pos;
	private:

		void moveTo(point_t target, int _delay);

		int stepsmm;

		double H; //frame height
		double l; //arm lenght

		double Sb; 	//P joints (Bi) equilateral triangle side

		double Wb; 	//planar distance from {0}
					//to P joints triangle side

		double Ub; 	//planar distance from {0}
					//to a vertex of the P joints triangle

		double Sp; //platform equilateral triangle side
		double Wp; //planar distance from {P} to near platform side
		double Up; //planar distance from {P} to a platform vertex

		double Oz; //nozzle z offset

		double a;
		double b;
		double c;
};


#endif
