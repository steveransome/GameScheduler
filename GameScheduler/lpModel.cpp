#include "lpModel.h"


lpModel::lpModel(std::string _description,int _weekCount, int _solverTimeout)
{
	int weekCounter;
	weekCount = _weekCount;
	solverTimeout = _solverTimeout;
	description = _description;

	for(int weekCounter = 0; weekCounter < _weekCount+1; weekCounter++)
{
    std::vector<Column*> columnsForWeek;
    columnsByWeek.push_back(columnsForWeek);
}

}

lpModel::lpModel()
{
}

lpModel::~lpModel()
{
}

int lpModel::addColumn(Column* _newColumn) {
	columns.push_back(_newColumn);
	columnsByWeek[_newColumn->slot->week].push_back(_newColumn);
	return 0;
}

float lpModel::getOptimumValue(Grade* _grade, Team * _homeTeam, Team * _awayTeam, dow * _dow, int _week, int _startTime, Rink * _rink)
{
	int columnCounter;
	for (columnCounter = 0; columnCounter < columnsByWeek[_week].size(); columnCounter++)
	{
		Column* targetColumn = columnsByWeek[_week][columnCounter];
		if (targetColumn->grade== _grade && targetColumn->homeTeam==_homeTeam && targetColumn->awayTeam == _awayTeam && targetColumn->slot->dayOfWeek == _dow && targetColumn->slot->startTime == _startTime && targetColumn->slot->rink == _rink)
		{
			//return targetColumn->homeTeamWeighting*100 + targetColumn->optimumValue;
			return targetColumn->optimumValue;
		}
	}
	return -1;
}


int lpModel::filterColumns(std::vector<Column*>* _filteredColumns, Grade* _grade, Team * _homeTeam, Team * _awayTeam, dow * _dow, int _minWeek, int _maxWeek, int _minStartTime, int _maxStartTime, Rink * _rink)
{
	int columnCounter;
	for (columnCounter = 0; columnCounter < columns.size(); columnCounter++)
	{	
		Column* targetColumn = columns[columnCounter];
		if (isMatch(targetColumn,_grade,  _homeTeam, _awayTeam, _dow, _minWeek, _maxWeek, _minStartTime, _maxStartTime,_rink))
		_filteredColumns->push_back(columns[columnCounter]);
	}
	return 0;
}
bool lpModel::isMatch(Column* _column,Grade* _grade, Team * _homeTeam, Team * _awayTeam, dow * _dow, int _minWeek, int _maxWeek, int _minStartTime, int _maxStartTime,  Rink* _rink)
{
	if (_column->grade != _grade && _grade != nullptr)
	{
		return false;
	}

	if (_column->slot->week < _minWeek && _minWeek != NULL)
	{
		return false;
	}
	if (_column->slot->week > _maxWeek && _maxWeek != NULL)
	{
		return false;
	}
	if (_column->homeTeam != _homeTeam && _homeTeam != nullptr)
	{
		return false;
	}
	if (_column->awayTeam != _awayTeam && _awayTeam != nullptr)
	{
		return false;
	}
	if (_column->slot->startTime < _minStartTime && _minStartTime != NULL)
	{
		return false;
	}
	if (_column->slot->startTime > _maxStartTime && _maxStartTime != NULL)
	{
		return false;
	}

	if (_column->slot->dayOfWeek != _dow && _dow != nullptr)
	{
		return false;
	}


	//if ( _dow != NULL)
	//{
	//	if(_column->slot->dayOfWeek != _dow)
	//	return false;
	//}
	if (_column->slot->rink != _rink && _rink != nullptr)
	{
		return false;
	}
	return true;
}