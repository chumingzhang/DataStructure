//List.h
#include "List_Node.cpp"
#define List_entry int

enum Result_code {
	success, fail, underflow, overflow
};

class List{
private:
	Node *root;
	
public:
	List();
	Result_code insert(const Node_entry &add, int pos);
	Result_code erase(const Node_entry move);
	Result_code replace(const Node_entry &add, int pos);
	Node *get_by_pos(const int pos); 	//pos´Ó0¿ªÊ¼ 
	Node *get_by_num(const Node_entry num); 
	int size()const;
	bool empty() const;
	void clear();
	void show();
	~List();
};


