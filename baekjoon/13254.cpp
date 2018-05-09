#include<stdio.h>
#include<cstring>
#include<vector>
using namespace std;

/*
	1. ��� �� ������ �� ���ε��� �̿��� Ȯ���� ���Ѵ�.
	   �̷��� �ؼ� ������ ������ ������ ���θ� �̿��� Ȯ���� ���Ѵ�.
	2. �̷��� �� ���κ��� ������ Ȯ���� ���ϸ� �����̴�.
*/
int edge[55][55], house[55];
double temp[55];
vector<int> a[55];
int cnt;
void dfs(int node,int parent,int e_num,bool haveToCnt){
	if (haveToCnt){
		cnt++;
	}
	for (int i = 0; i < a[node].size(); i++){
		int next = a[node][i];
		if (next != parent){
			if (edge[node][next] == e_num || haveToCnt){
				dfs(next, node, e_num, true);
			}
			else{
				dfs(next, node, e_num, false);
			}
		}
	}
}

int main(){
	int n, m;
	scanf("%d %d",&n,&m);
	memset(edge, -1, sizeof(edge));
	for (int i = 0; i < n - 1; i++){
		temp[i] = 1;
	}
	for (int i = 0; i < n - 1; i++){
		int x, y;
		scanf("%d %d",&x,&y);
		a[x].push_back(y);
		a[y].push_back(x);
		edge[x][y] = i;
		edge[y][x] = i;
	}
	for (int i = 0; i < m; i++){
		scanf("%d",&house[i]);
	}
	double ans = 0;
	for (int i = 0; i < m ; i++){
		for (int j = 0; j < n - 1; j++){
			cnt = 0;
			dfs(house[i], -1, j, false);   //cnt: ���� Ȯ�� �� ���� �Ѿ �ִ� ���� ����.
			temp[j] *= (double)cnt / (n - 1);   //�ڽ��� �� ��ġ�� ���� ����ؾ� �ϹǷ� n-1
		}
	}
	for (int i = 0; i < n - 1; i++){
		ans += temp[i];
	}
	printf("%.10lf",ans);
	return 0;
}