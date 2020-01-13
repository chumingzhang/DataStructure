#include "Entry.cpp"

enum Balance_factor {
	left_higher, equal_height, right_higher
};

template<class Entry>
class Binary_node {
public: 
	Entry data;			//data members
	Binary_node<Entry> *left, *right;
	Binary_node();		//constructors
	Binary_node(const Entry &x);
	virtual void set_balance(Balance_factor b);
	virtual Balance_factor get_balance() const;
}; 

