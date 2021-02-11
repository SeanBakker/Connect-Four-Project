/*
Sean Bakker
*/

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
	ifstream fin("game_moves.txt");
	
	if (!fin)
	{
		cout << "File not found" << endl;
		return EXIT_FAILURE;
	}
	
	const int ROW_SIZE = 6, COL_SIZE = 7, WIN = 4;
	const string X = "X", O = "O", DASH = "-";
	string board[ROW_SIZE][COL_SIZE] = {};
	
	int position = 0, count = 0, numX = 0, numO = 0;
	string turn = "";
	
	bool playerXWon = false;
	bool playerOWon = false;
	
	for (int row = 0; row < ROW_SIZE; row++)
	{
		for (int col = 0; col < COL_SIZE; col++)
			board[row][col] = DASH;
	}
	
	while (fin >> position)
	{
		int row = ROW_SIZE - 1;
		
		if (count == 0)
			turn = X;
		else 
			turn = O;
		
		while (board[row][position - 1] != DASH)
		{
			row--;
		}
		
		board[row][position - 1] = turn;
		
		if (count > 0)
			count = 0;
		else 
			count++;
	}
	
	for (int col = 0; col < COL_SIZE; col++)
	{
		for (int row = 0; row < ROW_SIZE; row++)
		{
			if (board[row][col] == X)
			{
				numX++;
				numO = 0;
			}
			else if (board[row][col] == O)
			{
				numO++;
				numX = 0;
			}
			else 
			{
				numO = 0;
				numX = 0;
			}
		
			if (numX == WIN)
				playerXWon = true;
			else if (numO == WIN)
				playerOWon = true;
		}	
		
		numO = 0;
		numX = 0;
	}
	
	for (int row = 0; row < ROW_SIZE; row++)
	{
		for (int col = 0; col < COL_SIZE; col++)
		{
			if (board[row][col] == X)
			{
				numX++;
				numO = 0;
			}
			else if (board[row][col] == O)
			{
				numO++;
				numX = 0;
			}
			else 
			{
				numO = 0;
				numX = 0;
			}
		
			if (numX == WIN)
				playerXWon = true;
			else if (numO == WIN)
				playerOWon = true;
		}	
		
		numO = 0;
		numX = 0;
	}
	
	for (int row = 0; row < ROW_SIZE; row++)
	{
		for (int col = 0; col < COL_SIZE; col++)
			cout << board[row][col] << " ";
			
		cout << endl;
	}

	if (playerXWon)
		cout << "Player X has won." << endl;
	else if (playerOWon)
		cout << "Player O has won." << endl;
	else 
		cout << "Neither player has won yet." << endl;
	
	
	fin.close();
	system("PAUSE");
	return EXIT_SUCCESS;
}
/*
- - - - - - -
- - - - - - -
- - - - - - -
- O - - - - -
O X O X - X X
X X X O O O O
Player O has won.
*/

