#define ver4

#ifdef ver4
#include<stdio.h>
#include<vector>
//#include<queue>
using namespace std;
struct Edge{
	int to, cost;
	bool operator<(const Edge& e)const{
		return this->cost > e.cost;
	}
};

template <typename T>
struct priority_queue{
	T* heap;    //Ȥ�ó� �迭 ũ�Ⱑ �ʹ� ũ�ٰ� �Ǵܵ� ��쿡�� �� �κ��� vector�� �ٲ���. �迭�� �̸� ��Ƴ����� stack �޸𸮰� �ʰ� �ǹǷ� ���� �Ҵ� ����.
	int n = 0;
	priority_queue(){
		heap = new T[10000005];
		n = 0;
	}
	~priority_queue(){
		delete[] heap;
	}
	void push(T value){
		heap[n++] = value;
		int node = n - 1;
		//��Ʈ�� �����ϰų� value�̻��� ���Ҹ� ���� ������ ���� ������ �ݺ�
		while (node > 0 && heap[(node - 1) / 2] < heap[node]){
			swap(heap[(node - 1) / 2], heap[node]);
			node = (node - 1) / 2;
		}
	}
	void pop(){
		heap[0] = heap[n - 1];
		n--;
		int node = 0;
		while (true){
			int left = 2 * node + 1;
			int right = 2 * node + 2;
			if (left >= n)  //���� ��忡 ���� ������
				break;
			int next = node;
			if (heap[next] < heap[left]){  //���� operator< �� ����ϹǷ� �� ������ ����Ҷ� '<' �� ���ִ°� ����. 
				next = left;
			}
			if (right < n && heap[next] < heap[right]){
				next = right;
			}
			if (next == node)  //�� �ڼ��� ��� �ڱ� �ڽ� ������ ���Ҹ� ������ ������
				break;
			swap(heap[node], heap[next]);
			node = next;
		}
	}
	T top(){
		return heap[0];
	}
	bool empty(){
		return n == 0;
	}
};

const int INF = 1e9;
vector<Edge> a[20001];
int dist[20001];
bool check[20001];
int pre[20001];

void dijkstra(int start){
	dist[start] = 0;
	priority_queue<Edge> q;
	q.push({ start, 0 });
	while (!q.empty()){
		auto p = q.top();
		q.pop();
		int node = p.to;
		/*if (dist[node] < p.cost)
		continue;*/
		if (check[node])
			continue;
		check[node] = true;
		for (int i = 0; i < a[node].size(); i++){
			int next = a[node][i].to;
			int cost = a[node][i].cost;
			if (dist[next] > dist[node] + cost){
				dist[next] = dist[node] + cost;
				q.push({ next, dist[next] });
			}
		}

	}
}

int main(){
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < m; i++){
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		a[x].push_back({ y, z });
	}
	for (int i = 1; i <= n; i++){
		dist[i] = INF;
	}
	dijkstra(k);
	for (int i = 1; i <= n; i++){
		if (dist[i] != INF)
			printf("%d\n", dist[i]);
		else{
			printf("INF\n");
		}
	}
	return 0;
}

#endif

#ifdef ver1
#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
struct Edge{
	int to, cost;
};

bool operator<(const Edge& u, const Edge& v){
	return u.cost > v.cost;               //�̰� �´�.
}

vector<Edge> a[20001];
int dist[20001];
bool check[20001];
void dijkstra(int start){
	dist[start] = 0;
	priority_queue< Edge > q;
	q.push({ start, 0 });
	while (!q.empty()){
		auto p = q.top();
		q.pop();
		int node = p.to;
		if (!check[node]){
			check[node] = true;
			for (int i = 0; i < a[node].size(); i++){
				int next = a[node][i].to;
				int cost = a[node][i].cost;
				if (dist[next] > dist[node] + cost){
					dist[next] = dist[node] + cost;
					q.push({ next, dist[next] });
				}
			}
		}
	}
}

int main(){
	const int INF = 100000000;
	int V, E, K;
	scanf("%d %d", &V, &E);
	scanf("%d", &K);
	for (int i = 0; i < E; i++){
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		a[u].push_back({ v, w });
	}
	for (int i = 1; i <= V; i++){
		dist[i] = INF;
	}
	dijkstra(K);
	for (int i = 1; i <= V; i++){
		if (dist[i] == INF)
			printf("INF\n");
		else
			printf("%d\n", dist[i]);
	}
	return 0;
}

#endif

#ifdef ver2
#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
struct Edge{
	int to, cost;
};

bool operator<(const Edge& u, const Edge& v){
	return u.cost > v.cost;               //�̰� �´�.
}

vector<Edge> a[20001];
int dist[20001];
void dijkstra(int start){
	dist[start] = 0;
	priority_queue< Edge > q;
	q.push({ start, 0 });
	while (!q.empty()){
		auto p = q.top();
		q.pop();
		int node = p.to;
		if (dist[node] < p.cost)    //üũ��ſ� �� ���� ��� �� �� �ִ�.
			continue;

		for (int i = 0; i < a[node].size(); i++){
			int next = a[node][i].to;
			int cost = a[node][i].cost;
			if (dist[next] > dist[node] + cost){
				dist[next] = dist[node] + cost;
				q.push({ next, dist[next] });
			}
		}
	}
}

int main(){
	const int INF = 100000000;
	int V, E, K;
	scanf("%d %d", &V, &E);
	scanf("%d", &K);
	for (int i = 0; i < E; i++){
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		a[u].push_back({ v, w });
	}
	for (int i = 1; i <= V; i++){
		dist[i] = INF;
	}
	dijkstra(K);
	for (int i = 1; i <= V; i++){
		if (dist[i] == INF)
			printf("INF\n");
		else
			printf("%d\n", dist[i]);
	}
	return 0;
}
#endif

#ifdef ver3

#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;

vector< pair<int, int> > a[20001];           // to , cost
bool check[20001];
int dist[20001];

void dijkstra(int start){
	dist[start] = 0;
	priority_queue< pair<int, int> > q;            //cost, node
	q.push({ 0, start });
	while (!q.empty()){
		auto p = q.top();
		q.pop();
		int node = p.second;
		if (!check[node]){
			check[node] = true;
			for (int i = 0; i < a[node].size(); i++){
				int next = a[node][i].first;
				int cost = a[node][i].second;
				if (dist[next] > dist[node] + cost){
					dist[next] = dist[node] + cost;
					q.push({ -dist[next], next });
				}
			}
		}

	}
}

int main(){
	const int INF = 100000000;
	int V, E, K;
	scanf("%d %d", &V, &E);
	scanf("%d", &K);
	for (int i = 0; i < E; i++){
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		a[u].push_back({ v, w });
	}
	for (int i = 1; i <= V; i++){
		dist[i] = INF;
	}
	dijkstra(K);
	for (int i = 1; i <= V; i++){
		if (dist[i] == INF)
			printf("INF\n");
		else
			printf("%d\n", dist[i]);
	}
	return 0;
}
#endif
