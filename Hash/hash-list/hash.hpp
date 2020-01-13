#include "LinkedList.cpp"

//delete��ɾ��ָ��ָ��Ķ���,�����ͷ��ڴ档ָ���еĵ�ַ����,����һ����deleteָ���,Ҫ����ָ���ֵ��ֵNULL(�ÿ�)��

class HashTable{
private:
	LinkedList *array;
	int length;				//��ϣ����ĳ���
	int hash(string key);	//ͨ��key����hashֵ

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
