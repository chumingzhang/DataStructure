#include "BT.hpp"
#define MAX(a, b) (a) > (b) ? a : b

template<class Entry>
Binary_tree<Entry>::Binary_tree() {
	root = NULL;
}

template<class Entry>
Binary_tree<Entry>::Binary_tree(const Binary_tree<Entry> &original) {
	(*this) = original;
}

template<class Entry>
Binary_tree<Entry> & Binary_tree<Entry>::operator = (const Binary_tree<Entry> &original) {
	Binary_node<Entry> *temp1 = original.root;
	Binary_node<Entry> *temp2 = new Binary_node<Entry>();
	copy(temp2, temp1);
	root = temp2;
}

template<class Entry>
void Binary_tree<Entry>::copy(Binary_node<Entry> *&to, Binary_node<Entry> *from) {
	if(from != NULL) {
		to->data = from->data;
		
		if(from->left != NULL)
			to->left = new Binary_node<Entry>();
		copy(to->left, from->left);
		if(from->right != NULL)
			to->right = new Binary_node<Entry>();
		copy(to->right, from->right);
	}
}


template<class Entry>
Binary_node<Entry> *Binary_tree<Entry>::get_root() {
	return root;
}

template<class Entry>
void Binary_tree<Entry>::preorder(Binary_node<Entry> *root1) {
	if(root1 != NULL) {
		cout << root1->data << " ";
		preorder(root1->left);
		preorder(root1->right);
	}
}

template<class Entry>
void Binary_tree<Entry>::inorder(Binary_node<Entry> *root1) {
	if(root1 != NULL) {
		inorder(root1->left);
		cout << root1->data << " ";
		inorder(root1->right);
	}
//	if(root1 != NULL) {
//		inorder(root1->left);
//		cout << "当前节点为： " << root1->data;
//		if(root1->left != NULL)
//			cout << "  左节点为： " << root1->left->data;
//		if(root1->right != NULL)
//			cout << "  右节点为： " << root1->right->data;
//		cout << endl << endl;
//		inorder(root1->right);
//	}
}

template<class Entry>
void Binary_tree<Entry>::postorder(Binary_node<Entry> *root1) {
	if(root1 != NULL) {
		postorder(root1->left);
		postorder(root1->right);
		cout << root1->data << " ";
	}
}

template<class Entry>
int Binary_tree<Entry>::size() const {
	int cur = 0;
	int count = counting(root, cur);	//直接传 0 不会被认为是 int &， 所以设置变量 cur
	return count;
}

//常量参数只能调用常量成员函数，所以函数最后加 const 
template<class Entry>
int Binary_tree<Entry>::counting(Binary_node<Entry> *root1, int &cur) const{
	if(root1 == NULL)
		return cur;
	else {
		cur++;
		counting(root1->left, cur);
		counting(root1->right, cur);
	}
	return cur;
}


template<class Entry>
void Binary_tree<Entry>::clear() {
	clearing(this->root);
	root = NULL;
}

template<class Entry>
void Binary_tree<Entry>::clearing(Binary_node<Entry> *root1) {
	if(root1 != NULL) {
		clearing(root1->left);
		clearing(root1->right);
		delete root1;
		root1 = NULL;	//置为空，防止野指针 
	}
}

template<class Entry>
int Binary_tree<Entry>::height() const {
	int ans = heighting(this->root, 0, 0);
	return ans;
} 

template<class Entry>
int Binary_tree<Entry>::left_height(Binary_node<Entry> *root1) const {
	if(root1 == NULL)
		return 0;
	int ans = heighting(root1->left, 0, 0);
	return ans;
}

template<class Entry>
int Binary_tree<Entry>::right_height(Binary_node<Entry> *root1) const {
	if(root1 == NULL)
		return 0;
	int ans = heighting(root1->right, 0, 0);
	return ans;
}

template<class Entry>
int Binary_tree<Entry>::heighting(Binary_node<Entry> *root1, int cur, int ans) const {
	if(root1 == NULL)
		return ans = MAX(ans, cur);
	else {
		ans = max(ans, heighting(root1->left, cur + 1, ans));
		ans = max(ans, heighting(root1->right, cur + 1, ans));
	}
	return ans;
}

template<class Entry>
bool Binary_tree<Entry>::empty() const {
	return root == NULL;
}

template<class Entry>
Binary_tree<Entry>::~Binary_tree() {
	delete root;
}
