/*****************************************************************************
 * AUTHOR: Mikayla Weber
 * COURSE: CS 150 : C++ Programming 1
 * SECTION: online
 * IC (PROJECT)#: Final Exam
 * LAST MODIFIED: 5/21/25
 *****************************************************************************/
/*****************************************************************************
 * Computer Depot Inventory System
 *****************************************************************************
 * PROGRAM DESCRIPTION:
 * A menu-driven console application to manage an inventory of Computers
 * and Laptops. Demonstrates object-oriented programming with inheritance.
 * Runs on a single scrolling screen in the terminal.
 *****************************************************************************
 * ALGORITHM:
 * 1.  Initialize computer and laptop inventory arrays and counters.
 *     Define maximum inventory size.
 * 2.  Loop until user chooses to quit (option 3):
 * 		a.  Display the main menu options.
 * 		b.  Prompt user for their choice.
 * 		c.  Process the user's choice using a switch statement:
 * 			i.  Case 1 (Add Item): Prompts and logic for adding Computer or Laptop
 * 			ii. Case 2 (Display Inventory): Prints inventory header and items
 * 			iii.Case 3 (Quit): Sets flag to exit loop.
 * 			iv. Default (Invalid choice): Displays error message.
 * d.  Uses pauseExecution() to allow user to read messages before continuing.
 * 3.  Return EXIT_SUCCESS.
 *****************************************************************************
 * ALL IMPORTED LIBRARIES NEEDED AND PURPOSE:
 * <iostream>   - For console input/output operations (cin, cout).
 * <cstdlib>    - For EXIT_SUCCESS and system(). (system() not used for screen clear anymore)
 * <string>     - For using the string data type.
 * <iomanip>    - For output formatting (setw, setprecision, fixed, left, right).
 * <limits>     - For std::numeric_limits (used to clear input buffer).
 * "Computer.h" - Definition of the Computer class.
 * "Laptop.h"   - Definition of the Laptop class.
 *****************************************************************************/

#include <iostream>
#include <cstdlib> // For EXIT_SUCCESS
#include <string>
#include <iomanip>
#include <limits> // Required for std::numeric_limits

#include "Computer.h"
#include "Laptop.h"

using namespace std;

const int MAX_ITEMS = 50; // Maximum number of computers or laptops

// Function to pause execution
void pauseExecution()
{
	cout << "\nPress Enter to continue...";
	if (cin.peek() == '\n')
	{ // If the next char is newline, consume it
		cin.ignore();
	}
	cin.get();	  // Waits for the user to press Enter
	cout << endl; // Add a newline after pause for better separation
}

void displayMenu()
{
	cout
		<< "\n*************************************************************************\n"
		<< "** Welcome to the Computer Depot                       **\n"
		<< "*************************************************************************\n"
		<< "** Please enter choice :                                               **\n"
		<< "** 1) Add computer to inventory                                        **\n"
		<< "** 2) Display entire inventory                                         **\n"
		<< "** 3) Quit                                                             **\n"
		<< "*************************************************************************\n";
	cout << ">> ";
}

void clearInputBuffer()
{
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main(int argc, char *argv[])
{ // huhhh
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
			cout << "\n** Invalid choice. Please try again. **\n";
			cin.clear(); // Clear error flags
			clearInputBuffer();
			pauseExecution();
			continue;
		}
		clearInputBuffer(); // Clear newline after reading choice



		switch (choice)
		{
		case 1:
		{ // Add item
			cout << "\n--- Add Item to Inventory ---\n";
			int itemType;
			cout << "Enter 1 for Computer or 2 for Laptop >> ";
			cin >> itemType;

			if (cin.fail() || (itemType != 1 && itemType != 2))
			{
				cout << "\n** Invalid item type. Returning to main menu. **\n";
				cin.clear();
				clearInputBuffer();
				pauseExecution();
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
				cout << "\n** Invalid price input. Returning to main menu. **\n";
				cin.clear();
				clearInputBuffer();
				pauseExecution();
				break;
			}
			clearInputBuffer();

			if (itemType == 1)
			{ // Computer
				if (numComputers < MAX_ITEMS)
				{
					computers[numComputers++] = Computer(make, model, price);
					cout << "\n** Computer added to inventory. **\n";
				}
				else
				{
					cout << "\n** Computer inventory is full. **\n";
				}
			}
			else
			{ // Laptop
				double batteryLife, weight;
				cout << "Enter battery life (hrs) >> ";
				cin >> batteryLife;
				if (cin.fail())
				{
					cout << "\n** Invalid battery life input. Returning to main menu. **\n";
					cin.clear();
					clearInputBuffer();
					pauseExecution();
					break;
				}
				clearInputBuffer();

				cout << "Enter weight (lbs)       >> ";
				cin >> weight;
				if (cin.fail())
				{
					cout << "\n** Invalid weight input. Returning to main menu. **\n";
					cin.clear();
					clearInputBuffer();
					pauseExecution();
					break;
				}
				clearInputBuffer();

				if (numLaptops < MAX_ITEMS)
				{
					laptops[numLaptops++] = Laptop(make, model, price, batteryLife, weight);
					cout << "\n** Laptop added to inventory. **\n";
				}
				else
				{
					cout << "\n** Laptop inventory is full. **\n";
				}
			}
			pauseExecution();
			break;
		}
		case 2:
		{ // Display inventory
			cout << "\n--- Entire Inventory ---\n";
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
			// clearScreen(); // REMOVED
			break;
		}
		case 3:
		{ // Quit
			cout << "\n** Thank you for using Computer Depot! Exiting... **\n\n";
			running = false;
			break;
		}
		default: // Back up
			cout << "\n** Internal error: Invalid choice processed in switch. **\n";
			pauseExecution();

			break;
		}
	}

	return EXIT_SUCCESS;
}