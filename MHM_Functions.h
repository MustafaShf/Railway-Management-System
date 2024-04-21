#include"MHM_Classes.h"


int Admin :: GetRouteData(int* &all_routes, string*&start, string *&end)
{	
	all_routes = new int[5];			//will be a fixed number, deoending upon number of routes in the data base
	int i = 0, number_of_rectangles=0;
	start = new string[5];
	end = new string[5];
	ifstream routes;
	routes.open("Assets\\routes.txt");
	if (!routes.is_open())
	{
		cout << "Unable to open file" << endl;
		exit(0);
	}
	while (routes >> all_routes[i] >> start[i] >> end[i])
	{
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

	while(getline(iroutes, a))
	{
		if(all_routes[i] == 1)
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