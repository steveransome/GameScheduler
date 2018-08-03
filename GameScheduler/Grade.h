#pragma once
#include "Team.h"
class Grade
{
public:
	std::string name;
	std::string description;
	int  rounds;
	std::vector<Team*> teams;
	std::vector<int> noGames;

	Grade(std::string _name, std::string _description, int _rounds, std::vector<int> _noGames);
	Grade();
	~Grade();
	bool gamesAllowed(int weekToCheck, int _maxWeeks);
	int Weeks();
};

