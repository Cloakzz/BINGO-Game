#include "Application.h"

int main()
{
	srand(unsigned(time(NULL)));
	runMenu();
	return 0;
}

int readDisplayMenu()
{
	ifstream file1;
	string temp;
	int input = 0;
	int option = 0;

	while (input == 0)
	{
		//Reading Display Menu
		file1.open("displayMenu.txt");

		//Checks if file exists
		if (file1.is_open())
		{
			while (!file1.eof())
			{
				getline(file1, temp);
				cout << temp << endl;
			}
		}
		else
		{
			cout << "File is not open.";
		}
		file1.close();

		//Asking For Input
		cout << "Which option would you like (1-7): ";
		cin >> option;

		//Input Validation
		if ((option == 1) || (option == 2) || (option == 3) || (option == 4) || (option == 5) || (option == 6) || (option == 7))
		{
			input = 1;
		}
		else
		{
			cout << "Invalid option, please enter a valid input." << endl;
			cout << "\n";
			system("pause");
			system("CLS");
		}
	}
	return option;
}

void runMenu()
{
	int end = 0;
	int option = 0;
	
	//Calling Display Menu
	while (end == 0)
	{
		option = readDisplayMenu();

		//CHOOSING OPTION 1
		if (option == 1)
		{
			cout << "\nThank you for using this application." << endl;
			end = 1;
		}

		//CHOOSING OPTION 2
		else if (option == 2)
		{
			system("CLS");

			ifstream file2;
			string temp;

			//Function
			file2.open("gameRules.txt");

			//Checks if file exists
			if (file2.is_open())
			{
				while (!file2.eof())
				{
					getline(file2, temp);
					cout << temp << endl;
				}
			}
			else
			{
				cout << "File is not open.";
			}
			file2.close();
			cout << "\n";

			system("pause");
			system("CLS");
		}

		//CHOOSING OPTION 3
		else if (option == 3)
		{
			system("CLS");
			
			int valid = 0;
			int amount;
			string name;

			//Check for how many cards to generate
			while (valid == 0)
			{
				cout << "How many cards do you want to generate: ";
				cin >> amount;
				if (amount == 0)
				{
					cout << "Input is not valid.\n\n";
					system("pause");
					system("CLS");
				}
				else
				{
					valid = 1;
				}
			}

			//Function
			for (int generate = 1; generate < amount + 1; generate++)
			{
				name = "Card" + generate;
				Card name;
				name.createCard();
				name.writeCard(generate);

				//Displaying the cards
				cout << "Card " << generate << "\n";
				cout << "B\tI\tN\tG\tO" << "\n";
				for (int row = 0; row < 5; row++)
				{
					for (int col = 0; col < 5; col++)
					{
						cout << name.getCardArray(row, col) << "\t";
					}
					cout << "\n";
				}
				cout << "\n";
			}
			cout << "\tThese " << amount << " card(s) are now saved into CardsGenerated.txt files\n\n";

			system("pause");
			system("CLS");
		}

		//CHOOSING OPTION 4
		else if (option == 4)
		{
			system("CLS");

			int valid = 0;
			int amount;
			string name;
			string playerName;
			int playerNum;

			//Check for how many players to generate
			while (valid == 0)
			{
				cout << "How many players do you want to generate: ";
				cin >> amount;
				if (amount == 0)
				{
					cout << "Input is not valid.\n\n";
					system("pause");
					system("CLS");
				}
				else
				{
					valid = 1;
				}
			}

			//Asking player(s)' name
			if (amount == 1)
			{
				cout << "Please enter name for player 1: ";
				cin.ignore();
				getline(cin, playerName);
				vPlayerNames.push_back(playerName);
			}
			else
			{
				cout << "Please enter name for player 1: ";
				cin.ignore();
				getline(cin, playerName);
				vPlayerNames.push_back(playerName);
				for (int num = 1; num < amount; num++)
				{
					playerNum = num + 1;
					cout << "Please enter name for player " << playerNum << ": ";
					cin.ignore(-1);
					getline(cin, playerName);
					vPlayerNames.push_back(playerName);
				}
			}

			system("CLS");

			for (int generate = 1; generate < amount + 1; generate++)
			{
				//Creating player cards
				name = "Player" + generate;
				Player name;
				name.createPlayerCard();

				//Displaying player cards
				cout << "Player " << generate << ": " << vPlayerNames[generate - 1] << "\n";
				cout << "B\tI\tN\tG\tO" << "\n";
				for (int row = 0; row < 5; row++)
				{
					for (int col = 0; col < 5; col++)
					{
						cout << name.getPlayerCard(row, col) << "\t";
					}
					cout << "\n";
				}
				cout << "\n";
			}

			system("pause");
			system("CLS");
		}
			

		//CHOOSING OPTION 5
		else if (option == 5)
		{	
			system("CLS");

			int win = 0;
			int valid = 0;
			char prefix;
			int calledNum;
			ifstream file5;
			string bingoArt, winner;

			//Check if vector is empty
			if (vPlayerNames.empty())
			{
				cout << "Please generate players first (Choose option 4)\n\n";
			}

			//Bingo Caller
			else
			{
				Caller bingo;

				while (valid == 0)
				{
					cout << "The called number is ...\n\n";
					system("pause");

					//Generate number and showing the called number
					calledNum = bingo.generateNumber();
					prefix = bingo.checkForPrefix(calledNum);
					cout << "\n\t" << prefix << calledNum << "\n\n";
					system("pause");

					//Showing all the called numbers and save or restore
					cout << "\nThese numbers have been called:\n";
					bingo.displayCaller();
					cout << "\n\n";
					valid = bingo.saveRestoreOrBingo();

					system("CLS");
				}

				//Ask which player won
				cout << "Who won? ";
				cin.ignore();
				getline(cin, winner);

				file5.open("bingoWinner.txt");
				while (!file5.eof())
				{
					getline(file5, bingoArt);
					cout << bingoArt << endl;
				}

				cout << "\nCONGRATULATIONS, " << winner << ". It took you " << bingo.numberOfCalls() << " turns to win." << endl;
				cout << "Please generate players after closing this tab.\n\n";
			}

			vPlayerNames.clear();

			system("pause");
			system("CLS");
		}

		//CHOOSING OPTION 6 (THE GAME)
		else if (option == 6)
		{
			system("CLS");

			int valid = 0;
			int validMark = 0;
			int win = 0;
			int amount, calledNum, win1, win2;
			string name1, name2, bingoArt, winner, loser;
			char prefix, playerMark1, playerMark2;
			ifstream file5;

			//Function
			while (valid == 0)
			{
				cout << "Please enter the number of players to generate (MAX: 2): ";
				cin >> amount;
				if ((amount == 1) || (amount == 2))
				{
					valid = 1;
				}
				else
				{
					cout << "Input is not valid.\n\n";
					system("pause");
					system("CLS");
				}
			}
			if (amount == 1)
			{
				//Asking for name and instantiation
				cout << "Please enter the name for player 1: ";
				cin.ignore();
				getline(cin, name1);
				cout << "\n";

				//Choosing mark
				while (validMark == 0)
				{
					cout << "Please choose a mark for your grid (X/O): ";
					cin >> playerMark1;
					if ((playerMark1 == 'X') || (playerMark1 == 'O'))
					{
						validMark = 1;
					}
					else
					{
						cout << "Sorry, choose a valid mark.\n\n";
						system("pause");
						system("CLS");
					}
				}

				Player player1(name1, playerMark1);
				player1.createPlayerCard();

				system("CLS");

				//Displaying Player 1 Card
				cout << "Player 1" << "\n\n";
				cout << "Player name: " << name1 << "\n";
				cout << "Card is:" << "\n\n";
				cout << "B\tI\tN\tG\tO" << "\n";
				for (int row = 0; row < 5; row++)
				{
					for (int col = 0; col < 5; col++)
					{
						cout << player1.getPlayerCard(row, col) << "\t";
					}
					cout << "\n";
				}
				cout << "\n";

				system("pause");
				system("CLS");

				//Bingo 1 Player
				Caller bingo;

				while (win == 0)
				{
					cout << "The called number is ...\n\n";
					system("pause");
					
					//Generate number and showing the called number
					calledNum = bingo.generateNumber();
					prefix = bingo.checkForPrefix(calledNum);
					cout << "\n\t" << prefix << calledNum << "\n\n";
					system("pause");

					//Check for bingo
					cout << "\n";
					player1.checkPlayerGrid(calledNum, playerMark1);
					win = player1.checkBingo(playerMark1);

					//Showing all the called numbers and save or restore
					cout << "\nThese numbers have been called:\n";
					bingo.displayCaller();
					cout << "\n\n";
					bingo.saveOrRestore();

					system("CLS");
				}

				file5.open("bingoWinner.txt");
				while (!file5.eof())
				{
					getline(file5, bingoArt);
					cout << bingoArt << endl;
				}

				cout << "\nCONGRATULATIONS, " << name1 << ". It took you " << bingo.numberOfCalls() << " turns to win.\n\n";

				system("pause");
				system("CLS");
			}
			else
			{
				//Asking for names and instantiations
				cout << "Please enter the name for player 1: ";
				cin.ignore();
				getline(cin, name1);
				cout << "Please enter the name for player 2: ";
				cin.ignore(-1);
				getline(cin, name2);
				cout << "\n";

				//Choosing mark
				while (validMark == 0)
				{
					cout << "Please choose a mark for " << name1 << "'s grid (X/O) : ";
					cin >> playerMark1;
					if ((playerMark1 == 'X') || (playerMark1 == 'O'))
					{
						validMark = 1;
					}
					else
					{
						cout << "Sorry, choose a valid mark.\n\n";
						system("pause");
						system("CLS");
					}
				}
				if (playerMark1 == 'X')
				{
					playerMark2 = 'O';
				}
				else
				{
					playerMark2 = 'X';
				}

				//Telling which player has which mark
				cout << name1 << " will have the mark, " << playerMark1 << ", and " << name2 << " will have the mark, " << playerMark2 << "\n\n";
				system("pause");
				system("CLS");

				Player player1(name1, playerMark1);
				Player player2(name2, playerMark2);
				player1.createPlayerCard();
				player2.createPlayerCard();

				system("CLS");

				//Displaying Player 1 Card
				cout << "Player 1" << "\n\n";
				cout << "Player name: " << name1 << "\n";
				cout << "Card is:" << "\n\n";
				cout << "B\tI\tN\tG\tO" << "\n";
				for (int row = 0; row < 5; row++)
				{
					for (int col = 0; col < 5; col++)
					{
						cout << player1.getPlayerCard(row, col) << "\t";
					}
					cout << "\n";
				}
				cout << "\n";

				//Displaying Player 2 Card
				cout << "Player 2" << "\n\n";
				cout << "Player name: " << name2 << "\n";
				cout << "Card is:" << "\n\n";
				cout << "B\tI\tN\tG\tO" << "\n";
				for (int row = 0; row < 5; row++)
				{
					for (int col = 0; col < 5; col++)
					{
						cout << player2.getPlayerCard(row, col) << "\t";
					}
					cout << "\n";
				}
				cout << "\n\n";

				system("pause");
				system("CLS");

				//Bingo 2 Players
				Caller bingo;

				while (win == 0)
				{
					cout << "The called number is ...\n\n";
					system("pause");

					//Generate number and showing the called number
					calledNum = bingo.generateNumber();
					prefix = bingo.checkForPrefix(calledNum);
					cout << "\n\t" << prefix << calledNum << "\n\n";
					system("pause");

					//Check for bingo
					cout << "\n";
					player1.checkPlayerGrid(calledNum, playerMark1);
					win1 = player1.checkBingo(playerMark1);

					cout << "\n";
					player2.checkPlayerGrid(calledNum, playerMark2);
					win2 = player2.checkBingo(playerMark2);

					if ((win1 == 1) || (win1 == 2))
					{
						win = win1;
					}
					else if ((win2 == 1) || (win2 == 2))
					{
						win = win2;
					}

					//Showing all the called numbers and save or restore
					cout << "\nThese numbers have been called:\n";
					bingo.displayCaller();
					cout << "\n\n";
					bingo.saveOrRestore();

					system("CLS");
				}

				//Determining the winner and loser
				if ((playerMark1 == 'X') && (win == 1))
				{
					winner = name1;
					loser = name2;
				}
				else if ((playerMark1 == 'O') && (win == 2))
				{
					winner = name1;
					loser = name2;
				}
				else if ((playerMark2 == 'X') && (win == 1))
				{
					winner = name2;
					loser = name1;
				}
				else if ((playerMark2 == 'O') && (win == 2))
				{
					winner = name2;
					loser = name1;
				}

				file5.open("bingoWinner.txt");

				//Checks if file exists
				if (file5.is_open())
				{
					while (!file5.eof())
					{
						getline(file5, bingoArt);
						cout << bingoArt << endl;
					}
				}
				else
				{
					cout << "File is not open.";
				}

				cout << "\nCONGRATULATIONS, " << winner << ". It took you " << bingo.numberOfCalls() << " turns to win." << endl;
				cout << "Better luck next time, " << loser << ".\n\n";

				system("pause");
				system("CLS");
			}
		}

		//CHOOSING OPTION 7
		else if (option == 7)
		{
			system("CLS");

			ifstream file6;
			string temp;

			//Function
			file6.open("ReflectionReport.txt");

			//Checks if file exists
			if (file6.is_open())
			{
				while (!file6.eof())
				{
					getline(file6, temp);
					cout << temp << endl;
				}
			}
			else
			{
				cout << "File is not open.";
			}
			file6.close();
			cout << "\n";

			system("pause");
			system("CLS");
		}	
	}
}