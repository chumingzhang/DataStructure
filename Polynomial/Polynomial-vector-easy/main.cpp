#include "Polynomial.cpp"

int main()
{
	vector<Node> a;
	a.push_back(Node(1, 1));
	a.push_back(Node(2, 2));
	
	vector<Node> b;
	b.push_back(Node(1, 1));
	b.push_back(Node(2, 2));
	b.push_back(Node(3, 3));
	b.push_back(Node(4, 4));
	
	Polynomial t1(a);
	Polynomial t2(b);
	
	cout << "t1" << endl;
	t1.show();
	cout << "t2" << endl;
	t2.show();
	t1 = t2 + t1;
	cout << "t1" << endl; 
	t1.show();
	
	return 0;
}
