/**************************************************************************
 * Name: Dev Chauhan                                                      *
 * Program Name: Imperial Mechanic                                        *
 * Date: March 30 2020                                                    *
 * Program: The purpose of this program is to keep information about each *
 *          vehicle needs will be kept and manipulated in this program.   *
 **************************************************************************/

#ifndef prog5_H
#define prog5_H

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <fstream>
#include <sstream>
using namespace std;

struct Cost //structure for cost
{
	float numHours;	
	float CostperHour;
	float Costparts;
	float Costmaterial;
};

struct Vehicles // structure for vehicle
{
	string name;
	string description;
	bool weapons;
	Cost cost;
};

int enterVehicles(int, Vehicles*);
int deleteVehicle(int, Vehicles*);
bool moveArrayElements(string, int, Vehicles*);
void printStatistics(int, Vehicles*);
void printVehicle(int, Vehicles*);
void saveVehiclesToFile(int, Vehicles*);
float convertToFloat(string);

#endif