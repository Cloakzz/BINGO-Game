#ifndef CARD_H
#define CARD_H
#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include <fstream>
using namespace std;

class Card
{
private:
	//Declaring Data Member
	int cardArray[5][5];

public:
	//Declaring Constructor and Destructor
	Card();
	~Card();

	//Declaring Setter and Getter
	void setCardArray(int row, int column, int value);
	int getCardArray(int row, int column);

	//Declaring Member Functions
	void createCard();
	void writeCard(int num);
};

#endif