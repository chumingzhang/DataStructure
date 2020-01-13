//0.ººÅµËþ
//1.Hanoi
//#include<iostream>
//
//using namespace std;
//
//void move(int count, int start, int finish, int temp) {
//	if(count == 0)
//		return;
//	if(count == 1)
//	{
//		cout << "Move disk  " << count << "  from  " << start << "  to  " << finish << endl;
//		return;
//	}
//	
//	move(count - 1, start, temp, finish);
//	cout << "Move disk  " << count << "  from  " << start << "  to  " << finish << endl;
//	move(count - 1, temp, finish, start);
//}
//
//int main()
//{
//	move(3, 1, 2, 3);
//	return 0;
//} 



//1.Fibonacci(ì³²¨ÄÇÆõÊýÁÐ) 
//#include<iostream>
//
//using namespace std;
//
//int main()
//{
//	int n;
//	cin >> n;
//	int fib[100];
//	fib[0] = fib[1] = 1;
//	for(int i = 2; i < n; ++i)
//		fib[i] = fib[i - 1] + fib[i - 2];
//		
//	for(int i = 0; i < n; ++i)
//		cout << fib[i] << " ";
//	cout << endl; 
//	return 0;
//}
