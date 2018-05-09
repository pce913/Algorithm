//#include<stdio.h>
//#include<vector>
//using namespace std;
//
//int dist[501];
//vector< pair<int,int> > a[501];
//int main(){
//	int n, m;
//	scanf("%d %d",&n,&m);
//	for (int i = 0; i < m; i++){
//		int x, y, z;
//		scanf("%d %d %d",&x,&y,&z);
//		a[x].push_back(make_pair(y, z));
//	}
//	const int MAX = 100000000;
//	for (int i = 1; i <= n; i++)
//		dist[i] = MAX;
//
//	dist[1] = 0;                   // 1�� ���ÿ��� ���.
//	bool negative_cycle = false;
//	
//	for (int k = 1; k <= n; k++){      //������ n-1�� �ݺ��ϴµ� ���� ����Ŭ�� üũ�ϱ� ���� �ѹ� �� �ݺ� ��Ų��.
//		for (int i = 1; i <= n; i++){        
//			for (int j = 0; j < a[i].size(); j++){            //���� ����Ŭ�� �ִٸ� ������ �ݺ����� dist�� �� ���������� '���Ѵ�.'
//				int from = i;                                 // ������ ������ ���� ����Ŭ�� ���� ���̴�.
//				int to = a[i][j].first;
//				int cost = a[i][j].second;
//
//				if (dist[from] != MAX && dist[to] > dist[from] + cost){
//					dist[to] = dist[from] + cost;
//					if (k == n){
//						negative_cycle = true;
//					}
//				}
//			}
//		}
//	}
//	
//	if (negative_cycle)
//		printf("-1\n");
//	else{
//		for (int i = 2; i <= n; i++){
//			if (dist[i] == MAX)
//				printf("-1\n");
//			else{
//				printf("%d\n",dist[i]);
//			}
//		}
//	}
//	return 0;
//}
#include<stdio.h>
#include<vector>
using namespace std;
vector< pair<int, int> > a[501];
int dist[501];
int main(){
	const int INF = 100000000;
	int n, m;
	scanf("%d %d",&n,&m);
	for (int i = 0; i < m; i++){
		int x, y, z;
		scanf("%d %d %d",&x,&y,&z);
		a[x].push_back({y,z});
	}
	for (int i = 1; i <= n; i++)
		dist[i] = INF;

	dist[1] = 0;
	bool negative_cycle = false;
	for (int k = 1; k <= n; k++){
		for (int i = 1; i <= n; i++){
			for (auto &v : a[i]){
				int node = i;
				int next = v.first;
				int cost = v.second;
				if (dist[node] != INF && dist[next] > dist[node] + cost){
					dist[next] = dist[node] + cost;
					if (k == n)
						negative_cycle = true;
				}
			}
		}
	}
	if (negative_cycle)
		printf("-1\n");
	else{
		for (int i = 2; i <= n; i++)
			printf("%d\n", dist[i] == INF ? -1 : dist[i]);
	}
	return 0;
}