#include "Machine.h"
using namespace std;

Machine::Machine()
{
	Name = "";
	Publisher = "";
	Type = "";
	Year = 0; // Initializes private variables to default.
}
Machine::Machine(const Machine& machine)
{
	Name = machine.Name;
	Publisher = machine.Publisher;
	Type = machine.Type;
	Year = machine.Year; // Copies person values into private variables.
	for (unsigned int i = 0; i < MachinesCopier.size(); i++)
	{
		MachinesCopier2[i] = MachinesCopier[i];
	}
}

Machine::~Machine()
{
}

vector<Machine> Machine::getVector() //Allows vector to be accessed in main.
{
	return MachinesCopier;
}
// The getters
string Machine::getName()
{
	return Name;
}
string Machine::getPublisher()
{
	return Publisher;
}
int Machine::getYear()
{
	return Year;
}
string Machine::getType()
{
	return Type;
}
// The setters
void Machine::setName(string name)
{
	Name = name;
}
void Machine::setPublisher(string publisher)
{
	Publisher = publisher;
}
void Machine::setYear(int year)
{
	Year = year;
}
void Machine::setType(string type)
{
	Type = type;
}

//Method to read in a file.
bool Machine::readFile()
{
	Machine data;
	cout << "Enter filename: ";
	string filename = "";
	cin >> filename; // Takes the name of the file to be read.

	ifstream din;
	din.open(filename.c_str());
	if (din.fail()) // Decides to continue commands only if the file can be opened.
	{
		cout << "Error: could not open file" << endl;
		return 1;
	}
	else
	{
		while (!din.eof()) // Repeats until the file is done.
		{
			getline(din, Name, ',');
			getline(din, Publisher, ','); // Gets all of the info from the file and stores it in the Machine object.
			din >> Year;
			getline(din, Type);
			data.setName(Name);
			data.setPublisher(Publisher);
			data.setYear(Year);
			data.setType(Type);
			MachinesCopier.push_back(data); // Adds the info of the Machine object to the end of the vector.
		}
	}
	return 0;
}

void Machine::printMachines() //Prints the information of all of the Machine objects stored in the vector.
{
	for (unsigned int i = 0; i < MachinesCopier.size(); i++)
	{
		cout << MachinesCopier[i].getName() << ',';
		cout << MachinesCopier[i].getPublisher() << ',';
		cout << MachinesCopier[i].getYear();
		cout << MachinesCopier[i].getType() << endl;
	}
}
void Machine::printoneMachine(int num) //Prints a chosen Machine object in the vector.
{
	cout << MachinesCopier[num].getName() << ',';
	cout << MachinesCopier[num].getPublisher() << ',';
	cout << MachinesCopier[num].getYear();
	cout << MachinesCopier[num].getType() << endl;
}

int Machine::searchName(string name, int low, int high)
{
	// (Some comments below taken from given recursive binary search code.)
	// Calculate midpoint index
	int mid = (low + high) / 2;
	string compareString = MachinesCopier[mid].getName(); //Putting the name at mid into a comparable string for convenience.
	// Check termination condition
	if (low > high)
	{
		cout << endl << "Count Number: " << j << endl;
		cout << "Input type = Invalid" << endl;
		j = 0;
		return -1;
	}

	// Check if value is found
	else if (compareString == name)
	{
		cout << endl << "Count Number: " << j << endl;
		cout << "Input type = Valid" << endl;
		j = 0;
		return mid;
	}

	// Search to the left
	else if (compareString > name)
	{
		j++;
		return searchName(name, low, mid - 1);
	}

	// Search to the right
	else
	{
		j++;
		return searchName(name, mid + 1, high);
	}
}

int Machine::searchYear(int year, int low, int high)
{
	// (Comments below taken from given iterative binary search code.)
	// Search array using divide and conquer approach
	int mid = MachinesCopier.size() / 2;
	while ((MachinesCopier[mid].getYear() != year) && (high >= low))
	{
		// Change min to search right half
		if (MachinesCopier[mid].getYear() < year)
		{
			j++;
			low = mid + 1;
		}

		// Change max to search left half
		else if (MachinesCopier[mid].getYear() > year)
		{
			j++;
			high = mid - 1;
		}

		// Update mid location
		mid = (low + high) / 2;
	}

	// Return results of search
	if (MachinesCopier[mid].getYear() == year)
	{
		while ((MachinesCopier[mid].getYear() == year)) 
		{
			mid = mid - 1;
			if (MachinesCopier[mid].getName() == MachinesCopier[0].getName()) //Finds the first Machine object in the vector to have the desired year and returns it.
			{
				cout << endl << "Count Number: " << j << endl;
				cout << "Input type = Valid" << endl;
				j = 0;
				return mid;
			}
			j++;
		}
		cout << endl << "Count Number: " << j << endl;
		cout << "Input type = Valid" << endl;
		j = 0;
		return(mid+1);
	}
	else
	{
		cout << endl << "Count Number: " << j << endl;
		cout << "Input type = Invalid" << endl;
		j = 0;
		return(-1);
	}
	return 0;
}
