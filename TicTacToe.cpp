//FileName:		TicTacToe.cpp
//Programmer:	Alex Ko
//Date:			3/26/25
//Purpose:		This file defines the methods for the TicTacToe class

#include "TicTacToe.h"
#include <string>
#include <iostream>
#include "location.h"
using namespace std;

void TicTacToe::drawBoard()
{
	cout << "     |     |     " << endl;
	cout << "  " << spaces[0] << "  |  " << spaces[1] << "  |  " <<  spaces[2] << endl;
	cout << "     |     |     " << endl;
	cout << "-----------------" << endl;
	cout << "     |     |     " << endl;
	cout << "  " << spaces[3] << "  |  " << spaces[4] << "  |  " << spaces[5] << endl;
	cout << "     |     |     " << endl;
	cout << "-----------------" << endl;
	cout << "     |     |     " << endl;
	cout << "  " << spaces[6] << "  |  " << spaces[7] << "  |  " << spaces[8] << endl;
	cout << "     |     |     " << endl;
}

void TicTacToe::playerMove()
{
	int num; 
	
	do
	{
		cout << "Enter a number (1-9): ";
		
		cin >> num;

		num--; // decrement so num is in range of spaces array
			   // this is assuming that the user doesn't know that arrays start at index 0

		if (num < 0 || num > 8) // out of range
		{
			cout << "Invalid spot!\n";
		}
		else if (spaces[num] == ' ') // if spot is blank, change to X
		{
			spaces[num] = user;
		}
	} while (num < 0 || num > 8);

}

void TicTacToe::cpuMove() 
{
	srand(time(0));
	int cpu = rand() % 9; // cpu's move is at random number between 0-8

	do 
	{
		cpu = rand() % 9;  
	} while (spaces[cpu] != ' ');

	spaces[cpu] = 'O';

}

void TicTacToe::checkWin(char* spaces)  
{
	Item* t = new Item("medal");
	// check for row win
	if ((spaces[0] != ' ') && (spaces[0] == spaces[1]) && (spaces[1] == spaces[2]))
	{
		if (spaces[0] == user)
		{
			cout << "YOU ARE THE WINNER!\n"; 
			ground.insert(t);
			userWin = true;
		}
		else cout << "You lost!\n";
		running = false;
	}
	else if ((spaces[3] != ' ') && (spaces[3] == spaces[4]) && (spaces[4] == spaces[5]))
	{
		if (spaces[3] == user)
		{
			cout << "YOU ARE THE WINNER!\n";
			ground.insert(t);
			userWin = true;
		}
		else cout << "You lost!\n";
		running = false;
	}
	else if ((spaces[6] != ' ') && (spaces[6] == spaces[7]) && (spaces[7] == spaces[8]))
	{
		if (spaces[6] == user)
		{
			cout << "YOU ARE THE WINNER!\n";
			ground.insert(t);
			userWin = true;
		}
		else cout << "You lost!\n";
		running = false;
	}
	// check for diagonal win
	else if ((spaces[0] != ' ') && (spaces[0] == spaces[4]) && (spaces[4] == spaces[8]))
	{
		if (spaces[0] == user)
		{
			cout << "YOU ARE THE WINNER!\n";
			ground.insert(t);
			userWin = true;
		}
		else cout << "You lost!\n";
		running = false;
	}
	else if ((spaces[2] != ' ') && (spaces[2] == spaces[4]) && (spaces[4] == spaces[6]))
	{
		if (spaces[2] == user)
		{
			cout << "YOU ARE THE WINNER!\n";
			ground.insert(t);
			userWin = true;
		}
		else cout << "You lost!\n";
		running = false;
	}
	// check for column win
	else if ((spaces[0] != ' ') && (spaces[0] == spaces[3]) && (spaces[3] == spaces[6]))
	{
		if (spaces[0] == user)
		{
			cout << "YOU ARE THE WINNER!\n";
			ground.insert(t);
			userWin = true;
		}
		else cout << "You lost!\n";
		running = false;
	}
	else if ((spaces[1] != ' ') && (spaces[1] == spaces[4]) && (spaces[4] == spaces[7]))
	{
		if (spaces[1] == user)
		{
			cout << "YOU ARE THE WINNER!\n";
			ground.insert(t);
			userWin = true;
		}
		else cout << "You lost!\n";
		running = false;
	}
	else if ((spaces[2] != ' ') && (spaces[2] == spaces[5]) && (spaces[5] == spaces[8]))
	{
		if (spaces[2] == user)
		{
			cout << "YOU ARE THE WINNER!\n";
			ground.insert(t);
			userWin = true;
		}
		else cout << "You lost!\n";
		running = false;
	}
}

bool TicTacToe::checkTie(char* spaces)
{
	for (int i = 0; i < 9; i++)
	{
		if (spaces[i] == ' ') // if there's empty spaces, game continues
		{
			return false;
		}
	}
		cout << "TIE!\n"; 
		running = false;
		return true;
}

int TicTacToe::visit(Player &p)
{
	if (visited == false)
	{
		cout << "********************************************************\n";
		cout << "*       Welcome to the classic game of Tic-Tac-Toe!    *\n";
		cout << "*       Beat the computer and win a prize!             *\n";
		cout << "********************************************************\n";
		cout << "\nYou are playing as: " << user << endl;
		drawBoard();
	}
	else if (userWin)
	{
		cout << "You won in Tic-Tac-Toe! Now try the other games!\n";
	}
	else if (tie)
	{
		cout << "C'mon, you can do better than that, right?\n";
	}
	else cout << "So you're telling me you let the computer beat you in Tic-Tac-Toe?\n";

	while (running == true)
	{
		playerMove();
		drawBoard();

		checkWin(spaces);
		if (running == false) break; // game ends if winner is found or there's a tie

		tie = checkTie(spaces);
		if (tie) break; // game ends if winner is found or there's a tie

		cpuMove();
		cout << "********************************************************\n";
		drawBoard();

		checkWin(spaces);
		if (running == false) break;

		tie = checkTie(spaces);
		if (tie) break;
	}
	visited = true;

	
	return 0;
}
