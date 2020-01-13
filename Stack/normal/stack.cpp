#include "stack.h"

Stack::Stack(int maxs) {
	sizes = maxs;
	index = 0;
}

RESULT_CODE Stack::push(int num) {
	if(index >= sizes) {
		cout << "��ǰ��������!" << endl;
		return overflow;
	} 
	
	nums[index] = num;
	index++;
	return success;
}

RESULT_CODE Stack::pop() {
	if(index <= 0) { 
		cout << "��ǰ����Ϊ��!" << endl;
		return underflow;
	} 
	
	index--;
	return success;
}

RESULT_CODE Stack::empty() {
	if(index == 0) {
		cout << "��ǰ����Ϊ��!" << endl; 
		return success;
	}
	
	cout << "��ǰ������Ϊ��!" << endl; 
	return fail;
}

int Stack::top() {
	if(index == 0) { 
		cout << "��ǰ����Ϊ��!" << endl;
		return underflow;
	} 
	return nums[index - 1];	//�ն�ջ 
}

int Stack::pop_top() {
	if(index == 0) { 
		cout << "��ǰ����Ϊ��!" << endl;
		return 0;
	} 
	int result = nums[index - 1];
	index--;
	return result;
}

int Stack::size() {
	return index;
}

void Stack::printf() {
	cout << "�������: " << sizes << "  ��ǰ����: " << index << endl;
	for(int i = index - 1; i >= 0; --i)
		cout << nums[i] << " ";
	cout << endl;
}
