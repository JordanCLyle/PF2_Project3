#include <iostream>
#include "Machine.h"
using namespace std;

int main()
{
	int selection;
	int i = 0;
	int typeofVector1 = 0;
	int typeofVector2 = 0;
	Machine Name; //Object for when recursive Name sort is chosen.
	Machine Year; //Object for when iterative Year sort is chosen.
	while (i == 0) // Loops the selection interface until the user is done.
	{
		cout << endl << "1) Find those with given Name." << endl;
		cout << "2) Find those with given Year." << endl;  // Gives selection of commands.
		cout << "3) Quit." << endl;
		cout << "Choose your selection number: ";
		cin >> selection;
		switch (selection) // Decides which method to call based on the command.
		{
		case 1:
		{
			if (typeofVector1 != 1) //If file for Name has not been read in yet.
			{
				if (Name.readFile() == 1) // Calls the method to read the text file into the vector.
				{
					return 0;
				}
				typeofVector1 = 1; //Tells that the Name file no longer needs to be read in.
			}
			string name;
			cout << "What is its name?: ";
			cin.ignore();
			getline(cin, name);  //Reads in name of machine.
			int low = 0;
			int high = (Name.getVector()).size();
			int index = Name.searchName(name, low, high); //Searches for a matching Name
			if (index != -1)
			{
				Name.printoneMachine(index); // Prints all of the information of the matching machine.
			}
			break;
		}
		case 2:
		{
			if (typeofVector2 != 2) //If file for Year has not been read in yet.
			{
				if (Year.readFile() == 1) // Calls the method to read the text file into the vector
				{
					return 0;
				}
				typeofVector2 = 2; // Tells that the Year file no longer needs to be read in.
			}
			int year;
			cout << "What year was it made?: ";
			cin >> year;
			int low = 0;
			int high = (Year.getVector()).size();
			int index = Year.searchYear(year, low, high); //Searches for the first matching Year
			if (index != -1)
			{
				Year.printoneMachine(index); // Prints all of the information of the matching machine.
			}
			break;
		}
		default:
		{
			i = 1; // Tells the interface loop to stop when the user decides to quit.
			break;
		}
		}
	}
	return 0;
}
