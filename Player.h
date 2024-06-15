#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <string>
#include <ctime>
#include <vector>
using namespace std;

class Player
{
private:
	//Declaring Data Members
	string playerName;
	int playerCard[5][5];
	char markedCard[5][5];

public:
	//Declaring Constructors and Destructor
	Player();
	Player(string newName);
	Player(string newName, char mark);
	~Player();

	//Declaring Setters and Getters
	void setPlayerCard(int row, int col, int value);
	void setMarkedCard(int row, int col, char mark);
	int getPlayerCard(int row, int col);
	char getMarkedCard(int row, int col);

	//Declaring Member Functions
	void createPlayerCard();
	void checkPlayerGrid(int calledNumber, char mark);
	int checkBingo(char mark);
};

#endif