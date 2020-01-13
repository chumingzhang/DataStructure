#include<iostream>
using namespace std;

class Node{
private:
	int coef, index;
	
public:
	Node();
	Node(int a, int b);
	int get_coef() const;
	int get_index() const;
	void set_coef(int a);
	void set_index(int b);
	
	bool operator == (Node &a);
	bool operator != (Node &a);
};
