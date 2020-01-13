//Node.cpp
#include "List_Node.h"
Node::Node()
{
	entry = 0;
	prev = NULL;
	next = NULL;
}

Node::Node(Node_entry num, Node *link_prev, Node *link_next)
{
	entry = num;
	prev = link_prev;
	next = link_next;
}
