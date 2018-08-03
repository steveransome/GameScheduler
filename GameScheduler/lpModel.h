#pragma once
#include "Column.h"
#include <string>

class lpModel
{
public:
	std::vector<Column*> columns;
	std::vector<std::vector<Column*>> columnsByWeek;
	int  weekCount;
	int solverTimeout;
	std::string description;

	int addColumn(Column* _newColumn);
	float getOptimumValue(Grade* _grade, Team * _homeTeam, Team * _awayTeam, dow * _dow, int _week, int _startTime, Rink * _rink);
	int filterColumns(std::vector<Column*>* _filteredColumns, Grade* _grade,  Team * _homeTeam, Team * _awayTeam, dow * _dow, int _minWeek, int _maxWeek, int _minStartTime, int _maxStartTime, Rink * _rink);
	bool isMatch(Column* _column, Grade* _grade, Team * _homeTeam, Team * _awayTeam, dow * _dow, int _minWeek, int _maxWeek, int _minStartTime, int _maxStartTime, Rink* _rink);
	lpModel();
	lpModel(std::string _description, int _weekCount, int _solverTimeout);
	~lpModel();
};

