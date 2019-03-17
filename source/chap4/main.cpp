//Mario D. Flores
//April, Monday 16, 2018
//This program calculates the occupancy rate of a hotel.

#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	int floors, last_floor;
	int rooms_per_floor, taken_per_floor;//counters
	int total_rooms = 0, rooms_taken = 0;//accumulators
	int thirteen_offset = 0;//this stores the offset for when the building has 13 or more floors
	double occupancy_percent;
	bool floor_validation = false, room_validation = false, tenant_validation = false;//flags for input validation

	const int UNLUCKY_FLOOR = 13;

	cout << "This program gives you the percentage of occupancy of a hotel" << endl << endl;

	do //error check for floor input
	{
		if (floor_validation)
			cout << "Input must be at least 1 or greater. Floors can't be negative." << endl;

		cout << "Please, enter the number of floors: ";
		cin >> floors; cout << endl;

		floor_validation = floors < 0;
	} while (floor_validation);

	//determining if 13 floor is present. If so set the offset to 1
	if (floors >= UNLUCKY_FLOOR)
		thirteen_offset = 1;

	//calculating the number of the last floor
	last_floor = floors + thirteen_offset;

	//loop for per-floor input
	for (int i = 1; i <= last_floor; i++)
	{
		//conditional check to skip the 13th floor if present
		if (i!= UNLUCKY_FLOOR)
		{
			do //error check for rooms input
			{
				if (room_validation)
					cout << "Rooms must be at least 10 or greater." << endl;;

				cout << "How many rooms for the " << i << ((i % 10 == 1) ? "st" : (i % 10 == 2 ? "nd" : (i % 10 == 3 ? "rd" : "th"))) << " floor: ";
				cin >> rooms_per_floor;

				room_validation = rooms_per_floor < 10;
			} while (room_validation);

			//updating accumulator for rooms
			total_rooms += rooms_per_floor;

			do //error check for occupancy input
			{
				if (tenant_validation)
					cout << "Occupancy must be within 0 and " << rooms_per_floor << "(inclusive)." << endl;

				cout << "How many of the rooms for the " << i << (i % 10 == 1 ? "st" : (i % 10 == 2 ? "nd" : (i % 10 == 3 ? "rd" : "th"))) << " floor are occupied: ";
				cin >> taken_per_floor;

				tenant_validation = taken_per_floor<0 || taken_per_floor>rooms_per_floor;
			} while (tenant_validation);

			//updating accumulator for occupancy
			rooms_taken += taken_per_floor;

			cout << endl; //Extra line to keep different floor input separated
		}
		//displaying a message that the thirteen floor was skipped
		else
			cout << "Thirteen floor was skipped because it makes people uncomfortable." << endl;
	}

	//calculating the percentage
	occupancy_percent = static_cast<double>(rooms_taken) / total_rooms * 100;

	//just a line to make things organized
	cout << endl << "------------------------------------------------------------------" << endl;

	//displaying all the final results for the given input, as well as setting up formatting
	cout << setw(32) << left << "Number of floors:" << floors << " floors" << endl;
	cout << setw(32) << left << "Total of rooms:" << total_rooms << endl;
	cout << setw(32) << left << "Total of rooms occupied:" << rooms_taken << endl;
	cout << setprecision(2) << fixed;
	cout << setw(32) << left << "Occupancy percentage:" << occupancy_percent << "%" << endl;

	//--------------------------------
	cout << endl << endl;
	system("pause");
	return 0;
}