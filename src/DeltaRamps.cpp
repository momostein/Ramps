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
	double C1  =  point.x^2 + point.y^2 + point.z^2 + a^2 + b^2 + 2*a*point.x + 2*b*point.y - l^2;
	double C2  =  point.x^2 + point.y^2 + point.z^2 + a^2 + b^2 - 2*a*point.x + 2*b*point.y - l^2;
	double C3  =  point.x^2 + point.y^2 + point.z^2 + c^2 + 2*c*point.y - l^2;

	

	return point;
}

point_t DeltaRamps::convertToCart(point_t point)
{
	//omvormen van de posities van de assen tot een punt in het cartesiaans assenstelsel

	return point;
}

point_t DeltaRamps::getPosition()
{
	return convertToCart(point_t(motorX.position, motorY.position, motorZ.position));
}
