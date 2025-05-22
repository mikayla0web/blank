/*****************************************************************************
 * AUTHOR: Mikayla Weber
 * COURSE: CS 150 : C++ Programming 1
 * SECTION: online
 * IC (PROJECT)#: Final Exam
 * LAST MODIFIED: 5/21/25
 *****************************************************************************/
/*****************************************************************************
 * Updated Computer Class
 *****************************************************************************
 * PROGRAM DESCRIPTION:
 * Defines the Computer class, serving as a base class for computer devices.
 * It stores information like ID, make, model, and price.
 *****************************************************************************
 * ALGORITHM:
 * 1. Declare member variables: m_id, m_make, m_model, m_price.
 * 2. Declare static member variable s_nextId for unique ID generation.
 * 3. Declare constructors (default and parameterized).
 * 4. Declare accessor methods for all member variables.
 * 5. Declare mutator methods for make, model, and price.
 * 6. Declare overloaded equality operator.
 * 7. Declare overloaded stream insertion operator as a friend function.
 *****************************************************************************
 * ALL IMPORTED LIBRARIES NEEDED AND PURPOSE:
 * <iostream>   - For input/output
 * <cstdlib>    - For EXIT_SUCCESS and system().
 * <string>     - For using the string data type.
 * <iomanip>    - For output formatting (setw, setprecision, fixed, left, right).
 * <limits>     - For std::numeric_limits (used to clear input buffer).
 * "Computer.h" - Definition of the Computer class.
 * "Laptop.h"   - Definition of the Laptop class.
 *****************************************************************************/

#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <limits> // Required for std::numeric_limits

#include "Computer.h"
#include "Laptop.h"

using namespace std;

const int MAX_ITEMS = 50;

void clearScreen()
{
#ifdef _WIN32 // Check if the system is Windows
	system("CLS");
#else
	system("clear");
#endif
}

// Function to pause execution (cross-platform alternative to system("PAUSE"))
void pauseExecution()
{
	cout << "Press Enter to continue...";
	cin.get(); // Waits for the user to press Enter
}

void displayMenu()
{
	cout
		<< "*************************************************************************\n"
		<< "**                 Welcome to the Computer Depot                       **\n"
		<< "*************************************************************************\n"
		<< "** Please enter choice :                                               **\n"
		<< "** 1) Add computer to inventory                                        **\n"
		<< "** 2) Display entire inventory                                         **\n"
		<< "** 3) Quit                                                             **\n"
		<< "*************************************************************************\n";
}

void clearInputBuffer()
{
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main(int argc, char *argv[])
{
	Computer computers[MAX_ITEMS];
	Laptop laptops[MAX_ITEMS];
	int numComputers = 0;
	int numLaptops = 0;
	int choice;
	bool running = true;

	while (running)
	{
		displayMenu();
		cin >> choice;

		if (cin.fail() || choice < 1 || choice > 3)
		{
			cout << "** Invalid choice. Please try again. **\n";
			cin.clear(); // Clear error flags
			clearInputBuffer();
			system("PAUSE");
			system("CLS");
			continue;
		}
		clearInputBuffer(); // Clear newline after reading choice

		clearScreen();

		switch (choice)
		{
		case 1:
		{ // Add item
			int itemType;
			cout << "Enter 1 for Computer or 2 for Laptop >> ";
			cin >> itemType;

			if (cin.fail() || (itemType != 1 && itemType != 2))
			{
				cout << "** Invalid item type. Returning to main menu. **\n";
				cin.clear();
				clearInputBuffer();
				pauseExecution();
				clearScreen();
				break;
			}
			clearInputBuffer(); // Clear newline

			string make, model;
			double price;

			cout << "Enter make               >> ";
			getline(cin, make);
			cout << "Enter model              >> ";
			getline(cin, model);
			cout << "Enter price              >> $";
			cin >> price;
			if (cin.fail())
			{
				cout << "** Invalid price input. Returning to main menu. **\n";
				cin.clear();
				clearInputBuffer();
				pauseExecution();
				clearScreen();
				break;
			}
			clearInputBuffer();

			if (itemType == 1)
			{ // Computer
				if (numComputers < MAX_ITEMS)
				{
					computers[numComputers++] = Computer(make, model, price);
					cout << "** Computer added to inventory. **\n";
				}
				else
				{
					cout << "** Computer inventory is full. **\n";
				}
			}
			else
			{ // Laptop
				double batteryLife, weight;
				cout << "Enter battery life (hrs) >> ";
				cin >> batteryLife;
				if (cin.fail())
				{
					cout << "** Invalid battery life input. Returning to main menu. **\n";
					cin.clear();
					clearInputBuffer();
					pauseExecution();
					clearScreen();
					break;
				}
				clearInputBuffer();

				cout << "Enter weight (lbs)       >> ";
				cin >> weight;
				if (cin.fail())
				{
					cout << "** Invalid weight input. Returning to main menu. **\n";
					cin.clear();
					clearInputBuffer();
					pauseExecution();
					clearScreen();
					break;
				}
				clearInputBuffer();

				if (numLaptops < MAX_ITEMS)
				{
					laptops[numLaptops++] = Laptop(make, model, price, batteryLife, weight);
					cout << "** Laptop added to inventory. **\n";
				}
				else
				{
					cout << "** Laptop inventory is full. **\n";
				}
			}
			pauseExecution();
			clearScreen();
			break;
		}
		case 2:
		{ // Display inventory
			cout
				<< "*****************************************************************************************\n"
				<< "** Entire Inventory                                   **\n"
				<< "*****************************************************************************************\n"
				<< "| Id # | Make    | Model           | Price    | Battery (hrs)   | Weight (lbs)    |\n"
				<< "*****************************************************************************************\n";

			cout << fixed << setprecision(2);

			for (int i = 0; i < numComputers; ++i)
			{
				cout << computers[i] << "                 |                 |" << endl;
			}
			for (int i = 0; i < numLaptops; ++i)
			{
				cout << laptops[i] << endl;
			}
			if (numComputers == 0 && numLaptops == 0)
			{
				cout << "|                        No items in inventory currently.                         |\n";
			}
			cout << "*****************************************************************************************\n";
			pauseExecution();
			clearScreen();
			break;
		}
		case 3:
		{ // Quit
			cout << "** Thank you for using Computer Depot! Exiting... **\n";
			running = false;
			break;
		}
		default:
			cout << "** Should not happen. Invalid choice: " << choice << " **\n";
			pauseExecution();
			clearScreen();
			break;
		}
	}
	return EXIT_SUCCESS;
}