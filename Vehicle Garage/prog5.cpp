/**************************************************************************
 * Name: Dev Chauhan                                                      *
 * Program Name: Imperial Mechanic                                        *
 * Date: March 30 2020                                                    *
 * Program: The purpose of this program is to keep information about each *
 *          vehicle needs will be kept and manipulated in this program.   *
 **************************************************************************/

#include "prog5.h"

int main()
{
	int choice;
	Vehicles vehicleArr[100]; //vehicle array
	int currNumVehicles = 0;
	char option;
	
	do
	{
		
		cout << ">>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<" << endl;
		cout << " What would you like to do?" << endl;
		cout << "\t 1. Enter some vehicles" << endl;
		cout << "\t 2. Delete a vehicle" << endl;
		cout << "\t 3. List/Print vehicles" << endl;
		cout << "\t 4. Print statitics on vehicle cost" << endl;
		cout << "\t 5. End program." << endl;
		cout << "\t Enter 1, 2, 3, 4, or 5." << endl;
		do
		{
		cout << "CHOICE: ";
		cin >> choice;
	    }while(choice < 1 || choice > 5);// validating user choice
		cout << "\n";
		
		switch(choice)
		{	
			case 1: currNumVehicles = enterVehicles(currNumVehicles, vehicleArr);
		
					break;
		
			case 2: currNumVehicles = deleteVehicle(currNumVehicles, vehicleArr);
		
					break;
		
			case 3: printVehicle(currNumVehicles, vehicleArr);
		
					break;
	
			case 4: printStatistics(currNumVehicles, vehicleArr);
		
					break;
		
			case 5: 
					cout << "Do you wish to save your garage to a file? ";
					cin >> option;
				
					if(option == 'y' || option == 'Y') 
						saveVehiclesToFile(currNumVehicles, vehicleArr);
		            break;
		}
	
	}while(choice != 5);
	
	cout << "\n>>>>>>>>>>>>GOODBYE!<<<<<<<<<<<<<<<<<<<";
	
	return 0;
}	