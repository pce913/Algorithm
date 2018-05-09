#include<stdio.h>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
//���� long long
//ans1: degree�� 1�� �༮���� ����
//ans2: degree�� 1�� (BCC�� ũ�� - 1)�� ��

bool check[50005], cut[50005];
vector<long long> a[50005], node_color[50005], bcc[50005];
long long low[50005], num[50005];
long long timer;
long long n, m;
long long cpiv;
void dfs(long long node, long long parent, long long root){
	low[node] = num[node] = ++timer;
	long long children = 0;
	for (long long next : a[node]){
		if (next == parent)
			continue;

		if (num[next] == 0){
			children++;
			dfs(next, node, root);
			low[node] = min(low[node], low[next]);

			if (node == root && children >= 2){
				cut[node] = true;
			}

			if (node != root && low[next] >= num[node]){
				cut[node] = true;
			}

		}
		else{
			low[node] = min(low[node], num[next]);
		}
	}
}

void color(long long node, long long c){  //�� �ڵ带 ����� ��� ��� ��尡 bcc ���� �ȿ� ���� ���� �ƴϴ�. if(c>0) ���� ������ ó�� ���� �ȵ� �� ����.
	if (c > 0){    //ù��° ��常 ���������� �� �ڵ� ���� �Ƚ�Ŵ.
		node_color[node].push_back(c);
	}
	check[node] = true;
	for (long long next : a[node]){
		if (check[next])
			continue;
		if (low[next] >= num[node]){  //�̰� ������ �ƴѰ�? ������ �������� �ƴϴ�. �������� ��Ʈ�� ���ܷ� ����� �ϴµ� �� �ڵ尡 ����.
			node_color[node].push_back(++cpiv);
			color(next, cpiv);
		}
		else{
			color(next, c);
		}
	}
}

void init(){
	n = 0;
	timer = 0;
	cpiv = 0;
	memset(cut, false, sizeof(cut));
	memset(low, 0, sizeof(low));
	memset(check, 0, sizeof(check));
	memset(num, 0, sizeof(num));
}

void solve(long long test){
	init();
	for (long long i = 0; i < m; i++){
		long long x, y;
		scanf("%lld %lld", &x, &y);
		a[x].push_back(y);
		a[y].push_back(x);
		n = max(n, x);
		n = max(n, y);
	}
	printf("Case %lld: ", test);
	dfs(1, -1, 1);   //input���� �׻� ����׷����� �شٰ� ��.
	color(1, 0);  //�̷��� �ϸ� �� �����Ѵ�.
	for (long long i = 1; i <= n; i++){
		for (long long color : node_color[i]){
			bcc[color].push_back(i);
		}
	}

	long long ans1 = 0;
	long long ans2 = 1;
	for (long long i = 1; i <= cpiv; i++){
		long long degree = 0;
		for (long long node : bcc[i]){
			if (cut[node]){
				degree++;
			}
		}
		if (degree == 1){
			ans1++;
			ans2 = ans2*((long long)bcc[i].size() - 1);
		}
	}
	if (ans1 > 0)
		printf("%lld %lld\n", ans1, ans2);
	else    //degree�� 1�� �༮�� �������� ���� ���
		printf("2 %lld\n", (long long)n*(n - 1) / 2);
	for (long long i = 1; i <= n; i++){
		a[i].clear();
		node_color[i].clear();
	}
	for (long long i = 1; i <= cpiv; i++)bcc[i].clear();
}

int main(){
	long long test = 1;
	while (true){
		scanf("%lld", &m);
		if (m == 0)
			break;
		solve(test++);
	}
	return 0;
}
//#include<stdio.h>
//#include<vector>
//#include<cstring>
//#include<algorithm>
//using namespace std;
////���� long long
//
//bool check[50005], cut[50005];
//vector<long long> a[50005];
//long long low[50005], num[50005], last[50005];
//long long timer;
//long long cut_cnt;
//long long n, m;
//void dfs(long long node, long long parent, long long root){
//	low[node] = num[node] = ++timer;
//	long long children = 0;
//	for (long long next : a[node]){
//		if (next == parent)
//			continue;
//
//		if (num[next] == 0){
//			children++;
//			dfs(next, node, root);
//			low[node] = min(low[node], low[next]);
//
//			if (node == root && children >= 2){
//				cut[node] = true;
//				cut_cnt++;
//			}
//
//			if (node != root && low[next] >= num[node]){
//				cut[node] = true;
//				cut_cnt++;
//			}
//
//		}
//		else{
//			low[node] = min(low[node], num[next]);
//		}
//	}
//}
//
//void ff(long long n, long long &size, long long &conn, long long id)
//{
//	check[n] = 1;
//	size++;
//	for (long long t : a[n]){
//		if (cut[t]){
//			if (last[t] != id) conn++;
//			last[t] = id;
//			continue;
//		}
//		if (check[t]) continue;
//		ff(t, size, conn, id);
//	}
//}
//
//void init(){
//	n = 0;
//	timer = 0;
//	cut_cnt = 0;
//	memset(cut, false, sizeof(cut));
//	memset(low, 0, sizeof(low));
//	memset(check, 0, sizeof(check));
//	memset(num, 0, sizeof(num));
//	memset(last, 0, sizeof(last));
//}
//
//void solve(long long test){
//	init();
//	for (long long i = 0; i < m; i++){
//		long long x, y;
//		scanf("%lld %lld", &x, &y);
//		a[x].push_back(y);
//		a[y].push_back(x);
//		n = max(n, x);
//		n = max(n, y);
//	}
//	printf("Case %lld: ", test);
//	dfs(1, -1, 1);   //input���� �׻� ����׷����� �شٰ� ��.
//	long long ans1 = 0, ans2 = 1;
//	for (long long i = 1; i <= n; i++){
//		if (!cut[i] && !check[i]){
//			long long size = 0, conn = 0;
//			ff(i, size, conn, i);
//			if (conn == 1)ans1++, ans2 *= size;
//		}
//	}
//
//	if (ans1)
//		printf("%lld %lld\n", ans1, ans2);
//	else
//		printf("2 %lld\n", (long long)n*(n - 1) / 2);
//	for (long long i = 1; i <= n; i++)a[i].clear();
//
//}
//
//int main(){
//	long long test = 1;
//	while (true){
//		scanf("%lld", &m);
//		if (m == 0)
//			break;
//		solve(test++);
//	}
//	return 0;
//}