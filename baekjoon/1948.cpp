#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
vector< pair<int, int> > a[10001];
vector< pair<int, int> > r[10001];
queue<int> q;
int indegree[10001];
int rindegree[10001];
int time[10001];
bool isCritical[10001];
                        //�迭�� �߰��ؼ� �Ӱ��ΰ� �ƴѾֵ��� üũ���ش�.

int main(){                        // ������ �׷����� weight 12�� ������ 
	int n, m;                      // ������ �׷����� ������ �ϴ� ������ ���Ѵ�.
	int start, end;
	scanf("%d",&n);
	scanf("%d", &m);
	for (int i = 0; i < m; i++){
		int x, y, z;
		scanf("%d %d %d",&x,&y,&z);
		a[x].push_back(make_pair(y,z));
		r[y].push_back(make_pair(x,z));
		indegree[y]++;
		rindegree[x]++;
	}
	
	scanf("%d %d",&start,&end);
	q.push(start);
	while (!q.empty()){
		int node = q.front();
		q.pop();
		for (int i = 0; i < a[node].size(); i++){
			int next=a[node][i].first;
			indegree[next]--;
			if (indegree[next] == 0){
				q.push(next);
			}
			if (time[next] < time[node] + a[node][i].second){  
				time[next] = time[node] + a[node][i].second;
			}
		}
		
	}
	printf("%d\n", time[end]);

	int cnt = 0;
	q.push(end);
	isCritical[end] = true;
	while (!q.empty()){
		int node = q.front();
		q.pop();
		for (int i = 0; i < r[node].size(); i++){
			int next = r[node][i].first;
			rindegree[next]--;
			if (rindegree[next] == 0){    //q���� �ϴ� �� �־���� �Ѵ�. �׷��� ������ ���ܰ� ����.    && time[node] - r[node][i].second == time[next]
				q.push(next);
			}
			
			if (time[node] - r[node][i].second == time[next] && isCritical[node]==true){
				cnt++;
				isCritical[next] = true;
			}
		}
	}
	printf("%d",cnt);
	
	return 0;
}