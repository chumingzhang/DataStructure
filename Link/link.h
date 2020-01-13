#include<iostream>
#define Node_entry int
using namespace std;

class Node {
public:
	Node_entry entry;
	Node* next;

	Node();
	Node(Node_entry item, Node *add);
};

