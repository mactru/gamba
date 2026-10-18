#include <iostream>

using namespace std;

/****************************************************************************
	Name: Malcolm Trude
	Purpose: small gambling game called high/low
****************************************************************************/


int main()
{
	const string GREEN		= "\033[32m";
	const string RED		= "\033[31m";
	const string RESET		= "\033[0m";
	const string SLOW_BLINK = "\033[5m";

	int bet, numb, selection, selection2;
	int chipCount = 50;

	srand((unsigned)time(0));

	// Title Screen
	cout << "********************************" << endl
		 << "*			       *" << endl
		 << "*" << GREEN << SLOW_BLINK << "         HIGH " 
		 << RESET << "/" 
		 << RED << SLOW_BLINK << " LOW           " << RESET << "*" << endl
		 << "*                              *" << endl
		 << "*	 A gamba game          *" << endl
		 << "*	 developed by          *" << endl
		 << "*	    Malcolm            *" << endl
		 << "*                              *" << endl
		 << "********************************" << endl << endl;
	cout << "Rules: Out of 100 guess if the random number will be 51 - 100"
		 << " (" << GREEN << "HIGH" << RESET << ")" 
		 << " or 1 - 50 (" << RED << "LOW" << RESET << ")" << endl << endl;
	cout << "You get " << chipCount << " chips to start." << endl;

	// Game loop
	while (true)
	{
		// Input
		cout << endl << "How much would you like to bet: ";
		cin  >> bet;

		// Processing
		// error checking for the bet
		if (bet > chipCount || bet <= 0)
		{
			cout << endl
				 << "Error: Bet must not be greater than how many chips you"
				 << " have or it cannot be zero or negative." << endl;
			return 1;
		}
		else
		{
			// random number between 1 - 100 is generated
			numb = rand() % 100 + 1;

			cout << endl << endl << "Will the number be High or Low?" << endl
				 << endl << "Type 1 for High or 2 for Low and press Enter: ";
			cin  >> selection;

			// error checking for the selection
			if (selection != 1 && selection != 2)
			{
				cout << endl
					 << "Error: Selection must be 1 or 2" << endl;
				return 2;
			}
		}

		// Score logic
		if (numb >= 51 && selection == 1)
		{
			chipCount = chipCount + bet;

			cout << endl << "Congratulations! The number was " << numb << "." << endl
				 << endl << "You now have " << chipCount << " chips." << endl;
		}
		else if (numb <= 50 && selection == 1)
		{
			chipCount = chipCount - bet;

			cout << endl << "You lost. The number was " << numb << "." << endl
				 << endl << "You now have " << chipCount << " chips." << endl;
		}
		else if (numb <= 51 && selection == 2)
		{
			chipCount = chipCount + bet;

			cout << endl << "Congratulations! The number was " << numb << "." << endl
				 << endl << "You now have " << chipCount << " chips." << endl;
		}
		else if (numb >= 51 && selection == 2)
		{
			chipCount = chipCount - bet;

			cout << endl << "You lost. The number was " << numb << "." << endl
				 << endl << "You now have " << chipCount << " chips." << endl;
		}

		// redo or quit
		if (chipCount <= 0)
		{
			break;
		}
		cout << endl << "1: Go again	2: Quit" << endl << endl
			 << "Selection: ";
		cin  >> selection2;
		if (selection2 == 2)
		{
			break;
		}
	}

	cout << endl << "Thank you for playing!" << endl << endl
		 << "Your final chips amount is " << chipCount << "." << endl << endl;
	
	system("pause");
}