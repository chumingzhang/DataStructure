#include "queue_link.h"

Queue::Queue() {
	front = rear = NULL;
}

Queue::Queue(const Queue &original) {
	//ֻ�ж�һ���Ϳ��� 
	if(original.front == NULL || original.rear == NULL)
		front = rear = NULL;
	
	Node *original_node = original.front;
	front = rear = new Node(original_node->entry);
	while(original_node->next != NULL) {
		original_node = original_node->next;
		rear->next = new Node(original_node->entry);
		rear = rear->next;
	} 
}

Result_code Queue::append(const Queue_entry &item) {
	Node *new_node = new Node(item);
	if(new_node == NULL) {
		cout << "��ǰ��������" << endl;
		return overflow;
	}
	
	//ͷβ��Ϊ new_node 
	if(rear == NULL)
		front = rear = new_node;
		
	rear->next = new_node;
	rear = rear->next;
	return success;
}

Result_code Queue::serve() {
	if(front == NULL) {
		cout << "��ǰ����Ϊ��" << endl;
		return overflow;
	}
	
	front = front->next;
	if(front == NULL)	//don's forget
		rear = NULL;
	return success;
}

int Queue::retrieve() {
	if(front == NULL) {
		cout << "��ǰ����Ϊ��" << endl;
		return overflow;
	}
	return front->entry;
}

int Queue::serve_retrieve() {
	if(front == NULL) {
		cout << "��ǰ����Ϊ��" << endl;
		return overflow;
	}
	
	int temp = front->entry;
	front = front->next;
	if(front == NULL)
		rear = NULL;
	return temp;
}

//x = y�� ���� y ����ɾ�� x ������ֵ 
Result_code Queue::operator = (const Queue &original) {
	//ֻ�ж�һ���Ϳ��� 
	if(original.front == NULL || original.rear == NULL)
		front = rear = NULL;		
	
	//���� original 
	Node *original_node = original.front;
	Node *temp_front, *temp_rear;
	temp_front = temp_rear = new Node(original_node->entry);
	while(original_node->next != NULL) {
		original_node = original_node->next;
		temp_rear->next = new Node(original_node->entry);
		temp_rear = temp_rear->next;
	}
	
	//ɾ�� this 
	while(empty() == false)
		serve();
	
	 //this = original
	 front = temp_front;
	 rear = temp_rear;
	 return success; 
}

bool Queue::empty() {
//	if(size() == 0) {
//		cout << "��ǰ����Ϊ��" << endl;
//		return true; 
//	}
//	cout << "��ǰ���в�Ϊ��" << endl;
//	return false;
	if(front == NULL && rear == NULL) {
		cout << "��ǰ����Ϊ��" << endl;
		return true; 
	}
	cout << "��ǰ���в�Ϊ��" << endl;
	return false;
}

int Queue::size() const {
	int count = 0;
	Node *temp = front;
	//���� while(temp != NULL) 
	while(temp != rear) {
		count++;
		temp = temp->next;
	}
	return count;
}

void Queue::printf() {
	cout << "��ǰ����: " << size();
	if(front != NULL && rear != NULL)	//ֻ�ж�һ������ 
		cout << "  ��ǰͷ:  " << front->entry << "  ��ǰβ:  " << rear->entry << endl;
	Node *temp = front;
	//���� while(temp != NULL) 
	while(temp != NULL) {
		cout << temp->entry << " ";
		temp = temp->next;
	}
	cout << endl;
}

Queue::~Queue() {
	while(!empty())
		serve();
}
