/*
    DeltaRamps.cpp - Library voor een Deltarobot of -printer met een Ramps shield
    Gemaakt door Brecht Ooms
*/

#include "Arduino.h"
#include "math.h"

#include "DeltaRamps.h"



DeltaRamps::DeltaRamps(int _stepsmm, double _baseSide, double _towerHeight, double _armLenght, double _platformSide, double _nozzleOffset):Ramps()
{
	stepsmm = _stepsmm;

	H = _towerHeight;
	l = _armLenght;

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

void DeltaRamps::moveToDelta(point_t target, double stepSize, int delay)
{
	//hier worden de berekeningen gedaan en zo bewogen in een rechte lijn
	point_t targetAxes = convertToAxes(target);
	Ramps::moveTo(targetAxes.x, targetAxes.y, targetAxes.z, delay);
}

point_t DeltaRamps::convertToAxes(point_t point)
{
	point_t Axes = point_t(0,0,0);

	point.z = point.z + Oz - H; //de volgende berekingen hebben hun oorsprong aan de bovenkant van de constructie.

	double Cx  =  square(point.x) + square(point.y) + square(point.z) + square(a) + square(b) + 2*a*point.x + 2*b*point.y - square(l);
	double Cy  =  square(point.x) + square(point.y) + square(point.z) + square(a) + square(b) - 2*a*point.x + 2*b*point.y - square(l);
	double Cz  =  square(point.x) + square(point.y) + square(point.z) + square(c) + 2*c*point.y - square(l);

	Axes.x = ((-1)*point.z - sqrt(square(point.z) - Cx)) * stepsmm;
	Axes.y = ((-1)*point.z - sqrt(square(point.z) - Cy)) * stepsmm;
	Axes.z = ((-1)*point.z - sqrt(square(point.z) - Cz)) * stepsmm;

	return Axes;
}

point_t DeltaRamps::convertToCart(point_t point)
{
	point.x = point.x / stepsmm;
	point.y = point.y / stepsmm;
	point.z = point.z / stepsmm;

	point_t position = point_t(0,0,0);

	double d = (point.y - point.x) / (2*a);
	double e = (square(point.y)-square(point.x)) / (4*a);

	double D = (point.y - point.x - 2*a*d) / (b - c);
	double E = (square(c) - square(a) - square(b) - 2*a*e + square(point.z) - square(point.x)) / (2*(b - c));

	double A = square(d) + square(D) + l;
	double B = 2*(d*e + D*E + c*D + point.z);
	double C = square(e) + square(E) + square(c) + 2*c*E + square(point.z) - square(l);

	position.z = ((-1)*B - sqrt(square(B) - 4*A*C)) / (2*A);
	position.x = d*position.z + e;
	position.y = D*position.z + E;

	position.z = position.z - Oz + H; //de vorige berekingen hebben hun oorsprong aan de bovenkant van de constructie.

	return point;
}

point_t DeltaRamps::getPosition()
{
	return convertToCart(point_t(motorX.position, motorY.position, motorZ.position));
}
