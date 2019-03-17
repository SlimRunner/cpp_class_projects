//Mario D. Flores
//Arranges user's name input
//Monday, May 21, 2018

//Pre-processor directives
#include<iostream>

//Namespaces
using namespace std;

//Prototypes
void toProper(char[], int);
void arrange_LastThenFirst(const char[], const char[], const char[], char[], int);

int main()
{
	const int CHAR_SIZE = 25;
	const int CONCAT_SIZE = CHAR_SIZE * 3;

	char fullName[CONCAT_SIZE];
	char firstName[CHAR_SIZE] = "";
	char middleName[CHAR_SIZE] = "";
	char lastName[CHAR_SIZE] = "";
	char arrangedName[CONCAT_SIZE] = "";

	cout << "This program takes a full name as input, and rearranges it so that the last name goes first followed by the first and middle names.\n\n";

	cout << "Please enter full name: ";
	cin.getline(fullName, CONCAT_SIZE);

	//Stores the number spaces encountered in a C-String
	int countSpaces = 0;
	//Stores the location of the last space encountered in a C-String
	int lastSpacePos;

	//Segmentates the user input using space as delimeter onto three c-string arrays.
	for (int i = 0; i < CONCAT_SIZE - 1; i++)
	{
		if (fullName[i] != ' ' && fullName[i] != '\0') {
			switch (countSpaces)
			{
			case 0:
				firstName[i] = fullName[i];
				break;
			case 1:
				middleName[i % lastSpacePos] = fullName[i];
				break;
			case 2:
				lastName[i % lastSpacePos] = fullName[i];
				break;
			default:
				//SHORT CIRCUIT: discard anything beyond the the third word
				i = CONCAT_SIZE;
				break;
			}
		}
		else
		{
			(fullName[i] == '\0') ? countSpaces = 3 : countSpaces++;
			lastSpacePos = i + 1;
		}

	}

	arrange_LastThenFirst(firstName, middleName, lastName, arrangedName, CONCAT_SIZE);

	toProper(arrangedName, CONCAT_SIZE);

	cout << endl << "Your full name is: ";
	cout << arrangedName;

	//---------------------------
	cout << endl << endl;
	system("pause");
	return 0;
}


///<summary>Converts the first letter of every word within a C-String to capital.</summary>
///<param name="source">The C-String to be formatted with proper case.</param>
///<param name = "size">Array size of the source parameter.</param>
void toProper(char source[], int size)
{
	source[0] = toupper(source[0]);

	for (int i = 1; i < size; i++)
	{
		if (source[i - 1] == ' ')
			source[i] = toupper(source[i]);
		else
			source[i] = tolower(source[i]);
	}
}

///<summary>Arranges a full name to last, first, and middle.</summary>
///<param name="firstName">Null terminated c-string that contains the first name.</param>
///<param name="middleName">Null terminated c-string that contains the middle name.</param>
///<param name="lastName">Null terminated c-string that contains the last name.</param>
///<param name="fullName">C-String variable that will store the return of the funciton.</param>
///<param name="fullSize">Array size of the fullName parameter.</param>
///<returns>Returns a c-string containing arranged name.</returns>
void arrange_LastThenFirst(const char firstName[], const char middleName[], const char lastName[], char fullName[], int size)
{
	strcat_s(fullName, size, lastName);
	strcat_s(fullName, size, ", ");
	strcat_s(fullName, size, firstName);
	strcat_s(fullName, size, " ");
	strcat_s(fullName, size, middleName);
}