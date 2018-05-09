#include<stdio.h>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

vector<int> a[20005];
vector<int> r[20005];
vector<int> st;
bool check[20005];
int group[20005],indegree[20005],outdegree[20005];


//indegree�� 0�� ���� ������ outdegree�� 0�� ���� ���� �� �ִ��� ������ָ� �ȴ�.
//�׷����� ����Ŭ�� ������ �ϱ� ������ ����Ŭ�� �����Ϸ��� indegree�� outdegree�� ��� 1��
//�����ؾ� �ϱ� �����̴�.
//SCC�� ������ 1�϶��� ���ܷ� 0�� ����Ѵ�.
void dfs(int node){
	check[node] = true;
	for (int i = 0; i < a[node].size(); i++){
		int next = a[node][i];
		if (!check[next]){
			dfs(next);
		}
	}
	st.push_back(node);
}

void dfs_rev(int node, int group_num){
	check[node] = true;
	group[node] = group_num;
	for (int i = 0; i < r[node].size(); i++){
		int next = r[node][i];
		if (!check[next]){
			dfs_rev(next, group_num);
		}
	}
}

void find_degree(int node){
	check[node] = true;
	for (int i = 0; i < r[node].size(); i++){
		int next = r[node][i];
		if (group[next] != group[node]){
			indegree[group[next]]++;
			outdegree[group[node]]++;
		}
		if (!check[next]){
			find_degree(next);
		}
	}
}

void solve(){
	int n, m;
	scanf("%d %d",&n,&m);
	memset(check, false, sizeof(check));
	memset(group, 0, sizeof(group));
	memset(indegree, 0, sizeof(indegree));
	memset(outdegree, 0, sizeof(outdegree));
	st.clear();
	for (int i = 1; i <= n; i++){
		a[i].clear();
		r[i].clear();
	}
		
	for (int i = 0; i < m; i++){
		int x, y;
		scanf("%d %d",&x,&y);
		a[x].push_back(y);
		r[y].push_back(x);
	}
	for (int i = 1; i <= n; i++){
		if (!check[i]){
			dfs(i);
		}
	}

	memset(check, false, sizeof(check));
	int group_num = 0;
	for (int i = st.size() - 1; i >= 0; i--){
		int node = st[i];
		if (!check[node]){
			dfs_rev(node, ++group_num);
		}
	}

	memset(check, false, sizeof(check));
	for (int i = st.size() - 1; i >= 0; i--){
		int node = st[i];
		if (!check[node]){
			find_degree(node);
		}
	}

	if (group_num == 1){
		printf("0\n");
	}
	else{
		int icnt = 0, ocnt = 0;
		for (int i = 1; i <= group_num; i++){
			if (indegree[i] == 0)
				icnt++;
			if (outdegree[i] == 0)
				ocnt++;
		}
		printf("%d\n",max(icnt,ocnt));
	}
}

int main(){
	int T;
	scanf("%d",&T);
	for (int test = 1; test <= T; test++){
		solve();
	}
	return 0;
}