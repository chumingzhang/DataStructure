#include<iostream>
#define Stack_entry int
using namespace std;

enum RESULT_CODE {
	success, fail, overflow, underflow
};

//�ն�ջ����indexָ���
class Stack
{
private:
	int sizes;					//������� 
	Stack_entry nums[100];		//���� 
	int index;					//��ǰλ�� 
	
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

