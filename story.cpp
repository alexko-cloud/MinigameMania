//FileName:		story.cpp
//Programmer:	Alex Ko
//Date:			3/26/2025
//Purpose:		This file defines the methods for the Story class
#include "story.h"
#include "player.h"
#include "TicTacToe.h"
#include "Quiz.h"
#include "Hangman.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
using namespace std;

Story::Story()
{
	srand(time(0));

	world = 0;
	rows = cols = playerRow = playerCol = 0;
}

void Story::setUpStory()
{
	int r, c;
	string type;

	ifstream is("world.txt");

	if (!is)
	{
		cout << "Could not open world.txt file!" << endl;
		exit(0);
	}

	is >> rows >> cols;

	//Now we need to dynamically allocate world to be a 2D array of pointers to Locations
	world = new Location **[rows];
	for (r = 0; r < rows; r++)
	{
		world[r] = new Location *[cols];
	}

	//Next, go and initialize all of the pointers in the array to NULL
	for (r = 0; r < rows; r++)
	{
		for (c = 0; c < cols; c++)
		{
			world[r][c] = 0;
		}
	}

	//Now we need to place all of the objects into the world
	for (r = 0; r < rows; r++)
	{
		for (c = 0; c < cols; c++)
		{
			is >> type;
			if (type == "t")
			{
				world[r][c] = new TicTacToe('T');
			}
			else if (type == "q")
			{
				world[r][c] = new Quiz('Q');
			}
			else if (type == "h")
			{
				world[r][c] = new Hangman('H');
			}
			else //nothing special at this place, so make Location object
			{
				world[r][c] = new Location();
			}
		}
	}

	world[0][0]->setVisited(true); //No action where the player begins
	playerRow = 0;
	playerCol = 0;
}


void Story::drawStoryWorld()
{
	for (int r = 0; r < rows; r++)
	{
		for (int c = 0; c < cols; c++)
		{
			if (r == playerRow && c == playerCol)
				cout << "P";
			else
				world[r][c]->draw();
		}
		cout << endl;
	}
}

void Story::tellStory()
{
	int state = 0;
	char move = 'x';

	instructions();
	setUpStory();  //Make sure file is read and the story is ready

	drawStoryWorld();
	while (p.sizeOfInventory() < 3) //The story continues until the player wins all of the prizes
	{
		move = 'x';
		//Handle player move
		do
		{
			cout << "Choose movement direction (u,d,l,r) or show inventory (i)? ";
			cin >> move;
			
			if (move == 'u' && playerRow > 0)
			{
				playerRow--;
			}
			else if (move == 'd' && playerRow < rows-1)
			{
				playerRow++;
			}
			else if (move == 'l' && playerCol > 0)
			{
				playerCol--;
			}
			else if (move == 'r' && playerCol < cols-1)
			{
				playerCol++;
			}
			else if (move == 'i')
			{
				cout << "You are carrying: " << endl;
				p.showInventory();
				system("pause");
			}
			else
			{
				cout << "Invalid move!" << endl;
				move = 'x';
			}
		} while (move == 'x');

		system("cls");
		drawStoryWorld();
		
		//resolve actions involved with that move
		world[playerRow][playerCol]->visit(p);
		world[playerRow][playerCol]->whatsHere(p);
	}
	cout << "Congratulations, you won all the prizes!" << endl;
	system("pause");
}


void Story::instructions()
{
	string name;
	cout << "What is your name? ";
	cin >> name;
	p.setName(name);
	
	cout << "Hi " << p.getName() << ", welcome to Minigame Mania! The objective\n";
	cout << "is to collect 3 prizes by winning in all 3 minigames. Good luck!\n\n";
	system("pause");
	system("cls");
}

Story::~Story()
{
	int r, c;

	if (world != 0) //delete the world if it has been made to point to something
	{
		//first delete all of the objects
		for (r = 0; r < rows; r++)
		{
			for (c = 0; c < cols; c++)
			{
				delete world[r][c];
			}
		}

		//now delete all of the columns on each row
		for (r = 0; r < rows; r++)
		{
			delete [] world[r];
		}

		//finally, we can delete the array
		delete [] world;
	}
}