#include "Team.h"

Team::Team(std::string _name, std::string _description, float _earliestStartTimeHome, float _latestStartTimeHome, float _earliestStartTimeAway, float _latestStartTimeAway)
{
	name = _name;
	description = _description;
	earliestStartTimeHome = _earliestStartTimeHome;
	latestStartTimeHome = _latestStartTimeHome;
	earliestStartTimeAway = _earliestStartTimeAway;
	latestStartTimeAway = _latestStartTimeAway;
}

Team::Team()
{
}

Team::~Team()
{
}
int Team::addHomeRink(Rink* _homeRink, float _weighting) 
{
	homeRinks.push_back(_homeRink);
	homeRinkWeights.push_back(_weighting);
	return 0;
}
