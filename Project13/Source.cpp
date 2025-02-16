#include "Header.h"     //linking of library name as header.h
using namespace MenuDriver;  //menudriver function is accessed that is in header file.
using namespace GamePlayFuncs;  //GamePlayFuncs function is accessed that is in header file.
int main()
{
	int Size, timer{}, hurdles, numberTypes, Matches;    //size is used for to create the table of size 10. timer is used to set the time. hurdles is used create hurdles. Numbertypes is used to decide that which numbers to be appeared in the table. Matches is used to make the match of numbers.
	bool exit = false;      
	int GameDuration;    
	bool GameOver;          //Gameover is used to use whether the game is overed or not.
	string Name;           //used to enter the name of user
	GameLogo(); // display game logo
	while (!exit)  // Loop until user quits
	{

		switch (Selected)
		{
		case 0:  // If case 0 is selected
			CreateMainMenu(); //Main menu appears
			break;
			// GamePlay
		case 1:  // If case 1 is selected
			DisplayChooseDifficulty(); // Ask the level of difficulty from user
			cout << "Enter Your Name : " << endl; 
			cin >> Name; // Input name from user
			PointingRow = 0; PointingColumn = 0; // Set Default value
			GameOver = false; // Default value
			if (Option == 1) // if easy level is selected by choosing 1.
			{
				Size = 10; timer = 60; hurdles = 0, numberTypes = 5;
			}
			else if (Option == 2)  // if very hard level is selected by choosing 2.
			{
				Size = 10; timer = 40; hurdles = 10, numberTypes = 8;
			}
			Moves = 15; // Reset moves
			Score = 0; // Reset score
			populateBoard(Size, numberTypes, hurdles); // Create random numbers
			GameDuration = clock() / 1000; // Check when game is started
			t = clock() / 1000 - GameDuration; // Set timer for the game

			while (!GameOver) // Loop until game ends
			{
				if (SwapAvailable(Size) == false) // If no match is possible then shuffle
				populateBoard(Size, numberTypes, hurdles);
				drawBoard(Size); // Create table of size 10 as it is initially set.
				numberMover(PointingRow, PointingColumn, Size, numberTypes); // allow user to move 
				Destroynumber(Size, numberTypes); // Destroy matched numbers
				if (t >= timer) // if time is over game over
					GameOver = true;
				t = clock() / 1000 - GameDuration; // Update time
				if (Moves <= 0) // if out of moves game over
					GameOver = true;  //if gameover is true than end
			}
			SaveScore(Name); // Save score with the name of the user 
			if (t >= timer) // if game over due to time
				cout << "=====> TIMES UP <=====" << endl;                 //the specific time of that game ends
			else // if game over due to moves
				cout << "=====> Out Of Moves <=====" << endl;            // display out of moves
			cout << setw(80) << "Score  : " << Score << endl << endl;    //display the score
			system("pause");
			ReturnToMainMenu();
			break;
		case 2:  // If Selected is 2
			exit = Exit(); // Confirm if user wants to exit
			if (exit) // if user want to exit
			{
				cout << "/Closing Files........\n..\n..\n..\n/Exiting Program.........\n..\n..\n..\nSuccesfully Quited\n"; //all the files are closed 
			}
			break;
		}
	}
	system("pause");
}