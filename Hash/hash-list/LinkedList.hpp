#include<iostream>
#include<string>
using namespace std;

struct Item{
	string key;
	Item *next;
};

class LinkedList{
private:
	Item *head;
	int len;	//Á´±í³¤¶È
public:
	LinkedList();
	void clear(); 
	void insertItem(Item *newItem);
	bool removeItem(string itemKey);
	Item *getItem(string itemKey);
	void printList();
	int getLength();
	~LinkedList(); 
};
