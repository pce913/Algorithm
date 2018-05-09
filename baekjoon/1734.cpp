#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace  std;
const int MAXN = 100005;
vector<int> adj[MAXN],children[MAXN];
int low[MAXN], num[MAXN],finish[MAXN];           //finish[node] : node���� ���� ���ö��� �ű� ��ȣ.
bool check[MAXN];
int cnt = 0;

void dfs(int node, int parent){
	check[node] = true;
	num[node] = low[node] = ++cnt;
	for (int next : adj[node]){
		if (next == parent)
			continue;
		if (!check[next]){   //tree edge
			dfs(next, node);
			low[node] = min(low[node], low[next]);
			children[node].push_back(next);
		}
		else{  //back edge
			low[node] = min(low[node], num[next]);
		}
	}
	finish[node] = ++cnt;
}

bool is_descendant(int x,int y){  //x�� y�� �ļ��̴�?  ok
	return num[x] >= num[y] && finish[x] <= finish[y];
}

int find_related_child(int x,int y){  //x�� ��Ʈ�� �ϴ� subtree���� y�� �� �� ��� child�� �پ� �ִ�?
	int left = 0;
	int right = children[x].size() - 1;
	int mid;
	while (left <= right){
		mid = (left + right) >> 1;
		int c = children[x][mid];
		if (finish[c] < num[y]){         //y�� mid���� ������ �ڽĿ� �޷� �ִ� ���
			left = mid + 1;
		}
		else if (num[c] > finish[y]){  //y�� mid���� ���� �ڽĿ� �޷� �ִ� ���
			right = mid - 1;
		}
		else{
			break;
		}
	}
	return children[x][mid];
}

int main(){
	int n, e;
	scanf("%d %d",&n,&e);
	for (int i = 0; i < e; i++){
		int x, y;
		scanf("%d %d",&x,&y);
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	dfs(1,-1);

	int qq;
	scanf("%d",&qq);
	for (int que = 0; que < qq; que++){
		int what;
		scanf("%d",&what);
		if (what == 1){   //������ ����
			int a, b, g1, g2;
			scanf("%d %d %d %d",&a,&b,&g1,&g2);
			if (is_descendant(g1, g2))
				swap(g1, g2);
			
			if (low[g2] <= num[g1]){   //���� �ö󰡴� ������ �ִ�. ��, �������� �ƴϴ�.
				printf("yes\n");
			}
			else if (is_descendant(a,g2) == is_descendant(b, g2)){ //�������϶�. ��, a�� b�� ���� ������ ������ �ְų�, a�� b�� �Ѵ� �ٸ� ������ ������ �ְų�. ok
				printf("yes\n");
			}
			else{
				printf("no\n");
			}
		}
		else if(what == 2){  //������ ����.
			int a, b, c;
			scanf("%d %d %d",&a,&b,&c);
			if (!is_descendant(a, c) && !is_descendant(b, c)){   //a�� c�� �ļյ� �ƴϰ� b�� c�� �ļ��� �ƴѰ��. 
				printf("yes\n");
			}
			else if (is_descendant(a, c) && is_descendant(b, c)){  //a,b�Ѵ� c�� �ļ��� ���
				int a_rel = find_related_child(c, a);
				int b_rel = find_related_child(c, b);
				if (a_rel == b_rel){   //a�� b�� ���� child�� �޷� �ִ� ���.
					printf("yes\n");
				}
				else if (low[a_rel] < num[c] && low[b_rel] < num[c]){   //a�� ���Ѱ��� child�� b�� ���Ѱ��� child�� �Ѵ� c�� �Ѵ� �鿧���� ������ �ִ�?
					printf("yes\n");
				}
				else{
					printf("no\n");
				}
			}
			else{      //a,b ���� �ϳ��� c�� �ļ��̰� �ٸ� �ϳ��� �ƴ� ���
				if (is_descendant(a, c))    //a�� c�� �ļ��̴�?
					swap(a, b);   //b�� �ϴ� ������ ����.
				int b_rel = find_related_child(c, b);
				if (low[b_rel] < num[c]){  //b�� ���Ѱ��� child�� c�� �Ѿ�� ������ ������ �ִ�?
					printf("yes\n");
				}
				else{
					printf("no\n");
				}
			}
		}
	}
	return 0;
}