#include "qlink.cpp"
#define Queue_entry int

enum Result_code {
	success, fail, overflow, underflow
};

class Queue{
private:
	Node *front, *rear;
	
public:
	Queue();
	Queue(const Queue &original);
	Result_code append(const Queue_entry &item);
	Result_code serve();
	int retrieve();
	int serve_retrieve();
	Result_code operator = (const Queue &original);
	bool empty();
	int size() const;
	void printf();
	~Queue();
};

