#pragma once
#include "Rink.h"
#include <string>
#include "dow.h"

//enum dow { SAT, SUN, MON, TUE, WED, THU, FRI };

class Slot
{
public:
	Slot(Rink* _rink,int _week,dow* _dayOfWeek,int _startTime,int _endTime);
	Slot();
	~Slot();
	std::string name();
	int week;		//first week of season is week 1
	dow* dayOfWeek;	//1 = Saturday
	Rink* rink;
	int startTime;	//minutes since midnight
	int endTime;	//minutes since midnight
	bool available;

	
private:

};

