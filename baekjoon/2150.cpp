//Tarjan ���
#include<stdio.h>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

stack<int> s;
vector<int> a[10005];
vector< vector<int> > ans;
int num[10005], low[10005];
bool check[10005];
int cnt = 0;
void dfs(int node){
	check[node] = true;
	s.push(node);
	num[node] = ++cnt;
	low[node] = cnt;
	for (int i = 0; i < a[node].size(); i++){
		int next = a[node][i];
		if (num[next] == 0){  //Tree Edge�� ���.
			dfs(next);
			low[node] = min(low[node], low[next]);
		}
		else if(check[next]){  //Back Edge�� ��츸 �� else if ���� ���� �ȴ�. Forward Edge�� �� �� ������ ���� low[node] == num[node]���� check[next]=false ó�����ش�.
			low[node] = min(low[node], num[next]);
		}
	}
	if (low[node] == num[node]){    //low[node] == num[node] �϶��� �ٷ� SCC�� ã�� ���̴�.
		vector<int> scc;
		while (!s.empty()){
			int x = s.top();
			scc.push_back(x);
			check[x] = false;
			s.pop();
			if (node == x)
				break;
		}
		sort(scc.begin(), scc.end());
		ans.push_back(scc);
	}
}

int main(){
	int n, m;
	scanf("%d %d",&n,&m);
	for (int i = 0; i < m; i++){
		int x, y;
		scanf("%d %d",&x,&y);
		a[x].push_back(y);
	}

	for (int i = 1; i <= n; i++){
		if (num[i] == 0){    //Forwardd Edge ó�� ������ check[i] ��ſ� num[i]�� ����Ѵ�.
			dfs(i);
		}
	}
	printf("%d\n",ans.size());
	sort(ans.begin(), ans.end());   //2���� ���͸� sort�ϸ� �� ������ ���� ù��° ���� �������� ���ĵȴ�.
	for (auto& scc : ans){
		for (int x : scc){
			printf("%d ",x);
		}
		printf("-1\n");
	}
	return 0;
}


////Kosaraju ���
//#include<cstdio>
//#include<vector>
//#include<queue>
//#include<stack>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//
//vector<int> a[10001];
//vector<int> r[10001];
//stack<int> s;
//vector<int> group[10001];
//bool check[10001];
//
//void dfs(int node, int group_num){
//	if (check[node])
//		return;
//	check[node] = true;
//	group[group_num].push_back(node);
//	for (int i = 0; i < r[node].size(); i++){
//		int next = r[node][i];
//		dfs(next, group_num);
//	}
//}
//
//void dfs(int node){
//	check[node] = true;
//	for (int i = 0; i < a[node].size(); i++){
//		int next = a[node][i];
//		if (!check[next]){
//			dfs(next);
//		}
//	}
//	s.push(node);
//}
//
//int main(){
//	int v, e;
//	scanf("%d %d", &v, &e);
//
//	for (int i = 0; i < e; i++){
//		int x, y;
//		scanf("%d %d", &x, &y);
//		a[x].push_back(y);
//		r[y].push_back(x);
//	}
//	for (int i = 1; i <= v; i++){
//		if (!check[i]){
//			dfs(i);
//		}
//	}
//	memset(check + 1, false, sizeof(bool)*v);
//	int group_num = 0;
//	while (!s.empty()){
//		int node = s.top();
//		s.pop();
//		if (!check[node]){
//			dfs(node, ++group_num);
//		}
//	}
//
//	priority_queue< pair<int, int> > print_order;
//	for (int i = 1; i <= group_num; i++){
//		sort(group[i].begin(), group[i].end());
//		print_order.push({ -group[i][0], i });
//	}
//
//	printf("%d\n", group_num);
//	while (!print_order.empty()){
//		auto p = print_order.top();
//		print_order.pop();
//		int k = p.second;
//		for (int j = 0; j < group[k].size(); j++){
//			printf("%d ", group[k][j]);
//		}
//		printf("-1\n");
//	}
//	return 0;
//}