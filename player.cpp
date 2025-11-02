//FileName:		player.cpp
//Programmer:	Alex Ko
//Date:			3/26/25
//Purpose:		This file defines the methods for the Player class

#include "player.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

Player::Player(string n)
{
	name = n;
	age = 0;
}

void Player::setName(string n)
{
	name = n;
}

string Player::getName()
{
	return name;
}

void Player::setAge(int a)
{
	age = a;
}

int Player::getAge()
{
	return age;
}

void Player::display()
{
	cout << "Name: " << name << endl;
	cout << "Age: " << age << endl;
}