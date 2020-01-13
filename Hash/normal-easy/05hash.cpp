#include<iostream>
#include<string>
using namespace std;

class Hash{
private:
	int len;
	int* nums;
public:
	Hash(const int num){
		len = num;
		nums = new int[num]();
	}
	
	int hash(int num){
		return num % len;
	}
	
	//线性查找 
	void insert(int num){
		int index = hash(num);
		int probe_count = 0;
		while(nums[index] != NULL && nums[index] != num && probe_count < (len + 1) / 2){
			index++; 
			probe_count++;
		}
		
		if(nums[index] == NULL)
			nums[index] = num;
		else
			return;
	}
	
	//平方查找 
//	void insert(int num){
//		int index = hash(num);
//		int probe_count = 0;
//		int increment = 1;
//		while(nums[index] != NULL && nums[index] != num && probe_count < (len + 1) / 2){
//			index += increment; 
//			probe_count++;
//			increment += 2;
//		}
//		
//		if(nums[index] == NULL)
//			nums[index] = num;
//		else
//			return;
//	}
	
	void show(){
		for(int i = 0; i < len; ++i){
			cout << "bucket " << i + 1 << ":   ";
			if(nums[i] != NULL)
				cout << nums[i];
			cout << endl;
		}
	}
	
	~Hash(){
		delete [] nums;
	}
};

int main()
{
	Hash test(11);
	test.insert(19);
	test.insert(14);
	test.insert(23);
	test.insert(01);
	test.insert(68);
	test.insert(84);
	test.insert(27);
	test.insert(55);
	test.insert(11);
	test.insert(34);
	test.insert(79);
	
	test.show();
	return 0;
}

