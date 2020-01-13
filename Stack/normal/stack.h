#include<iostream>
#define Stack_entry int
using namespace std;

enum RESULT_CODE {
	success, fail, overflow, underflow
};

//空堆栈——index指向空
class Stack
{
private:
	int sizes;					//最大容量 
	Stack_entry nums[100];		//容器 
	int index;					//当前位置 
	
public:
	Stack(int maxs);
	RESULT_CODE push(int num);
	RESULT_CODE pop();
	RESULT_CODE empty();
	int top();
	int pop_top();
	int size();
	void printf();
};

