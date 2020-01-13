#include "Buildable.hpp"

template<class Entry>
Result_code Buildable_tree<Entry>::build_tree(const list<Entry> &supply) {
	Result_code ordered_data = success;
	int count = 0;
	Entry x, last_x;
	list<Binary_node<Entry>*>last_node;
	Binary_node<Entry> *none = NULL;
	last_node.insert(0, none);
	while(supply.retrieve(count, x) == success) {
		if(count > 0 && x <= last_x) {
			ordered_data = fail;
			break;
		}
		build_insert(++count, x, last_node);
		last_x = x;
	}
	this->root = find_root(last_node);
	connect_trees(last_node);
	return ordered_data;
}

template<class Entry>
void Buildable_tree<Entry>::build_insert(int count, const Entry &new_data, list<Binary_node<Entry>*> &last_node) {
	int level;
	for(level = 1; count % 2 == 0; ++level)
		count /= 2;
	Binary_node<Entry> *node1, *parent;
	node1 = new Binary_node<Entry>(new_data);
	last_node.retrieve(level - 1, node1->left);
	if(last_node.size() <= level)
		last_node.insert(level, node1);
	else
		last_node.replace(level, node1);
	
	if(last_node.retrieve(level + 1, parent) == success && parent->right == NULL)
		parent->right = node1; 
}

template<class Entry>
Binary_node<Entry>* Buildable_tree<Entry>::find_root(list<Binary_node<Entry>*> &last_node) {
	Binary_node<Entry> *high_node;
	last_node.retrieve(last_node.size() - 1, high_node);
	return high_node;
}

template<class Entry>
void Buildable_tree<Entry>::connect_trees(const list<Binary_node<Entry>*> &last_node) {
	Binary_node<Entry> *hnode, *lnode;
	int hlevel = last_node.size() - 1, llevel;
	while(hlevel > 2) {
		last_node.retrieve(hlevel, hnode);
		if(hnode->right != NULL)
			hlevel--;
		else {
			llevel = hlevel;
			do {
				last_node.retrieve(--llevel, lnode);
			}while(lnode != NULL && lnode->data < hnode->data);
			hnode->right = lnode;
			hlevel = llevel;
		}
	}
}
