#include<stdio.h>
#include<queue>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
/*
������ �����߾���.
���� ���� ��ü�� ��Ȯ�ϰ� ��õǾ� ���� �ʴ�.
Ƽ���� ������ �ű⿡ �⺻��� s�� �ٰ� �� �� ���ʹ� 1ų�ι��ʹ� p�� ����� å���ȴٴ� ����
1 -> 2 -> 3 -> 4 -> 5 �� �����Ѵٰ� ������,
1���� Ƽ���� ��� 1->2 ����, 2->3, 4->5���������� �����ϰ� �̿��Ѵٰ� �ϸ�
1���� Ƽ���� �����Ƿ� 3���� ������ 's + (1���� 3������ �Ÿ�*p)' ��� �ݾ��� �ο��ȴ�. (�̰Թٷ� ���� �����ߴ��κ�.)
3->4������ ���ӽ����� �� ��ȹ�̹Ƿ� (ci*(y + p*di)) / 100. �� �ݾ����� �̿��ϰ�,
4->5������ �ٽ� �����ϰ� �̿��� ���̹Ƿ� �⺻Ƽ�� s�� �ٽ� �����ϰ� �ȴ�. ��, 's + 14���� 5������ �Ÿ�*p' �� �� ������� �ϴ� ���̴�.
*/
struct Edge{
	int to;
	double cost;
	bool operator<(const Edge& e)const{
		return cost - e.cost > 1e-12;
	}
};
const double INF = 1e18;
vector<Edge> a[405];
double dist[405];
void dijkstra(int start){
	priority_queue<Edge> q;
	dist[start] = 0;
	q.push({ start, 0 });
	while (!q.empty()){
		auto p = q.top();
		q.pop();
		int node = p.to;
		double ccost = p.cost;
		if (ccost > dist[node])
			continue;
		for (int i = 0; i < a[node].size(); i++){
			int next = a[node][i].to;
			double cost = a[node][i].cost;
			if (dist[next] > dist[node] + cost){
				dist[next] = dist[node] + cost;
				q.push({ next, dist[next] });
			}
		}

	}
}

void init(int n){
	for (int i = 1; i <= 2 * n; i++){
		dist[i] = INF;
		a[i].clear();
	}
}

void solve(){
	int n, m, start, end, s, p, y;
	scanf("%d %d %d %d %d %d %d", &n, &m, &start, &end, &s, &p, &y);
	init(n);
	for (int i = 1; i <= n; i++)
	{
		a[i].push_back({ i + n, s });
		a[i + n].push_back({ i, 0 });
	}
	for (int i = 0; i < m; i++){  //���� �����ϴ� ����� �ٸ� �ڵ��� �ٸ���. ���� �������� �ٽ� ����.
		int ai, bi, ci, di;
		scanf("%d %d %d %d", &ai, &bi, &ci, &di);
		//double cost = min(double(s + p*di), ((double)ci / 100)*(y + p*di));
		a[ai].push_back({ bi, (ci*(y + p*di)) / 100. });
		a[bi].push_back({ ai, (ci*(y + p*di)) / 100. });
		a[ai + n].push_back({ bi + n, p*di });
		a[bi + n].push_back({ ai + n, p*di });
	}
	dijkstra(start);
	printf("%.2f\n", dist[end]);    //�ݿø� ��������.
}
int main(){
	int T;
	scanf("%d", &T);
	for (int test = 0; test < T; test++){
		solve();
	}
	return 0;
}