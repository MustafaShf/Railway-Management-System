#include <iostream>
#include"MHM_Functions.h"
using namespace std;

#ifndef DATASTORERS_H
#define DATASTORERS_H

//Getting data from the files into manipulative data modifiers (variables, pointers etc.)
string* Start = nullptr, * End = nullptr;
int* all_routes = nullptr, ** Schedules = nullptr, number_of_routes = Admin::GetData(all_routes,Start,End,Schedules);

#endif