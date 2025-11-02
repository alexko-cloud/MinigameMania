//FileName:		Hangman.h
//Programmer:	Alex Ko
//Date:			4/2/2025
//Purpose:		This file defines the header for the Hangman class
//NOTE: ChatGPT was used to come up with the idea of implementing the Hangman game using set and unordered_set.
//ChatGPT was also used to generate the definition of the checkGuess function by debugging my previous code.

#pragma once
#include "location.h"
#include "player.h"
#include <set> // Include set STL class
#include <unordered_set> // Include unordered_set STL class
#include <vector>
using namespace std;

class Hangman : public Location
{
private:
	int attempts = 6;
	bool wordGuessed;
	bool userWin;
	string word;
	unordered_set<char> guessed; // tracks user's guessed letters
	set <char> unique; // tracks all unique letters in word

public:
	Hangman(char s = 'H') : Location(s) { ; }
	string getWord();
	void showPerson(int& attempts);
	void showSpaces();
	bool checkGuess(char guess);
	int visit(Player& p);
};