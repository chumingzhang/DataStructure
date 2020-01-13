//�����㷨��ʱ���½�  O(log(2^n))  ����  O(nlog(n)) 
//���ֻ����㷨 ---- https://www.runoob.com/w3cnote/sort-algorithm-summary.html 
//ʮ�������㷨 ---- https://www.cnblogs.com/xiaohuiduan/p/11188304.html

//���������㷨 
//ð������  O(n^2)
//ѡ������  O(n^2)
//��������  O(n^2)

//��Ч�����㷨(ϣ�����������������) 
//ϣ������  O(n^1.5)
//��������  O(N * logN)
//������  O(N * logN) 
//������  O(N^2 / 2p)  �����pΪ����

//�����ռ��Լʱ��ĸ�Ч�����㷨(Ͱ����ͼ�����������) 
//�鲢����  O(N * logN)
//��������  O(kn), kΪ���λ��
//��������  O(n + k)
//Ͱ����  O(x * n) 


//1.ð������(BubbleSort)  ƽ��ʱ�临�Ӷ�  O(n^2)
//����˼�룺�������Ƚϴ�С���ϴ�����³�����С����ð������

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





//2.ѡ������(SelctionSort)  ƽ��ʱ�临�Ӷ�  O(n^2)
//����˼�룺
//�ڳ���ΪN�����������У���һ�α���n-1�������ҵ���С����ֵ���һ��Ԫ�ؽ�����
//�ڶ��α���n-2�������ҵ���С����ֵ��ڶ���Ԫ�ؽ���......

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





//3.��������(Insertion Sort)  ƽ��ʱ�临�Ӷ�  O(n^2)
//����˼�룺��Ҫ�����һ�����У��ٶ�ǰn-1�����Ѿ��ź������ڽ���n�����嵽
//ǰ������������У�ʹ����n����Ҳ���ź�˳��ġ���˷���ѭ����ֱ��ȫ���ź�˳��

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




//4.ϣ������(Shell Sort)  ƽ��ʱ�临�Ӷ�  O(n^1.5)
//����˼�룺��Ҫ�����һ�����У�����ĳһ������Ϊ���������У����������зֱ���в�������
//Ȼ���𽥽�������С,���ظ��������̡�ֱ������Ϊ1,��ʱ�������л�������,�����в�������

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
//		for(int k = 0; k < increment; ++k) {		//����������Ϊ���������� 
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




//5.������(Comb sort)   ƽ��ʱ�临�Ӷ� O(N2/2p)  �����pΪ����
//����˼��:ð�����������ǵ�ѡ�������ڵ����������Ƚϣ��������ǵ�gapΪ1��
//��ʵ����������˲�ͬ�Ĺ۵㣬�����gap����Ϊһ���Ĵ�С

//#include<iostream>
//using namespace std;
//int n = 7;
//int num[7] = {26, 33, 25, 29, 19, 12, 22};
//
//void comb_sort() {
//	int step = n / 1.3;			//���� �� gap 
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




//6.��������(Quicksort)  ƽ��ʱ�临�Ӷ�  O(N*logN)
//����˼�룺�����Σ�
//�ȴ�������ȡ��һ������Ϊkeyֵ��
//���������С����ȫ������������ߣ����ڻ����������ȫ�����������ұߣ�
//����������С�����ظ��ڶ�����ֱ��������ֻ��1������

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




//7.�鲢����(Merge Sort)  ƽ��ʱ�临�Ӷ�  O(N*logN)
//����˼�룺������ֳ�2��A��B�������2�����ڵ����ݶ�������ģ���ô�Ϳ��Ժܷ���Ľ���2�����ݽ�������
//�������2���������������ˣ����Խ�A��B������ٷֳ�2�顣�������ƣ����ֳ�����С��ֻ��1������ʱ��
//������Ϊ���С�������Ѿ��ﵽ������Ȼ���ٺϲ����ڵ�2��С��Ϳ����ˡ�

//#include<iostream>
//using namespace std;
//
//int n = 7;
//int num[7] = {26, 33, 25, 29, 19, 12, 22};
//int temp[7];
//
////�ϲ�����----�������� a[] �� b[] ���ȷֱ�Ϊ n �� m , c[]����ϲ���Ľ�� 
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




//8.������(HeapSort)  ƽ��ʱ�临�Ӷ�(O(n^2))
//����˼�룺https://www.cnblogs.com/Java3y/p/8639937.html
//��ȫ�������и����ԣ�
//����ӽڵ�λ�� = ��ǰ���ڵ������ + 1���ұ��ӽڵ�λ�� = ��ǰ���ڵ������ + 2

//#include<iostream>
//using namespace std;
//int n = 7;
//int num[7] = {26, 33, 25, 29, 19, 12, 22};
//
////���Ѻ���----������ɺ������������� ���ڵ� > �ӽڵ� 
//void heapify(int cur_root, int size) {
//	if(cur_root < size) {
//		//��������������λ�� 
//		int left = cur_root * 2 + 1;
//		int right = cur_root * 2 + 2;
//		
//		int max = cur_root;		//�ѵ�ǰ���ڵ㵱�����ڵ�
//		
//		//���������������ֵ 
//		if(left < size)
//			if(num[max] < num[left])
//				max = left;
//		
//		if(right < size)
//			if(num[max] < num[right])
//				max = right;
//		
//		//������Ľڵ㲻�Ǹ��ڵ�,�򽻻�����������		
//		if(max != cur_root) {
//			int temp = num[max];
//			num[max] = num[cur_root];
//			num[cur_root] = temp;
//			
//			//�����Ƚ�,ֱ�����һ�ν��� 
//			heapify(max, size);
//		} 
//	}
//}
//
////��ɵ�һ�ν���֮�����ǻᷢ�����ֵ�����������λ 
//void maxHeapify(int size) {
//	for(int i = 0; i < size; ++i)
//		heapify(i, size);
//} 
//
//int main() {
////	���Ͻ��ѣ�Ȼ�����������һλ�뵱ǰ�Ѷ�(�����һλ)���н�����������
//	for(int i = 0; i < n; ++i) {
//		//ÿ�ν��ѾͿ����ų�һ��Ԫ��
//        maxHeapify(n - i);
//
//        //�����ֵ����������� 
//        int temp = num[0];
//        num[0] = num[n - 1 - i];
//        num[n - 1 - i] = temp;
//	} 
//
//	for(int i = 0; i < n; ++i)
//		cout << num[i] << " ";
//	return 0; 
//} 




//9.��������(RadixSort)  ƽ��ʱ�临�Ӷ�  O(d(n+r))
//����˼�룺BinSort�뷨�ǳ��򵥣����ȴ�������A[MaxValue]��
//Ȼ��ÿ�����ŵ���Ӧ��λ���ϣ�����17�����±�17������λ�ã������������飬��Ϊ�����Ľ����
//�������д��ڽϴ�ֵʱ��BinSort �����򷽷����˷Ѵ����Ŀռ俪����
//������������BinSort�Ļ����ϣ�ͨ�����������������ٿռ�Ŀ�����

//#include<iostream>
//using namespace std;
//int n = 7;
//int num[7] = {26, 33, 25, 29, 19, 12, 22};
//int temp[7];	//��ʱ����
//
////k:���λ��  r:����  cnt:�洢bin[i]�ĸ��� 
//void radix_sort(int k, int r, int cnt[]) {
//	for(int i = 0, rtok = 1; i < k; ++i, rtok *= r) {
//		//��ʼ��
//		for(int j = 0; j < r; ++j)
//			cnt[j] = 0;
//			
//		//����ÿ�����ӵ����ָ���
//		for(int j = 0; j < n; ++j)
//			cnt[(num[j] / rtok) % r]++;
//		
//		for(int k = 0; k < r; ++k)
//			cout << cnt[k] << " ";
//		cout << endl;
//		
//		//cnt[j]�ĸ����޸�Ϊǰ j ������һ���м�������
//		for(int j = 1; j < r; ++j)
//			cnt[j] = cnt[j - 1] + cnt[j]; 
//		
//		for(int k = 0; k < r; ++k)
//			cout << cnt[k] << " ";
//		cout << endl;
//		
//		//����!!!!!! 
//		for(int j = n - 1; j >= 0; --j){
//			cnt[(num[j] / rtok) % r]--;
//			temp[cnt[(num[j] / rtok) % r]] = num[j];
//		}
//		
//		//������Ƹ� num[] 
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




//10.��������(Counting sort)   ƽ��ʱ�临�Ӷ� O(n + k) 
//����˼��: ��������ʹ��һ�����������C������C�е�i��Ԫ���Ǵ���������A��ֵ����i��Ԫ�صĸ�����
//Ȼ���������C����A�е�Ԫ���ŵ���ȷ��λ�á�

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




//11.Ͱ����(Bucket sort)   ƽ��ʱ�临�Ӷ� O(x * n) 
//����˼��: Ͱ�������˼����ǽ�Ҫ��������ݷֵ����������Ͱ�ÿ
//��Ͱ�ٷֱ��������ÿ��Ͱ������ɺ��ٰ�ÿ��Ͱ������ݰ���˳������ȡ����
//����µ����У������о����ź�������С����ƹ鲢�������еķ���˼�롣

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
//	int buckets[max - min + 1] = {0};		//���� max - min ��Ͱ 
//	for(int i = 0; i < n; ++i)			//����ÿ��Ԫ�س��ִ��� 
//		buckets[num[i] - min]++;
//	
//	for(int i = 1; i < max - min + 1; ++i)	//���������Ͱ�ڵ�Ԫ�������������е�λ�� 
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

