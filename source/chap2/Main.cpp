// Mario D. Flores
// Feb 28, 2018
// Laboratory 2 - Stock Commission

#include <iostream>
using namespace std;

int main()
{
	//Initialiazing constants
	const double COMM_PERCENT = 0.02; //2%

	int shares  = 750; //Shares bought
	double pricePerStock = 35.0f; //price per share
	double sharesPrice, commAmount, totalPaid;

	//calculating how much all the shares bought cost
	sharesPrice = shares *pricePerStock;
	//calculating the commission percent for the broker
	commAmount = sharesPrice*COMM_PERCENT;
	//Calculating the grand total
	totalPaid = sharesPrice + commAmount;

	//displaying the results to the user
	cout << "You are buying " << shares  << " shares at a cost of $" << pricePerStock << " each" << endl << endl;
	cout << "Cost of shares: $" << sharesPrice << endl;
	cout << "Broker commission: $" << commAmount << endl;
	cout << "Grand total is: $" << totalPaid << endl;
	

	//--------------------------------
	cout << endl << endl;
	system("pause");
	return 0;
}