#include "Caller.h"

//Defining Constructor and Destructor
Caller::Caller()
{
	for (int i = 0; i < 1000; i++)
	{
		usedNumArray[i] = 0;
	}
}

Caller::~Caller()
{
	//Automatically called when program ends
}

//Defining Member Functions
int Caller::generateNumber()
{
	int generateNum;
	char prefix;
	
	do
	{
		generateNum = rand() % 75 + 1;
	} while (usedNumArray[generateNum - 1] == 1);
	prefix = checkForPrefix(generateNum);
	usedNumArray[generateNum - 1] = 1;
	vUsedNum.push_back(generateNum);

	return generateNum;
}

char Caller::checkForPrefix(int newNumber)
{
	int number = newNumber;
	if ((number >= 1) && (number <= 15))
	{
		return 'B';
	}
	else if ((number >= 16) && (number <= 30))
	{
		return 'I';
	}
	else if ((number >= 31) && (number <= 45))
	{
		return 'N';
	}
	else if ((number >= 46) && (number <= 60))
	{
		return 'G';
	}
	else if ((number >= 61) && (number <= 75))
	{
		return 'O';
	}
}

void Caller::displayCaller()
{
	//Display all the called numbers
	for (int i = 0; i < vUsedNum.size(); i++)
	{
		if (i % 10 == 0)
		{
			cout << "\n";
		}
		cout << vUsedNum[i] << "\t";
	}
}

void Caller::saveOrRestore()
{
	int valid = 0;
	char choice;
	ofstream file4;
	string temp;
	
	//Input Validation
	while (valid == 0)
	{
		cout << "Save to textfile (s) or Continue BINGO (b): ";
		cin >> choice;
		if ((choice == 's') || (choice == 'b'))
		{
			valid = 1;
		}
	}

	//If the user wants to save to textfile
	if (choice == 's')
	{
		file4.open("bingoCaller.txt", ios::app);

		//Checks if file exists
		if (file4.is_open())
		{
			for (int i = 0; i < vUsedNum.size(); i++)
			{
				if (i % 10 == 0)
				{
					cout << "\n";
				}
				file4 << vUsedNum[i] << "\t";
			}
		}
		else
		{
			cout << "File is not open.";
		}
		file4.close();
		cout << "\tThe Bingo Caller's value(s) have been saved to bingoCaller.txt\n\n";

		system("pause");
	}
}

int Caller::numberOfCalls()
{
	int number = vUsedNum.size();
	return number;
}

int Caller::saveRestoreOrBingo()
{
	int valid = 0;
	char choice;
	ofstream file4;
	string temp;

	//Input Validation
	while (valid == 0)
	{
		cout << "Save to textfile (s), Continue to call number (c), or BINGO (b): ";
		cin >> choice;
		if ((choice == 's') || (choice == 'c') || (choice == 'b'))
		{
			valid = 1;
		}
	}

	//If the user wants to save to textfile
	if (choice == 's')
	{
		file4.open("bingoCaller.txt", ios::app);

		//Checks if file exists
		if (file4.is_open())
		{
			for (int i = 0; i < vUsedNum.size(); i++)
			{
				if (i % 10 == 0)
				{
					cout << "\n";
				}
				file4 << vUsedNum[i] << "\t";
			}
		}
		else
		{
			cout << "File is not open.";
		}
		file4.close();
		cout << "\tThe Bingo Caller's value(s) have been saved to bingoCaller.txt\n\n";

		system("pause");
		return 0;
	}

	//If the user wants to continue
	else if (choice == 'c')
	{
		return 0;
	}

	//If the user wants to BINGO
	else if (choice == 'b')
	{
		return 1;
	}
}