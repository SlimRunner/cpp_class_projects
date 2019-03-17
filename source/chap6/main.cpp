//Programmer: Mario D. Flores
//Keeps track of different types of salsa using arrays
//Monday, May 14, 2018

//Pre-processor directives
#include<iostream>
#include<string>
#include<iomanip>

//Global namespaces
using namespace std;

//Prototypes
void getQty_OnArray(int[], string[], int);
void generateReport(int[], string[], int);
void print_LowestSales(int[], string[], int);
void print_HighestSales(int[], string[], int);

//Main function
int main()
{
	const int SIZE = 5;
	
	string salsaNames[SIZE] = { "Mild","Medium","Sweet","Hot","Zesty" };
	int salsaQty[SIZE] = { 0 };

	cout << "This application creates a report for the quantity of salsas you enter." << endl << endl;

	getQty_OnArray(salsaQty, salsaNames, SIZE);
	cout << endl << endl;
	generateReport(salsaQty, salsaNames, SIZE);


	//-----------------------------
	cout << endl << endl;
	system("pause");
	return 0;
}

//Prompts the user 'arraySize' many times and stores the input into 'newQty'
void getQty_OnArray(int newQty[], string itemName[],int arraySize)
{
	int index = 0;
	bool inputNotValid = false; 

	do
	{
		if (inputNotValid)
			cout << "Quantity can't be negative." << endl;
		else
			cout << endl;

		cout << "Enter the quantity for " << itemName[index] << ": ";
		cin >> newQty[index];

		inputNotValid = newQty[index] < 0;
		(inputNotValid) ? index=index: index++;
	} while (index < arraySize);
}

void generateReport(int salesQty[], string itemName[], int arraySize)
{
	const int PADDING_SIZE = 15;
	int totalSales = 0, currentIndex;
	
	for (int i = 0; i < arraySize; i++)
	{
		totalSales += salesQty[i];
		cout << setw(PADDING_SIZE) << left << itemName[i] << ":" << salesQty[i] << endl;
	}

	cout << endl << setw(PADDING_SIZE) << left << "Total" << ":" << totalSales << endl << endl;

	print_LowestSales(salesQty, itemName, arraySize);
	print_HighestSales(salesQty, itemName, arraySize);
}

void print_LowestSales(int salesQty[], string itemName[], int arraySize)
{
	int lowestNum = salesQty[0];
	int index = 1;

	while (index < arraySize)
	{
		if (lowestNum > salesQty[index])
		{
			lowestNum = salesQty[index];
		}
		index++;
	}

	for (int i = 0; i < arraySize; i++)
	{
		if (salesQty[i] == lowestNum)
			cout << setw(15) << left << "Lowest sales" << ":" << itemName[i] << " (" << salesQty[i] << ")" << endl;
	}
}

void print_HighestSales(int salesQty[], string itemName[], int arraySize)
{
	int highestNum = salesQty[0];
	int index = 1;

	while (index < arraySize)
	{
		if (highestNum < salesQty[index])
		{
			highestNum = salesQty[index];
		}
		index++;
	}

	for (int i = 0; i < arraySize; i++)
	{
		if (salesQty[i] == highestNum)
			cout << setw(15) << left << "Top sales" << ":" << itemName[i] << " (" << salesQty[i] << ")" << endl;
	}
}
