#include "BST.hpp"

template<class Entry>
Result_code Search_tree<Entry>::insert(const Entry &new_entry) {
//	if(this->root == NULL)
//		cout << "i am blank" << endl;
//	this->inorder(this->root);
	return search_and_insert(this->root, new_entry);
}

//Binary_node<Entry> *&root1 参数应为 & 引用，否则 root 不变 
template<class Entry>
Result_code Search_tree<Entry>::search_and_insert(Binary_node<Entry> *&root1, const Entry &new_data) const {
	if(root1 == NULL) {
//		cout << "what the fuck" << endl;
		root1 = new Binary_node<Entry>(new_data);
//		if(root1 == NULL)
//			cout << "really" << endl;
		return success;
	}
	if(root1->data == new_data)
		return duplicate_error;
	if(root1->data > new_data) {
//		cout << root1->data << "  root1->data > new_data  " << new_data << endl;
		return search_and_insert(root1->left, new_data);
	} else {
//	cout << root1->data << "  root1->data < new_data  "  << new_data  << endl;	
		return search_and_insert(root1->right, new_data);
	}

//My version
//	Result_code result = success;
//	if(root1 == NULL) {
//		root1 = new Binary_node<Entry>(new_data);
//		return result;
//	}
//	if(tree_search(new_data) == success)
//		result = duplicate_error;
//	
//	Binary_node<Entry> *last;
//	int left_or_right = 0;
//	while(root1 != NULL) {
//		last = root1;
//		if(root1->data < new_data){
//			root1 = root1->right;
//			left_or_right = 1;
//		} else {
//			root1 = root1->left;
//			left_or_right = 0;
//		}
//	}
//	
//	if(left_or_right == 0)
//		last->left = new Binary_node<Entry>(new_data);
//	else
//		last->right = new Binary_node<Entry>(new_data);
//	return result;
}

template<class Entry>
Result_code Search_tree<Entry>::remove(Entry &old_entry) {
	return search_and_destory(this->root, old_entry);
}

template<class Entry>
Result_code Search_tree<Entry>::search_and_destory(Binary_node<Entry> *&root1, Entry &old_entry) {
	if(root1 == NULL)
		return not_present;
	if(root1->data == old_entry) {
		if(this->left_height(root1) >= this->right_height(root1)) {
//			cout << "left >= right   " << root1->data << endl;
			return remove_root_from_left(root1);
		}
		else {
//			cout << "left < right   " << root1->data << endl;
			return remove_root_from_right(root1);
		}
			
	}
	if(root1->data > old_entry)
		return search_and_destory(root1->left, old_entry);
	return search_and_destory(root1->right, old_entry);
}

template<class Entry>
Result_code Search_tree<Entry>::remove_root_from_right(Binary_node<Entry> *&root1) {
	Binary_node<Entry> *to_delete = root1;
	to_delete = root1->right; 
//	cout << "to_delete_right  " << to_delete->data << endl;
	Binary_node<Entry> *parent = root1;
	while(to_delete->left != NULL) {
		parent = to_delete;
		to_delete = to_delete->left;
	}
	root1->data = to_delete->data;
	if(parent == root1)		//which means root1->right->left == NULL
		parent->right = to_delete->right;
	else
		parent->left = to_delete->right;
	
//	cout << "to_delete_right_after  " << to_delete->data << endl;
	delete to_delete;
	return success;
}


template<class Entry>
Result_code Search_tree<Entry>::remove_root_from_left(Binary_node<Entry> *&root1) {
	if(root1->left == NULL) {	//左子树高度 >= 右子树高度时都删除左子树， 可能 left_height = right_height = 0 
		delete root1;
		root1 = NULL;
		return success;
	}
	
	Binary_node<Entry> *to_delete = root1;
	to_delete = root1->left;
//	cout << "to_delete_left  " << to_delete->data << endl;
	Binary_node<Entry> *parent = root1;
	while(to_delete->right != NULL) {
		parent = to_delete;
		to_delete = to_delete->right;
	}
	root1->data = to_delete->data;
	if(parent == root1)		//which means root1->left->right == NULL
		parent->left = to_delete->left;
	else
		parent->right = to_delete->left;

//	cout << "to_delete_left_after  " << to_delete->data << endl;
	delete to_delete;
	to_delete = NULL;
	return success;
}

template<class Entry>
Result_code Search_tree<Entry>::tree_search(const Entry &target) {
	Result_code result = success;
	Binary_node<Entry> *found = search_for_node(this->root, target);
	if(found == NULL)
		result = not_present;
//	cout << result << "    result    " << target << endl;
	return result;
}

//1.Recursive version
template<class Entry>
Binary_node<Entry> *Search_tree<Entry>::search_for_node(Binary_node<Entry> *root1, const Entry &target) {
	if(root1 == NULL || root1->data == target)
		return root1;
	if(root1->data < target)
		return search_for_node(root1->right, target);
	return search_for_node(root1->left, target);
}

//2.Nonrecursive version
// Binary_node<Entry> *root1 参数不应为引用， 否则每次查找 root 被改变 
//template<class Entry>
//Binary_node<Entry> *Search_tree<Entry>::search_for_node(Binary_node<Entry> *root1, const Entry &target) {
////	cout << root1->data << "   outside   " << target << endl;
//	while(root1 != NULL && root1->data != target) {
////		cout << root1->data << "  " << target << endl;
//		if(root1->data < target)
//			root1 = root1->right;
//		else
//			root1 = root1->left;
//	}
//	return root1;
//}
