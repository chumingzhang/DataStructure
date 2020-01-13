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
	
	//�����У���++�ٸ�ֵ������β����� 
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
		cout << "����Ϊ��" << endl;
		return true; 
	}
	cout << "���в�Ϊ��" << endl; 
	return false;
}

bool Queue::full() {
	if(this->size() == total - 1) {
		cout << "��������" << endl;
		return true;
	}
	cout << "����δ��" << endl;
	return false;
}

int Queue::size() const {
	return (total + rear - front + 1) % total;
}

void Queue::printf() {
	cout << "�������: " << total << "  ��ǰ����: " << this->size();
	cout << "  ��ǰͷ: " << front << "  ��ǰβ: " << rear << endl;
	for(int i = 0; i < this->size(); ++i)
		cout << nums[i] << " ";
	cout << endl; 
}

void Queue::clear() {
	front = 0;
	rear = total - 1;
}
