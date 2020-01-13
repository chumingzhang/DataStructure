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
		cout << "当前堆栈已满" << endl;
		return overflow; 
	}
	
	top_node = new_top;
	return success;
}

Result_code Stack::pop() {
	if(top_node == NULL) {
		cout << "当前堆栈为空" << endl; 
		return underflow;
	}
	
	top_node = top_node->next;
	return success;
}

Result_code Stack::empty() {
	if(top_node == NULL) {
		cout << "当前堆栈为空" << endl; 
		return success;
	}

	cout << "当前堆栈不为空" << endl; 
	return fail;
}

Stack_entry Stack::top() {
	if(top_node == NULL) {
		cout << "当前堆栈为空" << endl; 
		return -1;
	}
	return top_node->entry;
} 

Stack_entry Stack::pop_top() {
	if(top_node == NULL) {
		cout << "当前堆栈为空" << endl; 
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
	cout << "当前容量为： " << this->size() << endl; 
	
	Node *temp_top = top_node;
	while(temp_top != NULL) {
		cout << temp_top->entry << " ";
		temp_top = temp_top->next;
	}
	cout << endl;
}

//重载 = 操作符 
void Stack::operator = (const Stack &original) {
	//方法1： copyY -> deleteX -> X = Y ，类似于拷贝构造函数
	//方法2： 直接 X = Y
	if(original.top_node == NULL) {
		while(empty() == fail)
			pop();
	}
	
	Node *now_node = top_node, *original_node = original.top_node;
	//两边都不为空,直接赋值 
	while(original_node->next != NULL && now_node->next != NULL) {
		now_node->entry = original_node->entry;
		original_node = original_node->next;
		now_node = now_node->next;		
	}
	now_node->entry = original_node->entry;
	
	//1 和 2 不可能同时发生 
	//1.本身已经为空,还有数据要传进来	
	while(original_node->next != NULL) {
		now_node->next = new Node(original_node->next->entry);
		original_node  = original_node->next;
		now_node = now_node->next;
	}
	
	//2.数据已经传完,本身还不为空
	while(now_node->next != NULL) {
		Node *delete_node = now_node->next;
//		now_node->next = NULL; 
		delete now_node;
		now_node = delete_node; 
	}
	//别忘了最后一个 
	delete now_node;
}

Stack::~Stack() {
	while(empty() == fail)
		pop();
	delete top_node;
}
