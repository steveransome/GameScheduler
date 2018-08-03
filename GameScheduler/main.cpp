#include <stdio.h>
#include <stdlib.h>
#include "lp_lib.h"
#include <string>
#include "Slot.h"
#include "Grade.h"
#include "Column.h"
#include "lpModel.h"
#include <fstream>
#include <string>
#include <ctime>

std::vector<Slot*> slots;
std::vector<Slot*> slotsFiltered;
std::vector<Rink*> rinks;
std::vector<Grade*> grades;
std::vector<dow*> days;

int runScheduler()
{
	int constraintCounter = 0;
	int gradeCounter;
	int homeTeamCounter;
	int awayTeamCounter;
	int roundCounter;
	int slotCounter;
	int homeRinkCounter;
	int teamCounter;
	int result;
	
	int dayCounter;
	int rinkCounter;
	int weekCounter;
	//int weekCount = 24;
	lpModel Model("12w1gV2.06_",12,600);

	dow SAT(0, "SAT");
	days.push_back(&SAT);
	dow SUN(1, "SUN");
	days.push_back(&SUN);

	Rink SIA("SIA", "Sydney Ice Arena");
	rinks.push_back(&SIA);
	Rink PIP("PIP", "Penrith Ice Palace");
	rinks.push_back(&PIP);
	Rink HISS("HISS", "Hunter Ice Skating Stadium");
	rinks.push_back(&HISS);
	Rink MACQ("MACQ", "Macquarie Ice Arena");
	rinks.push_back(&MACQ);
	Rink COIR("COIR", "Caterbury Olympic Ice Rink");
	rinks.push_back(&COIR);
	Rink LCC("LCC", "Liverpool Catholic Club");
	rinks.push_back(&LCC);
	Rink EIA("EIA", "Erina Ice Arena");
	rinks.push_back(&EIA);
	Rink ACT("ACT", "ACT rink");
	rinks.push_back(&ACT);

	Grade MIDGET("Midget", "MidgetDescription",4,{  });
	grades.push_back(&MIDGET);
	//start time between for home and away
	MIDGET.teams.push_back(new Team("Emperors", "Midget-Emperors", 9.0, 20.0, 10.0, 19.0));
	MIDGET.teams[MIDGET.teams.size() - 1]->addHomeRink(&COIR, 100.0);
	MIDGET.teams[MIDGET.teams.size() - 1]->addHomeRink(&PIP,120.0);
	MIDGET.teams[MIDGET.teams.size() - 1]->addHomeRink(&LCC,50.0);
	//MIDGET.teams[MIDGET.teams.size() - 1]->addHomeRink(&MACQ,80.0);
	MIDGET.teams.push_back(new Team("Saints", "Midget-Saints", 9.0, 20.0, 10.0, 19.0));
	MIDGET.teams[MIDGET.teams.size() - 1]->addHomeRink(&LCC,140.0);
	MIDGET.teams.push_back(new Team("Flyers", "Midget-Flyers", 8.0, 20.0, 10.0, 19.0));
	MIDGET.teams[MIDGET.teams.size() - 1]->addHomeRink(&PIP,130.0);
	MIDGET.teams[MIDGET.teams.size() - 1]->addHomeRink(&COIR,80.0);
	//MIDGET.teams[MIDGET.teams.size() - 1]->addHomeRink(&MACQ,50.0);
	MIDGET.teams.push_back(new Team("Bears", "Midget-Bears", 8.0, 19.0, 10.0, 19.0));
	MIDGET.teams[MIDGET.teams.size() - 1]->addHomeRink(&MACQ,110.0);
	MIDGET.teams[MIDGET.teams.size() - 1]->addHomeRink(&COIR,90.0);
	MIDGET.teams[MIDGET.teams.size() - 1]->addHomeRink(&PIP,100.0);
	MIDGET.teams.push_back(new Team("Newcastle", "Midget-Newcastle", 13.0, 19.0, 10.0, 19.0));
	MIDGET.teams[MIDGET.teams.size() - 1]->addHomeRink(&HISS,100.0);
	MIDGET.teams.push_back(new Team("Ice Caps", "Midget-Ice Caps", 9.0, 18.5, 10.0, 18.50));
	MIDGET.teams[MIDGET.teams.size() - 1]->addHomeRink(&ACT,120.0);

	//times need to be rink specific rather than home and away

	for (weekCounter = 1; weekCounter <= Model.weekCount; weekCounter++)
	{
		slots.push_back(new Slot(&COIR, weekCounter, &SAT, 19.0, 20.25));
		slots.push_back(new Slot(&COIR, weekCounter, &SAT, 20.5, 22.00));
		slots.push_back(new Slot(&COIR, weekCounter, &SUN, 7.0, 8.25));
		slots.push_back(new Slot(&COIR, weekCounter, &SUN, 8.5, 9.75));
		slots.push_back(new Slot(&COIR, weekCounter, &SUN, 10.0, 11.25));
		slots.push_back(new Slot(&COIR, weekCounter, &SUN, 18.0, 19.25));
		slots.push_back(new Slot(&COIR, weekCounter, &SUN, 19.5, 20.75));
		slots.push_back(new Slot(&COIR, weekCounter, &SUN, 21.0, 22.25));

		slots.push_back(new Slot(&PIP, weekCounter, &SAT, 17.0, 18.25));
		slots.push_back(new Slot(&PIP, weekCounter, &SAT, 18.5, 19.75));
		slots.push_back(new Slot(&PIP, weekCounter, &SAT, 20.0, 21.25));
		slots.push_back(new Slot(&PIP, weekCounter, &SUN, 16.5, 17.75));
		slots.push_back(new Slot(&PIP, weekCounter, &SUN, 18.0, 19.25));
		slots.push_back(new Slot(&PIP, weekCounter, &SUN, 19.5, 20.75));
		slots.push_back(new Slot(&PIP, weekCounter, &SUN, 21.0, 22.25));

		slots.push_back(new Slot(&MACQ, weekCounter, &SAT, 18.0, 19.25));
		slots.push_back(new Slot(&MACQ, weekCounter, &SAT, 19.5, 20.75));
		slots.push_back(new Slot(&MACQ, weekCounter, &SUN, 7.0, 8.25));
		slots.push_back(new Slot(&MACQ, weekCounter, &SUN, 8.5, 9.75));
		slots.push_back(new Slot(&MACQ, weekCounter, &SUN, 18.0, 19.25));
		slots.push_back(new Slot(&MACQ, weekCounter, &SUN, 19.5, 20.75));

		slots.push_back(new Slot(&LCC, weekCounter, &SUN, 7.0, 8.25));
		slots.push_back(new Slot(&LCC, weekCounter, &SUN, 8.5, 9.75));
		slots.push_back(new Slot(&LCC, weekCounter, &SUN, 10.0, 11.25));
		slots.push_back(new Slot(&LCC, weekCounter, &SUN, 17.0, 18.25));
		slots.push_back(new Slot(&LCC, weekCounter, &SUN, 18.5, 19.75));
		slots.push_back(new Slot(&LCC, weekCounter, &SUN, 20.0, 21.25));

		slots.push_back(new Slot(&HISS, weekCounter, &SAT, 17.0, 19.25));
		slots.push_back(new Slot(&HISS, weekCounter, &SAT, 18.5, 20.75));
		slots.push_back(new Slot(&HISS, weekCounter, &SUN, 17.0, 19.25));
		slots.push_back(new Slot(&HISS, weekCounter, &SUN, 18.5, 20.75));

		slots.push_back(new Slot(&ACT, weekCounter, &SAT, 12.0, 13.25));
		slots.push_back(new Slot(&ACT, weekCounter, &SAT, 16.0, 17.25));
	}

	lprec *lp;
	int Ncol;
	int *colno = NULL;
	
	int	j;
	int ret = 0;
	REAL *row = NULL;

	for (gradeCounter = 0; gradeCounter < grades.size(); gradeCounter++){
		for (homeTeamCounter = 0; homeTeamCounter < grades[gradeCounter]->teams.size(); homeTeamCounter++) {
			for (awayTeamCounter = 0; awayTeamCounter < grades[gradeCounter]->teams.size(); awayTeamCounter++) {
				if (homeTeamCounter != awayTeamCounter) {
					
						for (weekCounter = 1; weekCounter <= Model.weekCount; weekCounter++) {
							if (grades[gradeCounter]->gamesAllowed(weekCounter,Model.weekCount))
							{
								for (homeRinkCounter = 0; homeRinkCounter < grades[gradeCounter]->teams[homeTeamCounter]->homeRinks.size(); homeRinkCounter++)
								{
									for (slotCounter = 0; slotCounter< slots.size(); slotCounter++)
									{
										if (slots[slotCounter]->week == weekCounter && slots[slotCounter]->available && slots[slotCounter]->rink->name == grades[gradeCounter]->teams[homeTeamCounter]->homeRinks[homeRinkCounter]->name && grades[gradeCounter]->gamesAllowed(weekCounter,Model.weekCount))
										{
											if (grades[gradeCounter]->teams[homeTeamCounter]->earliestStartTimeHome<=slots[slotCounter]->startTime && 
												grades[gradeCounter]->teams[homeTeamCounter]->latestStartTimeHome >= slots[slotCounter]->startTime && 
												grades[gradeCounter]->teams[awayTeamCounter]->earliestStartTimeAway <= slots[slotCounter]->startTime && 
												grades[gradeCounter]->teams[awayTeamCounter]->latestStartTimeAway >= slots[slotCounter]->startTime) {
												int currentSize = Model.columns.size() + 1;
												std::string varStr = std::string() + std::to_string(currentSize) + '_' + grades[gradeCounter]->name + '_' + grades[gradeCounter]->teams[homeTeamCounter]->name + 'v' + grades[gradeCounter]->teams[awayTeamCounter]->name + '_' + std::to_string(weekCounter) + '_' + slots[slotCounter]->name();
												Model.addColumn(new Column(
													grades[gradeCounter],
													grades[gradeCounter]->teams[homeTeamCounter],
													grades[gradeCounter]->teams[homeTeamCounter]->homeRinkWeights[homeRinkCounter],
													grades[gradeCounter]->teams[awayTeamCounter],
													slots[slotCounter],
													varStr, Model.columns.size() + 1));
											}

										}
									}
								}
							}

						}
					
				}
			}
		}
	}	

	Ncol = Model.columns.size(); 
	lp = make_lp(0, Ncol);
	set_lp_name(lp, (char*)(Model.description.c_str()));
	if (lp == NULL)
		ret = 1; /* couldn't construct a new model... */

	if (ret == 0) {
		
		//create columns

		int i = 0;
		for (i = 0; i < Model.columns.size(); i++) {
			set_col_name(lp, Model.columns[i]->columnID, (char *)Model.columns[i]->columnName.c_str());
			set_binary(lp, Model.columns[i]->columnID, TRUE);
		}

		/* create space large enough for one row */
		colno = (int *)malloc(Ncol * sizeof(*colno));
		row = (REAL *)malloc(Ncol * sizeof(*row));
		if ((colno == NULL) || (row == NULL))
			ret = 2;
	}

	set_add_rowmode(lp, TRUE);  /* makes building the model faster if it is done rows by row */

	std::vector<Column*> subColumns;
  
	//Set OBJECTIVE
	int columnCounter;
	for(columnCounter=0;columnCounter<Model.columns.size()-1;columnCounter++)
	{
		colno[columnCounter] = Model.columns[columnCounter]->columnID;
		
		if (Model.columns[columnCounter]->homeTeamWeighting > 0.0)
		{
			row[columnCounter] = Model.columns[columnCounter]->homeTeamWeighting + (1 - (Model.columns[columnCounter]->slot->startTime/24));
		}
		else
		{
			row[columnCounter] = 1.0;
		}	
	}
	if (!set_obj_fnex(lp, columnCounter, row, colno))
		ret = 4;

	//Set CONSTRAINTS
	
	std::string strConstraintCount;

	//Each Slot can only be assigned to a single game
	constraintCounter = 0;
	for (slotCounter = 0; slotCounter < slots.size(); slotCounter++)
	{
		std::string varStr = std::string() + std::to_string(slotCounter) + '_' + slots[slotCounter]->rink->name + '_' + std::to_string(slots[slotCounter]->week) + '_' + slots[slotCounter]->dayOfWeek->dayName + '_' + std::to_string(slots[slotCounter]->startTime) ;
		//printf("%s\n", varStr.c_str());

		int result = Model.filterColumns(&subColumns, nullptr, nullptr,nullptr, slots[slotCounter]->dayOfWeek,slots[slotCounter]->week , slots[slotCounter]->week, slots[slotCounter]->startTime, slots[slotCounter]->startTime,slots[slotCounter]->rink);
		//created the constraint
		if (subColumns.size() > 0)
		{
			if (ret == 0)
			{
				for (columnCounter = 0; columnCounter < subColumns.size(); columnCounter++)
				{

					colno[columnCounter] = subColumns[columnCounter]->columnID;
					row[columnCounter] = 1.0;
				}
				constraintCounter++;
				if (!add_constraintex(lp, columnCounter, row, colno, LE, 1.0))
					ret = 3;
				//if (!add_SOS(lp, (char*)"SOS slot used once", 1, 1, columnCounter, colno, NULL))
				//	ret = 3;
				subColumns.clear();
			}
		}
	}
	strConstraintCount = std::string() + "Constraint 1: " + std::to_string(constraintCounter);
	printf("%s\n", strConstraintCount.c_str());

	//Each team can play at most once each week
	constraintCounter = 0;
	for (gradeCounter = 0; gradeCounter < grades.size(); gradeCounter++)
	{
		for (teamCounter = 0; teamCounter < MIDGET.teams.size(); teamCounter++)
		{
			for (weekCounter = 1; weekCounter <= Model.weekCount; weekCounter++)
			{
				subColumns.clear();
				 result = Model.filterColumns(&subColumns, grades[gradeCounter], grades[gradeCounter]->teams[teamCounter], nullptr, nullptr, weekCounter, weekCounter, 1.0, 23.0, nullptr);
				 result = Model.filterColumns(&subColumns, grades[gradeCounter], nullptr, grades[gradeCounter]->teams[teamCounter], nullptr, weekCounter, weekCounter, 1.0, 23.0, nullptr);
				//created the constraint
				if (subColumns.size() > 0)
				{
					if (ret == 0)
					{
						for (columnCounter = 0; columnCounter < subColumns.size(); columnCounter++)
						{
							colno[columnCounter] = subColumns[columnCounter]->columnID;
							row[columnCounter] = 1.0;
						}
						//if (!add_constraintex(lp, columnCounter, row, colno, LE, 1.0))
						//	ret = 3;
						constraintCounter++;
						if (!add_SOS(lp, (char*)"SOS play once per week", 1, 1, columnCounter, colno, NULL))
							ret = 3;
						subColumns.clear();
					}
				}
			}
		}
	}
	strConstraintCount = std::string() + "Constraint 2: " + std::to_string(constraintCounter);
	printf("%s\n", strConstraintCount.c_str());

	// Each Home-Away-Grade combination is only played twice ROADWORK (for a 4 round competition)
	constraintCounter = 0;
	//for (gradeCounter = 0; gradeCounter < grades.size(); gradeCounter++) {
	//	for (homeTeamCounter = 0; homeTeamCounter < grades[gradeCounter]->teams.size(); homeTeamCounter++) {
	//		for (awayTeamCounter = 0; awayTeamCounter < grades[gradeCounter]->teams.size(); awayTeamCounter++) {
	//						subColumns.clear();
	//						result = Model.filterColumns(&subColumns, grades[gradeCounter],grades[gradeCounter]->teams[homeTeamCounter], grades[gradeCounter]->teams[awayTeamCounter],&SAT, 0, 100, 0.0, 23.0, nullptr);
	//						result = Model.filterColumns(&subColumns, grades[gradeCounter], grades[gradeCounter]->teams[homeTeamCounter], grades[gradeCounter]->teams[awayTeamCounter], &SUN, 0, 100, 0.0, 23.0, nullptr);
	//						//created the constraint
	//						if (subColumns.size() > 0)
	//						{
	//							for (columnCounter = 0; columnCounter < subColumns.size(); columnCounter++)
	//							{
	//								colno[columnCounter] = subColumns[columnCounter]->columnID;
	//								row[columnCounter] = 1.0;
	//							}
	//							constraintCounter++;
	//							if (!add_constraintex(lp, columnCounter, row, colno, LE, 1.0))
	//								ret = 3;
	//						//if (!add_SOS(lp, (char*)"SOS play once SAT", 1, 1, columnCounter, colno, NULL))
	//						//	ret = 3;
	//							subColumns.clear();
	//						}	
	//		}
	//	}
	//}
	strConstraintCount = std::string() + "Constraint 3: " + std::to_string(constraintCounter);
	printf("%s\n", strConstraintCount.c_str());

	//two teams can't play each other more than once over a x week period
	constraintCounter = 0;
	//for (gradeCounter = 0; gradeCounter < grades.size(); gradeCounter++) {
	//	for (homeTeamCounter = 0; homeTeamCounter < grades[gradeCounter]->teams.size(); homeTeamCounter++) {
	//		for (awayTeamCounter = 0; awayTeamCounter < grades[gradeCounter]->teams.size(); awayTeamCounter++) {
	//			for (weekCounter = 1; weekCounter <= Model.weekCount-3; weekCounter+=3){
	//						subColumns.clear();
	//						result = Model.filterColumns(&subColumns, grades[gradeCounter], grades[gradeCounter]->teams[homeTeamCounter], grades[gradeCounter]->teams[awayTeamCounter],nullptr, weekCounter, weekCounter+2, 0.0, 23.0, nullptr);
	//						result = Model.filterColumns(&subColumns, grades[gradeCounter], grades[gradeCounter]->teams[awayTeamCounter], grades[gradeCounter]->teams[homeTeamCounter], nullptr, weekCounter, weekCounter+2, 0.0, 23.0, nullptr);
	//						//created the constraint
	//						if (subColumns.size() > 0)
	//						{
	//							for (columnCounter = 0; columnCounter < subColumns.size(); columnCounter++)
	//							{
	//								colno[columnCounter] = subColumns[columnCounter]->columnID;
	//								row[columnCounter] = 1.0;
	//							}
	//							constraintCounter++;
	//							if (!add_constraintex(lp, columnCounter, row, colno, LE, 1.0))
	//								ret = 3;
	//							subColumns.clear();
	//						}
	//			}
	//		}
	//	}
	//}
	strConstraintCount = std::string() + "Constraint 4: " + std::to_string(constraintCounter);
	printf("%s\n", strConstraintCount.c_str());

	//ensure games are spread out - at least 1 home game in first 1/2
	constraintCounter = 0;
	for (gradeCounter = 0; gradeCounter < grades.size(); gradeCounter++) {
		for (homeTeamCounter = 0; homeTeamCounter < grades[gradeCounter]->teams.size(); homeTeamCounter++) {
			for (awayTeamCounter = 0; awayTeamCounter < grades[gradeCounter]->teams.size(); awayTeamCounter++) {
					subColumns.clear();
					result = Model.filterColumns(&subColumns, grades[gradeCounter], grades[gradeCounter]->teams[homeTeamCounter], grades[gradeCounter]->teams[awayTeamCounter], nullptr, 0, Model.weekCount/2, 0.0, 23.0, nullptr);
					//created the constraint
					if (subColumns.size() > 0)
					{
						for (columnCounter = 0; columnCounter < subColumns.size(); columnCounter++)
						{
							colno[columnCounter] = subColumns[columnCounter]->columnID;
							row[columnCounter] = 1.0;
						}
						constraintCounter++;
						if (!add_constraintex(lp, columnCounter, row, colno, LE, 1.0)) 
							ret = 3;
						subColumns.clear();
					}
				
			}
		}
	}
	strConstraintCount = std::string() + "Constraint 5: " + std::to_string(constraintCounter);
	printf("%s\n", strConstraintCount.c_str());

	//ensure games are spread out - not more than 1 home game in mid 1/2
	constraintCounter = 0;
	for (gradeCounter = 0; gradeCounter < grades.size(); gradeCounter++) {
		for (homeTeamCounter = 0; homeTeamCounter < grades[gradeCounter]->teams.size(); homeTeamCounter++) {
			for (awayTeamCounter = 0; awayTeamCounter < grades[gradeCounter]->teams.size(); awayTeamCounter++) {
				subColumns.clear();
				result = Model.filterColumns(&subColumns, grades[gradeCounter], grades[gradeCounter]->teams[homeTeamCounter], grades[gradeCounter]->teams[awayTeamCounter], nullptr, Model.weekCount / 4, Model.weekCount * 3 / 4, 0.0, 23.0, nullptr);
				//created the constraint
				if (subColumns.size() > 0)
				{
					for (columnCounter = 0; columnCounter < subColumns.size(); columnCounter++)
					{
						colno[columnCounter] = subColumns[columnCounter]->columnID;
						row[columnCounter] = 1.0;
					}
					constraintCounter++;
					if (!add_constraintex(lp, columnCounter, row, colno, LE, 1.0))
						ret = 3;
					subColumns.clear();
				}

			}
		}
	}
	strConstraintCount = std::string() + "Constraint 6: " + std::to_string(constraintCounter);
	printf("%s\n", strConstraintCount.c_str());

	//ensure games are spread out - at least 1 home game in last 1/2
	constraintCounter = 0;
	for (gradeCounter = 0; gradeCounter < grades.size(); gradeCounter++) {
		for (homeTeamCounter = 0; homeTeamCounter < grades[gradeCounter]->teams.size(); homeTeamCounter++) {
			for (awayTeamCounter = 0; awayTeamCounter < grades[gradeCounter]->teams.size(); awayTeamCounter++) {
				subColumns.clear();
				result = Model.filterColumns(&subColumns, grades[gradeCounter], grades[gradeCounter]->teams[homeTeamCounter], grades[gradeCounter]->teams[awayTeamCounter], nullptr, (Model.weekCount / 2)+1, Model.weekCount, 0.0, 23.0, nullptr);
				//created the constraint
				if (subColumns.size() > 0)
				{
					for (columnCounter = 0; columnCounter < subColumns.size(); columnCounter++)
					{
						colno[columnCounter] = subColumns[columnCounter]->columnID;
						row[columnCounter] = 1.0;
					}
					constraintCounter++;
					if (!add_constraintex(lp, columnCounter, row, colno, LE, 1.0)) 
						ret = 3;
					subColumns.clear();
				}

			}
		}
	}
	strConstraintCount = std::string() + "Constraint 7: " + std::to_string(constraintCounter);
	printf("%s\n", strConstraintCount.c_str());

	//make sure at most 1 home hame is played in the first 14 weeks
	constraintCounter = 0;
	//for (gradeCounter = 0; gradeCounter < grades.size(); gradeCounter++) {
	//	for (homeTeamCounter = 0; homeTeamCounter < grades[gradeCounter]->teams.size(); homeTeamCounter++) {
	//		for (awayTeamCounter = 0; awayTeamCounter < grades[gradeCounter]->teams.size(); awayTeamCounter++) {
	//			subColumns.clear();
	//			result = Model.filterColumns(&subColumns, grades[gradeCounter], grades[gradeCounter]->teams[homeTeamCounter], grades[gradeCounter]->teams[awayTeamCounter], nullptr, 0, 14, 0.0, 23.0, nullptr);
	//			//created the constraint
	//			if (subColumns.size() > 0)
	//			{
	//				for (columnCounter = 0; columnCounter < subColumns.size(); columnCounter++)
	//				{
	//					colno[columnCounter] = subColumns[columnCounter]->columnID;
	//					row[columnCounter] = 1.0;
	//				}
	//				constraintCounter++;
	//				if (!add_constraintex(lp, columnCounter, row, colno, LE, 1)) 
	//					ret = 3;
	//				subColumns.clear();
	//			}

	//		}
	//	}
	//}
	strConstraintCount = std::string() + "Constraint 8: " + std::to_string(constraintCounter);
	printf("%s\n", strConstraintCount.c_str());

	//make sure at most 1 home hame is played in the last 14 weeks
	constraintCounter = 0;
	//for (gradeCounter = 0; gradeCounter < grades.size(); gradeCounter++) {
	//	for (homeTeamCounter = 0; homeTeamCounter < grades[gradeCounter]->teams.size(); homeTeamCounter++) {
	//		for (awayTeamCounter = 0; awayTeamCounter < grades[gradeCounter]->teams.size(); awayTeamCounter++) {
	//			subColumns.clear();
	//			result = Model.filterColumns(&subColumns, grades[gradeCounter], grades[gradeCounter]->teams[homeTeamCounter], grades[gradeCounter]->teams[awayTeamCounter], nullptr,10, 24, 0.0, 23.0, nullptr);
	//			//created the constraint
	//			if (subColumns.size() > 0)
	//			{
	//				for (columnCounter = 0; columnCounter < subColumns.size(); columnCounter++)
	//				{
	//					colno[columnCounter] = subColumns[columnCounter]->columnID;
	//					row[columnCounter] = 1.0;
	//				}
	//				constraintCounter++;
	//				if (!add_constraintex(lp, columnCounter, row, colno, LE, 1))
	//					ret = 3;
	//				subColumns.clear();
	//			}

	//		}
	//	}
	//}
	strConstraintCount = std::string() + "Constraint 9: " + std::to_string(constraintCounter);
	printf("%s\n", strConstraintCount.c_str());

	write_mps(lp, (char*)"model.mps");

	if (ret == 0) {
		/* set the object direction to maximize */
		set_maxim(lp);

		/* just out of curioucity, now show the model in lp format on screen */
		/* this only works if this is a console application. If not, use write_lp and a filename */
		//write_LP(lp, stdout);

		//Note from KP: reading above comment it would seem that write_LP(lp, stdout); should
		//work but its not. so instead use the 2 lines below to write the model to a
		//file. the file will be created in the GameScheduler sub folder. it will get
		//overwritten each time you re-run program. this should be the only change
		//you need and then everything else works
		char filename[10] = "model.lp";
		write_lp(lp, filename);

		/* I only want to see important messages on screen while solving */
		set_verbose(lp, NORMAL);

		set_add_rowmode(lp, FALSE);
		/* Now let lpsolve calculate a solution */


		set_epsint(lp, 1.0e-3);

		ret = read_basis(lp, (char*)"model.bas", NULL);

		set_timeout(lp, Model.solverTimeout);
		ret = solve(lp);
		ret = write_basis(lp, (char*)"model.bas");
		if (ret == OPTIMAL)
			ret = 0;
		else
			ret = 5;
	}

	//0 - opt, 1=sub optimal, 2=infeas, 3 unbound, 4=degen, 5= fail, 6=user abort, 7=timeout, 9=presolve
	if (ret != NULL ) {
		/* a solution is calculated, now lets get some results */

		/* objective value */
		//printf("Objective value: %f\n", get_objective(lp));

		/* variable values */
		get_variables(lp, row);
		for (j = 0; j < Ncol; j++)
		{

			Model.columns[j]->optimumValue = row[j];
			//printf("%s: %f\n", get_col_name(lp, j + 1), row[j]);
		}

		for (j = 0; j < Ncol; j++)
		{
			//if (row[j]>0)
			//printf("%s: %f\n", get_col_name(lp, j + 1), row[j]);
		}
		/* we are done now */

		std::string delimiter = ",";
		std::ofstream outfile;
		outfile.open("afile.csv");
		std::string data;

		data = "\"Week\",\"Day\",\"Rink\",\"Time\"";
		outfile << data;
		outfile << delimiter;
		for (gradeCounter = 0; gradeCounter < grades.size(); gradeCounter++) {
			for (homeTeamCounter = 0; homeTeamCounter < grades[gradeCounter]->teams.size(); homeTeamCounter++) {
				for (awayTeamCounter = 0; awayTeamCounter < grades[gradeCounter]->teams.size(); awayTeamCounter++) {
					if(homeTeamCounter!=awayTeamCounter){
						
							data = '"' + grades[gradeCounter]->name + '"';
							//outfile << data << std::endl;
							outfile << data;
							outfile << delimiter;
						
					}
				}
			}
		}
		outfile << std::endl;
		std::string lpName = get_lp_name(lp);
		data = "\"" + lpName + "\",\" \",\" \",\" \"";
		outfile << data;
		outfile << delimiter;
		for (gradeCounter = 0; gradeCounter < grades.size(); gradeCounter++) {
			for (homeTeamCounter = 0; homeTeamCounter < grades[gradeCounter]->teams.size(); homeTeamCounter++) {
				for (awayTeamCounter = 0; awayTeamCounter < grades[gradeCounter]->teams.size(); awayTeamCounter++) {
					if (homeTeamCounter != awayTeamCounter) {
						
							data = '"' + grades[gradeCounter]->teams[homeTeamCounter]->name + '"';
							//outfile << data << std::endl;
							outfile << data;
							outfile << delimiter;
						
					}
				}
			}
		}
		outfile << std::endl;
		data = "\" \",\" \",\" \",\" \"";
		outfile << data;
		outfile << delimiter;
		for (gradeCounter = 0; gradeCounter < grades.size(); gradeCounter++) {
			for (homeTeamCounter = 0; homeTeamCounter < grades[gradeCounter]->teams.size(); homeTeamCounter++) {
				for (awayTeamCounter = 0; awayTeamCounter < grades[gradeCounter]->teams.size(); awayTeamCounter++) {
					if (homeTeamCounter != awayTeamCounter) {
						
							data = '"' + grades[gradeCounter]->teams[awayTeamCounter]->name + '"';
							//outfile << data << std::endl;
							outfile << data;
							outfile << delimiter;
						
					}
				}
			}
		}

		outfile << std::endl;
		for (slotCounter = 0; slotCounter < slots.size(); slotCounter++) {

			data = "\"" + std::to_string(slots[slotCounter]->week) + "\",\"" + slots[slotCounter]->dayOfWeek->dayName + "\",\"" + slots[slotCounter]->rink->name + "\",\"" + std::to_string(slots[slotCounter]->startTime) + "\"";
			outfile << data;
			outfile << delimiter;
			for (gradeCounter = 0; gradeCounter < grades.size(); gradeCounter++) {
				for (homeTeamCounter = 0; homeTeamCounter < grades[gradeCounter]->teams.size(); homeTeamCounter++) {
					for (awayTeamCounter = 0; awayTeamCounter < grades[gradeCounter]->teams.size(); awayTeamCounter++) {
						if (homeTeamCounter != awayTeamCounter) {
							
								//result = Model.getOptimumValue(grades[gradeCounter], roundCounter, grades[gradeCounter]->teams[homeTeamCounter], grades[gradeCounter]->teams[awayTeamCounter],slots[slotCounter]->dayOfWeek, slots[slotCounter]->week, slots[slotCounter]->startTime, slots[slotCounter]->rink);
								//outfile << data << std::endl;
								result = Model.getOptimumValue(grades[gradeCounter],  grades[gradeCounter]->teams[homeTeamCounter], grades[gradeCounter]->teams[awayTeamCounter], slots[slotCounter]->dayOfWeek, slots[slotCounter]->week, slots[slotCounter]->startTime, slots[slotCounter]->rink);
								if (result < 0) {
									outfile << "";
								}
								else
								{
									if (result > 0)
									{
										outfile << std::to_string(result);
									}
									else
									{
										outfile << std::to_string(result);
									}

								}

								outfile << delimiter;
							
						}
					}
				}
			}
			outfile << std::endl;
		}

		outfile.close();
	}

	/* free allocated memory */
	if (row != NULL)
		free(row);
	if (colno != NULL)
		free(colno);

	if (lp != NULL) {
		/* clean up such that all used memory by lpsolve is freed */
		delete_lp(lp);
	}

	return(ret);
}

int main()
{
	
	runScheduler();
	
	//Note from KP: i added the getchar() just so it waits at the end before exiting
	//so you get a chance to read output to command window
	getchar();
	return 0;

	//lprec *lp;

	//lp = make_lp(0, 4);

	/* ... */

	//delete_lp(lp);
}