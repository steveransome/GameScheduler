#pragma once
#include "Column.h"

class Columns
{
public:
	std::vector<Column*> columns;

	Columns();
	~Columns();
	int filter(std::vector<Slot>* _filteredVariables, Grade* _grade, int _minRound, int _maxRound, Team * _homeTeam, Team * _awayTeam, dow _dow, int _minWeek, int _maxWeek, int _minStartTime, int _maxStartTime);


};

