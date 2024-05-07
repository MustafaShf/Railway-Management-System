#ifndef Classes_H
#define Classes_H

#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include <msclr/marshal_cppstd.h>
#include"MHM_User.h"

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
	//blah blah
};

//to take data from database that is set by admin
class UserDataRetriever
{
	int availability_user;
	string start_user;
	string end_user;
	int* schedule_user;
	int* trains_user;
public:
	void UserDataSetter(int x, string y, string z)
	{
		availability_user = x;
		start_user = y;
		end_user = z;
	}

	void availabilityUserSetter(int x)
	{
		availability_user = x;
	}

	void scheduleUserSetter(int* ptr)
	{
		this->schedule_user = new int[24];
		for (int i = 0; i < 24; i++)
		{
			this->schedule_user[i] = ptr[i];
		}
	}

	void trainsUserSetter(int* ptr)
	{
		this->trains_user = new int[3];
		for (int i = 0; i < 3; i++)
		{
			this->trains_user[i] = ptr[i];
		}
	}

	int availabilityUserGetter()
	{
		return availability_user;
	}

	string startUserGetter()
	{
		return start_user;
	}

	string endUserGetter()
	{
		return end_user;
	}

	int* scheduleUserGetter()
	{
		return this->schedule_user;
	}

	int* trainsUserGetter()
	{
		return trains_user;
	}
};

class UserSelection : public Accounts
{
	string route;		//the route that is selected by the user
	int schedule;		//the schedule selected by user
	int train;		//the train selected by the user
	int no_of_Executive_seats;
	int no_of_Economic_seats;
	int no_of_Business_seats;
public:
	
	int GetData(UserDataRetriever*& b);

	void UserRouteSetter(string x)
	{
		route = x;
	}

	void UserScheduleSetter(int x)
	{
		schedule = x;
	}

	void UserTrainSetter(int x)
	{
		train = x;
	}

	string UserRouteGetter()
	{
		return route;
	}

	int UserScheduleGetter()
	{
		return schedule;
	}

	int UserTrainGetter()
	{
		return train;
	}

	UserSelection(string a = "", int b=0, int c=0, int d=0, int e=0, int f=0 ) : route(a), schedule(b), train(c), no_of_Executive_seats(d), no_of_Economic_seats(e),no_of_Business_seats(f)
	{}
};

#endif 