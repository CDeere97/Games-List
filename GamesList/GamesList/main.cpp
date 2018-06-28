// Chris Deere 2018
// Games List

#include <iostream>
#include <conio.h>
#include <string>
#include <vector>

using namespace std;

int main()
{
	vector<string> games;
	vector<string>::const_iterator iter;

	bool quit = false; // quit application or not
	string game; // game to enter

	// allow the user to keep entering games until '#' is pressed
	cout << "Enter your games. Enter '*' when you're done." << endl << endl;
	while (game != "#")
	{
		cout << "Enter a game: ";
		cin >> game;
		games.push_back(game);
	}
	// remove the '#' from the vector
	games.pop_back();

	while (quit != true)
	{
		// games list
		cout << endl << "Your games:" << endl;
		for (iter = games.begin(); iter != games.end(); ++iter)
		{
			cout << *iter << endl;
		}

		cout << endl << "What would you like to do next?" << endl;
		cout << "1 - Add new games" << endl;
		cout << "2 - Delete games" << endl;
		cout << "3 - Clear list" << endl;
		cout << "4 - Quit" << endl;
		cout << "Enter number to make choice: ";

		int choice;
		cin >> choice;

		switch (choice)
		{
			case 1: // Add game
			{
				cout << endl << "Enter your games. Enter '#' when you're done." << endl << endl;
				string newGame;
				while (newGame != "#")
				{
					cout << "Enter a game: ";
					cin >> newGame;
					games.push_back(newGame);
				}
				// remove the '#' from the vector
				games.pop_back();
				break;
			}
			case 2: // Delete games
			{
				cout << endl << "Enter the name of game you want to delete. Enter '#' when you're done." << endl << endl;
				string delGame;
				while (delGame != "#")
				{
					bool found = false; // whether games found or not
					cout << "Enter game: ";
					cin >> delGame;
					if (delGame != "#")
					{
						// remove game that is entered
						for (unsigned int i = 0; i < games.size(); ++i)
						{
							if (games[i] == delGame) // delete game if found
							{
								games.erase((games.begin() + i));
								found = true;
							}
							if (found == false && i >= (games.size() - 1)) // inform user that game entered is not on list
							{
								cout << "item not in list" << endl;
							}
						}
					}
				}
				break;
			}
			case 3: // Clear list
			{
				games.clear();
				break;
			}
			case 4: // Quit game
			{
				quit = true;
				break;
			}
			default:
			{
				cout << endl << "Invalid choice" << endl << endl;
				break;
			}
		}
	}

	_getch();

	return 0;
}