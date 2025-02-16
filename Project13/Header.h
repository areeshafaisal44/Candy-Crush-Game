#include<iostream> //used for input output 
#include<iomanip> // For using setw and setf
#include<windows.h> // To change console text color and size
#include<conio.h> // Using this to input keys from user(kbhit library)
#include<cstdlib> //use srand function
#include<ctime> // To use time functions 
#include <fstream> // To read and write data on file
#include <string> // To use string in our program
using namespace std;
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE); // creating an instance of handle to change color of console's text . This belongs to windows.h  
namespace MenuDriver // It contain functions related to the main menu of the game
{

	int Option = 1; // These are the options of the main menu for example playgame credits etc.
	int Selected = 0; // It represents which option is being selected
	int GetKey() // Checks which main menu option user is choosing
	{
		int key = _getch(); // get the key
		return key;
	}
	void MenuOptionMove(int& Opt, int min, int max)  // It is used to move between options on main menu. We used '&' reference to constantly change value of Option
	{
		int PointingOption = Opt; // The option at which program is poining
		int key = GetKey(); // takes key from user
		if ((key == 87 || key == 119) && PointingOption > min) // Press W to move up the menu
			PointingOption -= 1;
		else if ((key == 83 || key == 115) && PointingOption < max) // Press S to move down the menu
			PointingOption += 1;
		else if (key == 13) // Press enter to select the option
		{
			Selected = PointingOption; // The program selects the option which we are pointing at .
		}

		Opt = PointingOption; // Changes option value
	}
	// Create Menu Driver
	void CreateMainMenu()
	{
		system("cls"); // Clear screen
		cout << "Press w/s to move between menu and Enter to select\n";
		int Opt = Option; // It determines which option user is pointing to.
		cout << "\n\n";
		SetConsoleTextAttribute(h, 13); // Changing text color
		cout << endl << endl;
		cout << setw(105) /* giving spaces*/ << setfill(' ') << "<============> MATCH THREE <============>"<<endl;
		cout << endl;
		SetConsoleTextAttribute(h, 17); // Changing console text color as well as background color of text
		cout << setw(170) << setfill(' ') << "\n\n\n";
		SetConsoleTextAttribute(h, 11); // Changing console text color
		cout << setw(98) << setfill(' ') << "=======> MAIN MENU <======="<<endl;
		cout << setw(90);
		if (Opt == 1) // if user is pointing towards option 1 
		{
			SetConsoleTextAttribute(h, 7); // Changing console text color
			cout << ">    ";
		}
		SetConsoleTextAttribute(h, 14); // Changing console text color
		cout << "1 -- PLAY GAME\n";
		cout << setw(87);
		SetConsoleTextAttribute(h, 5); // Changing console text color
		cout << setw(86);
		if (Opt == 2) // if user is pointing towards option 2
		{
			SetConsoleTextAttribute(h, 7); // Changing console text color
			cout << ">     ";
		}
		if (Opt == 2)  // if user is pointing towards option 3 
		{
			SetConsoleTextAttribute(h, 7);
			cout << ">     ";
		}
		SetConsoleTextAttribute(h, 12); // Changing console text color
		cout << "2 -- EXIT\n\n";
		SetConsoleTextAttribute(h, 17); // Changing console text color as well as background color of text
		cout << endl << endl;
		cout << setw(168) << setfill(' ') << "\n";
		SetConsoleTextAttribute(h, 7); // Changing console text color
		MenuOptionMove(Option, 1, 5);
	}
	void ReturnToMainMenu() // Puts Selected value to 0 which is the value of main menu
	{
		Selected = 0;
	}
	// Exit the game
	bool Exit()
	{

		system("cls"); // Clear screen
		cout << "Are you sure you want to quit the game?\nY - To Confirm \nAny other key to return\n"; // displaying the message 
		int key = GetKey(); // Getting the input key from the user
		if (key == 121 || key == 89) // If user press Y then he wants to quit
			return true;
		else  // if the user presses any other key other than Y return to main menu
		{
			system("cls");
			ReturnToMainMenu();
			return false;
		}
	}
	void GameLogo()  // Creates game logo which appears on the beginning of game
	{
		system("cls"); // Clear screen
		cout << "\n\n";
		SetConsoleTextAttribute(h, 10);      //set the colour of the game logo 
		cout <<setw(50) << "Match Three Game" << endl;
		Sleep(2500); // Wait for 2.5 seconds then do next task
	}
	void DifficultyOptionMove(int& Opt, int& key) // Ask user to choose difficulty option . It manipulates the option variable which was used in main menu
	{
		int PointingOption = Option; // set pointing option to the paramenter value
		int SelectedDifficulty = 0; // Selected difficulty is 0 by default
		if ((key == 87 || key == 119) && PointingOption > 1) // Press W to move up the menu
			PointingOption -= 1;
		else if ((key == 83 || key == 115) && PointingOption < 2) // Press S to move down the menu
			PointingOption += 1;
		Option = PointingOption; // Changes value of option
	}
	bool ChooseDiff(int& key) // If user press enter then difficulty is selected
	{
		if (key == 13)
			return true; // if enter is pressed
		return false; // else stay false
	}
	void DisplayChooseDifficulty() // Creates menu driverof difficulty
	{
		int key;
		do 
		{
			system("cls");
			int Opt = Option;
			cout << "\n\n";
			SetConsoleTextAttribute(h, 13); // Changing text color
			cout << endl << endl;
			cout << setw(105) << setfill(' ') << "<============> NUMBER CRUSH <============>\n";  // giving spaces//
			cout << endl;
			SetConsoleTextAttribute(h, 19); // Changing console text color as well as background color of text
			cout << setw(170) << setfill(' ') << "\n\n\n";
			SetConsoleTextAttribute(h, 11); // Changing console text color
			cout << setw(110) << setfill(' ') << "=======> CHOOSE DIFFICULTY LEVEL <=======\n\n\n";
			cout << setw(80);
			if (Opt == 1)
			{
				SetConsoleTextAttribute(h, 7);
				cout << ">     ";
			}
			SetConsoleTextAttribute(h, 10);
			cout << "Level 1 - EASY\n";
			cout << setw(83);
			if (Opt == 2)
			{
				SetConsoleTextAttribute(h, 7);
				cout << ">     ";
			}
			SetConsoleTextAttribute(h, 12);
			cout << "Level 3 - VERY HARD\n\n\n\n";
			SetConsoleTextAttribute(h, 17); // Changing console text color as well as background color of text
			cout << setw(168) << setfill(' ') << "\n";
			SetConsoleTextAttribute(h, 7); // Changing console text color
			key = GetKey();
			DifficultyOptionMove(Option, key);
		}
		while (!ChooseDiff(key)); // Keep repeating until difficulty is selected
	}
	void LoadScores() // Load scores of Top 3 players with their names
	{
		string LargestN = " ", SecondLargestN = " ", ThirdLargestN = " "; // By Default set Top 3 names to Blank
		int Largest = 0, SecondLargest = 0, ThirdLargest = 0; // By default all scores are 0
		int Score = 0; // To read each score from file
		string Name;// To read each Name from file
		ifstream ReadScore; // To read Score file
		ReadScore.open("Score.txt", ios::in); // Opens score file
		if (ReadScore.is_open())  // if file opens 
		{
			while (!ReadScore.eof()) // Run loop until we reach end of the text file
			{
				ReadScore >> Score >> Name; // Inputs Score and Name from file
				/* Next to assign Largest , Second Largest and Third Largest Scores respectively*/
				if (Score > Largest)
				{
					ThirdLargest = SecondLargest;
					SecondLargest = Largest;
					Largest = Score;
					ThirdLargestN = SecondLargestN;
					SecondLargestN = LargestN;
					LargestN = Name;
				}
				else if (Score < Largest && Score > SecondLargest)
				{
					ThirdLargest = SecondLargest;
					SecondLargest = Score;
					ThirdLargestN = SecondLargestN;
					SecondLargestN = Name;
				}
				else if (Score < Largest && Score < SecondLargest && Score > ThirdLargest)
				{
					ThirdLargest = Score;
					ThirdLargestN = Name;
				}
			}
		}
		else // if file does not open
			cout << "File Doesn't exists or maybe there's no score recorded yet";
		system("cls"); // Clears screen
		cout << setw(80) << "1st Position : " << Largest << "\tBY\t" << LargestN << endl << endl << endl;
		cout << setw(80) << "2st Position : " << SecondLargest << "\tBY\t" << SecondLargestN << endl << endl;
		cout << setw(80) << "3st Position : " << ThirdLargest << "\tBY\t" << ThirdLargestN << endl << endl;
		cout << "Press Backspace key to return to main menu ";//returning to main menu.
		int key = GetKey(); // Input key from user
		if (key == 8) // If user press backspace
			ReturnToMainMenu(); // return to main menu(the function is called)
	}
	namespace GamePlayFuncs  // It contains function about the game play
	{
		// Prototype starts
		bool MatchesExists(int);
		int Matches(int, int, int);
		void Swap(int, int, int, int);
		void FalseSwap(int);
		void Bomb(int, int, int, int);
		void drawBoard(int);
		// prototype ends
		float t = clock(); // the time at which program started which is 0 seconds
		char numbers[11] = { '1','2','3','4','5','6','7','8','B','H','X' }; // Declaring all types of numbers , Hurdles and X which shows destroyed number
		char number[12][12]; // These are the numbers in the table
		int PointingRow = 0, PointingColumn = 0, SwappedWith_R, SwappedWith_C, Moves, Score = 0; // Pointing Row & Column shows at which number is the user pointing by default it is 0
		int _Matched[12][12]; // It stores locations of numbers which are being matched or makes combination
		string Message; // The message which will appear when user matches 3 or more numbers
		void populateBoard(int Size, int Num_Types, int H) // Generate random numbers depending upon difficulty level
		{
			srand(time(0)); // initiate srand function
			int Randomizer;
			for (int i = 0; i < Size; i++) // It generates random numbers in all cells of the 2D array
			{
				for (int j = 0; j < Size; j++)
				{
					Randomizer = rand() % Num_Types;
					number[i][j] = numbers[Randomizer];
				}
			}
			for (int i = 0; i < H; i++) // Generates hurdles according to the difficulty selected
			{
				int r = rand() % Size; // at any random row
				int c = rand() % Size; // and any random column
				if (number[r][c] != 'H') // If there's not a hurdle already there
					number[r][c] = numbers[9];
				else 
				{
					// if there is a hurdle already there
					int r = rand() % Size;
					int c = rand() % Size;
					i--;
				}
			}
			for (int i = 0; i < Size; i++) // To make sure no more than 2 numbers appears in consective blocks
			{
				for (int j = 0; j < Size - 1; j++)
				{
					if (number[i][j] == number[i][j + 1] && number[i][j] == number[i][j + 2]) // If three numbers are in consective column blocks
					{
						do 
						{
							Randomizer = rand() % Num_Types;
							number[i][j] = numbers[Randomizer];
						} while (number[i][j] == number[i][j + 1]); // keep generating random number at that location until no 3 numbers are consective
					}
					if (number[j][i] == number[j + 1][i] && number[j][i] == number[j + 2][i]) // If three numbers are in consective row blocks
					{
						do
						{
							Randomizer = rand() % Num_Types;
							number[j][i] = numbers[Randomizer];
						} while (number[j][i] == number[j + 1][i]); // keep generating random number at that location until no 3 numbers are consective
					}
				}
			}

		}
		void numbersColor(int i, int j, char numbers[12][12], int Size) // Assign color to each number in the cells
		{
			switch (numbers[i][j])
			{
			case '1':
				SetConsoleTextAttribute(h, 2); // Green
				cout << numbers[i][j];
				break;
			case '2':
				SetConsoleTextAttribute(h, 13); // Golden
				cout << numbers[i][j];
				break;
			case '3':
				SetConsoleTextAttribute(h, 14); // Yellow
				cout << numbers[i][j];
				break;
			case '4':
				SetConsoleTextAttribute(h, 12); // Red
				cout << numbers[i][j];
				break;
			case '5':
				SetConsoleTextAttribute(h, 11); // Cyan
				cout << numbers[i][j];
				break;
			case '6':
				SetConsoleTextAttribute(h, 10); // green
				cout << numbers[i][j];
				break;
			case '7':
				SetConsoleTextAttribute(h, 9); // Blue
				cout << numbers[i][j];
				break;
			case '8':
				SetConsoleTextAttribute(h, 6); // Brown
				cout << numbers[i][j];
				break;
			case 'B':
				SetConsoleTextAttribute(h, 5); // Purple
				cout << numbers[i][j];
				break;
			case 'H':
				SetConsoleTextAttribute(h, 4); // Red
				cout << number[i][j];
				break;
			case 'X':
				SetConsoleTextAttribute(h, 7); // Gray
				cout << number[i][j];
				break;
			}
			SetConsoleTextAttribute(h, 5);
		}
		void Moved(int& Moves)  // When successfully a move is performed then minus 1 from total moves left
		{
			Moves -= 1;
		}
		void numberMover(int& row, int& column, int Size, int number_Types) // Allow user to change the number he is pointing at
		{
			int key = MenuDriver::GetKey();
			if ((key == 87 || key == 119) && row > 0) // Press W to move up the menu
				row--;
			else if ((key == 83 || key == 115) && row < Size - 1) // Press S to move down the menu
				row++;
			else if ((key == 65 || key == 97) && column > 0) // Press A to move left on the menu
				column--;
			else if ((key == 68 || key == 100) && column < Size - 1) // Press S to move right on the menu
				column++;
			else if (key == 13 && number[row][column] != 'H') // Press S to move down the menu
			{
				Swap(row, column, Size, number_Types); // Swap the the number with selected direction
				if ((!MatchesExists(Size) || number[PointingRow][PointingColumn] == 'H')) // If it doesn't make match or there's a hurdle then swap back and cancel move
					FalseSwap(Size);
				else // otherwise move
					Moved(Moves);
			}
		}
		int Matches(int row, int column, int Size) // Checks how many number matches
		{
			int Matches;
			int count = 1, temp = row;
			while ((number[temp][column] == number[temp + 1][column] && temp < Size - 1)) // Keeps checking matches on right side of row
			{
				count++;
				temp++; // move to next right 
			}
			temp = row;
			while ((number[temp][column] == number[temp - 1][column]) && temp > 0) // Keeps checking matches on left side of row
			{
				count++;
				temp--; // move to left

			}
			if (number[temp][column] == 'B') // Consider Bomb as a combination for itself
			{
				count = 3;
			}
			if (count >= 3)
				return count; // Return matches in rows
			count = 1;
			temp = column;
			while ((number[row][temp] == number[row][temp + 1]) && temp < Size - 1) // Keeps checking matches on  upside of column
			{
				count++;
				temp++; // move down
			}
			temp = column;
			while ((number[row][temp] == number[row][temp - 1]) && temp > 0) // Keeps checking matches on down side of column
			{
				count++;
				temp--; // move up
			}
			if (number[row][column] == 'B') //Consider bomb as a combination of three itself
			{
				count = 3;
			}
			return count;
		}
		bool MatchesExists(int Size)  // If any cell shows 3 it means three numbers are making combinations and hence matches exists
		{
			bool exists = false;
			for (int i = 0; i < Size; i++)
			{
				for (int j = 0; j < Size; j++)
				{
					if (Matches(i, j, Size) >= 3)// If any cell shows 3 it means three numbers are making combinations
						return true; // matches exists
				}
			}
			return false;
		}
		void Swap(int row, int column, int Size, int number_Types) // perform swaps
		{
			int key = MenuDriver::GetKey(); // Input key from user
			char temp = number[row][column]; // Temporary stores value of that cell
			if (((key == 87 || key == 119) && row > 0)) // Press W to move up the menu
			{
				// Swaps number with upper one
				number[row][column] = number[row - 1][column];
				number[row - 1][column] = temp;
				// Store location of cell with which swap is performed
				SwappedWith_R = row - 1;
				SwappedWith_C = column;
				if (number[row][column] == 'B') // if selected number is a bomb
				{
					Bomb(Size, row, column, number_Types); // perform bomb function 
				}
				if (number[SwappedWith_R][SwappedWith_C] == 'B') // If the other cell which is being swapped with is bomb
				{
					Bomb(Size, SwappedWith_R, SwappedWith_C, number_Types);
				}
			}
			else if (((key == 83 || key == 115) && row < Size - 1)) // Press S to move down the menu
			{
				number[row][column] = number[row + 1][column];
				number[row + 1][column] = temp;
				// Store location of cell with which swap is performed
				SwappedWith_R = row + 1;
				SwappedWith_C = column;
				if (number[row][column] == 'B')  // if selected number is a bomb
				{
					Bomb(Size, row, column, number_Types); // Perform bomb function
				}
				if (number[SwappedWith_R][SwappedWith_C] == 'B') // If the other cell which is being swapped with is bomb
				{
					Bomb(Size, SwappedWith_R, SwappedWith_C, number_Types);
				}
			}
			else if (((key == 65 || key == 97) && column > 0)) // Press S to move down the menu
			{
				number[row][column] = number[row][column - 1];
				number[row][column - 1] = temp;
				// Store location of cell with which swap is performed
				SwappedWith_R = row;
				SwappedWith_C = column - 1;
				if (number[row][column] == 'B')  // if selected number is a bomb
				{
					Bomb(Size, row, column, number_Types);
				}
				if (number[SwappedWith_R][SwappedWith_C] == 'B') // If the other cell which is being swapped with is bomb
				{
					Bomb(Size, SwappedWith_R, SwappedWith_C, number_Types), number_Types; // Perform bomb function
				}
			}
			else if (((key == 68 || key == 100) && column < Size - 1)) // Press S to move down the menu
			{
				number[row][column] = number[row][column + 1];
				number[row][column + 1] = temp;
				// Store location of cell with which swap is performed
				SwappedWith_R = row;
				SwappedWith_C = column + 1;
				if (number[row][column] == 'B') // if selected number is a bomb
				{
					Bomb(Size, row, column, number_Types); // Perform bomb functin
				}
				if (number[SwappedWith_R][SwappedWith_C] == 'B') // If the other cell which is being swapped with is bomb
				{
					Bomb(Size, SwappedWith_R, SwappedWith_C, number_Types); // Perform bomb function
				}
			}
			for (int i = 0; i < Size; i++)
			{
				for (int j = 0; j < Size; j++) 
				{

					_Matched[i][j] = Matches(i, j, Size); // perform matches function in each cell and store its location in _Matches[][]
				}
			}
		}
		void FalseSwap(int Size) // Cancels swap
		{
			char temp = number[SwappedWith_R][SwappedWith_C];
			number[SwappedWith_R][SwappedWith_C] = number[PointingRow][PointingColumn];
			number[PointingRow][PointingColumn] = temp;
		}
		bool SwapAvailable(int Size) // Checks if swap is available
		{
			for (int row = 0; row < Size; row++)
			{
				for (int column = 0; column < Size; column++)
				{

					int count = 0;
					if ((number[row][column] == number[row + 2][column] && number[row][column] == number[row + 3][column]) && row < Size - 3) // Checks if any combination exists in row
					{
						count++;
					}
					if (row > 3 && (number[row][column] == number[row - 2][column] && number[row][column] == number[row - 3][column])) // Checks if any combination exists in row
					{
						count++;
					}
					if (count >= 1)
						return true;
					else
					{
						count = 0;
						if ((number[row][column] == number[row][column + 2] && number[row][column] == number[row][column + 3]) && column < Size - 3) // Checks if any combination exists in column
						{
							count++;
						}
						if (column > 3 && (number[row][column] == number[row][column - 2] && number[row][column] == number[row][column - 3])) // Checks if any combination exists in column
						{
							count++;
						}
						if (count >= 1)
							return true;
					}
				}
			}
			return false;
		}
		void drawBoard(int Size) // Function to Draw table of the given size.
		{
			system("cls");         //system clear screen
			cout << setw(169) << setfill('=') << "\n";
			cout << setw(78) << setfill(' ') << "Score      : " << Score << endl;
			cout << setw(78) << "Time       : " << t << endl;          //time is displayed at the top 
			cout << setw(78) << "Moves Left : " << Moves << endl;     //number of moves left is displayed at the top.
			cout << setw(78) << Message << endl;
			cout << setw(169) << setfill('=') << "\n";

			SetConsoleTextAttribute(h, 5);
			for (int i = 0; i < Size; i++) // This outer loop will control the Row of table mean all cells under 1 row
			{
				if (i == 0)  // At first row, the table upper border will be created
				{
					for (int j = 0; j < Size; j++) // Each cell of table has 6 spaces
						cout << "__________"; // For each cell 6 '_' will be printed
				}
				cout << endl; // After printing the upper border of table new line starts
				for (int j = 0; j < Size; j++) // This controls the column of table.
				{

					if (j == 0) // When J is 0, mean it is first column.
					{
						for (int k = 0; k < Size; k++)  // This loop runs to create borders( left and right) of each cell
						{


							if (k == Size - 1) // When it is last coloumn of cell
								cout << "|         |";
							else if (k == 0) // when it is first column of cell
								cout << "|         ";
							else  // if its between first and last column of cell
								cout << "|         ";

						}
						cout << endl;
						if (i == PointingRow && j == PointingColumn)
						{
							SetConsoleTextAttribute(h, 15);
							cout << "| >  ";
							SetConsoleTextAttribute(h, 5);
						}
						else
							cout << "|    ";
						numbersColor(i, j, number, Size);
						cout << "    "; //Print the first elements with its border (left and right)

					}
					else if (j == Size - 1) // if it is last column of cell
					{
						if (i == PointingRow && j == PointingColumn)
						{
							SetConsoleTextAttribute(h, 15);
							cout << "| >  ";
							SetConsoleTextAttribute(h, 5);
						}
						else
							cout << "|    ";
						numbersColor(i, j, number, Size);
						cout << "    |" << endl;
						for (int k = 0; k < Size; k++) // prints bottom border of cell
						{
							if (k != Size - 1)
								cout << "|_________";
							else
								cout << "|_________|";
						}
					}
					else // print elements between borders of each cell
					{
						if (i == PointingRow && j == PointingColumn)
						{
							SetConsoleTextAttribute(h, 15);
							cout << "| >  ";
							SetConsoleTextAttribute(h, 5);
						}
						else
							cout << "|    ";
						numbersColor(i, j, number, Size);
						cout << "    ";
					}
				}
			}
			cout << endl << endl;
			Message = " ";
			SetConsoleTextAttribute(h, 7);
		}
		void Destroynumber(int Size, int number_Types) // Destroys numbers
		{
			int ScoreToBeAdded = 0;
			bool To_destroy = false;
			for (int i = 0; i < Size; i++)
			{
				for (int j = 0; j < Size; j++) {
					if (_Matched[i][j] >= 3 && number[i][j] != 'H' && number[i][j] != 'B') // there's any combination mark them as X which shows they are being destroyed
					{
						number[i][j] = numbers[10];
						To_destroy = true;
					}
				}
			}
			if (To_destroy)
			{
				drawBoard(Size); // Redraw the table
				ScoreToBeAdded = 10;
				Message = "Combo1";          //displayes the message combo1 at the top
				srand(time(0));
				int Randomizer, match = 0, count = 0;
				for (int i = 0; i < Size; i++)
				{
					for (int j = 0; j < Size; j++)
					{
						// Creates bomb if combination is greater than 3
						if (number[i][j] == numbers[10] && (_Matched[SwappedWith_R][SwappedWith_C] >= 4 && _Matched[SwappedWith_R][SwappedWith_C] < 6))
						{
							number[SwappedWith_R][SwappedWith_C] = numbers[8];
							ScoreToBeAdded = 20;
							Message = "Combo2";   //displayes the message combo2 at the top
						}
						// Creates bomb if combination is greater than 3
						else if (number[i][j] == numbers[10] && (_Matched[PointingRow][PointingColumn] >= 4 && _Matched[PointingRow][PointingColumn] < 6))
						{
							number[PointingRow][PointingColumn] = numbers[8];
							ScoreToBeAdded = 20;
							Message = "Combo3"; //displayes the message combo3 at the top
						}
						// Replace 'X' with new random numbers making sure they do not form 3 consective numbers
						if (number[i][j] == numbers[10])
						{
							do 
							{
								Randomizer = rand() % number_Types;
								number[i][j] = numbers[Randomizer];
							} while ((number[i][j] == number[i + 1][j] && i < Size - 2) || (number[i][j] == number[i - 1][j] && i > 2) || (number[i][j] == number[i][j + 1] && j < Size - 2) || (number[i][j] == number[i][j + 1] && j > 2));
						}
						_Matched[i][j] = Matches(i, j, Size); // Reset their combination to neutral
					}
				}
				To_destroy = false;
			}
			Score += ScoreToBeAdded; // score is incrementing
			if (ScoreToBeAdded == 10)
			{ 
				Sleep(1400); // wait for 1.4 seconds 
			}
			else if (ScoreToBeAdded == 20)  // if score is 20
			{
				Sleep(1400); // wait for 1.4 seconds
			}
		}
		void Bomb(int Size, int row, int column, int number_Types) // Function of Bomb
		{
			number[row][column] = numbers[10];
			for (int j = 0; j < Size; j++) // Destroys all cells(left,right,up and down) of that respective cell
			{
				if (number[row][j] != 'H')
					number[row][j] = numbers[10];
				if (number[j][column] != 'H')
					number[j][column] = numbers[10];
			}
			Message = "Combo4"; // Display message combo4 at the top
			drawBoard(Size);
			int Randomizer;
			for (int i = 0; i < Size; i++)
			{
				for (int j = 0; j < Size; j++)
				{
					if (number[i][j] == numbers[10])
					{
						do 
						{
							Randomizer = rand() % number_Types;
							number[i][j] = numbers[Randomizer];
						} while ((i < Size - 2 && number[i][j] == number[i + 1][j]) || (i > 2 && number[i][j] == number[i - 1][j]) || (j < Size - 2 && number[i][j] == number[i][j + 1]) || (j > 2 && number[i][j] == number[i][j + 1]));

					}
				}
			}
			Score += 30; // if four consective numbers are together then score will be added by 30.
			Sleep(1500); // wait for 1.5 seconds
		}
		void SaveScore(string Name) // It Saves the scores
		{
			ofstream WriteScore;
			WriteScore.open("Score.txt", ios::app);
			WriteScore << Name << " " << Score << endl;
			WriteScore.close();
		}
	}
}