#include "List.h"

List::List() {
	root = new Node;
}

Result_code List::insert(const Node_entry &add, int pos) {
	if(pos < 0)
		return underflow;
	else if(pos > this->size() + 1)
		return overflow;
	
	Node *new_add = new Node;
	if(new_add == NULL)		//判断是否申请成功 
		return overflow;
	new_add->entry = add;
	
	//如果在头部插入 
	if(pos == 0) {
		new_add->next = root;
		root->prev = new_add;
		root = new_add;
		return success;
	} else {
		//temp为 pos - 1的位置，不用当前位置，因为当前位置可能为空（尾插入） 
		Node *temp = get_by_pos(pos - 1);
		
		new_add->next = temp->next;
		new_add->prev = temp;
		if(temp->next != NULL)
			temp->next->prev = new_add;
		temp->next = new_add;
		return success;
	}
}

Result_code List::erase(const Node_entry move) {
	Node *temp = get_by_num(move);
	if(temp == NULL)
		return fail;
	
	//判断是否为头节点,头节点无 prev 
	if(temp->prev != NULL) 
		temp->prev->next = temp->next;
	else
		root = temp->next;
	
	//同理，判断是否为尾节点，尾节点无 next 
	if(temp->next != NULL) 
		temp->next->prev = temp->prev;
		
	delete temp;
	return success;
}

Result_code List::replace(const Node_entry &add, int pos) {
	Node *temp = get_by_pos(pos);
	if(temp == NULL)
		return fail;
		
	temp->entry = add;
	return success;
} 

//pos从0开始 
Node* List::get_by_pos(const int pos) {
	if(pos < 0 || pos >= size())
		return NULL;
	
	int count = 0;
	Node *find = root;
	while(count < pos && find != NULL) {
		count++;
		find = find->next;
	}
	return find;
}

Node* List::get_by_num(const Node_entry num) {
	Node *find = root;
	while(find != NULL) {
		if(find->entry == num)
			return find;
		find = find->next;
	}
	return NULL;
}

int List::size()const {
	int count = 0;
	Node *to_count = root;
	while(to_count != NULL) {
		count++;
		to_count = to_count->next;
	}
	return count;
}

bool List::empty() const {
	if(this->size() == 0) {
		cout << "当前链表为空" << endl;
		return true; 
	}
	cout << "当前链表不为空" << endl;
	return false;
}

void List::clear() {
	Node *to_delete = root;
	while(root != NULL) {
		root = root->next;
		delete to_delete;
		to_delete = root;
	}
}

void List::show() {
	cout << "当前链表大小为: " << size() << endl;
	
	Node *to_print = root;
	while(to_print != NULL) {
		cout << to_print->entry << " ";
		to_print = to_print->next;
	}
	cout << endl;
}

List::~List() {
	delete root;
}
