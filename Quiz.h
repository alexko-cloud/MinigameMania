//FileName:		Quiz.h
//Programmer:	Alex Ko
//Date:			3/27/2025
//Purpose:		This file defines the header for the Quiz class

#pragma once
#include "location.h"
#include "player.h"
#include <string>
#include <queue> // Include queue stl class

class Quiz : public Location
{
	private:
		bool userPass = false;
		int score = 0;

		typedef string questions;
		typedef string options;
		queue <questions> q;
		queue <options> o;

		questions q1 = "What year was the University of the Pacific founded?"; // 1851
		questions q2 = "Who is UOP's mascot?"; // Powercat
		questions q3 = "What is UOP known for?"; // Being California's first university
		questions q4 = "Who is UOP's current President?"; // President Callahan

		options o1 = "A) 1851 | B) 1758 | C) 1867 | D) 1798\n"; // A 
		options o2 = "A) Tony the Tiger | B) Pacificat | C) Powercat | D) Powertiger\n"; // C 
		options o3 = "A) CA's first university | B) CA's first pharmacy program\nC) The only university to use PST | D) Stockton's only university\n"; // A
		options o4 = "A) Pres. Cristofer | B) Pres. Calhoun | C) Pres. McCaffrey | D) Pres. Callahan\n"; // D

		char userAnswers[4] = { ' ', ' ', ' ', ' '}; // will be updated with each user input
		char answerKey[4] = { 'A', 'C', 'A', 'D' }; // for comparison with userAnswers
	
	public:
		Quiz(char s = 'Q') : Location(s) { ; }
		void getQuestion();
		int getScore();
		bool passed(int score); // divide score by queue size to check if user passed
		int visit(Player &p);
};