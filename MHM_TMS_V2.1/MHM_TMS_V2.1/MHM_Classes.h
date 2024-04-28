#pragma once
#include<iostream>
#include"raylib.h"
#include<fstream>
#include<string>
#include<cstring>

using namespace std;
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Data::SqlClient;
using namespace System::Runtime::InteropServices;

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
	/*static string* Start, * End;
	static int* all_routes, ** Schedules, number_of_routes;*/
	
	void SetAvailabilityOfTrain();
	void SetAvailableSchedule();
	void SetFare();
	static int GetData(int*& all_routes, string*& start, string*& end, int**& schedules);
	static void ChangeRouteAvailability(int* all_routes);
	void viewFeedback();

	//Admin()
	//{
	//	//getting all the data from the database
	//	number_of_routes = GetData(all_routes, Start, End, Schedules);
	//	//as database is involved, parameterized constructor doesnt make sense
	//}
};

//int Admin::number_of_routes = 0, Admin::*all_routes = nullptr, Admin::**Schedules=nullptr;
//string Admin::* Start = nullptr, Admin::* End = nullptr;