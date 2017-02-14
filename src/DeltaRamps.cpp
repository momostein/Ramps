/*
    DeltaRamps.cpp - Library voor een Deltarobot of -printer met een Ramps shield
    Gemaakt door Brecht Ooms
*/

#include "Arduino.h"
#include "math.h"

#include "DeltaRamps.h"



DeltaRamps::DeltaRamps(int _stepsmm, double _towerRadius, double _towerHeight, double _armLenght, double _pivotOffset, double _toolOffset):Ramps()
{
	stepsmm = _stepsmm;

	armLenght = _armLenght;

	pivotOffset = _pivotOffset;
	tooloffset = _tooloffset;

	strutX.x = _towerRadius; // towerRadius * cos(0°)
	strutY.x = _towerRadius * cos(M_2_PI / 3); // 2/3 * Pi (120°)
	strutZ.x = _towerRadius * cos(M_2_PI / 3); // 2/3 * Pi (120°)

	strutX.y = 0; // towerRadius * cos(90°)
	strutY.y = _towerRadius * cos(M_PI_2 / 3); // 1/6 * Pi (30°)
	strutZ.y = _towerRadius * cos(5 * M_PI_2 / 3); // 5/6 * Pi (150°)

	strutX.z = _towerHeight;
	strutY.z = _towerHeight;
	strutZ.z = _towerHeight;
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
