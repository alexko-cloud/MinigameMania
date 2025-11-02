//FileName:		Quiz.cpp
//Programmer:	Alex Ko
//Date:			3/27/2025
//Purpose:		This file defines the methods for the Quiz class

#include "Quiz.h"
#include "player.h"
#include <queue>
#include <iostream>

void Quiz::getQuestion()
{
	char answer;
	q.push(q1);
	q.push(q2);
	q.push(q3);
	q.push(q4);

	o.push(o1);
	o.push(o2);
	o.push(o3);
	o.push(o4);

	for (int i = 0; i < q.size() + 3; i++) // not sure why i have to add 3 in order to see all questions, but 
										   // i think it's because popping is changing the size, leading to not every question being printed.
	{
		cout << "\n------------------------------\n";
		cout << q.front() << endl;
		cout << "------------------------------\n";
		cout << o.front() << endl;
		do
		{
			cout << "ENTER ANSWER: ";
			cin >> answer;

			answer = toupper(answer); // takes possible lowercase input and makes it uppercase

			if (answer == 'A' || answer == 'B' || answer == 'C' || answer == 'D')	 /* only store user input if == one of the options.
																					 this fixes an issue where if the user enters an invalid input,
																					 the questions and options would be still popped, leading to
																					 improper storage of userAnswers and improper score tracking. */														
			{
				userAnswers[i] = answer; // store user answers to later compare with answer key array

				q.pop(); // remove question and options from queue once user answers
				o.pop();
			}
			else cout << "Invalid choice!\n";

		} while (answer != 'A' && answer != 'B' && answer != 'C' && answer != 'D');

	}
}

int Quiz::getScore()
{
	for (int i = 0; i < 4; i++)
	{
		if (userAnswers[i] == answerKey[i])
		{
			score++;
		}
	}
	return score;
}


bool Quiz::passed(int score)
{
	if (static_cast<double>(score) / 4 >= 0.7) // score has to be changed to double to get decimal score
	{
		cout << "YOU PASSED!\n"; // player passes if they get 70% or higher
		Item* quizPrize = new Item("plushie");
		ground.insert(quizPrize);
		return true;
	}
	else 
	{
		cout << "Better luck next time...\n";
		return false;
	}
}

int Quiz::visit(Player &p)
{
	if (visited == false)
	{
		cout << "+-------------------------------------+\n";
		cout << "|        Welcome to UOP trivia!       |\n";
		cout << "|      Get a passing grade to win!    |\n";
		cout << "+-------------------------------------+\n";

		getQuestion();
		cout << "YOUR SCORE: " << getScore() << "/4\n";
		userPass = passed(score); // checks if user passed

		visited = true;
	}
	else if (userPass)
	{
		cout << "You made Powercat proud!\n";
	}
	else cout << "It was just a fluke... right?\n";

	return 0;
}