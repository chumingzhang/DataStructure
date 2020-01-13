#include "slink.h"

Node::Node()
{
	next = NULL;
}

Node::Node(const Node_entry item, Node *add)
{
	entry = item;
	next = add;
}

//Node::Node(Node *original)
//{
//	entry = original->entry;
//	next = original->next;
//}
