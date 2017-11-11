#include<stdio.h>
#include<vector>
using namespace std;

void update(vector<int>& tree,int x,int diff){                     // ����Ʈ�� ���
	for (int i = x; i < tree.size(); i += i&-i){
		tree[i] += diff;
	}
}

int sum(vector<int>& tree, int x){
	int ans = 0;
	for (int i = x; i>0; i -= i&-i){
		ans += tree[i];
	}
	return ans;
}

int main(){
	int T;
	scanf("%d",&T);
	for (int test = 0; test < T; test++){
		int n, m;
		scanf("%d %d",&n,&m);
		vector<int> tree(n + m + 1);                  // ��ȭ�� �ø� ������ŭ Ʈ���� �� ����� �ش�.
		vector<int> position(n + 1);               // ���ڰ� �ִ� ������ ��ġ�� �����ϴ� �迭
		for (int i = 1; i <= n; i++){
			update(tree,m+i,1);
			position[i] = m + i;
		}
		for (int i = 0; i < m; i++){
			int x;
			scanf("%d",&x);
			printf("%d ",sum(tree,position[x]-1));
			update(tree,position[x],-1);               // ��ȭ�� ���� ���� �ø���.
			position[x] = m-i;
			update(tree, position[x], 1);           // �� ����⿡ ���Ӱ� �÷��� ��ȭ�� ���� update �Ѵ�.
		}
		printf("\n");
	}
	return 0;
}