#ifndef APPLICATION_H
#define APPLICATION_H

//#include files
#include "Card.h"
#include "Player.h"
#include "Caller.h"
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <vector>
using namespace std;

//Declaring Functions
void runMenu();
int readDisplayMenu();

//Declaring Variables
vector<string> vPlayerNames;

#endif