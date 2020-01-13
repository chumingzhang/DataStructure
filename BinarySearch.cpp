#include<iostream>
using namespace std;

//1.递归式 
//int binFind(int begin, int end, int cur_time, int nums[], int target) {
//	if(begin > end) {
//		return -1;
//	}
//	int mid = (begin + end) / 2;
//	if(target < nums[mid])
//		binFind(begin, mid - 1, cur_time + 1, nums, target);
//	else if(target == nums[mid])
//		return cur_time;
//	else
//		binFind(mid + 1, end, cur_time + 1, nums, target);
//}


//2.循环式 
//int binFind(int begin, int end, int cur_time, int nums[], int target) {
//	while(begin <= end) {
//		int mid = (begin + end) / 2;
//		if(target < nums[mid])
//			end = mid - 1;
//		else if(target == nums[mid])
//			return cur_time;
//		else
//			begin = mid + 1;
//		cur_time++;
//	}
//	return -1;
//} 

int main() {
	int nums[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	for(int i = 1; i < 10; ++i) {
		int count = binFind(0, 8, 0, nums, i);
		cout << "找" << i << "共递归了" << count + 1 << "次" << endl; 
	}
	return 0;
} 
