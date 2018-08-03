#pragma once
#include "Rink.h"
#include <string>
class Team
{
public:
		std::string name;
		std::string description;
		int earliestStartTimeHome;
		int latestStartTimeHome;
		int earliestStartTimeAway;
		int latestStartTimeAway;
		std::vector<Rink*> homeRinks;
		std::vector<float> homeRinkWeights;

	Team(std::string _name, std::string _description, float _earliestStartTimeHome, float _latestStartTimeHome, float _earliestStartTimeAway, float _latestStartTimeAway);
	Team();
	~Team();
	int addHomeRink(Rink* _homeRink, float _weighting);
};

