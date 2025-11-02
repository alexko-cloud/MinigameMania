//FileName:		location.h
//Programmer:	Alex Ko
//Date:			3/26/25
//Purpose:		This file defines the header for the Location class

#pragma once
#include <string>
#include <iostream>
#include "player.h"
#include "LinkedList.h"
using namespace std;

class Location
{
	protected:
		bool visited;
		char symbol;

		LinkedList ground;

	public:
		Location(char s = ' ') {symbol = s; visited = false;}

		void setVisited(bool v) {visited = v;}
		void setSymbol(char s) {symbol = s;}

		bool getVisited() {return visited;}
		char getSymbol() {return symbol;}

		virtual void draw() {if (visited) cout << symbol; else cout << ".";}
		virtual int visit(Player &p) {visited = true; return 0;}

		void whatsHere(Player& p);
};