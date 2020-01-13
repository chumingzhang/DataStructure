#include "AVL_node.hpp"

template<class Entry>
AVL_node<Entry>::AVL_node() {
	this->left = NULL;
	this->right = NULL;
	balance = equal_height;
}

template<class Entry>
AVL_node<Entry>::AVL_node(const Entry &x) {
	this->data = x;
	this->left = NULL;
	this->right = NULL;
	balance = equal_height;
}

template<class Entry>
void AVL_node<Entry>::set_balance(Balance_factor b) {
	balance = b;
}

template<class Entry>
Balance_factor AVL_node<Entry>::get_balance() const {
	return balance;
}
