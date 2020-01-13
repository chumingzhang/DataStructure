#include "Node.cpp"
#include<vector>
#include<algorithm>

using namespace std;

class Polynomial{
private:
	vector<Node> entry;
	
public:
	Polynomial();
	Polynomial(const vector<Node> &a);
	Polynomial(const Polynomial &a);
	void entry_sort();
	
	bool operator == (Polynomial a);
	void operator = (const Polynomial &a);
	Polynomial operator + (Polynomial a);
	Polynomial operator - (Polynomial a);
//Ҫ�ϲ�ͬ���� 
//	Polynomial operator * (Polynomial a);
//	Polynomial operator / (Polynomial a);
	
	void show();
};
