#include "stdafx.h"
#include "List.h"
#include <iostream>


using namespace std;
List::List()
{
	head = nullptr;
}

List::~List()
{
	while (head != nullptr) {
		Node * temp = head;
		head = head->next;
		delete temp;
	}
}

void List::push_front(const int&value) {
	if (head != nullptr) {
		Node *temp = head;
		head = new Node(value);
		head->next = temp;
	}
	else {
		head = new Node(value);
	}
}

void List::push_back(const int&value) {
	if (head == nullptr) {
		head = new Node(value);
	}
	else {
		Node* temp = head;
		while (temp->next != nullptr) {
				temp = temp->next;
			
		}
		Node* newNode = new Node(value);
		newNode->next = nullptr;
		temp->next = newNode;

	}
}


void List::remove(const int&value) {
	
	while (head != nullptr && head->data == value) {
		Node *temp = head;
		head = head->next;
		delete temp;
	}
	Node *temp = head;
	while (temp->next != nullptr) {
		if (temp->next->data == value) {
			Node * toBeDeleted = temp->next;
			temp->next = toBeDeleted->next;
			delete toBeDeleted;
		}
		else {
			temp = temp->next;
		}
	}
}

Iterator List::begin() {
	return Iterator(head);
}

Iterator List::end() {
	Node * temp = head;
	while (temp != nullptr) {
		temp = temp->next;
	}
	return temp;
}

int List::size() const {
	int counter = 0;
	Node *temp = head;
	while (temp != nullptr) {
		counter++;
		temp = temp->next;
	}
	return counter;
}

void List::PrintList() {
	Node * temp = head;
	while (temp != nullptr) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}
