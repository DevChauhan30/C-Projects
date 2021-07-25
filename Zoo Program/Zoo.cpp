/************************************************************************************************************************************** 
    Name: Dev Chauhan
    Date: 09/28/2020
***************************************************************************************************************************************/ 
#include "LinkedList.h"
#include "Creature.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

int enterMagicalCreature(LinkedList<Creature> zoo);
void enterMagicalCreatureFromFile(LinkedList<Creature> zoo);
void printCreatures(LinkedList <Creature> zoo);
void deleteCreature(LinkedList <Creature> zoo, int numNodes);
void saveCreatureToFile(LinkedList<Creature> zoo);

int main()
{
    int choice, numNodes, response;
    char option;
    LinkedList<Creature> zoo;
	
	do
	{
		cout << ">>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<" << endl;
		cout << " What would you like to do?" << endl;
		cout << "\t 1. Enter Magical Creature" << endl;
		cout << "\t 2. Delete a Magical Creature" << endl;
		cout << "\t 3. List/Print Creature" << endl;
		cout << "\t 4. End program." << endl;
		cout << "\t Enter 1, 2, 3, or 4." << endl;
		do
		{
		cout << "CHOICE: ";
		cin >> choice;
	    }while(choice < 1 || choice > 4);// validating user choice
		cout << "\n";
		
		switch(choice)
		{	
			case 1: cout<< "Do you want to enter the creature(s) "<< endl;
                    cout<< "\t1.  Manually?" << endl;
                    cout<< "\t2.  From a file?" << endl;
                    cout<< "ENTER 1 or 2: ";
                    cin>> response;

                    while(response < 1 || response > 2)// validating user choice
                    {
                        cout << "Error!! Please eneter 1 or 2." << endl;
                        cout << "ENTER 1 or 2: ";
                        cin >> response;
                    }	
                    if( response == 1)
                        enterMagicalCreature(zoo);

                    else if( response ==2)
                        enterMagicalCreatureFromFile(zoo);
                
					break;
		
			case 2: deleteCreature(zoo, numNodes);
		
					break;
		
			case 3: printCreatures(zoo);
		
					break;
		
			case 4: 
					cout << "Do you wish to save your creature list to a file? (y or n) ";
					cin >> option;
				
					if(option == 'y' || option == 'Y') 
						saveCreatureToFile(zoo);

					else if(option == 'y'|| option == 'Y')

						cout<< "Good Bye!!"	<<endl;
		            
		}
	
	}while(choice != 4);
	
	cout << "\n>>>>>>>>>>>>GOODBYE!<<<<<<<<<<<<<<<<<<<";
}

int enterMagicalCreature(LinkedList<Creature> zoo)
{
    string temp;
    char tempChar;
    int cost;
	Creature print;
	
	do
	{
		cin.ignore();		
		cout << "\nNAME: ";
		getline(cin, temp);		
		print.setName(temp);

		cout << "\nDESCRIPTION: ";
		getline(cin, temp);
		print.setDescription(temp);

		cout << "\nIS IT A DANGEROUS CREATURE? (y or n): ";
		cin >> tempChar;
		if(tempChar == 'y' || tempChar == 'Y')
		print.setDangerous(1);
		else if (tempChar == 'n' || tempChar == 'N')
		print.setDangerous(0);
	
		cout << "\nCOST PER MONTH TO CARE FOR CREATURE: " << endl;
		cin >> cost;
		print.setCost(cost);

		cout << "\nWould you like to add more creatures? (y or n): ";
		cin >> tempChar;
	
	}while(tempChar == 'y' || tempChar == 'Y');	
	
    cout << endl;	
		
}

void enterMagicalCreatureFromFile(LinkedList<Creature> zoo)
{
	ifstream inFile;
	char temp[1000];
	string Name, filename, Description;
	bool Dangerous;
	float Cost; 
	Creature *creature;
	creature = new Creature;
	
	cout << "What is the File name?" << endl;
	cout << "Filename: ";
	getline(cin, filename);

	inFile.open(filename.c_str());
	if(inFile.good())
	{
		inFile.getline(temp, 1000);
		while(!inFile.eof())
		{	
            inFile.getline(temp, 1000);
			inFile >> Name;
			creature->setName(temp);
            inFile.ignore();
            inFile.getline(temp, 1000);
			inFile >> Description;
			creature->setDescription(temp);
			inFile.ignore(); 
			inFile >> Dangerous;
			if(Dangerous == 'y' || Dangerous == 'Y')
			creature->setDangerous(1);
			else if (Dangerous == 'n' || Dangerous == 'N')
			creature->setDangerous(0);
			inFile >> Cost;
			creature->setCost(Cost);
			inFile.getline(temp, 100);
			
		}
	
	}
	else
	{
		cout << "\n\nSorry, I was unable to open the file.\n";
	}
}

void printCreatures(LinkedList <Creature> zoo)
{
	Creature print;
	string Name, Description;
	bool Dangerous;
	float Cost;
	
	cout << "------------------------------------------------------------------" << endl;
    for(int x = 0; x < zoo.getLength(); x++)
	{
		print = zoo.getNodeValue(x);
		cout << "\nCREATURE " << x+1 << ": " << endl;
		print.printCreature();
	}
}


void deleteCreature( LinkedList <Creature> zoo, int numNodes)
{
	string Name;
	int num;
	bool deleted;
	Creature print;

	cout << "The following is a list of all the creatures you take care of: " << endl;

	for(int x = 0; x < zoo.getLength(); x++)
	{
		print = zoo.getNodeValue(x);
		cout << x+1 << print.getName() << endl;;
	}

	cout << "What creature do you wish to remove?" << endl;
	cout << "CREATURE NUMBER: ";
	cin >> num;

	if(deleted)
	{
		numNodes--;
		cout << "You have removed the creature" << endl;
	}
	else
	{
		cout << "Creature Not Found " << endl;
	}

}

void saveCreatureToFile(LinkedList<Creature> zoo)
{
	ofstream outFile;
    string filename;

    cout << "What is the name of the file you want to save your creatures to?" << endl;
	cout << "\nFILENAME: ";
	getline(cin, filename);
		
	outFile.open(filename.c_str());
	
	outFile.close();
	
	cout << "\n\nAll creatures in your library have been printed to " << filename << endl;
}
