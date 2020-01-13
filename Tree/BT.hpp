//#ifndef _H_BT
//#define _H_BT

//#include "Entry.cpp"
//#include "BNode.hpp"
#include "BNode.cpp"

template<class Entry>
class Binary_tree {
private:
	void copy(Binary_node<Entry> *&to, Binary_node<Entry> *from);
	int counting(Binary_node<Entry> *root1, int &cur) const;
	void clearing(Binary_node<Entry> *root1);
	int heighting(Binary_node<Entry> *root1, int cur, int ans) const;
	
protected:
	Binary_node<Entry> *root;

public:
	Binary_tree();
	Binary_tree(const Binary_tree<Entry> &original);
	Binary_tree & operator = (const Binary_tree<Entry> &original);
	
	Binary_node<Entry> *get_root();
	
	bool empty() const;
//	void inorder(void(*visit)(Entry &));
//	void preorder(void(*visit)(Entry &));
//	void postorder(void(*visit)(Entry &));
	void preorder(Binary_node<Entry> *root1);
	void inorder(Binary_node<Entry> *root1);
	void postorder(Binary_node<Entry> *root1);
	int size() const;
	void clear();
	int height() const;
	int left_height(Binary_node<Entry> *root1) const;		//AVL
	int right_height(Binary_node<Entry> *root1) const;		//AVL
	
	~Binary_tree();
};

//#endif
