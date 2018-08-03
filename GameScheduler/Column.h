#pragma once
#include "Team.h"
#include "Slot.h"
#include "Grade.h"



class Column
{
public:
	Grade* grade;
	Team* homeTeam;
	Team* awayTeam;
	Slot* slot;
	bool lockced;	
	int columnID;  
	std::string columnName; 
	float optimumValue;
	float homeTeamWeighting;
	

	Column(Grade * _grade, Team * _homeTeam,float _homeTeamWeighting, Team * _awayTeam, Slot * _slot, std::string _columnName, int columnID);
	Column();
	~Column();
};

