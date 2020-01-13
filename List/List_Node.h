//Node.h
#include <iostream>
#define Node_entry int
using namespace std;

class Node{
public:
	Node_entry entry;
	Node *prev;
	Node *next;
	
	Node();
	Node(Node_entry num, Node *link_prev = NULL, Node *link_next = NULL);
};
