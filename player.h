//FileName:		player.h
//Programmer:	Alex Ko
//Date:			3/26/25
//Purpose:		This file defines the header for the Player class

#pragma once
#include "LinkedList.h"
#include <string>
using namespace std;

class Player
{
	private: //attributes usually go here
		string name;
		int age;

		LinkedList inventory;

	public:  //method prototypes usually go here
		Player(string n = "none");  //Constructors allow us to initialize attributes

		//Set methods allow objects to change the attributes
		void setName(string n);
		void setAge(int a);

		//Get methods allow objects to tell us about their attributes
		string getName();
		int getAge();

		//Functionality methods are additional actions of objects of the class
		void display();
		bool haveItem(string n) { if (inventory.find(n) != 0) return true; else return false; }
		void addToInventory(Item* i) { inventory.insert(i); }
		Item* removeFromInventory(string item) { return inventory.remove(item); }
		void showInventory() { inventory.print(); }
		int sizeOfInventory() { return inventory.length(); }
};