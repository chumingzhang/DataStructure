#include "BNode.hpp"

template<class Entry>
Binary_node<Entry>::Binary_node() {
	left = NULL;
	right = NULL;
}

template<class Entry>
Binary_node<Entry>::Binary_node(const Entry &x) {
	data = x;
	left = NULL;
	right = NULL;
}

template<class Entry>
void Binary_node<Entry>::set_balance(Balance_factor b) {
	
}

template<class Entry>
Balance_factor Binary_node<Entry>::get_balance() const {
	return equal_height;
}
