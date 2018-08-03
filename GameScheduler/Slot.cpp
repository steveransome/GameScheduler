#include "Slot.h"


Slot::Slot(Rink* _rink, int _week, dow* _dayOfWeek, int _startTime, int _endTime)
{
	rink = _rink;
	week = _week;
	dayOfWeek = _dayOfWeek;
	startTime = _startTime;
	endTime = _endTime;
	available = true;	
}

Slot::~Slot()
{
}

Slot::Slot()
{
}

std::string Slot::name() {
	return rink->name + "_" + std::to_string(week) + "_" + dayOfWeek->dayName + "_" + std::to_string(startTime);
}