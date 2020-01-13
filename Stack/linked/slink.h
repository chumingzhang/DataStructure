#include<iostream>
#define Node_entry int
using namespace std;

class Node {
public:
	Node_entry entry;
	Node *next;

	Node();
	//缺省值只在声明写 
	Node(const Node_entry item, Node *add = NULL);
//	Node(Node *original);
};

