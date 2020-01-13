#include<list>
#include "BST.cpp"

template<class Entry>
class Buildable_tree: public Search_tree<Entry> {
private:
	
public:
	Result_code build_tree(const list<Entry> &supply);
	void build_insert(int count, const Entry &new_Data, list<Binary_node<Entry>*> &last_node);
	Binary_node<Entry>* find_root(list<Binary_node<Entry>*> &last_node);
	void connect_trees(const list<Binary_node<Entry>*> &last_node);
}; 
