#include "Node.h"

Node::Node() {
	coef = 0;
	index = 0;
}

Node::Node(int a, int b) {
	coef = a;
	index = b;
}

int Node::get_coef() const {
	return coef;
}

int Node::get_index() const {
	return index;
}

void Node::set_coef(int a) {
	coef = a;
}

void Node::set_index(int b) {
	index = b;
}

bool Node::operator == (Node &a) {
	return (coef == a.coef && index == a.index);
}
bool Node::operator != (Node &a) {
	return (coef != a.coef || index != a.index);
}
