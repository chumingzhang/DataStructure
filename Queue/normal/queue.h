#include<iostream>
#define Queue_entry int
using namespace std;

enum Result_code {
	success, fail, overflow, underflow
};

//双向循环队列 
class Queue{
private:
	int total;				//最大容量 
	int front;				//当前头位置 
	int rear;				//当前尾位置
	Queue_entry nums[100];	//容器  
	
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

