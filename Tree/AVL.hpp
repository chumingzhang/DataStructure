//#ifndef _H_AVL
//#define _H_AVL

//The AVL tree which means that |height of left-subtree - height of right-subtree| <= 1

//The worst AVL tree����Fibonacci trees
//has the height = 1.44log(n)����base is 2 

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
	void left_balance(Binary_node<Entry> *&root1);	//���̫����Ҫƽ�� 
	void right_balance(Binary_node<Entry> *&root1);	//�ұ�̫����Ҫƽ�� 
	void rotate_left(Binary_node<Entry> *&root1);	//������ת��root1��Ϊ���ƶ�����߼����� 
	void rotate_right(Binary_node<Entry> *&root1);	//������ת��root1��Ϊ���ƶ�����߼����� 
	Result_code avl_remove(Binary_node<Entry> *&root1, const Entry &old_data, bool &shorter);
public:
	Result_code insert(const Entry &new_data);
	Result_code balance_remove(const Entry &old_data);
};

//#endif
