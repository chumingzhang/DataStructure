////��Ŀ��ַ----https://www.acwing.com/problem/
////DP��̬�滮����ȫ����ʼ��Ϊ0�� dp[i]��ʾС�ڵ��� i ʱ�����ֵ
////DP��̬�滮����dp[0]��ʼ��Ϊ0�������ʼ��Ϊ-�ޣ� ��dp[i]��ʾǡ�õ��� i ʱ�����ֵ
//
////1.01��������----ѡ��ѡ
//#include<iostream>
//using namespace std;
//
//int main() {
//    int count, volume;
//	cin >> count >> volume; 
//	int stuff[1005][2] = {0};
//	for(int i = 1; i <= count; ++i)
//		cin >> stuff[i][0] >> stuff[i][1];
//	
//	int dp[1005][1005] = {0};
//	for(int i = 1; i <= count; ++i) {
//	    for(int j = 0; j <= volume; ++j) {
//		    dp[i][j] = dp[i - 1][j];
//		    if(j >= stuff[i][0])
//				dp[i][j] = max(dp[i][j], dp[i - 1][j - stuff[i][0]] + stuff[i][1]);   
//		}
//	}
//	
//	cout << dp[count][volume];		
//// 	int ans = 0;
//// 	for(int i = 0; i <= volume; ++i)
//// 		ans = max(ans, dp[count][i]);
//// 	cout << ans;
//    return 0;
//}
//
////2.��ȫ��������----����ѡ������
//#include<iostream>
//
//using namespace std;
//
//int main() {
//    int volume, count;
//    cin >> count >> volume;
//    int goods[count + 1][2];
//    for(int i = 1; i <= count; ++i)
//        cin >> goods[i][0] >> goods[i][1];
//    
//    int dp[volume + 1] = {0};
//    for(int i = 1; i <= count; ++i)
//        for(int j = goods[i][0]; j <= volume; ++j)
//            dp[j] = max(dp[j], dp[j - goods[i][0]] + goods[i][1]);
//            
//    cout << dp[volume];
//    return 0;
//}
//
//
////3.���ر��������----�Ѷ����ֳ�һ��һ��,���01��������
//#include<iostream>
//using namespace std;
//
//int main() {
//    int count, volume;
//    cin >> count >> volume;
//    int goods[105][3] = {0};
//    for(int i = 1; i <= count; ++i)
//        cin >> goods[i][0] >> goods[i][1] >> goods[i][2];
//    
//    int dp[105] = {0};
//    for(int i = 1; i <= count; ++i) {
//        for(int j = volume; j >= goods[i][0]; --j) {
//            for(int k = 0; (k <= goods[i][2] && k * goods[i][0] <= j); ++k)
//                dp[j] = max(dp[j], dp[j - k * goods[i][0]] + k * goods[i][1]);
//        }
//    }
//    
//    cout << dp[volume];
//}
//
//
////4.���ر��������----�ö������Ż����ر�������
//#include<iostream>
//#include<vector>
//using namespace std;
//
//class Good{
//public:
//    int volume;
//    int value;
//};
//
//int main() {
//    int count, volume;
//    cin >> count >> volume;
//    int v, m, s;
//    vector<Good> goods;
//    for(int i = 0; i < count; ++i) {
//        cin >> v >> m >> s;
//        for(int k = 1; k <= s; k *= 2) {
//            goods.push_back({k * v, k * m});
//            s -= k;
//        }
//        if(s > 0)
//            goods.push_back({s * v, s * m});
//    }
//    
//    int dp[2010] = {0};
//    for(int i = 0; i <= goods.size(); ++i)
//        for(int j = volume; j >= goods[i].volume; --j)
//            dp[j] = max(dp[j], dp[j - goods[i].volume] + goods[i].value);
//    
//    cout << dp[volume];
//} 
//
//
//
////5.���ر��������
//#include<iostream>
//#include<string.h>
//using namespace std;
//
//int count, volume;
//int f[20010], g[20010], q[20010];
//
//int main() {
//    cin >> count >> volume;
//    int c, w, s;
//    for(int i = 0; i < count; ++i) {
//        cin >> c >> w >> s;
//        memcpy(g, f, sizeof(f));
//        
//        for(int j = 0; j < c; ++j) {
//            int hh = 0, tt = -1;
//            //���ݶ�����cȡģ������������,��ͬһ���s�������еݹ�
//            for(int k = j; k <= volume; k += c) {
//                f[k] = g[k];
//                if(hh <= tt && k - s * c > q[hh])
//                    hh++;
//                if(hh <= tt)
//                    f[k] = max(f[k], g[q[hh]] + (k - q[hh]) / c * w);
//                while(hh <= tt && g[q[tt]] - (q[tt] - j) / c * w <= g[k] - (k - j) / c * w)
//                    tt--;
//                q[++tt] = k;
//            }
//        }
//    }
//    
//    cout << f[volume] << endl;
//    return 0;
//} 
//
//
//
////6.��ϱ�������----�и���Ʒ��ֻ��ѡһ��,�еĿ���ѡ������,�е�ѡ�Ĵ�������
//#include<iostream>
//#include<vector>
//using namespace std;
//
//class Good{
//public:
//    int kind;
//    int volume, weight;
//};
//
//int count, volume;
//int dp[1010];
//
//int main() {
//    cin >> count >> volume;
//    int v, w, s;
//    vector<Good> goods;
//    for(int i = 0; i < count; ++i) {
//        cin >> v >> w >> s;
//        if(s < 0)
//            goods.push_back({-1, v, w});
//        else if(s == 0)
//            goods.push_back({0, v, w});
//        else {
//            for(int k = 1; k <= s; k *= 2) {
//                goods.push_back({-1, k * v, k * w});
//                s -= k;
//            }
//            if(s > 0)
//                goods.push_back({-1, s * v, s * w});
//        }
//    }
//    
//    for(int i = 0; i < goods.size(); ++i) {
//        if(goods[i].kind == -1) {
//            for(int j = volume; j >= goods[i].volume; --j)
//                dp[j] = max(dp[j], dp[j - goods[i].volume] + goods[i].weight);
//        }
//        else {
//            for(int j = goods[i].volume; j <= volume; ++j)
//                dp[j] = max(dp[j], dp[j - goods[i].volume] + goods[i].weight);
//        }
//    }
//    
//    cout << dp[volume] << endl;
//    return 0;
//}
//
//
//
////7.��ά���ñ�������----��������������(���������)
//#include<iostream>
//using namespace std;
//
//int count, volume, weight;
//int dp[110][110];
//
//int main() {
//    cin >> count >> volume >> weight;
//    int a, b, c;
//    for(int i = 1; i <= count; ++i) {
//        cin >> a >> b >> c;
//        for(int j = volume; j >= a; --j)
//            for(int k = weight; k >= b; --k)
//                dp[j][k] = max(dp[j][k], dp[j - a][k - b] + c);
//    }
//
//    
//    //����ݹ�ֿ�
//    // int goods[1010][3];
//    // for(int i = 1; i <= count; ++i)
//    //     cin >> goods[i][0] >> goods[i][1] >> goods[i][2];
//        
//    // int dp[110][110] = {0};
//    // for(int i = 1; i <= count; ++i)
//    //     for(int j = volume; j >= goods[i][0]; --j)
//    //         for(int k = weight; k >= goods[i][1]; --k)
//    //             dp[j][k] = max(dp[j][k], dp[j - goods[i][0]][k - goods[i][1]] + goods[i][2]);
//    cout << dp[volume][weight];
//}
//
//
//
////8.���鱳������----ͬһ�����Ʒֻ��ѡһ��
//#include<iostream>
//#include<vector>
//using namespace std;
//
//class Good{
//public:
//    int volume, value;
//};
//
//vector<Good> goods;
//int count, volume;
//int dp[110];
//
//int main() {
//    cin >> count >> volume;
//    int in_count, v, w;
//    for(int i = 0; i < count; ++i) {
//        cin >> in_count;
//        for(int j = 0; j < in_count; ++j) {
//            cin >> v >> w;
//            goods.push_back({v, w});
//        }
//        
//        for(int j = volume; j >= 0; --j)
//            for(int k = 0; k < in_count; ++k)
//                if(j >= goods[k].volume)
//                    dp[j] = max(dp[j], dp[j - goods[k].volume] + goods[k].value);
//
//        goods.clear();
//    }
//    
//    cout << dp[volume];
//}
//
//
//
////9.�������ı�������----ѡ����ǰ����ѡ������
////˼·�������и��ڵ��j����ͼ�ֵ�ۼӵ��ӽڵ���,Ȼ����01�������
////���󣺿��ܰ�һ�����ڵ��ۼӶ��
//// #include<iostream>
//// using namespace std;
//
//// int count, volume;
//// int dp[110];
//
//// int main()
//// {
////     cin >> count >> volume;
////     int v[110], w[110], p[110];
////     for(int i = 1; i <= count; ++i)
////         cin >> v[i] >> w[i] >> p[i];
//    
////     //���ܱ�������ۼ� ���ڵ㲻һ����һ������
////     for(int i = 1; i <= count; ++i) {
////         while(p[i] != -1) {
////             v[i] += v[p[i]];
////             w[i] += w[p[i]];
////             p[i] = p[p[i]];
////         }
////     }
//    
////     for(int i = 1; i <= count; ++i)
////         for(int j = volume; j >= v[i]; --j)
////             dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
//        
////     cout << dp[volume];
////     return 0;
//// }
//
//
//
////9.�������ı�����������
//#include<iostream>
//#include<cstring>
//using namespace std;
//
//int count, volume;
//int v[110], w[110];
//int dp[110][110];
//
////��������ɱ�
//int h[110], e[110], ne[110], idx;
//
//void add(int x, int y) {
//    e[idx] = y;
//    ne[idx] = h[x];
//    h[x] = idx ++;
//}
//
//void dfs(int x) {
//    for(int i = h[x]; i != -1; i = ne[i]) {
//        int y = e[i];
//        dfs(y);
//        for(int j = volume - v[x]; j >= 0; --j)
//            for(int k = 0; k <= j; ++k)
//                dp[x][j] = max(dp[x][j], dp[x][j - k] + dp[y][k]);
//    }
//    
//    for(int i = volume; i >= v[x]; --i)
//        dp[x][i] = dp[x][i - v[x]] + w[x];
//        
//    for(int i = 0; i < v[x]; ++i)
//        dp[x][i] = 0;
//}
//
//int main() {
//    memset(h, -1, sizeof(h));
//    cin >> count >> volume;
//    int root;
//    for(int i = 1; i <= count; ++i) {
//        int p;
//        cin >> v[i] >> w[i] >> p;
//        if(p == -1)
//            root = i;
//        else
//            add(p, i);
//    }
//    dfs(root);
//    cout << dp[root][volume] << endl;
//    return 0;
//}
//
//
//
////10.�󷽰���
//#include<iostream>
//using namespace std;
//
//const int mod = 1000000007, INF = 1000000000;
//int volume, count;
//int f[1010], g[1010];
//
//int main() { 
//    cin >> count >> volume;
//    g[0] = 1;
//    for(int i = 1; i <= volume; ++i)
//        f[i] = -INF;
//        
//    for(int i = 0; i < count; ++i) {
//        int v, w;
//        cin >> v >> w;
//        for(int j = volume; j >= v; --j) {
//            int t = max(f[j], f[j - v] + w);
//            int s = 0;
//            if(t == f[j])
//                s += g[j];
//            if(t == f[j - v] + w)
//                s += g[j - v];
//            if(s >= mod)
//                s -= mod;
//            f[j] = t;
//            g[j] = s;
//        }
//    }
//    
//    // int maxn = 0;
//    // for(int i = 0; i <= volume; ++i)
//    //     maxn = max(maxn, f[i]);
//    
//    int res = 0;
//    for(int i = 0; i <= volume; ++i) {
//        if(f[volume] == f[i]) {
//            res += g[i];
//            if(res >= mod)
//                res -= mod;
//        }
//    }
//    cout << res;
//    return 0;
//}
//
//
////11.����巽��----�ֵ����С����
//#include<iostream>
//using namespace std;
//
//int count, volume;
//int f[1010][1010];
//int v[1010], w[1010];
//
//int main() {
//    cin >> count >> volume;
//    
//    for(int i = 1; i <= count; ++i)
//        cin >> v[i] >> w[i];
//        
//    for(int i = count; i >= 1; --i) {
//        for(int j = 0; j <= volume; ++j) {
//            f[i][j] = f[i + 1][j];
//            if(j >= v[i])
//                f[i][j] = max(f[i][j], f[i + 1][j - v[i]] + w[i]);
//        }
//    }
//
//    int vol = volume;
//    for(int i = 1; i <= count; ++i) {
//        if(vol - v[i] >= 0 && f[i][vol] == f[i + 1][vol - v[i]] + w[i]) {
//            cout << i << ' ';
//            vol -= v[i];
//        }
//    }
//    
//    return 0;
//}



//2.����н����� 
//#include<iostream>
//using namespace std;
//
//int main() {
//	int work[9][3] = { {0, 0, 0},
//		{5, 1, 4}, {1, 3, 5}, {8, 0, 6}, {4, 4, 7},
//		{6, 3, 8}, {3, 5, 9}, {2, 6, 10}, {4, 8, 11}
//	};
//	
//	int pre[9] = {0};
//	for(int i = 1; i < 9; ++i) {
//		for(int j = i - 1; j >= 1; --j) {
//			if(work[j][2] <= work[i][1]) {
//				pre[i] = j;
//				break;
//			}
//		}
//	}
//	
//	int opt[9] = {0};
//	for(int i = 1; i < 9; ++i)
//		opt[i] = max(opt[i - 1], work[i][0] + opt[pre[i]]);
//	
//	for(int i = 1; i < 9; ++i)
//		cout << i << " " << pre[i] << " " << opt[i] << endl;
//	return 0;
//}



//3.������������� 
//#include<iostream>
//using namespace std;
//
//int main() {
////	int nums[9] = {0, 0, 1, 2, 4, 1, 7, 8, 3};
////	int dp[9] = {0};
//	int count;
//	cin >> count;
//	int nums[100] = {0};
//	for(int i = 2; i < count + 2; ++i)
//		cin >> nums[i];
//		
//	int dp[100] = {0};
//	for(int i = 2; i < count + 2; ++i) {
//		dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
//		cout << i - 2 << " " << dp[i] << endl;
//	} 
//	return 0;
//}



//4.������Ӹպ�Ϊgoal 
//#include<iostream>
//using namespace std;
//
//int main() {
////	int nums[] = {3, 34, 5, 12, 2, 4};
////	int goal = 9;
////	bool maps[6][9] = {0};

//	int goal, count;
//	cin >> goal >> count;
//	int nums[100];
//	for(int i = 0; i < count; ++i)
//		cin >> nums[i];
//	
//	bool maps[100][100] = {0};
//	for(int i = 0; i < count; ++i) {
//		for(int j = 0; j < goal; ++j) {
//			if(j == 0)
//				maps[i][j] = true;
//			else if(i == 0 && j != nums[i])
//				maps[i][j] = false;
//			else if(i == 0 && j == nums[i])
//				maps[i][j] = true;
//			else {
//				if(nums[i] > j)
//					maps[i][j] = maps[i - 1][j];
//				else
//					maps[i][j] = (maps[i - 1][j] || maps[i - 1][j - nums[i]]);
//			}
//		}
//	}
//	cout << maps[count - 1][goal - 1] << endl;
//	return 0;
//} 
