/**************************************************************************
 * Name: Dev Chauhan                                                      *
 * Program Name: Imperial Mechanic                                        *
 * Date: March 30 2020                                                    *
 * Program: The purpose of this program is to keep information about each *
 *          vehicle needs will be kept and manipulated in this program.   *
 **************************************************************************/
 
#include "prog5.h"

int enterVehicles(int currNumVehicles, Vehicles* vehicleArr)//enter function
{  
  
	int input;
	string filename;
	string temp;
	ifstream inFile;// file intialization
	char tempChar;

	if(currNumVehicles < 100)
	{
		cout << "What do you want to do?" << endl;
		cout << "\t1.  Load my vehicle from a file" << endl;
		cout << "\t2.  Enter one vehicle manually" << endl;
		cout << "\tChoose 1 or 2." << endl;
		cout << "CHOICE: ";
		cin >> input;
		
		while(input < 1 || input > 2)// validating user choice
	    {
			cout << "Error!! Please eneter 1 or 2." << endl;
			cout << "CHOICE: ";
			cin >> input;
	    }	
		
		if(input == 1)
		{
			cin.ignore();
			cout << "What is the name of the file with your list of vehicles? (ex: filename.txt)" << endl;
			cout << "FILENAME: ";
			getline(cin, filename);
			
			inFile.open(filename.c_str());
			if (inFile.good())
		    {
				getline(inFile, temp, '#');
				while(!inFile.eof())
				{
					vehicleArr[currNumVehicles].name = temp;
					getline(inFile, temp, '#');
					
					vehicleArr[currNumVehicles].description = temp;
					getline(inFile, temp, '#');
					
					vehicleArr[currNumVehicles].weapons = convertToFloat(temp);
					getline(inFile, temp, '#');
					
					vehicleArr[currNumVehicles].cost.numHours = convertToFloat(temp);
					getline(inFile, temp, '#');
					
					vehicleArr[currNumVehicles].cost.CostperHour = convertToFloat(temp);
					getline(inFile, temp, '#');
					
					vehicleArr[currNumVehicles].cost.Costparts = convertToFloat(temp);
					getline(inFile, temp, '#');
					
					vehicleArr[currNumVehicles].cost.Costmaterial = convertToFloat(temp);
					currNumVehicles++;
					getline(inFile, temp, '#');
				}	
			}
			else
			{
				cout << filename << " does not exist or is corrupt. Sorry. Can't load vehicles." << endl;	
			}
		}	
		else if(input == 2)
		{
			do
			{
				cin.ignore();
				
				cout << "\nNAME: ";
				getline(cin, temp);
				vehicleArr[currNumVehicles].name = temp;
			
				cout << "\nDESCRIPTION: ";
				getline(cin, temp);
				vehicleArr[currNumVehicles].description = temp;
			
				cout << "\nDOES THIS VEHICLE HAVE WEAPONS? (y or n): ";
				cin >> tempChar;
				if(tempChar == 'y' || tempChar == 'Y')
					vehicleArr[currNumVehicles].weapons = 1;
				else
					vehicleArr[currNumVehicles].weapons = 0;
			
				cout << "\nHow many hours do you spend repairing the " << vehicleArr[currNumVehicles].name << "?" << endl;
				cout << "NUM HOURS: ";
				cin >> vehicleArr[currNumVehicles].cost.numHours;
			
				cout << "\nWhat is the cost per hour for repairing for the " << vehicleArr[currNumVehicles].name << "?" << endl;
				cout << "COST PER HOUR: ";
				cin >> vehicleArr[currNumVehicles].cost.CostperHour;
			
				cout << "\nHow much money do you spend on part for the " << vehicleArr[currNumVehicles].name << "?" << endl; 
				cout << "PART COST: ";
				cin >> vehicleArr[currNumVehicles].cost.Costparts;
			
				cout << "\nHow much money do you spend on supplies for the " << vehicleArr[currNumVehicles].name << "?" << endl;
				cout << "SUPPLIES COST: ";
				cin >> vehicleArr[currNumVehicles].cost.Costmaterial;
			
				currNumVehicles++;
			
				cout << "\nWould you like to add more vehicles? (y or n): ";
				cin >> tempChar;
				cin.ignore();
			}while(tempChar == 'y' || tempChar == 'Y');
			
			cout << endl;
		}	
		
	}
	else
	{
		cout << "SORRY!! You have no space in your garage" << endl;
	}
	return currNumVehicles;

}

int deleteVehicle(int currNumVehicles, Vehicles* vehicleArr)//Delete Function
{
	cin.ignore();
	string temp;
	bool deleted;
	
	cout << "The following is a list of all the vehicles you take care of: " << endl;
	
	for(int x = 0; x < currNumVehicles; x++)
	{
		cout << vehicleArr[x].name << endl;
	}
	cout << "What vehicle do you wish to remove?" << endl;
	cout << "\nVEHICLE NAME: ";
	getline(cin, temp); 
	
	deleted = moveArrayElements(temp, currNumVehicles, vehicleArr);
	
	if(deleted)
	{
		currNumVehicles--;
		cout << endl << temp << "was removed from your garage.";
	}	
    else
	{
		cout << "Vehicle Not Found" << endl;
	}
return currNumVehicles;	
}

bool moveArrayElements(string name, int currNumVehicles, Vehicles* vehicleArr)// bool function
{
	int index;
	bool found = false;
	
	int numremove = 101;
	Vehicles userInput;
	
	for(int x = 0; x < currNumVehicles; x++)
	{
		if(name == vehicleArr[x].name)
		{
			index = x;
			found = true;
		}
    }
	
	if(found == false)
	{
		return false;
	}	
	
	else
	{
		for(int x = index; x < currNumVehicles; x++)
		{
			vehicleArr[x].name = vehicleArr[x+1].name;
			vehicleArr[x].description =vehicleArr[x+1].description;
			vehicleArr[x].weapons = vehicleArr[x+1].weapons;
			vehicleArr[x].cost.numHours = vehicleArr[x+1].cost.numHours;
		    vehicleArr[x].cost.CostperHour = vehicleArr[x+1].cost.CostperHour;
			vehicleArr[x].cost.Costparts = vehicleArr[x+1].cost.Costparts;
			vehicleArr[x].cost.Costmaterial = vehicleArr[x+1].cost.Costmaterial;
		}
	  return true;	
	}
}	

void printVehicle(int currNumVehicles, Vehicles* vehicleArr)
{
	int response;
	
	cout << "What  would like to do?" << endl;
	cout << "\t1. Print vehicle to the screen" << endl;
	cout << "\t2. Print vehicle to a file" << endl;
	cout << "\tChoose 1 or 2." << endl;
	cout << "CHOICE: ";
	cin >> response;
	
	
	while(response < 1 || response > 2)
	{
		cout << "Error!! Please eneter 1 or 2." << endl;
		cout << "CHOICE: ";
		cin >> response;
	}

	if(response == 1)
	{	
		for(int x = 0; x < currNumVehicles; x++)
	    {
			cout << "------------------------------------------------------------------" << endl;
			cout << "\nVEHICLE " << x+1 << ": " << endl;
			cout << "\nName:\t\t" << vehicleArr[x].name << endl;
			cout << "Description:\t" << vehicleArr[x].description << endl;
			cout << "\nHas Weapons?\t" << vehicleArr[x].weapons << endl;
			if(vehicleArr[x].weapons == 1)
				cout << "yes" <<endl;
			else
				cout << "no" << endl;
			cout << "Number of Hours to repair Vehicle:\t\t" << vehicleArr[x].cost.numHours << endl;
			cout << "Cost Per Hour:\t\t" << vehicleArr[x].cost.CostperHour << endl;
			cout << "Cost for Parts:\t\t" << vehicleArr[x].cost.Costparts << endl;
			cout << "Supplies Cost:\t\t" << vehicleArr[x].cost.Costmaterial << endl;
		
			cout << "---------------------------------------------------------------------" << endl;
			cout << "\n\n";
		}
	}	
	else if(response == 2)
	{	
		string filename;
		ofstream outFile;
		
		cout << "What is the name of your file you wish to write to?" << endl;
		cout << "FILENAME: ";
		getline(cin, filename);
		outFile.open(filename.c_str());

		for(int x = 0; x < currNumVehicles; x++)
        {
			outFile << "------------------------------------------------------------------" << endl;
			outFile << "\nVEHICLE " << x+1 << ": " << endl;
			outFile << "Name:\t\t" << vehicleArr[x].name << endl;
			outFile << "Description:\t\t" << vehicleArr[x].description << endl;
			outFile << "Has Weapons?\t\t" << vehicleArr[x].weapons << endl;
			outFile << "Number of Hours to repair Vehicle:\t\t" << vehicleArr[x].cost.numHours << endl;
			outFile << "Cost Per Hour:\t\t" << vehicleArr[x].cost.CostperHour << endl;
			outFile << "Cost for Parts:\t\t" << vehicleArr[x].cost.Costparts << endl;
			outFile << "Supplies Cost:\t\t" << vehicleArr[x].cost.Costmaterial << endl;
		}			
		cout << "Vehicles have been entered into " << filename << ".";
		outFile.close();
	}
}

void printStatistics(int currNumVehicles, Vehicles* vehicleArr)
{
	double totalCost;
	double cost;
	
	cout << "COST OF EACH VEHICLE:\n\nVEHICLE\t\tCOST" << endl;
	
	for(int x = 0; x < currNumVehicles; x++)
	{
		cost = vehicleArr[x].cost.numHours = vehicleArr[x].cost.CostperHour + vehicleArr[x].cost.Costparts + vehicleArr[x].cost.Costmaterial;
		cout << endl << vehicleArr[x].name << "\t$" << setprecision(2) << fixed << cost;
		totalCost += cost;
	}
 
	cout << "\n\nTOTAL COST:\t$" << setprecision(2) << fixed << totalCost << endl;
	
}	
void saveVehiclesToFile(int currNumVehicles, Vehicles* vehicleArr)
{   
   char response;
   ofstream outfile;
   string filename;
   cin.ignore();
   
	cout << "Would you like to save your vehicle list to a file? (y or n)" << endl;
	cin >> response;
	
	if(response == 'y' || response == 'Y')
	{
		cout << "What is the name of the file you want to save your vehicles to?" << endl;
		cout << "\nFILENAME: ";
		getline(cin, filename);
		
		outfile.open(filename.c_str());
	
		for(int x = 0; x < currNumVehicles; x++)
		{
			outfile << vehicleArr[x].name << "#";
			outfile << vehicleArr[x].description << "#";
			outfile << vehicleArr[x].weapons << "#";
			outfile << vehicleArr[x].cost.numHours << "#";
			outfile << vehicleArr[x].cost.CostperHour << "#";
			outfile << vehicleArr[x].cost.Costparts << "#";				
			outfile << vehicleArr[x].cost.Costmaterial << "#";
		}
		outfile.close();
		
		cout << "\nYour vehicles were successfully saved to the" << filename << "infile." << endl;
		cout << "\n*****************************************************************" << endl;
		cout << "GOODBYE!" << endl;
	}	
	
}

float convertToFloat(string s)
{
	istringstream i(s);
	float x;
	if (!(i >> x))
		x = 0;
	return x;
}
