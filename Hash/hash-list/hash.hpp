#include "LinkedList.cpp"

//delete是删除指针指向的对象,让其释放内存。指针中的地址不变,所以一般在delete指针后,要将该指针的值赋值NULL(置空)。

class HashTable{
private:
	LinkedList *array;
	int length;				//哈希链表的长度
	int hash(string key);	//通过key计算hash值

public:
	HashTable(int len = 13);
	void insertItem(Item *newItem);
	bool removeItem(string key);
	Item *getItemByKey(string key);
	void printTable();
	void printHistogram();
	void clear();
	int getLength();
	int getNumberOfItems();
	~HashTable();
};
