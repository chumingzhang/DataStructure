//TEXT
#include "List.cpp"

int main()
{
//	Node *text = new Node[1];
//	text->entry = 25;
//
//	Node *next1 = new Node[1];
//	next1->entry = 26;
//
//	text->next = next1;
//	cout << "text:  " << text->entry << "  next:  " << next1->entry << endl;
//	delete next1;
//	cout << "text:  " << text->entry << "  next:  " << text->next->entry << endl;

	List text;
//µ÷ÊÔ 
//	text.insert(5,0);
//	text.show();
//	text.insert(15,1);
//	text.show();
//	text.insert(25,2);
//	text.show();
//	text.insert(35,3);
//	text.show();
//	text.insert(45,2);
//	text.show();
	for(int i = 1; i <= 5; ++i)
		text.insert(i, i);
	text.show();
	text.empty();

//²âÊÔ insert
	text.insert(317, 0);
	text.insert(318, 2);
	text.insert(319, 6);
	text.insert(320, 15);
	text.show();

//²âÊÔ erase 
//	text.erase(317);
//	text.erase(2);
//	text.erase(3);
//	text.erase(4);
//	text.erase(5);
//	text.erase(0);
//	text.show();

//²âÊÔ clear
//	text.clear();
//	text.show();
//	text.empty();

//²âÊÔ replace
	text.replace(25,0);
	text.show(); 
	
}
