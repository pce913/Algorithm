#include<stdio.h>
#include<vector>
#include<stack>
#include<cstring>
using namespace std;
/*
� ������ �ݵ�� ���̾�߸� �Ѵٴ� ������ 2-SAT �Ŀ� �� ��Ƶ�� �Ϸ��� 
(x1 V x1)
�̷� ���� �߰��ϸ� �ȴ�.
�� �� �� �ϳ� �̻��� ���̾�� �ϴµ�, ���� �Ȱ����ϱ� �ᱹ x1�� ���̾�߸� �Ѵٴ� �Ҹ��̴�.
*/

vector<int> a[2005],r[2005];
int n, m;
bool check[2005];
stack<int> s;
int group[2005];

void dfs(int node){
	check[node] = true;
	for (int i = 0; i < a[node].size(); i++){
		int next = a[node][i];
		if (!check[next]){
			dfs(next);
		}
	}
	s.push(node);
}

void dfs_rev(int node,int gnum){
	check[node] = true;
	group[node] = gnum;
	for (int i = 0; i < r[node].size(); i++){
		int next = r[node][i];
		if (!check[next]){
			dfs_rev(next,gnum);
		}
	}
}

void init(){
	for (int i = 1; i <= 2*n; i++){
		a[i].clear();
		r[i].clear();
	}
	memset(check, false, sizeof(check));
	memset(group, 0, sizeof(group));
}

int convert(int x){
	return x < 0 ? -x + n : x;
}

int exchange(int x){
	return x > n ? x - n : x + n;
}

void solve(){
	init();
	for (int i = 0; i < m; i++){
		int x, y;
		scanf("%d %d",&x,&y);
		x = convert(x);
		y = convert(y);
		a[exchange(x)].push_back(y);
		a[exchange(y)].push_back(x);
		r[y].push_back(exchange(x));
		r[x].push_back(exchange(y));
	}
	a[exchange(1)].push_back(1);
	r[1].push_back(exchange(1));
	for (int i = 1; i <= 2*n; i++){
		if (!check[i]){
			dfs(i);
		}
	}
	memset(check, false, sizeof(check));
	int gnum = 0;
	while (!s.empty()){
		int node = s.top();
		s.pop();
		if (!check[node]){
			dfs_rev(node, ++gnum);
		}
	}
	for (int i = 1; i <= n; i++){
		if (group[i] == group[i + n]){
			printf("no\n");
			return;
		}
	}
	printf("yes\n");
}

int main(){
	while (scanf("%d %d",&n,&m) == 2){
		solve();
	}
	return 0;
}