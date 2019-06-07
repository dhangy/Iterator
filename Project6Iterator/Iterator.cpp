#include "stdafx.h"
#include "Iterator.h"



Iterator::Iterator(Node *start)
{
	n = start;
}


bool Iterator::operator!=(Iterator& other) {
	return (n != other.n);
}
bool Iterator::is_item() {
	bool val = n != nullptr;
	return val;
}

void Iterator::operator++() {
	if (is_item()) {
		n = n->next;
	}
}

int Iterator::operator*() {
	if (is_item()) {
		return n->data;
	}
	else {
		return 0;
	}
   }