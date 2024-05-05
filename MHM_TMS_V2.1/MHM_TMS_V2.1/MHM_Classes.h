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
using namespace System::Collections::Generic;
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
	int* schedule;
	string Feedback;
	string seatNo;
	string Ratings;
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

	void scheduleSetter(int*ptr)
	{
		this->schedule = new int[24];
		for (int i = 0; i < 24; i++)
		{
			this->schedule[i] = ptr[i];
		}
	}

	void FeedbackSetter(string x, string y, string z)
	{
		Feedback = x;
		seatNo = y;
		Ratings = z;
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

	string FeedbackGetter()
	{
		return Feedback;
	}

	string FeedbackSeatNoGetter()
	{
		return seatNo;
	}

	string RatingsGetter()
	{
		return Ratings;
	}

	int* scheduleGetter()
	{
		return this->schedule;
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
	void AdminSetter(int w,int x,int y, int z)
	{
		routePrice = w;
		PriceOfExecutiveSeat = x;
		PriceOfEconomicSeat = y;
		PriceOfBusinessSeat = z;
	}

	int routePriceGetter()
	{
		return routePrice;
	}

	int ExecutiveGetter()
	{
		return PriceOfExecutiveSeat;
	}

	int EconomicGetter()
	{
		return PriceOfEconomicSeat;
	}

	int BusinessGetter()
	{
		return PriceOfBusinessSeat;
	}

	void SetAvailabilityOfTrain();
	void SetAvailableSchedule(dataRetriever* a);
	void SetFare(String^ text1, String^ text2, String^ text3, String^ text4, Admin& admin);
	int GetData(dataRetriever * &a, Admin &admin);
	void ChangeRouteAvailability(dataRetriever* all_routes);
	int viewFeedback(dataRetriever * &a);
};

#endif 