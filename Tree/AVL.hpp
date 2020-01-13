//#ifndef _H_AVL
//#define _H_AVL

//The AVL tree which means that |height of left-subtree - height of right-subtree| <= 1

//The worst AVL tree——Fibonacci trees
//has the height = 1.44log(n)——base is 2 

//The average height of the random binary search tree is 1.39log(n)
//The average height of the AVL tree is log(n)+0.25

//#include "Entry.cpp"
//#include "BNode.hpp"
//#include "BT.hpp"
//#include "BST.hpp"
//#include "AVL_node.hpp"
#include "AVL_node.cpp"

template<class Entry>
class AVL_tree: public Search_tree<Entry> {
private:
	Result_code avl_insert(Binary_node<Entry> *&root1, const Entry &new_data, bool &taller);
	void left_balance(Binary_node<Entry> *&root1);	//左边太大需要平衡 
	void right_balance(Binary_node<Entry> *&root1);	//右边太大需要平衡 
	void rotate_left(Binary_node<Entry> *&root1);	//向左旋转，root1作为被移动的最高级顶点 
	void rotate_right(Binary_node<Entry> *&root1);	//向右旋转，root1作为被移动的最高级顶点 
	Result_code avl_remove(Binary_node<Entry> *&root1, const Entry &old_data, bool &shorter);
public:
	Result_code insert(const Entry &new_data);
	Result_code balance_remove(const Entry &old_data);
};

//#endif
