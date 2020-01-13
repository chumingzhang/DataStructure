#include "slink.cpp"
#define Stack_entry int

enum Result_code {
	success, fail, overflow, underflow
};

class Stack
{
public:
	Node *top_node;
	
	Stack();
	Stack(const Stack &original); 
	Result_code push(const Stack_entry &item);
	Result_code pop();
	Result_code empty();
	Stack_entry top();
	Stack_entry pop_top();
	int size();
	void printf();
	//ÖØÔØ = ²Ù×÷·û 
	void operator = (const Stack &original);
	~Stack();
};
