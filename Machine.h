//-----------------------------------------------------------
// Purpose: Header file for the Table class.
//          This class is designed to store an array of Person
//          objects that describe a group of famous people.
//          The search methods locate and print information
//          about a specified subset of the famous people.
// Author:  Jordan Lyle
//-----------------------------------------------------------
#ifndef Machine_H
#define Machine_H
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

class Machine
{
public:
	// Constructor methods
	Machine();
	Machine(const Machine& machine);
	~Machine();

	// Input output methods
	void printMachines();
	void printoneMachine(int num);
	bool readFile();

	// Get and Set methods
	string getName();
	string getPublisher();
	string getType();
	int getYear();
	vector<Machine> getVector();

	void setName(string name);
	void setPublisher(string publisher);
	void setType(string type);
	void setYear(int year);


	// Searching methods
	int searchName(string name, int high, int mid);
	int searchYear(int year, int low, int high);

private:
	// Object attributes
	string Name;
	string Publisher;
	string Type;
	int Year;
	int count;
	int j = 0;
	vector<Machine> MachinesCopier;
	vector<Machine> MachinesCopier2;
};
#endif
