#include "stack.h"

Stack::Stack(int maxs) {
	sizes = maxs;
	index = 0;
}

RESULT_CODE Stack::push(int num) {
	if(index >= sizes) {
		cout << "当前容器已满!" << endl;
		return overflow;
	} 
	
	nums[index] = num;
	index++;
	return success;
}

RESULT_CODE Stack::pop() {
	if(index <= 0) { 
		cout << "当前容器为空!" << endl;
		return underflow;
	} 
	
	index--;
	return success;
}

RESULT_CODE Stack::empty() {
	if(index == 0) {
		cout << "当前容器为空!" << endl; 
		return success;
	}
	
	cout << "当前容器不为空!" << endl; 
	return fail;
}

int Stack::top() {
	if(index == 0) { 
		cout << "当前容器为空!" << endl;
		return underflow;
	} 
	return nums[index - 1];	//空堆栈 
}

int Stack::pop_top() {
	if(index == 0) { 
		cout << "当前容器为空!" << endl;
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
	cout << "最大容量: " << sizes << "  当前容量: " << index << endl;
	for(int i = index - 1; i >= 0; --i)
		cout << nums[i] << " ";
	cout << endl;
}
