#include "queue.cpp"

int main()
{
	Queue text(10);
	for(int i = 0; i < 10; ++i) {
		text.append(i);
		text.printf();
	} 
	cout << "???" << endl;
	cout << text.full() << endl;
	cout << "???" << endl;
	cout << text.retrieve() << endl; 
	cout << text.serve_retrieve() << endl; 
	cout << text.retrieve() << endl; 
	
	text.clear();
	for(int i = 0; i < 11; ++i)
		text.serve();
	
	text.empty();
	text.printf();
	cout << text.retrieve() << endl; 
	return 0;
}
