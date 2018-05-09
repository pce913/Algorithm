#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> a[100005];
int parent[100005], num[100005], low[100005];
bool check[100005];
int cnt = 0;
vector< pair<int, int> > ans;

void dfs(int node){
	check[node] = true;
	num[node] = ++cnt;
	low[node] = cnt;
	
	for (int i = 0; i < a[node].size(); i++){
		int next = a[node][i];

		if (next == parent[node])  //�̰� �ݵ�� �־�� ��. DFS Tree�� 'Ʈ��' �̹Ƿ� �θ� ���� �ٽ� ���� �ȵȴ�.
			continue;            //���⼭�� check�迭�� ������� �Ǵ� �� �� �����Ƿ� �� �ڵ� �ݵ�� �־�� �Ѵ�.

		if (!check[next]){
			parent[next] = node;
			dfs(next);
			low[node] = min(low[node], low[next]);
			if (low[next] > num[node]){
				ans.push_back({ min(node, next), max(node, next) });
			}
		}
		else{
			low[node] = min(low[node], num[next]);
		}
	}
}

int main(){
	int v, e;
	scanf("%d %d",&v,&e);
	for (int i = 0; i < e; i++){
		int x, y;
		scanf("%d %d",&x,&y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	dfs(1);
	sort(ans.begin(), ans.end());
	printf("%d\n",ans.size());
	for (int i = 0; i < ans.size(); i++){
		printf("%d %d\n",ans[i].first,ans[i].second);
	}
	return 0;
}
