#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
vector<int> a[50001];
int parent[50001];          //�� ����� parent ��带 ����.
bool check[50001];
int depth[50001];           //�� ����� depth�� ����.

int lca(int u,int v){
	if (depth[u] < depth[v]){                   // u�� ������ depth�� �� ū �༮���� ��´�. (level�� �� ���� �༮)
		swap(u, v);
	}
	while (depth[u] != depth[v]){              // depth�� ������������ u�� ���� �ø���.
		u = parent[u];
	}
	while (u != v){                       //u �� v�� ������������ u,v�� ���� �ø���.
		u = parent[u];
		v = parent[v];
	}
	return u;                           // u�� v�� �������ٸ� �װ��� �ٷ� LCA �̴�.
}

int lca(int u,int v){
	if (depth[u] < depth[v]){
		swap(u, v);
	}
	while (depth[u] != depth[v]){
		u = parent[u];
	}
	while (u != v){
		u = parent[u];
		v = parent[v];
	}
	return u;
}

void bfs(int start){
	queue<int> q;
	q.push(start);
	while (!q.empty()){
		int node = q.front();
		q.pop();
		for (int& next : a[node]){
			if (!check[next]){
				depth[next] = depth[node] + 1;
				check[next] = true;
				parent[next] = node;
				q.push(next);
			}
		}
	}
}

int main(){
	int n;
	scanf("%d",&n);
	for (int i = 0; i < n-1; i++){
		int x, y;
		scanf("%d %d",&x,&y);
		a[x].push_back(y);                // Ʈ���� �ܹ����� �ƴ� ����� �׷����� �����Ѵ�.
		a[y].push_back(x);
	}
	depth[1] = 0;
	check[1] = true;
	bfs(1);

	int m;
	scanf("%d",&m);
	for (int i = 0; i < m; i++){
		int x, y;
		scanf("%d %d",&x,&y);
		printf("%d\n",lca(x,y));
	}
	return 0;
}