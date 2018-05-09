#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;

void update_lazy(vector<int>& tree, vector<int>& lazy, int node, int start, int end){
	if (lazy[node] != 0){                 // lazy�� ���� ����ִٸ� update�� ù��° �湮�� �ƴ϶� ���̹Ƿ� �̶� lazy�� update �����ش�.
		if (lazy[node] % 2 == 1){       // lazy���� Ȧ���� ��쿡�� ������Ʈ. ����ġ �����̶�� �����̹Ƿ� ¦���϶��� ������Ʈ ���� �ʴ´�.
			tree[node] = (end - start + 1) - tree[node];       // 0 �Ǵ� ������ �����.
		}
	}
	if (start != end){        //leaf ��尡 �ƴϸ� lazy�� �����ش�. ������ lazy���� ���� �� �����Ƿ� += ���� ó��
		lazy[2 * node] += lazy[node];
		lazy[2 * node + 1] += lazy[node];
	}
	lazy[node] = 0;         //lazy���� �̿��ؼ� ���� node�� update ���������Ƿ� lazy���� 0���� �ٲ��ش�.
}

void update_range(vector<int>& tree, vector<int>& lazy, int node, int start, int end, int left, int right, long long diff){
	update_lazy(tree, lazy, node, start, end);                   //lazy�� ���� update �����ش�.
	if (left > end || right < start)
		return;
	if (left <= start && right >= end){                //�������� ������ ���ԵǸ�
		if (diff % 2 == 1){                              // ���̰� Ȧ���϶�
			tree[node] = (end - start + 1) - tree[node];     //��带 update���ش�.  0 �Ǵ� ������ �����.
		}
		if (start != end){                       //���� ��尡 ���� ��尡 �ƴ϶��
			lazy[2 * node] += diff;              //�ڽĿ��� lazy���� �����ش�.
			lazy[2 * node + 1] += diff;
		}
		return;
	}
	update_range(tree, lazy, 2 * node, start, (start + end) / 2, left, right, diff);
	update_range(tree, lazy, 2 * node + 1, (start + end) / 2 + 1, end, left, right, diff);
	tree[node] = tree[2 * node] + tree[2 * node + 1];
}

int sum(vector<int>& tree, vector<int>& lazy, int node, int start, int end, int left, int right){
	update_lazy(tree, lazy, node, start, end);
	if (left > end || right < start){
		return 0;
	}
	if (left <= start && right >= end){
		return tree[node];
	}
	return sum(tree, lazy, node * 2, start, (start + end) / 2, left, right) + sum(tree, lazy, node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	vector<int> A(n);
	int h = (int)ceil(log2(n));
	int tree_size = (1 << (h + 1));
	vector<int> tree(tree_size);
	vector<int> lazy(tree_size);

	for (int test = 0; test < m; test++){
		int t1;
		scanf("%d", &t1);
		if (t1 == 0){
			int start, end;
			scanf("%d %d", &start, &end);
			update_range(tree, lazy, 1, 0, n - 1, start - 1, end - 1, 1);
		}
		else if (t1 == 1){
			int start, end;
			scanf("%d %d", &start, &end);
			printf("%d\n", sum(tree, lazy, 1, 0, n - 1, start - 1, end - 1));
		}
	}
	return 0;
}