#include"MHM_Classes.h"

int Admin::GetData(int*& all_routes, string*& start, string*& end, int**& schedules)
{
	all_routes = new int[6];			//will be a fixed number, deoending upon number of routes in the data base
	int i = 0, number_of_rectangles = 0;
	start = new string[6];
	end = new string[6];
	schedules = new int* [6];	//will contain available schedules for each route

	ifstream routes, scheds;
	routes.open("Assets\\routes.txt");
	scheds.open("Assets\\Schedule.txt");
	if (!routes.is_open())
	{
		cout << "Unable to open routes file" << endl;
		exit(0);
	}
	if (!scheds.is_open())
	{
		cout << "Unable to open schedules file" << endl;
		exit(0);
	}

	while (i < 6 && routes >> all_routes[i] >> start[i] >> end[i])
	{
		schedules[i] = new int[24];

		for (int j = 0; j < 24; ++j)
		{
			if (!(scheds >> schedules[i][j]))
			{
				cout << "Error reading schedule data" << endl;
				exit(0);
			}
		}
		i++;
	}


	routes.close();
	return i;
}

void Admin::ChangeRouteAvailability(int* all_routes)
{
	string a;
	int i = 0;
	ifstream iroutes("Assets\\routes.txt");
	if (!iroutes.is_open())
	{
		cout << "Unable to open file input" << endl;
		exit(0);
	}
	ofstream oroutes("Assets\\temp.txt");
	if (!oroutes.is_open())
	{
		cout << "Unable to open file temp output" << endl;
		exit(0);
	}

	while (getline(iroutes, a))
	{
		if (all_routes[i] == 1)
			a[0] = '1';
		else if (all_routes[i] == 0)
			a[0] = '0';

		oroutes << a << endl;
		i++;
	}
	iroutes.close();
	oroutes.close();

	if (remove("Assets\\routes.txt") != 0)
	{
		cout << "Error deleting original file" << endl;
		exit(0);
	}
	if (rename("Assets\\temp.txt", "Assets\\routes.txt") != 0)
	{
		cout << "Error renaming temporary file" << endl;
		exit(0);
	}
}



DataFromSelectionClass::DataFromSelectionClass()
{
	
		economicSeats = 11;
		businessSeats = 2;
		executiveSeats = 3;

}

 int DataFromSelectionClass::getEconomicSeats() const { return economicSeats; }
int DataFromSelectionClass::getBusinessSeats() const { return businessSeats; }
int DataFromSelectionClass::getExecutiveSeats() const { return executiveSeats; }

DataFromAdminClass::DataFromAdminClass()
{
	
	routePrice = 122;
	train = "Shalimar";
	schedule = "12:00";
}
int DataFromAdminClass::getRoutePrice() const { return routePrice; }
string DataFromAdminClass::getTrain() const { return train; }
string DataFromAdminClass::getSchedule() const { return schedule; }

paymentFare::paymentFare()
{
	totalFare = 0;
}
int paymentFare::calculateFare(int economicPrice, int businessPrice, int executivePrice)
{
	totalFare = economicSeats * economicPrice +
		businessSeats * businessPrice +
		executiveSeats * executivePrice +
		routePrice;
	return totalFare;
}
int paymentFare::getTotalFare() const { return totalFare; }