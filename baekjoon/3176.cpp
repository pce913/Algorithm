#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

struct Edge{
	int to, cost;
};

vector<Edge> a[100001];
int parent[100001];          //�� ����� parent ��带 ����.
bool check[100001];
int depth[100001];           //�� ����� depth�� ����.
int p[100001][18];          //  p[i][j] : ���i�� 2^j��° ����
int dist[100001];
int len_min[100001][18];   //i�� 2^j��° parent���� �ö󰡸鼭 ������ ��� ���� �� ���� ª�� ������ ����. ��, �����̴�.
int len_max[100001][18];   //i�� 2^j��° parent���� �ö󰡸鼭 ������ ��� ���� �� ���� �� ������ ����. ��, �����̴�.

pair<int,int> lca(int u, int v){
	if (depth[u] < depth[v]){                   // u�� ������ depth�� �� ū �༮���� ��´�. (level�� �� ���� �༮)
		swap(u, v);
	}
	int ans_min = 1e9;                      // �ּҰ� �Ǵ� ������ ����
	int ans_max = 0;                             // �ִ밡 �Ǵ� ������ ����
	int log = 1;             // u�������� �ִ� ��ĭ���� ���� �ö� �� �ִ����� ���Ѵ�.
	while ((1 << log) <= depth[u]){
		log++;
	}
	log--;
	for (int i = log; i >= 0; i--){
		if (depth[u] - (1 << i) >= depth[v]){                 // u�� v�� ������������ u�� 2^i�� ���� �ø���.
			ans_min = min(ans_min,len_min[u][i]);
			ans_max = max(ans_max,len_max[u][i]);
			u = p[u][i];
		}
	}
	if (u == v){           
		return {ans_min,ans_max};
	}
	else{
		for (int i = log; i >= 0; i--){                    // depth(����)�� ������ ��尡 �ٸ���
			if (p[u][i] != 0 && p[u][i] != p[v][i]){       // u��v�� �������� �������� 2^i�� ���� �ø���.
				ans_min = min(ans_min, len_min[u][i]);
				ans_max = max(ans_max, len_max[u][i]);
				ans_min = min(ans_min, len_min[v][i]);
				ans_max = max(ans_max, len_max[v][i]);
				u = p[u][i];
				v = p[v][i];
			}
		}
		ans_min = min(ans_min, len_min[u][0]);   //lca �������� �ö����Ƿ� �� �θ������ ������ ���� �ָ� �ȴ�.
		ans_max = max(ans_max, len_max[u][0]);
		ans_min = min(ans_min, len_min[v][0]);
		ans_max = max(ans_max, len_max[v][0]);
		return {ans_min,ans_max};                  
	}
}

void bfs(int start){
	queue<int> q;
	q.push(start);
	check[start] = true;
	while (!q.empty()){
		int node = q.front();
		q.pop();
		for (auto& p : a[node]){
			int next = p.to;
			int cost = p.cost;
			if (!check[next]){
				depth[next] = depth[node] + 1;
				dist[next] = cost;              //�θ���� �ڽĳ�� ������ dist�� �����ش�.
				check[next] = true;
				parent[next] = node;
				q.push(next);
			}
		}
	}
}

int main(){
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++){
		int x, y,z;
		scanf("%d %d %d", &x, &y,&z);
		a[x].push_back({ y, z });                // Ʈ���� �ܹ����� �ƴ� ����� �׷����� �����Ѵ�.
		a[y].push_back({x,z});
	}

	bfs(1);

	for (int i = 1; i <= n; i++){
		p[i][0] = parent[i];
		len_min[i][0] = dist[i];
		len_max[i][0] = dist[i];
	}
	for (int j = 1; (1 << j) < n; j++){
		for (int i = 1; i <= n; i++){
			if (p[i][j - 1] != 0){
				p[i][j] = p[p[i][j - 1]][j - 1];           //i����� 2^j��° ������ i����� 2^(j-1)��° ������ 2^(j-1)��° ����� ����.
				
				len_min[i][j] = len_min[i][j-1];  
				len_max[i][j] = len_max[i][j-1];

				len_min[i][j] = min(len_min[i][j - 1], len_min[p[i][j - 1]][j - 1]);   //������ �ݹ� ������ ���߿� �ϳ��� �ּҰ��̴�.
				len_max[i][j] = max(len_max[i][j - 1], len_max[p[i][j - 1]][j - 1]);
				//if (p[i][j]!=0){
				//	len_min[i][j] = min(len_min[i][j-1],len_min[p[i][j-1]][j-1]);   //������ �ݹ� ������ ���߿� �ϳ��� �ּҰ��̴�.
				//	len_max[i][j] = max(len_max[i][j-1],len_max[p[i][j-1]][j-1]);
				//}
			}
		}
	}

	int k;
	scanf("%d", &k);
	for (int i = 0; i < k; i++){
		int x, y;
		scanf("%d %d", &x, &y);	
		auto p = lca(x, y);
		printf("%d %d\n", p.first,p.second);
	}
	return 0;
}