/*
*	Tyler Ingham
*	10/11/2017
*	Copywrite 2017 Tyler Ingham
*	//MIT Licnese//
*	Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"),
*	to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense,
*	and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
*	The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
*	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
*	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
*	DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE
*	USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include "Board.h"
#include<iostream>
#include<cstdlib>
#include<ctime>

void Board::__clear_board()
{
	for (int i = 0; i < _size_of_board; i++)
		for (int j = 0; j < _size_of_board; j++)
			board[i][j] = EMPTY;
}

Board::Board()
{
	__clear_board();
	turn_counter = 0;		//Default value
	is_playing = true;		//Default value
	srand(time(NULL));
}

void Board::ClearBoard()
{
	__clear_board();
}

void Board::PrintBoard()
{
	for (int i = 0; i < _size_of_board; i++)
	{
		std::cout << std::endl;
		for (int j = 0; j < _size_of_board; j++)
			std::cout << " [ " << board[i][j] << " ] ";
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void Board::ResetBoard()
{
	is_playing = true;
	turn_counter = 0;
}

int Board::CheckForWinner()
{
	int winner = -1;

	//Vertical Wins
	for (int i = 0; i < _size_of_board; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != EMPTY)
		{
			if (board[i][0] == X_PIECE)
			{
				winner = 0;
				return winner;
			}
			else
			{
				winner = 1;
				return winner;
			}
		}
	}
	//Horizontal Wins
	for (int i = 0; i < _size_of_board; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != EMPTY)
		{
			if (board[0][i] == X_PIECE)
			{
				winner = 0;
				return winner;
			}
			else
			{
				winner = 1;
				return winner;
			}
		}
	}
	//Diagonal Wins
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != EMPTY)
	{
		if (board[0][0] == X_PIECE)
		{
			winner = 0;
			return winner;
		}
		else
		{
			winner = 1;
			return winner;
		}
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != EMPTY)
	{
		if (board[0][2] == X_PIECE)
		{
			winner = 0;
			return winner;
		}
		else
		{
			winner = 1;
			return winner;
		}
	}
	//Cat's Game
	if (turn_counter > 8)
		winner = 2;

	return winner;
}

void Board::MakePlayerMove()
{
	int x, y;
	bool valid_move;
	do
	{
		valid_move = false;
		do
		{
			std::cout << "Enter row: ";
			std::cin >> x;
		} while (x < 0 || x > 2);
		do
		{
			std::cout << "Enter col: ";
			std::cin >> y;
		} while (y < 0 || y > 2);
		if (board[x][y] == EMPTY)
			valid_move = true;
	} while (!valid_move);
	board[x][y] = X_PIECE;
	turn_counter++;
}

void Board::MakeComputerMove()
{
	for (int i = 0; i < _size_of_board; i++)
	{
		for (int j = 0; j < _size_of_board; j++)
		{			
			if (board[i][j] == EMPTY)
			{
				//Make winning move
				board[i][j] = O_PIECE;
				if (CheckForWinner() == 1)
				{
					turn_counter++;
					return;
				}					
				//Block Losing Move
				board[i][j] = X_PIECE;
				if (CheckForWinner() == 0)
				{
					board[i][j] = O_PIECE;
					turn_counter++;
					return;
				}
				board[i][j] = EMPTY;
			}			
		}
	}
	//Make Random Move
	int row;
	int col;
	do
	{
		row = rand() % 3;
		col = rand() % 3;
	} while (board[row][col] != EMPTY);
	board[row][col] = O_PIECE;
	turn_counter++;
}

void Board::Play()
{
	int end_game;

	ClearBoard();
	PrintBoard();

	while (is_playing)
	{
		//Player Turn
		MakePlayerMove();
		PrintBoard();
		end_game = CheckForWinner();
		if (end_game >= 0)
			break;
		//Computer Turn
		MakeComputerMove();
		PrintBoard();
		end_game = CheckForWinner();
		if (end_game >= 0)
			break;		
	}

	PrintBoard();
	is_playing = false;

	switch (end_game)
	{
	case 0:
		std::cout << std::endl << "Congratulations! You won!" << std::endl;
		break;
	case 1:
		std::cout << std::endl << "Oh no! The computer won! Better Luck next time..." << std::endl;
		break;
	case 2:
		std::cout << std::endl << "That's a scratch! Nobody won that one." << std::endl;
		break;
	}
}