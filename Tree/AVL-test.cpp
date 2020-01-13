//#include "Entry.cpp"
//#include "BNode.hpp"
//#include "BT.hpp"
//#include "BST.hpp"
//#include "AVL_node.hpp"
//#include "AVL.cpp"
//#include "BNode.cpp" 


#include "AVL.cpp"

int main(){
	Entry a(100);
	Entry b(317);
	Entry c(21);
	Entry d(54);
	Entry e(920);
	Entry f(78);
	Entry g(50);
	Entry h(18);
	Entry i(52);
	Entry j(51);
	Entry k(96);
	Entry l(1024);
	Entry m(1028);
	Entry z(996);
	
	AVL_tree<Entry> *test1 = new AVL_tree<Entry>();
////	AVL_tree<Entry> test2;
//	
	//1.initial and empty test
	if(test1->empty())
		cout << "I am empty" << endl;
	cout << test1->size() << endl;
	cout << test1->height() << endl;
	cout << test1->left_height(test1->get_root()) << endl;
	cout << test1->right_height(test1->get_root()) << endl;
	
		//2.insert test
//test1！！double ratation at once 
//	test1->insert(a);//100
//	test1->insert(b);//317
//	test1->insert(c);//21
//	test1->insert(d);//54
//	test1->insert(e);//920
//	test1->insert(h);//18
//	test1->insert(f);//78
//	test1->insert(g);//50
//	test1->insert(i);//32


//test2！！single ratation twice 
	test1->insert(a);//100
	test1->insert(g);//50 
	test1->insert(b);//317
	test1->insert(c);//21
	test1->insert(d);//54
	test1->insert(e);//920
	test1->insert(f);//78
	test1->insert(h);//18
	test1->insert(i);//52
	test1->insert(l);//1024
	test1->insert(m);//1028
	test1->insert(j);//51
	test1->insert(k);//96
	
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

	//3.search test
//	if(test1->tree_search(a) == success)
//		cout << "Find you: " << a << endl;
//	if(test1->tree_search(b) == success)
//		cout << "Find you: " << b << endl;
//	if(test1->tree_search(c) == success)
//		cout << "Find you: " << c << endl;
//	if(test1->tree_search(d) == success)
//		cout << "Find you: " << d << endl;
//	if(test1->tree_search(h) == success)
//		cout << "Find you: " << h << endl;
//	if(test1->tree_search(i) == success)
//		cout << "Find you: " << i << endl;
//	if(test1->tree_search(z) == not_present)
//		cout << "Not find you: " << z << endl;
		
	//4.remove test
	test1->balance_remove(m);
//	test1->balance_remove(g);
//	test1->balance_remove(f);
//	test1->balance_remove(h);
////	test1->balance_remove(e);
////	test1->balance_remove(f);
	test1->inorder(test1->get_root());
	cout << endl;
	test1->preorder(test1->get_root());
	cout << endl;
	test1->postorder(test1->get_root());
	cout << endl;
//	
//	cout << test1->size() << endl;
//	cout << test1->height() << endl;
//	cout << test1->left_height(test1->get_root()) << endl;
//	cout << test1->right_height(test1->get_root()) << endl;
	return 0;
}
