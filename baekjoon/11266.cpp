#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> a[10005];
bool check[10005];
int num[10005], low[10005], cut[10005], parent[10005];
int cnt = 0;
//�� ������ ����� �׷��� �̹Ƿ� SCC�� ���Ҷ��� �ڵ尡 �ణ �ٸ���.
//dfs���� forward ������ ���� ����� �� �ʿ䰡 ����.
//��Ȯ���� forward ������ check�迭�� ���ؼ� �ڵ����� �ɷ�����.
void dfs(int node){
	check[node] = true;
	num[node] = ++cnt;
	low[node] = cnt;

	int children = 0;
	for (int i = 0; i < a[node].size(); i++){
		int next = a[node][i];
		if (next == parent[node])  //�̰� �ݵ�� �־�� ��. DFS Tree�� 'Ʈ��' �̹Ƿ� �θ� ���� �ٽ� ���� �ȵȴ�.
			continue;            //���⼭�� check�迭�� ������� �Ǵ� �� �� �����Ƿ� �� �ڵ� �ݵ�� �־�� �Ѵ�.

		if (!check[next]){
			children += 1;
			parent[next] = node;
			dfs(next);
			low[node] = min(low[next], low[node]);
			if (parent[node] == 0 && children >= 2){
				cut[node] = true;
			}
			if (parent[node] != 0 && low[next] >= num[node]){
				cut[node] = true;
			}
		}
		else {  //back edge
			low[node] = min(low[node], num[next]);
		}

	}
}

int main(){
	int n, m;
	scanf("%d %d",&n,&m);
	for (int i = 0; i < m; i++){
		int x, y;
		scanf("%d %d",&x,&y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	for (int i = 1; i <= n; i++){
		if (!check[i]){
			dfs(i);
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; i++){
		if (cut[i])
			ans += 1;
	}
	printf("%d\n",ans);
	for (int i = 1; i <= n; i++){
		if (cut[i])
			printf("%d ",i);
	}
	return 0;
}

//#include<stdio.h>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//vector<int> a[10001];
//int num[10001];         // DFS�� ���°�� �湮�ߴ���
//int low[10001];           // DFS Tree�� i�� ��Ʈ�� �ϴ� ����Ʈ������ �� �� �ִ� ���� ���� �ִ� ����
//bool check[10001];
//vector<int> point;
//int timer = 1;
//bool isA[10001];
//void dfs(int node,int root){                       // low�� num ���
//	num[node] = low[node]=timer++;
//	int cnt = 0;
//	for (int& next : a[node]){
//		if (!check[next]){          //tree edge
//			check[next] = true;
//			dfs(next,root);
//			low[node] = min(low[node], low[next]);
//			cnt++;
//			if (node != root && low[next] >= num[node]){
//				isA[node] = true;
//			}
//		}
//		else{          //back edge
//			low[node] = min(low[node], num[next]);
//		}
//	}
//	
//	if (node == root){
//		isA[node] = (cnt >= 2);
//	}
//}
//
//int main(){                              // ���� �׷����� �ƴ� �� �ִ�.
//	int v, e;
//	scanf("%d %d",&v,&e);
//	for (int i = 1; i <= e; i++){
//		int x, y;
//		scanf("%d %d",&x,&y);
//		a[x].push_back(y);
//		a[y].push_back(x);
//	}
//
//	for (int i = 1; i <= v; i++){
//		if (!check[i]){
//			check[i] = true;
//			dfs(i,i);
//		}
//		if (isA[i]){
//			point.push_back(i);
//		}
//	}
//
//	printf("%d\n",point.size());
//	for (int i = 0; i < point.size(); i++){
//		printf("%d ",point[i]);
//	}
//	return 0;
//}