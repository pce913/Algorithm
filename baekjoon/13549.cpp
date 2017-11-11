#include<stdio.h>
#include<queue>
using namespace std;

const int INF = 1000000000;
#define MAX 200001
bool check[MAX];
int dist[MAX];
int N, K;

void dijkstra(int start){
	dist[start] = 0;
	priority_queue< pair<int, int> > q;            //cost, node
	q.push({ 0, start });

	while (!q.empty()){
		auto p = q.top();
		q.pop();
		int node = p.second;
		if (node == K){                // q���� ���������� ������ �ִܰŸ��� ������ �ǹǷ� K�� ã������ break ��Ų��.
			break;
		}
		int next[3] = { node + 1, node - 1, 2 * node };
		if (!check[node]){
			check[node] = true;
			for (int i = 0; i < 3; i++){
				int to = next[i];
				int cost = ((i == 2) ? 0 : 1);
				if (to >= 0 && to < MAX){
					if (dist[to] > dist[node] + cost){
						dist[to] = dist[node] + cost;
						q.push({ -dist[to], to });
					}
				}
			}
		}

	}
}

int main(){
	scanf("%d %d", &N, &K);
	for (int i = 0; i < MAX; i++){
		dist[i] = INF;
	}
	dijkstra(N);
	printf("%d\n", dist[K]);
	return 0;
}