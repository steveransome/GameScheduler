#pragma once
#include <string>

class dow
{
public:
	int dayID;
	std::string dayName;

	dow(int _dayID, std::string _dayName);
	dow();
	~dow();
};

