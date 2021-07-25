/***********************************************************************
Name: Dev Chauhan
Date: March 30 2020
Program: The purpose of this program is to calculate total profits,
         average profit per month, the most profitable month, the least
		 profitable month, and also the quartely profits.
************************************************************************/

#ifndef PROGRAM_3_H
#define PROGRAM_3_H

#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

void getprofit(double[], int);
void getquarterly(double[], double[]);
double gettotal(double[]);
double getmin (double[]);
double getmax (double []);
#endif