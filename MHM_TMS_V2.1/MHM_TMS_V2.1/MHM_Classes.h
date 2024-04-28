#pragma once
#include<iostream>
#include"raylib.h"
#include<fstream>
#include<string>
#include<cstring>

using namespace std;

class Accounts
{
	//Assume blah blah
};

class Admin : protected Accounts
{
private:
	int routePrice;
	int PriceOfExecutiveSeat;
	int PriceOfEconomicSeat;
	int PriceOfBusinessSeat;
public:
	void SetAvailabilityOfTrain();
	void SetAvailableSchedule();
	void SetFare();
	static int GetData(int*& all_routes, string*& start, string*& end, int**& schedules);
	static void ChangeRouteAvailability(int* all_routes);
	void viewFeedback();
};