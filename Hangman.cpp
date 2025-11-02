//FileName:		Hangman.cpp
//Programmer:	Alex Ko
//Date:			4/2/2025
//Purpose:		This file defines the methods for the Hangman class
//NOTE: ChatGPT was used to come up with the idea of implementing the Hangman game using set and unordered_set.
//ChatGPT was also used to generate the definition of the checkGuess function by debugging my previous code.

#include "Hangman.h"
#include "player.h"
#include <set>
#include <unordered_set>
#include <iostream>
using namespace std;

string Hangman::getWord()
{
	vector<string> randomWords = { "CHAMBERS", "COMPSCI", "CPLUSPLUS", "DATASTRUCTURES", "VISUALSTUDIO" };
	srand(time(0));
	int index = rand() % 5; // index is numbers 0-4
	word = randomWords[index]; // word becomes an element from randomWords
	unique.insert(word.begin(), word.end()); // insert all unique letters into set
	return word;
}

void Hangman::showSpaces()
{
	for (int i = 0; i < word.size(); i++)
	{
		if (guessed.find(word[i]) != guessed.end())
		{
			cout << word[i] << " ";
		}
		else cout << "_ ";
	}
	cout << endl;
}

void Hangman::showPerson(int& attempts)
{
	switch (attempts)
	{
	case 6:
		cout << "----------|\n";
		cout << "|\n";
		cout << "|\n";
		cout << "|\n";
		cout << "|\n";
		cout << "-\n";
		break;
	case 5:
		cout << "----------|\n";
		cout << "|         O\n";
		cout << "|\n";
		cout << "|\n";
		cout << "|\n";
		cout << "-\n";
		break;
	case 4:
		cout << "----------|\n";
		cout << "|         O\n";
		cout << "|         |\n";
		cout << "|\n";
		cout << "|\n";
		cout << "-\n";
		break;
	case 3:
		cout << "----------|\n";
		cout << "|         O\n";
		cout << "|        /|\n";
		cout << "|\n";
		cout << "|\n";
		cout << "-\n";
		break;
	case 2:
		cout << "----------|\n";
		cout << "|         O\n";
		cout << "|        /|\\\n";
		cout << "|\n";
		cout << "|\n";
		cout << "-\n";
		break;
	case 1:
		cout << "----------|\n";
		cout << "|         O\n";
		cout << "|        /|\\\n";
		cout << "|        / \n";
		cout << "|\n";
		cout << "-\n";
		break;
	case 0:
		cout << "----------|\n";
		cout << "|         O\n";
		cout << "|        /|\\\n";
		cout << "|        / \\\n";
		cout << "|\n";
		cout << "-\n";
		break;
	}
}

bool Hangman::checkGuess(char guess)
{
	return unique.find(guess) != unique.end(); // ChatGPT was used to generate this line of code
}

int Hangman::visit(Player& p)
{
	char input;

	if (visited == false)
	{
		cout << "------------------------------\n";
		cout << ">     Welcome to Hangman!    <\n";
		cout << ">   Guess the word to win!   <\n";
		cout << "------------------------------\n";

		getWord();

		do
		{
			cout << endl;
			showPerson(attempts); // shows hangman visual
			showSpaces(); // prints letter spaces

			cout << "ENTER LETTER: ";
			cin >> input;

			input = toupper(input); // checks for possible lowercase input
			guessed.insert(input); // stores input in unordered set
			checkGuess(input);

			if (!checkGuess(input))
			{
				attempts--; // decrement attempts if guess is incorrect
			}

			wordGuessed = true;
			for (int i = 0; i < word.size(); i++)
			{
				if (guessed.find(word[i]) == guessed.end())
				{
					wordGuessed = false;
					break;
				}
			}

			if (wordGuessed)
			{
				Item* hPrize = new Item("trophy");
				ground.insert(hPrize);
				userWin = true;
				cout << "YOU GUESSED THE WORD: " << word << "!\n";
				break;
			}

			if (attempts == 0)
			{
				userWin = false;
				showPerson(attempts);
				cout << "GAME OVER! The word was: " << word << ".\n";
				break;
			}
		} while (attempts > 0);
		visited = true;
	}
	else if (userWin)
	{
		cout << "Good job! You've shown your skills in Hangman!\n";
	}
	else cout << "You lost in Hangman :(\n";

	return 0;
	
}
