#include "queue_link.h"

Queue::Queue() {
	front = rear = NULL;
}

Queue::Queue(const Queue &original) {
	//只判断一个就可以 
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
		cout << "当前队列已满" << endl;
		return overflow;
	}
	
	//头尾都为 new_node 
	if(rear == NULL)
		front = rear = new_node;
		
	rear->next = new_node;
	rear = rear->next;
	return success;
}

Result_code Queue::serve() {
	if(front == NULL) {
		cout << "当前队列为空" << endl;
		return overflow;
	}
	
	front = front->next;
	if(front == NULL)	//don's forget
		rear = NULL;
	return success;
}

int Queue::retrieve() {
	if(front == NULL) {
		cout << "当前队列为空" << endl;
		return overflow;
	}
	return front->entry;
}

int Queue::serve_retrieve() {
	if(front == NULL) {
		cout << "当前队列为空" << endl;
		return overflow;
	}
	
	int temp = front->entry;
	front = front->next;
	if(front == NULL)
		rear = NULL;
	return temp;
}

//x = y， 复制 y ——删除 x ——赋值 
Result_code Queue::operator = (const Queue &original) {
	//只判断一个就可以 
	if(original.front == NULL || original.rear == NULL)
		front = rear = NULL;		
	
	//复制 original 
	Node *original_node = original.front;
	Node *temp_front, *temp_rear;
	temp_front = temp_rear = new Node(original_node->entry);
	while(original_node->next != NULL) {
		original_node = original_node->next;
		temp_rear->next = new Node(original_node->entry);
		temp_rear = temp_rear->next;
	}
	
	//删除 this 
	while(empty() == false)
		serve();
	
	 //this = original
	 front = temp_front;
	 rear = temp_rear;
	 return success; 
}

bool Queue::empty() {
//	if(size() == 0) {
//		cout << "当前队列为空" << endl;
//		return true; 
//	}
//	cout << "当前队列不为空" << endl;
//	return false;
	if(front == NULL && rear == NULL) {
		cout << "当前队列为空" << endl;
		return true; 
	}
	cout << "当前队列不为空" << endl;
	return false;
}

int Queue::size() const {
	int count = 0;
	Node *temp = front;
	//或者 while(temp != NULL) 
	while(temp != rear) {
		count++;
		temp = temp->next;
	}
	return count;
}

void Queue::printf() {
	cout << "当前容量: " << size();
	if(front != NULL && rear != NULL)	//只判断一个即可 
		cout << "  当前头:  " << front->entry << "  当前尾:  " << rear->entry << endl;
	Node *temp = front;
	//或者 while(temp != NULL) 
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
