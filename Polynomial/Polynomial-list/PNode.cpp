#include"PNode.h"

PNode::PNode() {
	next = NULL;
}

PNode::PNode(int a, int b) {
	coef = a;
	expn = b;
	next = NULL;
}
