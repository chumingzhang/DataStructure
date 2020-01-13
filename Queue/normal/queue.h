#include<iostream>
#define Queue_entry int
using namespace std;

enum Result_code {
	success, fail, overflow, underflow
};

//˫��ѭ������ 
class Queue{
private:
	int total;				//������� 
	int front;				//��ǰͷλ�� 
	int rear;				//��ǰβλ��
	Queue_entry nums[100];	//����  
	
public:	
	Queue();
	Queue(const Queue_entry maxs);
	
	Result_code append(const Queue_entry &item);
	Result_code serve();
	int retrieve();
	int serve_retrieve();
	bool empty();
	bool full();
	int size() const;
	void printf();
	void clear();
};

