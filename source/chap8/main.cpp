//Programmer: Mario D. Flores
//Calculates the final score for a contestants given five different scores1
//Monday, April 30, 2018

//pre-processor directives
#include<iostream>
#include<string>
#include<iomanip>

//Prototypes
std::string getOrdinalSuffix(int);
void getJudgeData(double&);
void calcScore(double, double, double, double, double);
double findLowest(double, double, double, double, double);
double findHighest(double, double, double, double, double);

//namespaces
using namespace std;

int main()
{
	double count_score;
	double score1, score2, score3, score4, score5;

	cout << "This program calculates the final score of a contestant based on 5 scores" << endl << endl;
	
	for (int i = 1; i <= 5; i++)
	{
		cout << endl;

		switch (i)
		{
		case 1:getJudgeData(score1);
			break;
		case 2:getJudgeData(score2);
			break;
		case 3:getJudgeData(score3);
			break;
		case 4:getJudgeData(score4);
			break;
		case 5:getJudgeData(score5);
			break;
		default:
			break;
		}
	}

	cout << endl << endl;
	calcScore(score1, score2, score3, score4, score5);
	
	//----------------------------------
	cout << endl << endl;
	system("pause");
	return 0;
}

//Takes the input of an integer number and returns the corresponding ordinal preffix
std::string getOrdinalSuffix(int numInput)
{
	string ret_val;

	switch (numInput%10)
	{
	case 1:ret_val = "st";
		break;
	case 2:ret_val = "nd";
		break;
	case 3:ret_val = "rd";
		break;
	default:ret_val = "th";
		break;
	}

	return ret_val;
}

//Takes 5 numeric input from user and returns value in argument
void getJudgeData(double& numScore)
{
	static int judgeNumber = 1;
	bool range_validation = false;

	do
	{
		if (range_validation)
			cout << "Input has to be within 0 and 10." << endl;

		cout << "Enter the " << judgeNumber << getOrdinalSuffix(judgeNumber) << " score: ";
		cin >> numScore;

		range_validation = numScore < 0 || numScore > 10;
	} while (range_validation);
	judgeNumber++;
}

//Calculates a average of three of five numbers; ignoring the greatest and lowest value.
void calcScore(double numScore1, double numScore2, double numScore3, double numScore4, double numScore5)
{
	double average_score = 0;
	double subLowest, subHighest;

	subLowest = findLowest(numScore1, numScore2, numScore3, numScore4, numScore5);
	subHighest = findHighest(numScore1, numScore2, numScore3, numScore4, numScore5);

	average_score = (numScore1+ numScore2+ numScore3+ numScore4+ numScore5- subLowest- subHighest) / 3;

	cout << setprecision(1) << fixed;
	cout << "The final score is: " << average_score;
}

//Returns the lowest of 5 numbers
double findLowest(double numScore1, double numScore2, double numScore3, double numScore4, double numScore5)
{
	double lowest_val;

	lowest_val = numScore1;

	if (lowest_val > numScore2)
		lowest_val = numScore2;

	if (lowest_val > numScore3)
		lowest_val = numScore3;

	if (lowest_val > numScore4)
		lowest_val = numScore4;

	if (lowest_val > numScore5)
		lowest_val = numScore5;

	return lowest_val;
}

//Returns the highest of 5 numbers
double findHighest(double numScore1, double numScore2, double numScore3, double numScore4, double numScore5)
{
	double highest_val;

	highest_val = numScore1;

	if (highest_val < numScore2)
		highest_val = numScore2;

	if (highest_val < numScore3)
		highest_val = numScore3;

	if (highest_val < numScore4)
		highest_val = numScore4;

	if (highest_val < numScore5)
		highest_val = numScore5;

	return highest_val;
}