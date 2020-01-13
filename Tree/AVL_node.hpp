//#ifndef _H_BST
//#define _H_BST

//#include "Entry.cpp"
//#include "BNode.hpp"
//#include "BT.hpp"
//#include "BST.hpp"
#include "BST.cpp"

template<class Entry>
class AVL_node: public Binary_node<Entry> {
public:
	Balance_factor balance;
	AVL_node();
	AVL_node(const Entry &x);
	void set_balance(Balance_factor b);
	Balance_factor get_balance() const;
};

//#endif
