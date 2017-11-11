#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

const int MAXN = 100001;

vector<int> a[MAXN];
int depth[MAXN];
bool check[MAXN];
int parent[MAXN];     //�� ����� parent ��带 ����.
int p[MAXN][18];  //p[i][j]: ��� i�� 2^j��° ���� ����

void bfs(int start){
	queue<int> q;
	q.push(start);
	check[start] = true;
	while (!q.empty()){
		int node = q.front();
		q.pop();
		for (int i = 0; i < a[node].size(); i++){
			int next = a[node][i];
			if (!check[next]){
				check[next] = true;
				depth[next] = depth[node] + 1;
				parent[next] = node;
				q.push(next);
			}
		}
	}
}

int lca(int u, int v){
	if (depth[u] < depth[v]){
		swap(u, v);
	}
	int log = 1;    //u�������� �ִ� ��ĭ���� ���� �ö� �� �ִ����� ����.
	while ((1 << log) <= depth[u]){
		log++;
	}
	log--;
	for (int i = log; i >= 0; i--){
		if (depth[u] - (1 << i) >= depth[v]){
			u = p[u][i];
		}
	}
	if (u == v){   //�̷��� ���� �÷����� ��尡 �������ٸ� ���ܷ� ���� u�� ���ش�.
		return u;
	}
	else{
		for (int i = log; i >= 0; i--){
			if (p[u][i] != 0 && p[u][i] != p[v][i]){
				u = p[u][i];
				v = p[v][i];
			}
		}
		return parent[u];  // u�� v�� �������� �ٷ��������� �ö�� ���¿��� u�� parent�� LCA �̴�.
	}

}


int main(){
	int n; 
	scanf("%d",&n);
	for (int i = 0; i < n - 1; i++){
		int x, y;
		scanf("%d %d",&x,&y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	bfs(1);   //���� depth�� parent�� ���س��´�.
	for (int i = 1; i <= n; i++){
		p[i][0] = parent[i];   //�� ����� 2^0 ������ �ٷ� �θ��̴�.
	}

	for (int j = 1; (1 << j) < n; j++){   //
		for (int i = 1; i <= n; i++){
			if (p[i][j - 1] != 0){   //2^(j-1)��° ������ �����ϴ� ���
				p[i][j] = p[p[i][j - 1]][j - 1];    //2^3 + 2^3 == 2^4 �̰Ͱ� ����.
			}
		}
	}
	int m;
	scanf("%d",&m);
	for (int i = 0; i < m; i++){
		int x, y;
		scanf("%d %d",&x,&y);
		printf("%d\n",lca(x,y));
	}

	return 0;
}




//#include<stdio.h>
//#include<vector>
//#include<queue>
//using namespace std;
//vector<int> a[100001];
//int parent[100001];          //�� ����� parent ��带 ����.
//bool check[100001];
//int depth[100001];           //�� ����� depth�� ����.
//int p[100001][18];          //  p[i][j] : ���i�� 2^j��° ����
//
//int lca(int u, int v){
//	if (depth[u] < depth[v]){                   // u�� ������ depth�� �� ū �༮���� ��´�. (level�� �� ���� �༮)
//		swap(u, v);
//	}
//	int log = 1;             // u�������� �ִ� ��ĭ���� ���� �ö� �� �ִ����� ���Ѵ�.
//	while ((1<<log) <= depth[u]){
//		log++;
//	}
//	log--;
//	for (int i = log; i >= 0; i--){               
//		if (depth[u] - (1 << i) >= depth[v]){                 // u�� v�� ������������ u�� 2^i�� ���� �ø���.
//			u = p[u][i];
//		}
//	}
//	if (u == v){            // �̷��� ���� �÷����� ��尡 �������ٸ� ���ܷ� u�� �������ش�.
//		return u;
//	}
//	else{
//		for (int i = log;i>=0;i--){                    // depth(����)�� ������ ��尡 �ٸ���
//			if (p[u][i] != 0 && p[u][i] != p[v][i]){       // u��v�� �������� �������� 2^i�� ���� �ø���.
//				u = p[u][i];
//				v = p[v][i];
//			}
//		}
//		return parent[u];                  // u�� v�� �������� �ٷ��������� �ö�� ���¿��� u�� parent�� LCA �̴�.
//	}
//}
//
//void bfs(int start){
//	queue<int> q;
//	q.push(start);
//	while (!q.empty()){
//		int node = q.front();
//		q.pop();
//		for (int& next : a[node]){
//			if (!check[next]){
//				depth[next] = depth[node] + 1;
//				check[next] = true;
//				parent[next] = node;
//				q.push(next);
//			}
//		}
//	}
//}
//
//int main(){
//	int n;
//	scanf("%d", &n);
//	for (int i = 0; i < n - 1; i++){
//		int x, y;
//		scanf("%d %d", &x, &y);
//		a[x].push_back(y);                // Ʈ���� �ܹ����� �ƴ� ����� �׷����� �����Ѵ�.
//		a[y].push_back(x);
//	}
//	depth[1] = 0;
//	check[1] = true;
//	bfs(1);
//
//	for (int i = 1; i <= n; i++){
//		p[i][0] = parent[i];
//	}
//	for (int j = 1; (1 << j) < n; j++){
//		for (int i = 1; i <= n; i++){
//			if (p[i][j - 1] != 0){
//				p[i][j] = p[p[i][j - 1]][j - 1];           //i����� 2^j��° ������ i����� 2^(j-1)��° ������ 2^(j-1)��° ����� ����.
//			}
//		}
//	}
//
//	int m;
//	scanf("%d", &m);
//	for (int i = 0; i < m; i++){
//		int x, y;
//		scanf("%d %d", &x, &y);
//		printf("%d\n", lca(x, y));
//	}
//	return 0;
//}




//#include <cstdio>
//#include <vector>
//using namespace std;
//const int MAX = 100001;
//vector<int> a[MAX];
//int p[MAX][18];
//int tin[MAX];                                            //Ÿ�̸� �̿� �׷��� �̻��ϰԵ� �ð��ʰ� ����. �����ڵ� �׷��� �ٿ��� �ð��ʰ�.
//int tout[MAX];
//int timer;
//int l;
//void dfs(int v, int parent) {
//	tin[v] = ++timer;
//	p[v][0] = parent;
//	for (int i = 1; i <= l; i++) {                    // dfs�� �ϸ鼭 ���̳��� ���̺��� ä�� �� �ִ�.
//		p[v][i] = p[p[v][i - 1]][i - 1];             // dfs�� ����Ǹ鼭 ���� ����� parent ���� ��� ���̺��� ä���� �ֱ� �����̴�.
//	}
//	for (int to : a[v]) {
//		if (to != parent) {
//			dfs(to, v);
//		}
//	}
//	tout[v] = ++timer;
//}
//bool upper(int u, int v) {                             // u�� v�� ����� �ļ� ���������� Ȯ���Ѵ�.
//	return (tin[u] <= tin[v] && tout[u] >= tout[v]);
//}
//int lca(int u, int v) {
//	if (upper(u, v)) return u;                       // ����-�ļ� ������ �̹� ���� ����� ���� ������ ã�� ���̹Ƿ� return �Ѵ�.
//	if (upper(v, u)) return v;
//	for (int i = l; i >= 0; i--) {                   // ���� �ļ� ���谡 �ƴҰ�쿡 u�� 2^i �� ���� �ø���. 
//		if (!upper(p[u][i], v)) {
//			u = p[u][i];
//		}
//	}
//	return p[u][0];
//}
//int main() {
//	int n;
//	scanf("%d", &n);
//	for (int i = 0; i<n - 1; i++) {
//		int u, v;
//		scanf("%d %d", &u, &v);
//		a[u].push_back(v);
//		a[v].push_back(u);
//	}
//	for (l = 1; (1 << l) <= n; l++);
//	l -= 1;
//	dfs(1, 1);
//	int m;
//	scanf("%d", &m);
//	while (m--) {
//		int u, v;
//		scanf("%d %d", &u, &v);
//		printf("%d\n", lca(u, v));
//	}
//	return 0;
//}