#pragma once
#include "Iterator.h"
#include "Node.h"
class List
{
public:
	List();
	~List();
	void push_front(const int&value);
	void push_back(const int&value);
	void remove(const int&value);
	Iterator begin();
	Iterator end();
	int size() const;
	void PrintList();
private:
	Node * head;

};