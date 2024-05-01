#ifndef Classes_H
#define Classes_H

#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include"MHM_Admin0.h"

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

class dataRetriever
{
	int availability;
	string start;
	string end;
public:
	void dataSetter(int x, string y, string z)
	{
		availability = x;
		start = y;
		end = z;
	}

	void availabilitySetter(int x)
	{
		availability = x;
	}

	int availabilityGetter()
	{
		return availability;
	}

	string startGetter()
	{
		return start;
	}

	string endGetter()
	{
		return end;
	}
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
	int GetData(dataRetriever * &a);
	void ChangeRouteAvailability(dataRetriever* all_routes);
	void viewFeedback();
};

#endif 