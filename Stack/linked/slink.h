#include<iostream>
#define Node_entry int
using namespace std;

class Node {
public:
	Node_entry entry;
	Node *next;

	Node();
	//ȱʡֵֻ������д 
	Node(const Node_entry item, Node *add = NULL);
//	Node(Node *original);
};

