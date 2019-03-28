#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
const ll INF = 1e18;

struct Node{
	int node, next;
	ll cost;
}a[1000005];
int TC;
int head[35][200005];
ll bef[200005];  //내가 정답으로 취해야 할 cost를 저장
ll dist[200005];
int n, m;
ll ans;
int GN;
int make_node() {  //0번은 head위치에 있는 노드
	return ++GN;
}

void add(int u,int v,ll c) {
	int num = make_node();
	a[num].node = v;
	a[num].cost = c;
	a[num].next = head[TC][u];
	head[TC][u] = num;
}

void init() {
	GN = 0;
	++TC;
	for (int i = 1; i <= n; i++)dist[i] = INF;
}
const int BSIZE = 524288;
unsigned char buffer[BSIZE];
auto p = buffer + BSIZE;
inline unsigned char readChar() {
	if (p == buffer + BSIZE) {
		fread(buffer, 1, BSIZE, stdin);
		p = buffer;
	}
	return *p++;
}
int readInt() {
	unsigned char c = readChar();
	while (c < '-') {
		c = readChar();
	}
	int ret = 0;
	while (c >= '-') {
		ret = ret * 10 + c - '0';
		c = readChar();
	}
	return ret;
}
void dijkstra(int start) {
	priority_queue<pair<ll, int> > pq;
	dist[start] = 0;
	pq.push(make_pair(-dist[start], start));
	while (!pq.empty()) {
		auto p = pq.top();
		pq.pop();
		int node = p.second;
		ll cost = -p.first;
		if (cost > dist[node])continue;
		for (register int i = head[TC][node]; i != 0; i = a[i].next) {
			int next = a[i].node;
			ll ncost = a[i].cost;
			if (dist[next] > dist[node] + ncost) {
				dist[next] = dist[node] + ncost;
				bef[next] = ncost;
				pq.push(make_pair(-dist[next], next));
			}
			else if (dist[next] == dist[node] + ncost) {
				if (bef[next] > ncost) {
					bef[next] = ncost;
				}
			}
		}
	}
}

void solve(int test) {
	n = readInt(), m = readInt();
	init();
	for (register int i = 0, x, y, z; i < m; i++) {
		x = readInt(), y = readInt(), z = readInt();
		add(x, y, z);
		add(y, x, z);
	}
	ans = 0;
	dijkstra(1);
	for (int i = 1; i <= n; i++)ans += bef[i];
	cout << "#" << test << " " << ans << "\n";
}

int main() {
	int T = readInt();
	for (int test = 1; test <= T; test++)solve(test);
	return 0;
}
