#include<iostream>
using namespace std;

class Entry {
public:
	int data;
	
	Entry() {;}
	
	Entry(int a) {
		data = a;
	}
	
	void operator = (const Entry &entry) {
		data = entry.data;
	}
	
	bool operator >= (const Entry &entry) {
		return data >= entry.data;
	}
	
	bool operator >= (const Entry &entry) const {
		return data >= entry.data;
	}
	
	bool operator >= (Entry &entry) const {
		return data >= entry.data;
	}
	
	bool operator > (const Entry &entry) {
		return data > entry.data;
	}
		
	bool operator > (const Entry &entry) const {
		return data > entry.data;
	}
		
	bool operator > (Entry &entry) const {
		return data > entry.data;
	}
	
	bool operator <= (const Entry &entry) {
		return data <= entry.data;
	}
	
	bool operator <= (const Entry &entry) const {
		return data <= entry.data;
	}
	
	bool operator <= (Entry &entry) const {
		return data <= entry.data;
	}
	
	bool operator < (const Entry &entry) {
		return data < entry.data;
	}
	
	bool operator < (const Entry &entry) const {
		return data < entry.data;
	}
	
	bool operator < (Entry &entry) const {
		return data < entry.data;
	}
	
	bool operator == (const Entry &entry) {
		return data == entry.data;
	}
	
	bool operator == (const Entry &entry) const {
		return data == entry.data;
	}
	
	bool operator == (Entry &entry) const {
		return data == entry.data;
	}
	
	bool operator != (const Entry &entry) {
		return data != entry.data;
	}
	
	bool operator != (const Entry &entry) const {
		return data != entry.data;
	}
	
	bool operator != (Entry &entry) const {
		return data != entry.data;
	}
};

ostream& operator << (ostream &out, const Entry &entry) {
	out << entry.data;
	return out;
}

//#endif
