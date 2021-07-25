#include "PROGRAM_3.h"

int main()
{

	const int SIZE = 12;
	string monthNames[12] = {"January", "February", "March", "April"
						     "May", "June", "July", "August", "September"
	                         "October", "November", "December"}; 
	double profit [SIZE]; 
	double quarterlyProfit[4];
	char runagain;
	
	do
	{
		cout << "******************************************" << endl;
		cout << "Welcome to Flourish and Blotts Bookstore!" << endl;
		cout << "******************************************" << endl;
	
		getprofit(profit, SIZE);
	
		cout << "-------------------------------------------------------------" << endl;
		cout << "-------------------------------------------------------------" << endl;
	
		cout << "\tTOTAL PROFITS FOR YEAR:      $ " << gettotal(profit) << endl;
		cout << "\tYEARLY AVERAGE PROFIT:       $ " << gettotal(profit)/12 << endl;
		cout << "\tMONTH WITH LARGEST PROFIT:   $ " << getmax(profit) << endl;
		cout << "\tMONTH WITH SMALLEST PROFIT:  $ " << getmin(profit) << endl;
		cout << "--------------------------------------------------------------" << endl;
	
		getquarterly(profit, quarterlyProfit);
	
		cout << "\t\tQUARTERLY PROFITS" << endl;
		cout << "\tJanuary - March     $" << quarterlyProfit[0] << endl;
		cout << "\tApril - June        $" << quarterlyProfit[1] << endl;
		cout << "\tJuly - September    $" << quarterlyProfit[2]<< endl;
		cout << "\tOctober - December  $" << quarterlyProfit[3] << endl;
	
		cout << "---------------------------------------------------------------" << endl;
		cout << "---------------------------------------------------------------" << endl;
	
	
		cout << "Do you want to run the program again? (Y/N)\n";
		cin >> runagain;
	}while (runagain == 'Y' || runagain == 'y');
	
	return 0;
}


void getprofit (double profit[], int size)
{
	for (int x = 0; x < 12; x++)
	{
		cout << "\nEnter the profit for month " << x+1 << ": $";
		cin >> profit[x];
		cout << endl;
		
		while(profit[x] < 0) //Using a while loop for validating user input
		{
			cout << "I'm sorry, you must enter a profit grater than zero: $ ";
			cin >> profit[x];
		}
	}	
}


double gettotal (double profit[])
{double total = profit[0];
	for (int x = 0; x < 12; x++)
	{ 
		total = (total + profit[x]);
	}
return total;	
}
/*
void average(double profit[], int size )
{
	for (double x = 0; x < 12; x++)
	{
		get = sum + profit[x];
	}
	cout << sum/12 << endl;
}	
*/
double getmin(double profit[])
{double min = profit[0];

	for (int x = 1; x < 12; x++)
	{
		if (profit[x] < min)
		{	
			min = profit[x];
		}	
	}
return min;
}

double getmax(double profit[]) 
{double max = profit[0];

	for (int x = 1; x < 12; x++)
	{
		if (profit[x] > max)
		{	
			max = profit[x];
		}	
	}
return max;
}

void getquarterly (double profit[], double quarterlyProfit[])
{
	
	quarterlyProfit[0] = profit[0] + profit[1] + profit[2];
	quarterlyProfit[1] = profit[3] + profit[4] + profit[5];
	quarterlyProfit[2] = profit[6] + profit[7] + profit[8];
	quarterlyProfit[3] = profit[9] + profit[10] + profit[11];
}	

