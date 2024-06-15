#include "Card.h"

//Defining Constructor and Destructor
Card::Card()
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cardArray[i][j] = 0;
		}
	}
}

Card::~Card()
{
	//Automatically called when program ends
}

//Defining Setter
void Card::setCardArray(int row, int column, int value)
{
	cardArray[row][column] = value;
}

//Defining Getter
int Card::getCardArray(int row, int column)
{
	return cardArray[row][column];
}

//Defining Member Functions
void Card::createCard()
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
			cardArray[j][i] = randomNum;
			usedNumArray[randomNum - 1] = 1;
		}
		add = add + 15;
	}

	//Assigning middle value to "Free"
	cardArray[2][2] = 0;
}

void Card::writeCard(int num)
{
	ofstream file3;
	string temp;
	file3.open("CardsGenerated.txt", ios::app);

	//Checks if file exists
	if (file3.is_open())
	{
		file3 << "Card " << num << endl;
		for (int row = 0; row < 5; row++)
		{
			for (int col = 0; col < 5; col++)
			{
				file3 << cardArray[row][col] << "\t";
			}
			file3 << endl;
		}
		file3 << endl;
	}
	else
	{
		cout << "File is not open.";
	}
	file3.close();
}