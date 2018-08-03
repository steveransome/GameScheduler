#include "Grade.h"

Grade::Grade(std::string _name, std::string _description,int _rounds, std::vector<int> _noGames)
{
	name = _name;
	description = _description;
	rounds = _rounds;
	noGames = _noGames;
	
}

Grade::Grade()
{
}

Grade::~Grade()
{
}

int Grade::Weeks() 
{
	return (teams.size() - 1)*rounds;
}

bool Grade::gamesAllowed(int weekToCheck, int _maxWeeks) 
{
	int counter;
	for (counter = 0; counter < noGames.size(); counter++) {
		if (noGames[counter] == weekToCheck)
		{
			return false;
		}
	}

	return true;
}