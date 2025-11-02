//FileName:		linkedList.h
//Programmer:	Alex Ko
//Date:			3/26/25
//Purpose:		This file defines the header for a LinkedList class

#pragma once
#include "item.h"
#include <string>
using namespace std;

class LinkedList
{
	private:
		Item *head;

	public:
		LinkedList() {head = 0;}

		void insert(Item *p);
		Item *remove(string key);
		Item *find(string key);
		void print();
		Item *getfirst() {return head;}
		int length();

		~LinkedList();
};