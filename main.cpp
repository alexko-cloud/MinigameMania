//FileName:		main.cpp
//Programmer:	Alex Ko
//Date:			3/26/2025
//Purpose:		This file defines the main function for project 6

#include "story.h"

int main()
{
	/*
	STL classes used to complete Project 6:

	1. Queue: used in Quiz.h and Quiz.cpp to store and print trivia questions & options in order
	2. Vector: used in Hangman.cpp to store multiple random words as strings
	3. Set: used in Hangman.h and Hangman.cpp to store each unique letter in the random word
	4. Unordered_Set: used in Hangman.h and Hangman.cpp to store player's guessed letters
	
	*/
	
	cout << "STL classes used to implement features:\n";
	cout << "------------------------------------------\n";
	cout << "1. Queue: used in Quiz.h & Quiz.cpp to store and display\n";
	cout << "questions and answer options\n";
	cout << "2. Vector: used in Hangman.cpp to store multiple strings\n";
	cout << "as potential random words for player to guess\n";
	cout << "3. Set: used in Hangman.h & Hangman.cpp to store each unique letter in\n";
	cout << "the random word\n";
	cout << "4. Unordered_Set: used in Hangman.h & Hangman.cpp to store player's\n";
	cout << "guessed letters\n\n";
	Story s;
	s.tellStory();
	
	return 0;
}