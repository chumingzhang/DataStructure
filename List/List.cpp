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
	if(new_add == NULL)		//�ж��Ƿ�����ɹ� 
		return overflow;
	new_add->entry = add;
	
	//�����ͷ������ 
	if(pos == 0) {
		new_add->next = root;
		root->prev = new_add;
		root = new_add;
		return success;
	} else {
		//tempΪ pos - 1��λ�ã����õ�ǰλ�ã���Ϊ��ǰλ�ÿ���Ϊ�գ�β���룩 
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
	
	//�ж��Ƿ�Ϊͷ�ڵ�,ͷ�ڵ��� prev 
	if(temp->prev != NULL) 
		temp->prev->next = temp->next;
	else
		root = temp->next;
	
	//ͬ���ж��Ƿ�Ϊβ�ڵ㣬β�ڵ��� next 
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

//pos��0��ʼ 
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
		cout << "��ǰ����Ϊ��" << endl;
		return true; 
	}
	cout << "��ǰ����Ϊ��" << endl;
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
	cout << "��ǰ�����СΪ: " << size() << endl;
	
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
