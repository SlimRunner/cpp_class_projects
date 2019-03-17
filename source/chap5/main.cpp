// Mario D. Flores
// March 26, 2018
// Bank Charges: Calculates and display the fees charged by a bank

#include<iostream>
#include<iomanip>

using namespace std;

int main()
{
	int total_Checks;
	double initial_Balance,check_Fee;
	double total_fees;

	const double TOOLOW_SURCHARGE = 15;//amount charged if balance is below threshold
	const double SURCHARGE_THRESHOLD = 400;//threshold to which surcharge is going to be applied
	const double STANDARD_FEE = 10;

	//Welcome message
	cout << "This program calculates the fees you are going to be charged based on the number of checks you wrote and your balance." << endl << endl;

	//input of balance
	cout << "Enter balance: ";
	cin >> initial_Balance;

	//input of number of checks
	cout << "Enter the number of checks you wrote: ";
	cin >> total_Checks;

	//checking if total_Checks value is valid (not negative)
	if (total_Checks < 0)
	{
		//Second opportunity to input number of checks
		cout << endl << "This value cannot be negative." << endl;
		cout << "Enter the number of checks again: ";
		cin >> total_Checks;
	}

	//checking if total_Checks is valid again if not program will close
	if (total_Checks > 0)
	{

		//checking how much fees to charge based on the amount of checks written
		if (total_Checks < 20)
			check_Fee = 0.1;
		else if (total_Checks < 40)
			check_Fee = 0.08;
		else if (total_Checks < 60)
			check_Fee = 0.06;
		else
			check_Fee = 0.04;

		//ternary operator used to decide whether to charge or not a surcharge for low balance
		total_fees = initial_Balance < SURCHARGE_THRESHOLD ? TOOLOW_SURCHARGE + check_Fee*total_Checks+ STANDARD_FEE : check_Fee*total_Checks+ STANDARD_FEE;

		//Displaying warning of overdrawn account if balance is below 0
		if (initial_Balance < 0)
			cout << endl << "WARNING! Your account is overdrawn." << endl;

		cout << setprecision(2) << fixed << showpoint;

		//displaying final output to user
		cout << "You will pay a total amount of $" << total_fees << " for this month.";
	}

	else
	{
		cout << "This value cannot be negative. Program is closing.";
	}

	//--------------------------
	cout << endl << endl;
	system("pause");
	return 0;
}