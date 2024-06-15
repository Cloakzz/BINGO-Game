#ifndef CALLER_H
#define CALLER_H
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <fstream>
using namespace std;

class Caller
{
private:
	//Declaring Data Members
	vector<int> vUsedNum;
	int usedNumArray[1000];

public:
	//Declaring Constructor and Destructor
	Caller();
	~Caller();

	//Declaring Member Functions
	int generateNumber();
	char checkForPrefix(int newNumber);
	void displayCaller();
	void saveOrRestore();
	int numberOfCalls();
	int saveRestoreOrBingo();
};

#endif