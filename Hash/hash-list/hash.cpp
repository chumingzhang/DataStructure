#include "hash.hpp"

int HashTable::hash(string key) {
	int value = 0;
	for(int i = 0; i < key.length(); ++i)
		value += key[i] - '0';
	return (key.length() * value) % length;
}

HashTable::HashTable(int len) {
	if(len <= 0)
		length = 13;
	length = len;
	array = new LinkedList[len];
}

void HashTable::insertItem(Item *newItem) {
	int index = hash(newItem->key);
	array[index].insertItem(newItem);	
}

bool HashTable::removeItem(string key) {
	int index = hash(key);
	return array[index].removeItem(key);	
}

Item* HashTable::getItemByKey(string key) {
	int index = hash(key);
	return array[index].getItem(key);	
}

void HashTable::printTable() {
	cout << "HasTable" << endl;
	for(int i = 0; i < length; ++i) {
		cout << "Bucket " << i + 1 << ": ";
		array[i].printList();
	}
}

void HashTable::printHistogram() {
	cout << "Histogram" << endl;
	for(int i = 0; i < length; ++i) {
		cout << i + 1 << ":    ";
		for(int j = 0; j < array[i].getLength(); ++j)
			cout << "бя";
		cout << endl; 
	}
}

void HashTable::clear() {
	for(int i = 0; i < length; ++i)
		array[i].clear();
}

int HashTable::getLength() {
	return length;
}

int HashTable::getNumberOfItems() {
	int count = 0;
	for(int i = 0; i < length; ++i)
		count += array[i].getLength();
	return count;
}

HashTable::~HashTable() {
	clear();
	delete array;
}
