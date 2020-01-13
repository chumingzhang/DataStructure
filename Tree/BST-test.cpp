//Advantage1: The nodes need not all ba available at hte start 
//of the process, but are built into the tree one by one as they become available

//Advantage2: The search tree remain available for later insertions and removals

//Drawback: If the keys are already sorted, then treesort will be a disaster
//the search tree it builds will reduce to a chain

#include<iostream>
#include "BST.cpp"
using namespace std;

int main()
{
	Entry a(100);
	Entry b(317);
	Entry c(21);
	Entry d(54);
	Entry e(920);
	Entry f(78);
	Entry g(50);
	Entry h(18);
	Entry i(32);
	
	Search_tree<Entry> *test1 = new Search_tree<Entry>();
	Search_tree<Entry> test2;
	
	//1.initial and empty test
	if(test1->empty())
		cout << "I am empty" << endl;
	cout << test1->size() << endl;
	cout << test1->height() << endl;
	cout << test1->left_height(test1->get_root()) << endl;
	cout << test1->right_height(test1->get_root()) << endl;
	
	//2.insert test
	test1->insert(a);//100
	test1->insert(b);//317
	test1->insert(c);//21
	test1->insert(d);//54
	test1->insert(e);//920
	test1->insert(f);//78
	test1->insert(g);//50
	test1->insert(h);//18
	test1->insert(i);//32
	test1->inorder(test1->get_root());
	cout << endl;
	test1->preorder(test1->get_root());
	cout << endl;
	test1->postorder(test1->get_root());
	cout << endl;
	
	cout << test1->size() << endl;
	cout << test1->height() << endl;
	cout << test1->left_height(test1->get_root()) << endl;
	cout << test1->right_height(test1->get_root()) << endl;
	
	//test operator =
//	cout << "test2222222222222222222222222222222222222222222222222" << endl;
//	test2 = *(test1);
//	test1->inorder(test2.get_root());
//	cout << endl;
//	test1->preorder(test2.get_root());
//	cout << endl;
//	test1->postorder(test2.get_root());
//	cout << endl;
//	
//	cout << test2.size() << endl;
//	cout << test2.height() << endl;
//	
//	test1->clear();
//	cout << test1->size() << endl;
//	cout << test1->height() << endl;
//	
//	test2.inorder(test2.get_root());
//	cout << endl;
//	test2.preorder(test2.get_root());
//	cout << endl;
//	test2.postorder(test2.get_root());
//	cout << endl;
//	
//	cout << test2.size() << endl;
//	cout << test2.height() << endl;

	//test copy constructor
//	Binary_tree<Entry> test3 = *test1;
//	cout << "test3333333333333333333333333333333333333333333333333" << endl;
//	test1->inorder(test3.get_root());
//	cout << endl;
//	test1->preorder(test3.get_root());
//	cout << endl;
//	test1->postorder(test3.get_root());
//	cout << endl;
//	
//	cout << test3.size() << endl;
//	cout << test3.height() << endl;
//	
//	test1->clear();
//	cout << test1->size() << endl;
//	cout << test1->height() << endl;
//	
//	test3.inorder(test3.get_root());
//	cout << endl;
//	test3.preorder(test3.get_root());
//	cout << endl;
//	test3.postorder(test3.get_root());
//	cout << endl;
//	
//	cout << test3.size() << endl;
//	cout << test3.height() << endl;
	
//	//3.search test
//	if(test1->tree_search(a) == success)
//		cout << "Find you: " << a << endl;
//	if(test1->tree_search(b) == success)
//		cout << "Find you: " << b << endl;
//	if(test1->tree_search(c) == success)
//		cout << "Find you: " << c << endl;
//	if(test1->tree_search(d) == success)
//		cout << "Find you: " << d << endl;
//	if(test1->tree_search(e) == success)
//		cout << "Find you: " << e << endl;
//	if(test1->tree_search(f) == success)
//		cout << "Find you: " << f << endl;
//	
//	
	//4.remove test
//	test1->remove(a);
//	test1->remove(b);
////	test1->remove(c);
////	test1->remove(d);
////	test1->remove(e);
////	test1->remove(f);
//	test1->inorder(test1->get_root());
//	cout << endl;
//	test1->preorder(test1->get_root());
//	cout << endl;
//	test1->postorder(test1->get_root());
//	cout << endl;
//	
//	cout << test1->size() << endl;
//	cout << test1->height() << endl;
//
//	//5.clear test
//	test1->clear();
//	test1->inorder(test1->get_root());
//	cout << endl;
//	test1->preorder(test1->get_root());
//	cout << endl;
//	test1->postorder(test1->get_root());
//	cout << endl;
//	
//	cout << test1->size() << endl;
//	cout << test1->height() << endl;
//	cout << test1->left_height(test1->get_root()) << endl;
//	cout << test1->right_height(test1->get_root()) << endl;
	return 0;
}

