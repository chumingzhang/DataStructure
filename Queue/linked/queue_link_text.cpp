#include "queue_link.cpp"

int main()
{
	Queue text;
	for(int i = 0; i < 10; ++i)
		text.append(i);
	text.printf();
	
//	Queue text2(text);
//	cout << "text2" << endl;
//	text2.printf();
//	for(int i = 0; i < 10; ++i)
//		text2.serve();
//	text2.printf();

	Queue text3 = text;
	cout << "text3" << endl;
	text3.printf();
	for(int i = 0; i < 10; ++i)
		text3.serve();
	text3.printf();
	
	for(int i = 0; i < 2; ++i)
		text.serve();
	
	text.empty();
	text.printf();
	cout << text.retrieve() << endl;
	cout << text.serve_retrieve() << endl;
	cout << text.retrieve() << endl;
	text.serve();
	cout << text.retrieve() << endl;
	
	text.printf();
	return 0;
}
