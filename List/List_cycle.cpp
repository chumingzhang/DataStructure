#include "list.h"

List::List() {
	root = new Node;
	root->prev = root;
	root->next = root;
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
	
	if(pos == 0) {		//�����ͷ������root 
		new_add->next = root;
		new_add->prev = root->prev;
		root->prev->next = new_add;
		root->prev = new_add;
		root = new_add;			//����root 
		return success;
	}

	//tempΪ pos - 1��λ�ã����õ�ǰλ�ã���Ϊ��ǰλ�ÿ���Ϊ�գ�β���룩 
	Node *temp = get_by_pos(pos - 1);
	new_add->next = temp->next;
	new_add->prev = temp;
	temp->next->prev = new_add;
	temp->next = new_add;
	return success;
}

Result_code List::erase(const Node_entry move) {
	Node *temp = get_by_num(move);
	if(temp == NULL)
		return fail;
	
	temp->prev->next = temp->next;
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

Node* List::get_by_pos(const int pos) {		//pos��0��ʼ 
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
	int first = 0;	//�ж��ǲ��ǵ�һ��ѭ�� 
	Node *find = root;
	while(find != root || first == 0) {
		first = 1;
		if(find->entry == num)
			return find;
		find = find->next;
	}
	return NULL;
}

int List::size()const {
	int count = 0;
	Node *temp = root;
	while(temp != root || count == 0){
		count++;
		temp = temp->next;
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
	int count = 0;
	Node *to_print = root;
	while(to_print != root || count == 0) {
		cout << to_print->entry << " ";
		count++;
		to_print = to_print->next;
	}
	cout << endl << "����Ĵ�СΪ�� " << count << endl;
}

List::~List() {
	delete root;
}
