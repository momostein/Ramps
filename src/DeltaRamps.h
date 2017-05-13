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

//Nieuw type variabele met x, y en z waarde
//Dus een positievector
struct point_t
{
	//x, y en z waardes
	double x;
	double y;
	double z;

	//Constructor met parameters
	point_t(double _x, double _y, double _z)
	{
		x = _x;
		y = _y;
		z = _z;
	};

	//Constructor zonder parameters
	point_t()
	{
		x = 0;
		y = 0;
		z = 0;
	};

	//Bereken de lengte met pythagoras
	double length()
	{
		return sqrt(pow(x,2) + pow(y,2) + pow(z,2));
	};

};

//Alle operators voor point_t variabeletype

//point_t + point_t
inline point_t operator+(const point_t &a, const point_t &b)
{
	return point_t(a.x + b.x, a.y + b.y, a.z + b.z);
};
//point_t - point_t
inline point_t operator-(const point_t &a, const point_t &b)
{
	return point_t(a.x - b.x, a.y - b.y, a.z - b.z);
};

//point_t / n
inline point_t operator/(const point_t &p,const double &n)
{
	return point_t(p.x / n, p.y / n, p.z / n);
};
//n / point_t
inline point_t operator/(const double &n, const point_t &p)
{
	return point_t(n / p.x, n / p.y, n / p.z);
};

//point_t * n
inline point_t operator*(const point_t &p,const double &n)
{
	return point_t( p.x * n, p.y * n, p.z * n);
};
//n * point_t
inline point_t operator*(const double &n, const point_t &p)
{
	return point_t(n * p.x, n * p.y, n * p.z);
};


//DeltaRamps klasse
class DeltaRamps: public Ramps
{
	//Public variabelen en functies (die men kan gebruiken)
	public:
		//Constructor
		DeltaRamps(	int _stepsmm, double _baseSide, double _towerHeight,
					double _armLenght, double _platformSide,
					double _nozzleOffset);

		//home() is aangepast dus we declareren het opnieuw (met en zonder target)
		void home(int _delay);
		void home(int _delay, point_t target);

		//Beweeg in een rechte lijn
		void moveToDelta(point_t target, int delay);

		//Omrekening van een punt in de ruimte naar posities van de assen
		point_t convertToAxes(point_t point);

		//Positie van de eindeffector in de ruimte
		point_t pos;

	//Private variabelen en functies (die men niet kan gebruiken)
	private:

		//Overload de moveTo functie zodat hij werkt met point_t
		void moveTo(point_t target, int _delay);

		//Stappen per mm
		int stepsmm;

		//Afmetingen van de Deltarobot (voor de berekeningen)
		double H; //Frame height
		double l; //Arm lenght

		double Sb; 	//P joints (Bi) equilateral triangle side

		double Wb; 	//Planar distance from {0}
					//To P joints triangle side

		double Ub; 	//Planar distance from {0}
					//To a vertex of the P joints triangle

		double Sp; //Platform equilateral triangle side
		double Wp; //Planar distance from {P} to near platform side
		double Up; //Planar distance from {P} to a platform vertex

		double Oz; //Nozzle z offset

		//Hulpgetallen voor de berekeningen
		double a;
		double b;
		double c;
};


#endif
