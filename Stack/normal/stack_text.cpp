#include<iostream>
#include "stack.cpp"
using namespace std;

int main()
{
	Stack text(10);
	for(int i = 0; i < 10; ++i)
		text.push(i);
	text.printf();
	
	for(int i = 0; i < 5; ++i)
		text.pop();
	text.printf();
	
	text.empty(); 
		
	cout << "top is: " << text.top() << endl;
	text.printf();
	
	cout << "top is: " << text.pop_top() << endl;
	cout << "top is: " << text.pop_top() << endl;
	text.printf();
	
	cout << "top is: " << text.pop_top() << endl;
	cout << "top is: " << text.pop_top() << endl;
	
	cout << "top is: " << text.pop_top() << endl;
	cout << "top is: " << text.pop_top() << endl;
	
	cout << "top is: " << text.pop_top() << endl;
	cout << "top is: " << text.pop_top() << endl;
	return 0;
}
