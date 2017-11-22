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
	int log = 0;    //u�������� �ִ� ��ĭ���� ���� �ö� �� �ִ����� ����.
	while ((1 << (log + 1)) <= depth[u]){
		log++;
	}
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