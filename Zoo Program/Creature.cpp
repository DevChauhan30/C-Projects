/************************************************************************************************************************************** 
    Name: Dev Chauhan
    Date: 09/28/2020
***************************************************************************************************************************************/
#include "Creature.h"
#include "LinkedList.h"
#include <iostream>
using namespace std;
 
void Creature::printCreature()
{ 
    Creature print;

    cout << "--------------------------------------------------------" << endl;
    cout << "Name:  " << print.getName() << endl;
    cout << "Description:  " << print.getDescription() << endl;
    cout << "Dangerous:  " << print.getDangerous() << endl;
    cout << "Cost per Month to Care for Creature:  $ "<< print.getCost() << endl;
}

void Creature::printCreatureToFile( ofstream &outFile)
{
    Creature print;

	outFile << print.getName() << endl;
	outFile << print.getDescription() << endl;
	outFile << print.getDangerous()<< endl;
	outFile << print.getCost() << endl;
}