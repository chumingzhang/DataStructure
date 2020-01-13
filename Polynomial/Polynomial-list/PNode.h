#include<iostream>
using namespace std;

class PNode{
public:
	int coef;
	int expn;
	PNode *next;

	PNode();
	PNode(int a, int b);
};

