//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<iostream>
//#include<string>
//#include<cstring>
//#include<vector>
//#include<stack>
//#include<queue>
//#include<set>
//#include<map>
//#include<tuple>
//#include<iomanip>
//#include<algorithm>
//#include<functional>
//#include<cmath>
//#include<unordered_set>
//#include<unordered_map>
//using namespace std;
//const long long INF = 1e18;
//const long long MAXN = 1000005;
//long long a[MAXN];
//long long l[MAXN], r[MAXN], parent[MAXN], sz[MAXN];
//
//long long Find(long long x){
//	if (x == parent[x])
//		return x;
//	return parent[x] = Find(parent[x]);
//}
//
//void Union(long long x,long long y){
//	x = Find(x), y = Find(y);
//	if (x != y){
//		parent[y] = x;
//		sz[x] += sz[y];
//	}
//}
//
//int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	long long k, n;
//	cin >> k >> n;
//	for (long long i = 1; i <= n; i++){
//		cin >> a[i];
//		parent[i] = i;   //k�� ��� ����
//		sz[i] = 1;
//	}
//	for (long long i = 1; i <= n - 1; i++){  //���� �׷����� ������.
//		if (a[i] == a[i + 1]){
//			Union(i, i + 1);
//		}
//	}
//	//left,right �������.
//	l[1] = -1;
//	r[n] = INF;
//	for (long long i = 2; i <= n; i++){
//		if (a[i] == a[i - 1])
//			l[i] = l[i - 1];
//		else
//			l[i] = i - 1;
//	}
//	for (long long i = n - 1; i >= 1; i--){
//		if (a[i] == a[i + 1])
//			r[i] = r[i + 1];
//		else
//			r[i] = i + 1;
//	}
//	long long q;
//	cin >> q;
//	long long ans = 0;
//	for (long long qq = 0; qq < q; qq++){
//		long long cmd;
//		cin >> cmd;
//		if (cmd == 1){  //����
//			long long x;
//			cin >> x;
//			x = Find(x);   //������ ����� ��ǥ�� ������
//			sz[x]--;  //��ǥ�� ũ�� 1 ����
//			if (sz[x] != 0)
//				continue;
//
//			if (l[x] != -1){
//				long long lnode = Find(l[x]); //�����ǥ�� ���� ��ǥ�� ������
//				long long rnode = INF;
//				if (r[x] != INF){
//					rnode = Find(r[x]);
//				}
//				r[lnode] = rnode; //���ʴ�ǥ�� �������� �����ǥ�� �������� ��.
//			}
//			if (r[x] != INF){
//				long long rnode = Find(r[x]);
//				long long lnode = -1;
//				if (l[x] != -1){
//					lnode = Find(l[x]);
//				}
//				l[rnode] = lnode;
//			}
//			if (l[x] != -1 && r[x] != INF){
//				if (a[l[x]] == a[r[x]]){
//					Union(l[x], r[x]);
//				}
//			}
//		}
//		else{    //��Ŭ������ ����
//			long long x;
//			cin >> x;
//			x = Find(x);
//			ans += sz[x];
//		}
//	}
//	cout << ans;
//	return 0;
//}
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<tuple>
#include<iomanip>
#include<algorithm>
#include<functional>
#include<cmath>
#include<unordered_set>
#include<unordered_map>
using namespace std;
const long long INF = 1e18;
const long long MAXN = 1000005;
long long a[MAXN];
long long l[MAXN], r[MAXN], parent[MAXN], sz[MAXN];

long long Find(long long x){
	if (x == parent[x])
		return x;
	return parent[x] = Find(parent[x]);
}

void Union(long long x, long long y){
	x = Find(x), y = Find(y);
	if (x != y){
		parent[y] = x;
		sz[x] += sz[y];
		l[x] = min(l[x], l[y]);   //�̰� ������ Ʋ��.
		r[x] = max(r[x], r[y]);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long k, n;
	cin >> k >> n;
	for (long long i = 1; i <= n; i++){
		cin >> a[i];
		parent[i] = i;   //k�� ��� ����
		sz[i] = 1;
	}
	for (long long i = 1; i <= n - 1; i++){  //���� �׷����� ������.
		if (a[i] == a[i + 1]){
			Union(i, i + 1);
		}
	}
	l[1] = -1, r[n] = INF;
	for (int i = 2; i <= n; i++){
		if (a[i] == a[i - 1])
			l[i] = l[i - 1];
		else
			l[i] = i - 1;
	}
	for (int i = n - 1; i >= 1; i--){
		if (a[i] == a[i + 1])
			r[i] = r[i + 1];
		else
			r[i] = i + 1;
	}
	long long q;
	cin >> q;
	long long ans = 0;
	for (long long qq = 0; qq < q; qq++){
		long long cmd;
		cin >> cmd;
		if (cmd == 1){  //����
			long long x;
			cin >> x;
			x = Find(x);   //������ ����� ��ǥ�� ������
			sz[x]--;  //��ǥ�� ũ�� 1 ����
			if (sz[x] != 0)
				continue;
		
			if (l[x] != -1){
				long long lnode = Find(l[x]); //�����ǥ�� ���� ��ǥ�� ������
				long long rnode = INF;
				if (r[x] != INF){
					rnode = Find(r[x]);
				}
				r[lnode] = rnode; //���ʴ�ǥ�� �������� �����ǥ�� �������� ��.
			}
			if (r[x] != INF){
				long long rnode = Find(r[x]);
				long long lnode = -1;
				if (l[x] != -1){
					lnode = Find(l[x]);
				}
				l[rnode] = lnode;
			}
			if (l[x] != -1 && r[x] != INF){
				if (a[l[x]] == a[r[x]]){
					Union(l[x], r[x]);
				}
			}
		}
		else{    //��Ŭ������ ����
			long long x;
			cin >> x;
			x = Find(x);
			ans += sz[x];
		}
	}
	cout << ans;
	return 0;
}