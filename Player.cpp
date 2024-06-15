#include "Player.h"

//Defining Constructor and Destructor
Player::Player()
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			playerCard[i][j] = 0;
		}
	}
}

Player::Player(string newName)
{
	playerName = newName;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			playerCard[i][j] = 0;
		}
	}
}

Player::Player(string newName, char mark)
{
	playerName = newName;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			playerCard[i][j] = 0;
			markedCard[i][j] = '~';
		}
	}
	markedCard[2][2] = mark;
}

Player::~Player()
{
	//Automatically called when program ends
}

//Defining Setters
void Player::setPlayerCard(int row, int column, int value)
{
	playerCard[row][column] = value;
}

void Player::setMarkedCard(int row, int col, char mark)
{
	markedCard[row][col] = mark;
}

//Defining Getters
int Player::getPlayerCard(int row, int column)
{
	return playerCard[row][column];
}

char Player::getMarkedCard(int row, int col)
{
	return markedCard[row][col];
}

//Defining Member Functions
void Player::createPlayerCard()
{
	int base = 15;
	int add = 1;
	int randomNum;
	int usedNumArray[1000];

	//Initializing Array
	for (int a = 0; a < 1000; a++)
	{
		usedNumArray[a] = 0;
	}

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			//Making sure no repeating numbers and assigning number to card
			do
			{
				randomNum = rand() % base + add;
			} while (usedNumArray[randomNum - 1] == 1);
			playerCard[j][i] = randomNum;
			usedNumArray[randomNum - 1] = 1;
		}
		add = add + 15;
	}
	//Assigning middle value to "Free"
	playerCard[2][2] = 0;
}

void Player::checkPlayerGrid(int calledNumber, char mark)
{
	//Check if player's grid has the called number
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (playerCard[i][j] == calledNumber)
			{
				markedCard[i][j] = mark;
			}
		}
	}

	//Output the player's grid and the marked grid side by side
	cout << "Player Name: " << playerName << endl;
	cout << "B\tI\tN\tG\tO\t\tHere are the marks in your card:\n";
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << playerCard[i][j] << "\t";
		}

		cout << "\t";

		for (int j = 0; j < 5; j++)
		{
			cout << markedCard[i][j] << "\t";
		}
		cout << "\n";
	}
}

int Player::checkBingo(char mark)
{
	int win;
	if (mark == 'X')
	{
		win = 1;
	}
	else if (mark == 'O')
	{
		win = 2;
	}
	
	for (int i = 0; i < 5; i++)
	{
		//Check row
		if ((markedCard[i][0] == mark) && (markedCard[i][1] == mark) && (markedCard[i][2] == mark) && (markedCard[i][3] == mark) && (markedCard[i][4] == mark))
		{
			return win;
		}

		//Check column
		if ((markedCard[0][i] == mark) && (markedCard[1][i] == mark) && (markedCard[2][i] == mark) && (markedCard[3][i] == mark) && (markedCard[4][i] == mark))
		{
			return win;
		}
	}

	//Check diagonal
	if ((markedCard[0][0] == mark) && (markedCard[1][1] == mark) && (markedCard[2][2] == mark) && (markedCard[3][3] == mark) && (markedCard[4][4] == mark))
	{
		return win;
	}

	if ((markedCard[0][4] == mark) && (markedCard[1][3] == mark) && (markedCard[2][2] == mark) && (markedCard[3][1] == mark) && (markedCard[4][0] == mark))
	{
		return win;
	}

	//If no bingo found
	return 0;
}