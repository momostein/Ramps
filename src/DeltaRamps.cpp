/*
    DeltaRamps.cpp - Library voor een Deltarobot of -printer
	met een Ramps shield

	Gemaakt door Brecht Ooms
*/

#include "Arduino.h"
#include "math.h"

#include "DeltaRamps.h"


//Constructor inherits van de Ramps() constructor
DeltaRamps::DeltaRamps(	int _stepsmm, double _baseSide, double _towerHeight,
						double _armLenght, double _platformSide,
						double _nozzleOffset):Ramps()
{
	stepsmm = _stepsmm;

	H = _towerHeight;
	l = _armLenght;

	//berekenen van afmetingen
	Sb = _baseSide;
	Wb = sqrt(3) * Sb / 6;
	Ub = Sb / sqrt(3);

	Sp = _platformSide;
	Wp = sqrt(3) * Sp / 6;
	Up = Sp / sqrt(3);

	Oz = _nozzleOffset;

	a = (Sb - Sp) / 2;
	b = Wb - Wp;
	c = Up - Ub;
}

//home functie zonder target zal naar (0,0,0) bewegen nadat hij gehomed is
void DeltaRamps::home(int _delay)
{
	Ramps::home(_delay);
	delay(50);
	DeltaRamps::moveTo(DeltaRamps::convertToAxes(point_t(0,0,0)), _delay);
	pos = point_t(0,0,0);
}

//home functie met target zal naar de target bewegen nadat hij gehomed is
void DeltaRamps::home(int _delay, point_t target)
{
	Ramps::home(_delay);
	delay(50);
	DeltaRamps::moveTo(DeltaRamps::convertToAxes(target), _delay);
	pos = target;
}

//moveTo met poin_t idpv gewoon x, y en z
void DeltaRamps::moveTo(point_t target, int _delay)
{
	Ramps::moveTo(target.x, target.y, target.z, _delay);
}

//Beweeg in een rechte lijn
void DeltaRamps::moveToDelta(point_t target, int _delay)
{
	//bereken het aantal stappen van een mm lang
	int steps = int((target - pos).length());

	//maak een array met dat aantal posities
	point_t points[steps];

	//Laatste positie is de de eindpositie
	points[steps - 1] = target;

	//Step is de vector waarmee de positie veranderd per stap
	point_t step = (target - pos)/steps;

	//eerste positie waarnaar we bewegen is dus de beginpositie + step
	points[0] = pos + step;

	//elke andere positie is de vorige + step
	for (int i = 1; i < steps - 1; i++)
	{
		points[i] = points[i - 1] + step;
	}

	//alle posities omvormen naar posities van de assen
	for (int i = 0; i < steps; i++)
	{
		points[i] = DeltaRamps::convertToAxes(points[i]);
	}

	//één voor één bewegen naar de berekende posities
	for (int i = 0; i < steps; i++)
	{
		DeltaRamps::moveTo(points[i], _delay);
	}

	//Huidige positie is nu de eindpositie
	pos = target;
}

//Omvormen van posities in de ruimte naar posities van de assen
point_t DeltaRamps::convertToAxes(point_t point)
{
	point_t Axes;

	//voor de berekeningen ligt de oorsprong in de top
	point.z = point.z + Oz - H;

	double Cx  =	square(point.x) + square(point.y) + square(point.z)
					+ square(a) + square(b) + 2*a*point.x + 2*b*point.y
					- square(l);

	double Cy  =	square(point.x) + square(point.y) + square(point.z)
	 				+ square(a) + square(b) - 2*a*point.x + 2*b*point.y
					- square(l);

	double Cz  =	square(point.x) + square(point.y) + square(point.z)
	 				+ square(c) + 2*c*point.y - square(l);

	Axes.x = ((-1)*point.z - sqrt(square(point.z) - Cx)) * stepsmm;
	Axes.y = ((-1)*point.z - sqrt(square(point.z) - Cy)) * stepsmm;
	Axes.z = ((-1)*point.z - sqrt(square(point.z) - Cz)) * stepsmm;

	return Axes;
}
