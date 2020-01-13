#include "AVL.hpp"

template<class Entry>
Result_code AVL_tree<Entry>::insert(const Entry &new_data) {
	bool taller;
	return avl_insert(this->root, new_data, taller);
}

template<class Entry>
Result_code AVL_tree<Entry>::avl_insert(Binary_node<Entry> *&root1, const Entry &new_data, bool &taller) {
	if(root1 == NULL) {
		root1 = new AVL_node<Entry>(new_data);
		taller = true;
		return success;
	}
	if(new_data == root1->data) {
		taller = false;
		return duplicate_error;
	}
	
	Result_code result = success;
	if(new_data < root1->data) {
		result = avl_insert(root1->left, new_data, taller);
		if(taller == true) {
			switch(root1->get_balance()) {
				case left_higher:
					left_balance(root1);
					taller = false;
					break;
				case equal_height:
					root1->set_balance(left_higher);
					break;
				case right_higher:
					root1->set_balance(equal_height);
					taller = false;
					break;
			}
		}
		return result;
	} else {
		result = avl_insert(root1->right, new_data, taller);
		if(taller == true) {
			switch(root1->get_balance()) {
				case left_higher:
					root1->set_balance(equal_height);
					taller = false;
					break;
				case equal_height:
					root1->set_balance(right_higher);
					break;
				case right_higher:
					right_balance(root1);
					taller = false;
					break;
			}
		}
		return result;
	}
}


//向右移动 
template<class Entry>
void AVL_tree<Entry>::left_balance(Binary_node<Entry> *&root1) {
//Binary_node<Entry> *&ltree  一定是引用，因为可能会被传参到 rotate 
	Binary_node<Entry> *&ltree = root1->left;
	switch(ltree->get_balance()) {
		case left_higher:		//single rotation right
			root1->set_balance(equal_height);
			ltree->set_balance(equal_height);
			rotate_right(root1);
			break;
		case right_higher:
//Binary_node<Entry> *&stree  不是引用，因为不会被传参 
			Binary_node<Entry> *stree = ltree->right;
			switch(stree->get_balance()) {
				case left_higher:
					root1->set_balance(right_higher);
					ltree->set_balance(equal_height);
					break;
				case equal_height:
					root1->set_balance(equal_height);
					ltree->set_balance(equal_height);
					break;
				case right_higher:
					root1->set_balance(equal_height);
					ltree->set_balance(left_higher);
					break;
			}
			stree->set_balance(equal_height);
			rotate_left(ltree);
			rotate_right(root1);
			break;
	}
}

template<class Entry>
void AVL_tree<Entry>::right_balance(Binary_node<Entry> *&root1) {
//Binary_node<Entry> *&rtree  一定是引用，因为可能会被传参到 rotate 
	Binary_node<Entry> *&rtree = root1->right;
	switch(rtree->get_balance()) {
		case right_higher:		//single rotation left
			root1->set_balance(equal_height);
			rtree->set_balance(equal_height);
			rotate_left(root1);
			break;
		case left_higher:		//double rotation left
//Binary_node<Entry> *&stree  不是引用，因为不会被传参 
			Binary_node<Entry> *stree = rtree->left;
			switch(stree->get_balance()) {
				case right_higher:
					root1->set_balance(left_higher);
					rtree->set_balance(equal_height);
					break;
				case equal_height:		//stree一定还有左右子节点，否则不需要旋转 
					root1->set_balance(equal_height);
					rtree->set_balance(equal_height);
					break;
				case left_higher:
					root1->set_balance(equal_height);
					rtree->set_balance(right_higher);
					break;
			}
			stree->set_balance(equal_height);
			rotate_right(rtree);
			rotate_left(root1);
			break;
	}
}

template<class Entry>
void AVL_tree<Entry>::rotate_left(Binary_node<Entry> *&root1) {
	Binary_node<Entry> *rtree = root1->right;
	root1->right = rtree->left;
	rtree->left = root1; 
	root1 = rtree;
}

template<class Entry>
void AVL_tree<Entry>::rotate_right(Binary_node<Entry> *&root1) {
	Binary_node<Entry> *ltree = root1->left;
	root1->left = ltree->right;
	ltree->right = root1;
	root1 = ltree;
}

template<class Entry>
Result_code AVL_tree<Entry>::balance_remove(const Entry &old_data) {
	bool shorter;
	return avl_remove(this->root, old_data, shorter);
}

template<class Entry>
Result_code AVL_tree<Entry>::avl_remove(Binary_node<Entry> *&root1, const Entry &old_data, bool &shorter) {
	if(root1 == NULL) {
		shorter = false;
		return not_present;
	}
	if(root1->data == old_data) {
		this->remove(root1->data); 
		shorter = true;
		return success;
	}
	Result_code result = success;
	if(root1->data < old_data) {
		result = avl_remove(root1->right, old_data, shorter);
		if(shorter == true) {
			switch(root1->get_balance()) {
				case left_higher:{ 		//当case块过大且里面有定义新变量时用括号括起明确变量生命域 
					Binary_node<Entry> *&ltree = root1->left;
					switch(ltree->get_balance()) {
						case right_higher:{		//double rotation left 		//当case块过大且里面有定义新变量时用括号括起明确变量生命域  
							Binary_node<Entry> *stree = ltree->right;
							switch(stree->get_balance()) {
								case left_higher:
									root1->set_balance(right_higher);
									ltree->set_balance(equal_height);
									break;
								case equal_height:
									root1->set_balance(equal_height);
									ltree->set_balance(equal_height);
									break;
								case right_higher:
									root1->set_balance(equal_height);
									ltree->set_balance(left_higher);
									break;
							}
							stree->set_balance(equal_height);
							rotate_left(ltree);
							rotate_right(root1);
//							shorter = true;
							break;
						} 
						case equal_height:		//single rotation left
							ltree->set_balance(right_higher);
							rotate_right(root1);
							shorter = false;
							break;
						case left_higher:
							root1->set_balance(equal_height);
							ltree->set_balance(equal_height);
							rotate_right(root1);
//							shorter = true;		//no change
							break;
					}
					break;
				} 
				case equal_height:
					root1->set_balance(left_higher);
					shorter = false;
					break;
				case right_higher:
					root1->set_balance(equal_height);
//					shorter = true;		//no change
					break;
			}
		}
		return result;
	} else {
		result = avl_remove(root1->left, old_data, shorter);
		if(shorter == true) {
			switch(root1->get_balance()) {
				case left_higher:
					root1->set_balance(equal_height);
					break;
				case equal_height:
					root1->set_balance(right_higher);
					shorter = false;
					break;
				case right_higher: { 		//当case块过大且里面有定义新变量时用括号括起明确变量生命域  
					Binary_node<Entry> *&rtree = root1->right;
					switch(rtree->get_balance()) {
						case left_higher:{		//double rotation left 		//当case块过大且里面有定义新变量时用括号括起明确变量生命域 
							Binary_node<Entry> *stree = rtree->left;
							switch(stree->get_balance()) {
								case left_higher:
									root1->set_balance(equal_height);
									rtree->set_balance(right_higher);
									break;
								case equal_height://如果stree的左右子树高度都为 h-2, 则 rtree 不会left_higher 
									root1->set_balance(equal_height);
									rtree->set_balance(equal_height);
									break;
								case right_higher:
									root1->set_balance(left_higher);
									rtree->set_balance(equal_height);
									break;
							}
							stree->set_balance(equal_height);
							rotate_right(rtree);
							rotate_left(root1);
//							shorter = true;
							break;
						} 
						case equal_height:		//single rotation left
							rtree->set_balance(left_higher);
							rotate_left(root1);
							shorter = false;
							break;
						case right_higher:
							root1->set_balance(equal_height);
							rtree->set_balance(equal_height);
							rotate_left(root1);
//							shorter = true;		//no change
							break;
					}
					break;
				} 
			}
		}
		return result;
	}
}
