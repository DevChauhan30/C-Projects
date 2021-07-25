/************************************************************************************************************************************** 
    Name: Dev Chauhan
    Date: 09/28/2020
    Puropose: class specification for  the Creature class.
***************************************************************************************************************************************/    
#ifndef Creature_H
#define Creature_H
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

class Creature
{
    private:

        string Name;
        string Description;
        bool Dangerous;
        float Cost;

    public:

        string getName() const
        {
            return this->Name;
        }
        string getDescription() const
        {
            return this->Description;
        }
        bool getDangerous() const
        {
            return this->Dangerous;
        }
        float getCost() const
        {
            return this->Cost;
        }

        void setName(string name)
        {
            this->Name = name;
        }
        void setDescription(string description)
        {
            this->Description = description;
        }
        void setDangerous(bool dangerous)
        {
            this->Dangerous = dangerous;
        }
        void setCost(float cost)
        {
            this-> Cost = cost;
        }
        

    void printCreature();
    void printCreatureToFile(ofstream &outFile);
};

#endif