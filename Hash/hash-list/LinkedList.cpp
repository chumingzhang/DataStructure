#include "LinkedList.hpp"

LinkedList::LinkedList() {
	head = NULL;
	len = 0;
}

void LinkedList::clear() {
	Item *to_delete = head;
	while(head != NULL) {
		head = head->next;
		delete to_delete;
		to_delete = head;
	}
	len = 0;
}

void LinkedList::insertItem(Item *newItem) {
	if(head == NULL) {
		head = newItem;
		len++;
		return;
	}
	
	Item *last = head;
	Item *temp = head;
	while(temp != NULL) {
		last = temp;
		temp = temp->next;
	}
	last->next = newItem;
	len++;
	return;
}

bool LinkedList::removeItem(string itemKey) {
	if(head->key == itemKey) {
		Item *to_delete = head;
		head = head->next;
		delete to_delete;
		len--;
		return true;
	}
	
	Item *last = head;
	Item *to_delete = last->next;
	while(to_delete != NULL) {
		if(to_delete->key == itemKey) {
			last->next = to_delete->next;
			delete to_delete;
			len--;
			return true;
		}
		last = to_delete;
		to_delete = to_delete->next;
	}
	return false;
}

Item *LinkedList::getItem(string itemKey) {
	Item *to_find = head;
	while(to_find != NULL) {
		if(to_find->key == itemKey)
			return to_find;
		to_find = to_find->next;
	}
	return NULL;
}

void LinkedList::printList() {
	cout << "当前链表长度为: " << len << endl;
	Item *to_print = head;
	while(to_print != NULL) {
		cout << to_print->key << " ";
		to_print = to_print->next;
	}
	cout << endl << endl;
}

int LinkedList::getLength() {
	return len;
}

LinkedList::~LinkedList() {
	clear();
}
