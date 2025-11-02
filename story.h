//FileName:		story.h
//Programmer:	Alex Ko
//Date:			3/26/25
//Purpose:		This file defines the header for the Story class

#pragma once
#include "player.h"
#include "location.h"

class Story
{
	protected:
		Location ***world;
		Player p;

		int rows;
		int cols;
		int playerRow;
		int playerCol;

	public:
		Story();

		//Required Methods
		void instructions();
		void setUpStory();
		void tellStory();
		void drawStoryWorld();

		~Story();
};