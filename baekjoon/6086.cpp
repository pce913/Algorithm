#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
////codecollector.tistory.com/276 
int n, m, f;
string u, v;
struct MaximumFlow {
	struct Edge //������ �뷮�� ������ ����ü ����
	{
		int to;
		int capacity;
		Edge *reverse;
		Edge(int to, int capacity) :to(to), capacity(capacity) {};
	};

	int n;
	int source;
	int sink;
	vector<vector<Edge*>> graph;//Edge�� ����ü�� 2���� ���� ����
	MaximumFlow(int n, int source, int sink) :n(n), source(source), sink(sink)
	{
		graph.resize(n);
	};//������ ������ �־������� �׸�ŭ ������ ũ�⸦ Ȯ�������

	void add_Edge(int u, int v, int capacity)
	{
		Edge *ori = new Edge(v, capacity);
		Edge *reverse = new Edge(u, 0);//������
		ori->reverse = reverse;
		reverse->reverse = ori;
		graph[u].push_back(ori);
		graph[v].push_back(reverse);
	}
	int bfs()
	{
		vector <bool> check(n, false);
		vector <pair<int, int>> from(n, make_pair(-1, -1));
		queue <int> q;
		q.push(source);//������ Ǫ�� ��
		check[source] = true;//üũ
		while (!q.empty())
		{
			int x = q.front();
			q.pop();
			for (int i = 0; i < graph[x].size(); i++)
			{
				int y = graph[x][i]->to;
				if (graph[x][i]->capacity > 0 && check[y] == 0)//�뷮�� 0���� ũ�� üũ�� �ȵǾ��ٸ�
				{
					q.push(y);
					check[y] = true;
					from[y] = make_pair(x, i);//���� x�� i�� �̾���
				}
			}
		}
		//�������� üũ�� �ȵǾ��ٸ� �� �׷����� source�� sink�� ������ �ȵǾ������� �ǹ���
		if (check[sink] == 0)
		{
			return 0;//�׷��Ƿ� ����
		}
		int s = sink;
		int c = graph[from[s].first][from[s].second]->capacity;
		while (from[s].first != -1)
		{
			if (c > graph[from[s].first][from[s].second]->capacity)
			{
				c = graph[from[s].first][from[s].second]->capacity;
			}
			s = from[s].first;
		}
		s = sink;
		while (from[s].first != -1)
		{
			Edge *e = graph[from[s].first][from[s].second];
			e->capacity -= c;//���� ������ -
			e->reverse->capacity += c;//���� ������ +
			s = from[s].first;
		}
		return c;
	}
	int flow()
	{
		int ans = 0;
		while (1)
		{
			int f = bfs();

			if (f == 0) { break; }
			ans += f;
		}
		return ans;
	}
};

int node(string s)
{
	if (s[0] >= 'A'&&s[0] <= 'Z')
		return s[0] - 'A';
	else
		return s[0] - 'a' + 26;
}
int main() {
	cin >> n;
	MaximumFlow mf(52, 0, 'Z' - 'A');
	for (int i = 0; i < n; i++)
	{
		cin >> u >> v >> f;
		int p1, p2;
		p1 = node(u);
		p2 = node(v);
		mf.add_Edge(p1, p2, f);
		mf.add_Edge(p2, p1, f);
	}
	cout << mf.flow() << '\n';
}
//#include<stdio.h>
//#include<vector>
//#include<algorithm>
//#include<cstring>
//using namespace std;
//
//struct Edge{
//	int to;            //������ ����Ű�� �ִ� ���.
//	int cap;         //residual_capacity
//	int rev;          // to ������ �鿧��(ȸ������)�� ��ġ.
//	Edge(int _to,int _cap,int _rev):to(_to),cap(_cap),rev(_rev){}
//};
//
//vector<Edge> graph[257];
//bool check[257];
//void add_edge(int from,int to,int cap){
//	int a = graph[from].size();  
//	int b = graph[to].size();     //to���� from���� ������ �鿧���� ��ġ�� ����. 
//	graph[from].push_back(Edge(to,cap,b));
//	graph[to].push_back(Edge(from,0,a));            //�� ������ �޾���
//}
//
//int dfs(int here,int sink,int flow){
//	check[here] = true;
//	if (here == sink){
//		return flow;
//	}
//
//	for (int i = 0; i < graph[here].size(); i++){
//		Edge& ne = graph[here][i];     //�ݵ�� & �ٿ���� �Ѵ�. e.cap�� -- �� �ϱ� ������.
//
//		if (!check[ne.to]){  
//			if (ne.cap>0){
//				int d=dfs(ne.to,sink,min(flow,ne.cap));
//				if (d > 0){
//					ne.cap -= d;
//					graph[ne.to][ne.rev].cap += d;
//					return d;
//				}
//			}
//		}
//	}
//	return 0;     //0�� ���� �Ǿ��ٴ� ���� argument path�� ��ã�Ҵٴ� ���̴�. ��, ���̻� �÷ο츦 �긱�� ���ٴ� �ǹ�.
//}
//
//int max_flow(int src,int sink){
//	int flow = 0;
//	int store = 1;
//	while (store > 0){
//		memset(check, false, sizeof(check));
//		store = dfs(src, sink, 1e9);
//		flow += store;
//	}
//	return flow;
//}
//
//int main(){
//	int n;
//	scanf("%d",&n);
//	for (int i = 1; i <= n; i++){
//		char u, v;
//		int w;
//		scanf(" %c %c %d",&u,&v,&w);
//		add_edge(u,v,w);
//	}
//	int ans = max_flow('A','Z');
//	printf("%d",ans);
//	return 0;
//}