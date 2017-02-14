/*
    DeltaRamps.cpp - Library voor een Deltarobot of -printer met een Ramps shield
    Gemaakt door Brecht Ooms
*/

#include "DeltaRamps.h"
#include "Arduino.h"


DeltaRamps::DeltaRamps(int _stepsmm):Ramps()
{
	stepsmm = _stepsmm;

}

void DeltaRamps::home()
{
	Ramps::home();

	position = convertToCart(point_t(motorX.position, motorY.position, motorZ.position));
}

void DeltaRamps::moveToDelta(point_t target, double stepSize, int delay)
{
	//hier worden de berekeningen gedaan en zo bewogen in een rechte lijn
	point_t targetAxes = convertToAxes(target);
	Ramps::moveTo(targetAxes.x, targetAxes.y, targetAxes.z, delay);
}

point_t DeltaRamps::convertToAxes(point_t point)
{
	//omvormen van een cartesiaans punt tot de posities van de assen

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
