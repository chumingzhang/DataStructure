#include "stack_link.cpp"

int main()
{
	Stack text;
	for(int i = 0; i < 10; ++i)
		text.push(i);
		
	text.printf();
	
	Stack text2;
	for(int i = 0; i < 15; ++i)
		text2.push(i + 20);
	cout << "first time" << endl; 
	text2.printf();
	
	cout << endl << endl;
	text2 = text;
	cout << "seconde time text2" << endl;
	text2.printf();
	
	
//	Stack text3(text);
//	text3.printf();
//	cout << "shangmoianshi text3" << endl << endl;
	
//	for(int i = 0; i < 11; ++i)
//		text3.pop();
	
	text.empty();
	text.printf();
	cout << "i'm here" << endl; 
	cout << "????" << endl;
	return 0;
}
