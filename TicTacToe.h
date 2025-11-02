//FileName:		TicTacToe.h
//Programmer:	Alex Ko
//Date:			3/26/25
//Purpose:		This file defines the header for the TicTacToe class

#pragma once
#include <string>
#include <iostream>
#include "location.h"
using namespace std;

class TicTacToe : public Location
{
	private:
		bool running = true;
		bool tie = false;
		bool userWin = false; 
		char spaces[9] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' }; // spaces on board
		char user = 'X';
		char computer = 'O';
		

	public:
		TicTacToe(char s = 'T') : Location(s) { ; }
		void drawBoard();
		void playerMove();
		void cpuMove();
		void checkWin(char* spaces);
		bool checkTie(char* spaces);
		int visit(Player &p);
};