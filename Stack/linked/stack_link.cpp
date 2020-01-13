#include "stack_link.h"

Stack::Stack() {
	top_node = NULL;
}

Stack::Stack(const Stack &original) {
	if(original.top_node == NULL)
		top_node = NULL;

	Node *original_node = original.top_node;
	Node *new_top, *tail;
	new_top = tail = new Node(original_node->entry);
	while(original_node->next != NULL) {
		original_node = original_node->next;
		tail->next = new Node(original_node->entry);
		tail = tail->next; 
	}
	top_node = new_top;
}

Result_code Stack::push(const Stack_entry &item) {
	Node *new_top = new Node(item, top_node);
	if(new_top == NULL) {
		cout << "��ǰ��ջ����" << endl;
		return overflow; 
	}
	
	top_node = new_top;
	return success;
}

Result_code Stack::pop() {
	if(top_node == NULL) {
		cout << "��ǰ��ջΪ��" << endl; 
		return underflow;
	}
	
	top_node = top_node->next;
	return success;
}

Result_code Stack::empty() {
	if(top_node == NULL) {
		cout << "��ǰ��ջΪ��" << endl; 
		return success;
	}

	cout << "��ǰ��ջ��Ϊ��" << endl; 
	return fail;
}

Stack_entry Stack::top() {
	if(top_node == NULL) {
		cout << "��ǰ��ջΪ��" << endl; 
		return -1;
	}
	return top_node->entry;
} 

Stack_entry Stack::pop_top() {
	if(top_node == NULL) {
		cout << "��ǰ��ջΪ��" << endl; 
		return -1;
	}
	Stack_entry result = top_node->entry;
	top_node = top_node->next;
	return result;
}

int Stack::size() {
	int count = 0;
	Node *count_top = top_node;
	while(count_top != NULL) {
		count++;
		count_top = count_top->next;
	}
	return count;
}

void Stack::printf() {
	cout << "��ǰ����Ϊ�� " << this->size() << endl; 
	
	Node *temp_top = top_node;
	while(temp_top != NULL) {
		cout << temp_top->entry << " ";
		temp_top = temp_top->next;
	}
	cout << endl;
}

//���� = ������ 
void Stack::operator = (const Stack &original) {
	//����1�� copyY -> deleteX -> X = Y �������ڿ������캯��
	//����2�� ֱ�� X = Y
	if(original.top_node == NULL) {
		while(empty() == fail)
			pop();
	}
	
	Node *now_node = top_node, *original_node = original.top_node;
	//���߶���Ϊ��,ֱ�Ӹ�ֵ 
	while(original_node->next != NULL && now_node->next != NULL) {
		now_node->entry = original_node->entry;
		original_node = original_node->next;
		now_node = now_node->next;		
	}
	now_node->entry = original_node->entry;
	
	//1 �� 2 ������ͬʱ���� 
	//1.�����Ѿ�Ϊ��,��������Ҫ������	
	while(original_node->next != NULL) {
		now_node->next = new Node(original_node->next->entry);
		original_node  = original_node->next;
		now_node = now_node->next;
	}
	
	//2.�����Ѿ�����,������Ϊ��
	while(now_node->next != NULL) {
		Node *delete_node = now_node->next;
//		now_node->next = NULL; 
		delete now_node;
		now_node = delete_node; 
	}
	//���������һ�� 
	delete now_node;
}

Stack::~Stack() {
	while(empty() == fail)
		pop();
	delete top_node;
}
