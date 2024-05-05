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
class DataFromSelectionClass
{
protected:
    int economicSeats;
    int businessSeats;
    int executiveSeats;

public:
    DataFromSelectionClass();

   
    int getEconomicSeats() const;
    int getBusinessSeats() const;
    int getExecutiveSeats() const;
};

class DataFromAdminClass
{
protected:
    int routePrice;
    string train;
    string schedule;

public:
    DataFromAdminClass();

   
    int getRoutePrice() const;
    string getTrain() const;
    string getSchedule() const;
};

class paymentFare : public DataFromAdminClass, public DataFromSelectionClass
{
private:
    int totalFare;

public:
    paymentFare();

    
    int calculateFare(int economicPrice, int businessPrice, int executivePrice);

    // Getter for total fare
    int getTotalFare() const;
};
