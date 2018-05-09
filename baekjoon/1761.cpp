#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

struct Edge{
	int to, cost;
};
const int MAXN = 40005;
int parent[MAXN];
int p[MAXN][20];
bool check[MAXN];
int dist[MAXN];
int depth[MAXN];

vector<Edge> a[MAXN];



int lca(int u,int v){
	if (depth[u] < depth[v])     //������ u�� �Ʒ��� ����.
		swap(u, v);

	int log = 0;
	while ((1 << log) <= depth[u]){
		log++;
	}
	log--;
	for (int i = log; i >= 0; i--){
		if (depth[u] - (1 << i) >= depth[v]){
			u = p[u][i];
		}
	}
	if (u == v)
		return u;

	for (int i = log; i >= 0; i--){
		if (p[u][i] != 0 && p[u][i] != p[v][i]){
			u = p[u][i];
			v = p[v][i];
		}
	}
	return parent[u];
}

int getDist(int u, int v){
	return dist[u] + dist[v] - 2 * dist[lca(u, v)];
}

void bfs(int start){
	queue<int> q;
	q.push(start);
	check[start] = true;
	while (!q.empty()){
		int node = q.front();
		q.pop();
		for (int i = 0; i < a[node].size(); i++){
			int next = a[node][i].to;
			int cost = a[node][i].cost;
			if (!check[next]){
				check[next] = true;
				parent[next] = node;
				depth[next] = depth[node] + 1;
				dist[next] = dist[node] + cost;
				q.push(next);
			}
		}
	}
}

int main(){
	int n;
	scanf("%d",&n);
	for (int i = 0; i < n - 1; i++){
		int x, y, z;
		scanf("%d %d %d",&x,&y,&z);
		a[x].push_back({ y, z });
		a[y].push_back({ x, z });
	}
	bfs(1);
	for (int i = 1; i <=n ; i++){
		p[i][0] = parent[i];
	}
	for (int j = 1; (1 << j) < n; j++){
		for (int i = 1; i <= n; i++){
			if (p[i][j - 1] != 0){
				p[i][j] = p[p[i][j - 1]][j - 1];
			}
			
		}
	}
	int m;
	scanf("%d",&m);
	for (int i = 1; i <= m; i++){
		int x, y;
		scanf("%d %d",&x,&y);
		printf("%d\n",getDist(x,y));
	}

	return 0;
}

//#include<stdio.h>
//#include<vector>
//#include<queue>
//using namespace std;
//vector< pair<int,int> > a[40001];
//int parent[40001];          //�� ����� parent ��带 ����.
//bool check[40001];
//int depth[40001];           //�� ����� depth�� ����.
//int dist[40001];           // ��Ʈ�κ��� �� ���������� �Ÿ�
//
//int lca(int u, int v){
//	if (depth[u] < depth[v]){                   // u�� ������ depth�� �� ū �༮���� ��´�. (level�� �� ���� �༮)
//		swap(u, v);
//	}
//	while (depth[u] != depth[v]){              // depth�� ������������ u�� ���� �ø���.
//		u = parent[u];
//	}
//	while (u != v){                       //u �� v�� ������������ u,v�� ���� �ø���.
//		u = parent[u];
//		v = parent[v];
//	}
//	return u;                           // u�� v�� �������ٸ� �װ��� �ٷ� LCA �̴�.
//}
//
//void bfs(int start){
//	queue<int> q;
//	q.push(start);
//	while (!q.empty()){
//		int node = q.front();
//		q.pop();
//		for (auto& p : a[node]){
//			int next = p.first;
//			int cost = p.second;
//			if (!check[next]){
//				depth[next] = depth[node] + 1;
//				dist[next] = dist[node] + cost;
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
//		int x, y,z;
//		scanf("%d %d %d", &x, &y,&z);
//		a[x].push_back({y,z});                // Ʈ���� �ܹ����� �ƴ� ����� �׷����� �����Ѵ�.
//		a[y].push_back({x,z});
//	}
//	depth[1] = 0;
//	check[1] = true;
//	bfs(1);
//
//	int m;
//	scanf("%d", &m);
//	for (int i = 0; i < m; i++){
//		int x, y;
//		scanf("%d %d", &x, &y);
//		printf("%d\n", dist[x] + dist[y] - 2 * dist[lca(x, y)]);
//	}
//	return 0;
//}


//#include<stdio.h>
//#include<vector>
//#include<queue>
//#include<cstring>
//using namespace std;
//vector< pair<int, int> > a[40001];
//bool check[40001];
//int dist[40001];           // ��Ʈ�κ��� �� ���������� �Ÿ�
//
//int w, g;
//                                                       // bfs �ι� ���
//int bfs(int start){
//	check[start] = true;
//	queue<int> q;
//	q.push(start);
//	while (!q.empty()){
//		int node = q.front();
//		q.pop();
//		for (auto& p : a[node]){
//			int next = p.first;
//			int cost = p.second;
//			if (!check[next]){
//				dist[next] = dist[node] + cost;
//				check[next] = true;
//				if (next == w || next== g){
//					return next;
//				}
//				q.push(next);
//			}
//		}
//	}
//	return 0;
//}
//
//int main(){
//	int n;
//	scanf("%d", &n);
//	for (int i = 0; i < n - 1; i++){
//		int x, y, z;
//		scanf("%d %d %d", &x, &y, &z);
//		a[x].push_back({ y, z });                // Ʈ���� �ܹ����� �ƴ� ����� �׷����� �����Ѵ�.
//		a[y].push_back({ x, z });
//	}
//	
//	int m;
//	scanf("%d", &m);
//	for (int i = 0; i < m; i++){                          // ������ �������̱� ������ bfs�� ����������
//		scanf("%d %d", &w, &g);                           // �ð� �ʰ��� ���� �ȴ�.
//		int u=bfs(1);
//		int first_distance = dist[u];
//		memset(dist, 0, sizeof(int)*n);
//		memset(check,false,sizeof(bool)*n);
//		int v = bfs(u);
//		int second_distance = dist[v];
//		printf("%d\n",second_distance );
//	}
//	return 0;
//}