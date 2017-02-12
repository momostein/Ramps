/*
    DeltaRamps.cpp - Library voor een Deltarobot of -printer met een Ramps shield
    Gemaakt door Brecht Ooms
*/

DeltaRamps::DeltaRamps(int _stepsmm):Ramps()
{
	stepsmm = _stepsmm;

}

void DeltaRamps::moveTo(long targetX, long targetY, long targetZ, int _delay)
{
	//hier worden de berekeningen gedaan en zo bewogen in een rechte lijn
	


	Ramps::moveTo(long targetX, long targetY, long targetZ, int _delay)
}
