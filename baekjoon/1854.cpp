#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Edge{
	int to, cost;
	bool operator<(const Edge& e)const{
		return this->cost > e.cost;
	}
};

int n, m, k;
priority_queue<int> dist[1005];   //�� max������ �ؾ� �´°���?
vector<Edge> a[1005];
//bool check[1005];   //���⼭�� üũ�迭 ����ϸ� �ȵȴ�.

void dijkstra(int start){
	priority_queue<Edge> q;
	dist[start].push(0);
	q.push({ start, 0 });
	while (!q.empty()){
		auto p = q.top();   //�ִ� ��θ� �����°��� �ƴ϶�, �پ��� ��ΰ� ���´�.
		q.pop();
		int node = p.to;
		int cur_cost = p.cost;
		//�ִܰŸ� ������ �ƴϱ� ������ check�� ����ϸ� �ȵȴ�.
		for (int i = 0; i < a[node].size(); i++){
			int next = a[node][i].to;
			int ncost = a[node][i].cost;
			int next_dist = cur_cost + ncost;
			if (dist[next].size() < k ){   //�ϴ� k���� ��θ� �־��ش�.
				dist[next].push(next_dist);
				q.push({ next, next_dist });
			}
			else if (dist[next].top() > next_dist){  //k���� ��ΰ� �̹� ������ ��� heap�� root ��尡 k��° �ִܰ�ΰ� �ȴ�. �� ��κ��� ���� ��� ������ k��° ��θ� �����ϰ� �־��ش�.
				dist[next].pop();  
				dist[next].push(next_dist);
				q.push({ next, next_dist });   //���� ������ ��η� ���ؼ� �ٸ� ����� ��ε� ���� �� �� �����Ƿ� q�� �־��־�� �Ѵ�.
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;

	for (int i = 1; i <= m; i++){
		int x, y, z;
		cin >> x >> y >> z;
		a[x].push_back({ y, z });
	}
	dijkstra(1);
	for (int i = 1; i <= n; i++){
		if (dist[i].size() < k)
			cout << "-1\n";
		else{
			cout << dist[i].top() << "\n";
		}
	}
	return 0;
}