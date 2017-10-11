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

int main()
{
	Board board;
	char user_input;
	int menu_choice;

	do
	{
		user_input = ' ';
		menu_choice = 0;
		do
		{
			std::cout << "Welcome to TicTacToe!" << std::endl;
			std::cout << "Menu\n";
			std::cout << "1)\tPlay\n";
			std::cout << "2)\tRules\n";
			std::cout << "3)\tExit" << std::endl;
			std::cout << "Enter menu choice: " << std::endl;
			std::cin >> menu_choice;
		} while (menu_choice < 1 || menu_choice > 3);

		switch (menu_choice)
		{
		case 1:
			board.Play();
			std::cout << "Enter p to play again or q to quit" << std::endl;
			std::cin >> user_input;
			break;
		case 2:
			std::cout << "Standard TicTacToe - Get three in a row and you win!\n";
			std::cout << "Player is 'X' and Computer is  'O'\n";
			std::cout << "Board is as follows:\n"
				<< "[0,0] [0,1] [0,2]\n"
				<< "[1,0] [1,1] [1,2]\n"
				<< "[2,0] [2,1] [2,2]" << std::endl;
			std::cout << std::endl << "Enter p to play or q to quit" << std::endl;
			std::cin >> user_input;
			break;
		case 3:
			user_input = 'q';
			break;
		}
	} while (user_input != 'q' || user_input == 'p');

	return 0;
}