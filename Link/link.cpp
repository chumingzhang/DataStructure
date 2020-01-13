#include "link.h"

Node::Node()
{
	next = NULL;
}

Node::Node(Node_entry item, Node *add)
{
	entry = item;
	next = add;
}
