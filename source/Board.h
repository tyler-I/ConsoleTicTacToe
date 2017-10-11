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

#ifndef BOARD_H
#define BOARD_H

class Board
{

private:
	static const int _size_of_board = 3;	//Size of game board

	void __clear_board();					//Clears board - sets all spaces to empty char

public:
	const char X_PIECE = 'X';
	const char O_PIECE = 'O';
	const char EMPTY = ' ';
	char board[_size_of_board][_size_of_board];
	int turn_counter;
	bool is_playing;
	
	Board();								//Initializes member variables, clears board and seeds rand()
	void ClearBoard();
	void PrintBoard();
	void ResetBoard();						//Resets board and member variables to default values
	int CheckForWinner();					//Checks board for a winning state, returns 0 if player won, 1 if computer won, 2 if tie and -1 if game is still playable
	void MakePlayerMove();					//Prompts player for move
	void MakeComputerMove();				//Decides computer move by first trying make winning move, then trying to block losing move, then if neither case is present, makes random valid move
	void Play();							//Plays the game

};

#endif