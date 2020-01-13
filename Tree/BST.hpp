//#ifndef _H_BST
//#define _H_BST

//#include "Entry.cpp"
//#include "BNode.hpp"
//#include "BT.hpp"
#include "BT.cpp"

enum Result_code {
	success, fail, duplicate_error, not_present
};

template<class Entry>
class Search_tree: public Binary_tree<Entry> {
private:
	Binary_node<Entry> *search_for_node(Binary_node<Entry> *root1, const Entry &target);
	Result_code search_and_insert(Binary_node<Entry> *&root1, const Entry &new_data) const;
//	Result_code search_and_destory(Binary_node<Entry> *&root1, const Entry &new_data) const;
	Result_code search_and_destory(Binary_node<Entry> *&root1, Entry &old_entry);
	Result_code remove_root_from_right(Binary_node<Entry> *&root1);		//AVL
	Result_code remove_root_from_left(Binary_node<Entry> *&root1);		//AVL

public:
	Result_code insert(const Entry &new_entry);
//	Result_code remove(const Entry &old_entry);
	Result_code remove(Entry &old_entry);
	Result_code tree_search(const Entry &target);
};

//#endif
