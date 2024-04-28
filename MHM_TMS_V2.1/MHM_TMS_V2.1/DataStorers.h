#include"MHM_Functions.h"

#ifndef DATASTORERS_H
#define DATASTORERS_H

//Getting data from the files into manipulative data modifiers (variables, pointers etc.)
static string* Start, * End;
static int* all_routes, ** Schedules, number_of_routes = Admin::GetData(all_routes,Start, End, Schedules);


#endif