//BFS �� DFS����ͼ�Ļ����㷨 
//�ο���ַ��https://www.jianshu.com/p/70952b51f0c8

//BFS-������������ڽ�һ������ͼ�ж���֮ǰ���ȷ��ʵ�ǰ����������ڽӽ�㡣
//#include<iostream>
//#include<queue>
//#define N 5 
//using namespace std;
//
//int maze[N][N] = {
//	{0, 1, 1, 0, 0},
//	{0, 0, 1, 1, 0},
//	{0, 1, 1, 1, 0},
//	{1, 0, 0, 0, 0},
//	{0, 0, 1, 1, 0}
//};
//int visited[N] = {0};
//
//void BFS(int start) {
//	queue<int> qq;
//	qq.push(start);
//	visited[start] = 1;
//	while(!qq.empty()) {
//		int front = qq.front();
//		cout << front << " ";
//		qq.pop();
//		for(int i = 0; i < N; ++i) {
//			if(!visited[i] && maze[front][i] == 1) {
//				visited[i] = 1;
//				qq.push(i);
//			}
//		}
//	}
//}
//
//int main() {
//	for(int i = 0; i < N; ++i) {
//		if(visited[i] != 1)
//			BFS(i);
//	}
//	return 0;
//} 



//DFS-����������������������з���ĳ���������Ҫ�ݹ�ط��ʴ˶��������δ���ʹ������ڶ��㡣
//#include<iostream>
//#include<queue>
//#define N 5 
//using namespace std;
//
//int maze[N][N] = {
//	{0, 1, 1, 0, 0},
//	{0, 0, 1, 0, 1},
//	{0, 0, 1, 0, 0},
//	{1, 1, 0, 0, 1},
//	{0, 0, 1, 0, 0}
//};
//int visited[N] = {0};
//
//void DFS(int start) {
//	visited[start] = 1;
//	for(int i = 0; i < N; ++i) {
//		if(!visited[i] && maze[start][i] == 1)
//			DFS(i);
//	}
//	cout << start << endl;
//}
//
//int main() {
//	for(int i = 0; i < N; ++i) {
//		if(visited[i] != 1)
//			DFS(i);
//	}
//	return 0;
//} 
