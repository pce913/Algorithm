#include<stdio.h>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

struct Edge{
	int to;            //������ ����Ű�� �ִ� ���.
	int cap;         //residual_capacity
	int rev;          // to ������ �鿧��(ȸ������)�� ��ġ.
	Edge(int _to,int _cap,int _rev):to(_to),cap(_cap),rev(_rev){}
};

vector<Edge> graph[257];
bool check[257];
void add_edge(int from,int to,int cap){
	int a = graph[from].size();  
	int b = graph[to].size();     //to���� from���� ������ �鿧���� ��ġ�� ����. 
	graph[from].push_back(Edge(to,cap,b));
	graph[to].push_back(Edge(from,0,a));            //�� ������ �޾���
}

int dfs(int here,int sink,int flow){
	check[here] = true;
	if (here == sink){
		return flow;
	}

	for (int i = 0; i < graph[here].size(); i++){
		Edge& ne = graph[here][i];     //�ݵ�� & �ٿ���� �Ѵ�. e.cap�� -- �� �ϱ� ������.

		if (!check[ne.to]){  
			if (ne.cap>0){
				int d=dfs(ne.to,sink,min(flow,ne.cap));
				if (d > 0){
					ne.cap -= d;
					graph[ne.to][ne.rev].cap += d;
					return d;
				}
			}
		}
	}
	return 0;     //0�� ���� �Ǿ��ٴ� ���� argument path�� ��ã�Ҵٴ� ���̴�. ��, ���̻� �÷ο츦 �긱�� ���ٴ� �ǹ�.
}

int max_flow(int src,int sink){
	int flow = 0;
	int store = 1;
	while (store > 0){
		memset(check, false, sizeof(check));
		store = dfs(src, sink, 1e9);
		flow += store;
	}
	return flow;
}

int main(){
	int n;
	scanf("%d",&n);
	for (int i = 1; i <= n; i++){
		char u, v;
		int w;
		scanf(" %c %c %d",&u,&v,&w);
		add_edge(u,v,w);
	}
	int ans = max_flow('A','Z');
	printf("%d",ans);
	return 0;
}