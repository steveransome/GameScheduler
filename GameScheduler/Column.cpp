#pragma once
#include "Column.h"

Column::Column(Grade * _grade, Team * _homeTeam, float _homeTeamWeighting, Team * _awayTeam, Slot * _slot, std::string _columnName, int _columnID )
{
	grade = _grade;
	homeTeam = _homeTeam;
	awayTeam = _awayTeam;
	slot = _slot;
	columnName = _columnName;
	columnID = _columnID;
	homeTeamWeighting = _homeTeamWeighting;
}



Column::Column()
{
}


Column::~Column()
{
}
