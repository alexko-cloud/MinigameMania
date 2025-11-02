//Programmer:	Alex Ko
//Date:			3/26/25
//Purpose:		This file defines the methods for the LinkedList class

#include "LinkedList.h"
#include <iostream>
using namespace std;

void LinkedList::insert(Item *i)
{
	if (head == 0) //List is empty
	{
		head = i;
	}
	else if (i->getName() < head->getName())
	{
		i->setNext(head);
		head = i;
	}
	else //must search for the correct spot
	{
		Item *current = head;
		while (current->getNext() != 0 && current->getNext()->getName() < i->getName())
			current = current->getNext();
		i->setNext(current->getNext());
		current->setNext(i);
	}
}

Item *LinkedList::remove(string key)
{
	if (head == 0) //list is empty
	{
		return 0;
	}
	else if (head->getName() == key) //Only one thing in the list
	{
		Item *temp = head;
		head = head->getNext();
		temp->setNext(0);
		return temp;
	}
	else  //We must search for the item
	{	
		Item *current = head;
		while (current->getNext() != 0)
		{
			if (current->getNext()->getName() == key)
			{
				Item *temp = current->getNext();
				current->setNext(temp->getNext());
				temp->setNext(0);
				return temp;
			}
			current = current->getNext();
		}
	}
	return 0;
}

Item *LinkedList::find(string name)
{
	Item *current = head;
	while (current != 0) //List is NOT empty
	{
		if (current->getName() == name)
			return current;
		current = current->getNext();
	}
	return 0; //List was empty or we did not find the item
}

void LinkedList::print()
{
	Item* current = head;

	while (current != 0)
	{
		cout << current->getName() << endl;
		current = current->getNext();
	}
}

int LinkedList::length()
{
	Item *current = head;
	int total = 0;

	while (current != 0)
	{
		current = current->getNext();
		total++;
	}
	return total;
}

LinkedList::~LinkedList()
{
	Item *temp;

	while (head != 0)
	{
		temp = head;
		head = head->getNext();
		delete temp;
	}
}