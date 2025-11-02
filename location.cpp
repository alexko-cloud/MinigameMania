//FileName:		location.cpp
//Programmer:	Alex Ko
//Date:			3/26/25
//Purpose:		This file defines the methods for the Location class

#include "location.h"
#include <string>
#include <iostream>
using namespace std;

void Location::whatsHere(Player& p)
{
	string answer;
	if (ground.length() > 0)
	{
		cout << "You see the following items: " << endl;
		ground.print();

		cout << "Would you like to pick something up? (y/n): ";
		cin >> answer;

		while (answer == "y")
		{
			cout << "What would you like to pick up? ";
			cin >> answer;

			Item* i = ground.remove(answer);
			if (i != 0)
			{
				p.addToInventory(i);
			}
			else
			{
				cout << "Invalid item!" << endl;
			}

			if (ground.length() > 0)
			{
				cout << "Would you like to pick something else up? (y/n): ";
				cin >> answer;
			}
		}
	}

	if (p.sizeOfInventory() > 0)
	{
		cout << "Would you like to drop something from your inventory here? (y/n): ";
		cin >> answer;

		while (answer == "y")
		{
			cout << "You have the following items: " << endl;
			p.showInventory();

			cout << "What would you like to drop? ";
			cin >> answer;

			Item* i = p.removeFromInventory(answer);
			if (i != 0)
			{
				ground.insert(i);
			}
			else
			{
				cout << "You do not have that item." << endl;
			}

			if (p.sizeOfInventory() > 0)
			{
				cout << "Would you like to drop something else? (y/n): ";
				cin >> answer;
			}
		}
	}
}