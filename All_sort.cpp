//排序算法的时间下界  O(log(2^n))  或者  O(nlog(n)) 
//八种基本算法 ---- https://www.runoob.com/w3cnote/sort-algorithm-summary.html 
//十大排序算法 ---- https://www.cnblogs.com/xiaohuiduan/p/11188304.html

//基本排序算法 
//冒泡排序  O(n^2)
//选择排序  O(n^2)
//插入排序  O(n^2)

//高效排序算法(希尔排序和梳排序类似) 
//希尔排序  O(n^1.5)
//快速排序  O(N * logN)
//堆排序  O(N * logN) 
//梳排序  O(N^2 / 2p)  这里的p为增量

//牺牲空间节约时间的高效排序算法(桶排序和计数排序类似) 
//归并排序  O(N * logN)
//基数排序  O(kn), k为最高位数
//计数排序  O(n + k)
//桶排序  O(x * n) 


//1.冒泡排序(BubbleSort)  平均时间复杂度  O(n^2)
//基本思想：两个数比较大小，较大的数下沉，较小的数冒起来。

//#include<iostream>
//using namespace std;
//
//int main() {
//	int n = 7;
//	int num[7] = {26, 33, 25, 29, 19, 12, 22};
////	for(int i = 0; i < n; ++i) {
////		for(int j = i + 1; j < n; ++j) {
////			if(num[i] > num[j]) {
////				int temp = num[i];
////				num[i] = num[j];
////				num[j] = temp;
////			}
////		}
////	}
//
//	for(int i = 0; i < n; ++i) {
//		for(int j = 0; j < i; ++j) {
//			if(num[i] < num[j]) {
//				int temp = num[i];
//				num[i] = num[j];
//				num[j] = temp;
//			}
//		}
//	}
//	for(int i = 0; i < n; ++i)
//		cout << num[i] << " ";
//	return 0;
//}





//2.选择排序(SelctionSort)  平均时间复杂度  O(n^2)
//基本思想：
//在长度为N的无序数组中，第一次遍历n-1个数，找到最小的数值与第一个元素交换；
//第二次遍历n-2个数，找到最小的数值与第二个元素交换......

//#include<iostream>
//using namespace std;
//
//int main() {
//	int n = 7;
//	int num[7] = {26, 33, 25, 29, 19, 12, 22};
//	for(int i = 0; i < n; ++i) {
//		int min_index = i;
//		for(int j = i + 1; j < n; ++j)
//			if(num[min_index] > num[j])
//				min_index = j;
//		
//		if(min_index != i) {
//			int temp = num[i];
//			num[i] = num[min_index];
//			num[min_index] = temp;
//		}
//	}
//	for(int i = 0; i < n; ++i)
//		cout << num[i] << " ";
//	return 0; 
//} 





//3.插入排序(Insertion Sort)  平均时间复杂度  O(n^2)
//基本思想：在要排序的一组数中，假定前n-1个数已经排好序，现在将第n个数插到
//前面的有序数列中，使得这n个数也是排好顺序的。如此反复循环，直到全部排好顺序。

//#include<iostream>
//using namespace std;
//
//int main() {
//	int n = 7;
//	int num[7] = {26, 33, 25, 29, 19, 12, 22};
//	for(int i = 0; i < n - 1; ++i) {
//		for(int j = i + 1; j > 0; --j) {
//			if(num[j] < num[j - 1]) {
//				int temp = num[j - 1];
//				num[j - 1] = num[j];
//				num[j] = temp;
//			}
//			else
//				break;
//		}
//	}
//	for(int i = 0; i < n; ++i)
//		cout << num[i] << " ";
//	return 0; 
//} 




//4.希尔排序(Shell Sort)  平均时间复杂度  O(n^1.5)
//基本思想：在要排序的一组数中，根据某一增量分为若干子序列，并对子序列分别进行插入排序。
//然后逐渐将增量减小,并重复上述过程。直至增量为1,此时数据序列基本有序,最后进行插入排序。

//#include<iostream>
//using namespace std;
//
//int main() {
//	int n = 7;
//	int num[7] = {26, 33, 25, 29, 19, 12, 22};
//	
//	int increment = n;
//	while(1) {
//		increment /= 2;
//		for(int k = 0; k < increment; ++k) {		//根据增量分为若干子序列 
//			for(int i = k + increment; i < n; i += increment) {
//				for(int j = i; j > k; j -= increment) {
//					if(num[j] < num[j - increment]) {
//						int temp = num[j - increment];
//						num[j - increment] = num[j];
//						num[j] = temp;
//					}
//					else
//						break;
//				}
//			}
//		}
//		if(increment == 1)
//			break;
//	}
//	
//	for(int i = 0; i < n; ++i)
//		cout << num[i] << " ";
//	return 0; 
//} 




//5.疏排序(Comb sort)   平均时间复杂度 O(N2/2p)  这里的p为增量
//基本思想:冒泡排序上我们的选择是相邻的两个数做比较，就是他们的gap为1，
//其实梳排序提出了不同的观点，这里的gap设置为一定的大小

//#include<iostream>
//using namespace std;
//int n = 7;
//int num[7] = {26, 33, 25, 29, 19, 12, 22};
//
//void comb_sort() {
//	int step = n / 1.3;			//步长 即 gap 
//	while(step >= 1) {
//		for(int i = 0; i < n; ++i) {
//			if(i + step > n)
//				break;
//			if(i + step < n && num[i] > num[i + step]) {
//				int temp = num[i];
//				num[i] = num[i + step];
//				num[i + step] = temp;
//			}
//		}
//		step /= 1.3;
//	} 
//}
//
//int main() {
//
//	comb_sort();
//	for(int i = 0; i < n; ++i)
//		cout << num[i] << " ";
//	return 0;
//} 




//6.快速排序(Quicksort)  平均时间复杂度  O(N*logN)
//基本思想：（分治）
//先从数列中取出一个数作为key值；
//将比这个数小的数全部放在它的左边，大于或等于它的数全部放在它的右边；
//对左右两个小数列重复第二步，直至各区间只有1个数。

//#include<iostream>
//using namespace std;
//int n = 7;
//int num[7] = {26, 33, 25, 29, 19, 12, 22};
//
//void quick(int left, int right) {
//	if(left >= right)
//		return;
//	
//	int key = num[left];
//	int i = left, j = right;
//	while(i < j) {
//		for(; j > i; --j) {
//			if(num[j] < key) {
//				num[i] = num[j];
//				i++;
//				break;
//			}
//		}
//		
//		for(; i < j; ++i) {
//			if(num[i] > key) {
//				num[j] = num[i];
//				j--;
//				break;
//			}
//		}
//	}
//	
//	num[i] = key;
//	quick(left, i - 1);
//	quick(i + 1, right);
//}
//
//int main() {
//	quick(0, 6); 
//	for(int i = 0; i < n; ++i)
//		cout << num[i] << " ";
//	return 0; 
//} 




//7.归并排序(Merge Sort)  平均时间复杂度  O(N*logN)
//基本思想：将数组分成2组A，B，如果这2组组内的数据都是有序的，那么就可以很方便的将这2组数据进行排序。
//如何让这2组组内数据有序了？可以将A，B组各自再分成2组。依次类推，当分出来的小组只有1个数据时，
//可以认为这个小组组内已经达到了有序，然后再合并相邻的2个小组就可以了。

//#include<iostream>
//using namespace std;
//
//int n = 7;
//int num[7] = {26, 33, 25, 29, 19, 12, 22};
//int temp[7];
//
////合并函数----两个数组 a[] 和 b[] 长度分别为 n 和 m , c[]储存合并后的结果 
//void merge(int first, int mid, int last) {
//	int i = first, n = mid;
//	int j = mid + 1, m = last;
//	int k = 0;
//	
//	while(i <= n && j <= m) {
//		if(num[i] < num[j])
//			temp[k++] = num[i++];
//		else
//			temp[k++] = num[j++]; 
//	}  
//	
//	while(i <= n)
//		temp[k++] = num[i++];
//	while(j <= m)
//		temp[k++] = num[j++];
//		
//	for(int ii = 0; ii < k; ++ii)
//		num[first + ii] = temp[ii];
//}
//
//void merge_sort(int first, int last) {
//	if(first < last) {
//		int mid = (first + last) / 2;
//		merge_sort(first, mid);
//		merge_sort(mid + 1, last);
//		merge(first, mid, last);
//	}
//}
// 
//int main() {
//	merge_sort(0, 6);
//
//	for(int i = 0; i < n; ++i)
//		cout << num[i] << " ";
//	return 0; 
//} 




//8.堆排序(HeapSort)  平均时间复杂度(O(n^2))
//基本思想：https://www.cnblogs.com/Java3y/p/8639937.html
//完全二叉树有个特性：
//左边子节点位置 = 当前父节点的两倍 + 1，右边子节点位置 = 当前父节点的两倍 + 2

//#include<iostream>
//using namespace std;
//int n = 7;
//int num[7] = {26, 33, 25, 29, 19, 12, 22};
//
////建堆函数----建堆完成后左右子树都有 父节点 > 子节点 
//void heapify(int cur_root, int size) {
//	if(cur_root < size) {
//		//计算左右子树的位置 
//		int left = cur_root * 2 + 1;
//		int right = cur_root * 2 + 2;
//		
//		int max = cur_root;		//把当前父节点当作最大节点
//		
//		//在左右子树找最大值 
//		if(left < size)
//			if(num[max] < num[left])
//				max = left;
//		
//		if(right < size)
//			if(num[max] < num[right])
//				max = right;
//		
//		//如果最大的节点不是根节点,则交换并继续建堆		
//		if(max != cur_root) {
//			int temp = num[max];
//			num[max] = num[cur_root];
//			num[cur_root] = temp;
//			
//			//继续比较,直到完成一次建堆 
//			heapify(max, size);
//		} 
//	}
//}
//
////完成第一次建堆之后，我们会发现最大值会在数组的首位 
//void maxHeapify(int size) {
//	for(int i = 0; i < size; ++i)
//		heapify(i, size);
//} 
//
//int main() {
////	不断建堆，然后让数组最后一位与当前堆顶(数组第一位)进行交换即可排序：
//	for(int i = 0; i < n; ++i) {
//		//每次建堆就可以排除一个元素
//        maxHeapify(n - i);
//
//        //把最大值放在数组后面 
//        int temp = num[0];
//        num[0] = num[n - 1 - i];
//        num[n - 1 - i] = temp;
//	} 
//
//	for(int i = 0; i < n; ++i)
//		cout << num[i] << " ";
//	return 0; 
//} 




//9.基数排序(RadixSort)  平均时间复杂度  O(d(n+r))
//基本思想：BinSort想法非常简单，首先创建数组A[MaxValue]；
//然后将每个数放到相应的位置上（例如17放在下标17的数组位置）；最后遍历数组，即为排序后的结果。
//当序列中存在较大值时，BinSort 的排序方法会浪费大量的空间开销。
//基数排序是在BinSort的基础上，通过基数的限制来减少空间的开销。

//#include<iostream>
//using namespace std;
//int n = 7;
//int num[7] = {26, 33, 25, 29, 19, 12, 22};
//int temp[7];	//临时数组
//
////k:最大位数  r:基数  cnt:存储bin[i]的个数 
//void radix_sort(int k, int r, int cnt[]) {
//	for(int i = 0, rtok = 1; i < k; ++i, rtok *= r) {
//		//初始化
//		for(int j = 0; j < r; ++j)
//			cnt[j] = 0;
//			
//		//计算每个箱子的数字个数
//		for(int j = 0; j < n; ++j)
//			cnt[(num[j] / rtok) % r]++;
//		
//		for(int k = 0; k < r; ++k)
//			cout << cnt[k] << " ";
//		cout << endl;
//		
//		//cnt[j]的个数修改为前 j 个箱子一共有几个数字
//		for(int j = 1; j < r; ++j)
//			cnt[j] = cnt[j - 1] + cnt[j]; 
//		
//		for(int k = 0; k < r; ++k)
//			cout << cnt[k] << " ";
//		cout << endl;
//		
//		//精髓!!!!!! 
//		for(int j = n - 1; j >= 0; --j){
//			cnt[(num[j] / rtok) % r]--;
//			temp[cnt[(num[j] / rtok) % r]] = num[j];
//		}
//		
//		//结果复制给 num[] 
//		for(int j = 0; j < n; ++j)
//			num[j] = temp[j]; 
//		
//		for(int k = 0; k < n; ++k)
//			cout << num[k] << " ";
//		cout << endl << endl; 
//	}
//} 
//
//int main() {
//	int cnt[7];
//	radix_sort(2, 10, cnt); 
//
//	for(int i = 0; i < n; ++i)
//		cout << num[i] << " ";
//	return 0; 
//} 




//10.计数排序(Counting sort)   平均时间复杂度 O(n + k) 
//基本思想: 计数排序使用一个额外的数组C，其中C中第i个元素是待排序数组A中值等于i的元素的个数。
//然后根据数组C来将A中的元素排到正确的位置。

//#include<iostream>
//#define MAX(a, b) a > b ? a : b
//using namespace std;
//
//int main() {
//	int n = 7;
//	int num[7] = {26, 33, 25, 29, 19, 12, 22};
//	int max = num[0];
//	for(int i = 1; i < n; ++i)
//		max = MAX(max, num[i]);
//	
//	int count[max + 1] = {0};
//	for(int i = 0; i < n; ++i)
//		count[num[i]]++;
//	
//	int index = 0;
//	for(int i = 0; i < max + 1; ++i){
//		while(count[i] > 0) {
//			num[index++] = i;
//			count[i]--;
//		}
//	}
//	
//	for(int i = 0; i < n; ++i)
//		cout << num[i] << " ";
//	return 0;
//} 




//11.桶排序(Bucket sort)   平均时间复杂度 O(x * n) 
//基本思想: 桶排序核心思想就是将要排序的数据分到几个有序的桶里，每
//个桶再分别进行排序，每个桶排序完成后再把每个桶里的数据按照顺序依次取出，
//组成新的序列，该序列就是排好序的序列。类似归并排序中中的分治思想。

//#include<iostream>
//#define MAX(a, b) a > b ? a : b
//#define MIN(a, b) a > b ? b : a
//using namespace std;
//int n = 7;
//int num[7] = {26, 33, 25, 29, 19, 12, 22};
//
//void bucket_sort() {
//	int max = num[0];
//	int min = num[0];
//	int temp[7];
//	for(int i = 0; i < n; ++i) {
//		temp[i] = num[i];
//		max = MAX(max, num[i]);
//		min = MIN(min, num[i]);
//	}
// 
//	int buckets[max - min + 1] = {0};		//定义 max - min 个桶 
//	for(int i = 0; i < n; ++i)			//计算每个元素出现次数 
//		buckets[num[i] - min]++;
//	
//	for(int i = 1; i < max - min + 1; ++i)	//计算落入各桶内的元素在有序序列中的位置 
//		buckets[i] += buckets[i - 1]; 
//
//	for(int i = 0; i < n; ++i)
//		num[--buckets[temp[i] - min]] = temp[i]; 
//		
//}
//
//int main() {
//
//	bucket_sort();
//	
//	for(int i = 0; i < n; ++i)
//		cout << num[i] << " ";
//	return 0;
//} 

