#include "queue.h"

Queue::Queue() {
	total = 10;
	front = 0;
	rear = total - 1;
}

Queue::Queue(const Queue_entry maxs) {
	total = maxs;
	front = 0;
	rear = total - 1;
}

Result_code Queue::append(const Queue_entry &item) {
	if(this->full())
		return overflow;
	
	//满队列（先++再赋值），从尾部添加 
	rear = (rear + 1) % total;
	nums[rear] = item;
	return success; 
}

Result_code Queue::serve() {
	if(this->empty())
		return underflow;
		
	front = (front + 1) % total;
	return success; 
}

int Queue::retrieve(){
	if(this->empty())
		return -1;
		
	return nums[front];
}

int Queue::serve_retrieve() {
	if(this->empty())
		return -1;
		
	int result = nums[front];
	front = (front + 1) % total;
	return result;
}

bool Queue::empty() {
	if(this->size() == 0) {
		cout << "队列为空" << endl;
		return true; 
	}
	cout << "队列不为空" << endl; 
	return false;
}

bool Queue::full() {
	if(this->size() == total - 1) {
		cout << "队列已满" << endl;
		return true;
	}
	cout << "队列未满" << endl;
	return false;
}

int Queue::size() const {
	return (total + rear - front + 1) % total;
}

void Queue::printf() {
	cout << "最大容量: " << total << "  当前容量: " << this->size();
	cout << "  当前头: " << front << "  当前尾: " << rear << endl;
	for(int i = 0; i < this->size(); ++i)
		cout << nums[i] << " ";
	cout << endl; 
}

void Queue::clear() {
	front = 0;
	rear = total - 1;
}
