#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;

const int MAXN = 1000005;
long long a[MAXN];
long long tree[4 * MAXN];
long long lazy[4 * MAXN];

void init(int node,int start,int end){
	if (start == end){
		tree[node] = a[start];
		return;
	}
	init(2 * node, start, (start + end) / 2);
	init(2 * node + 1, (start + end) / 2+1,end );
	tree[node] = tree[2 * node] + tree[2 * node + 1];
}

void update_lazy(int node,int start,int end){    //lazy�� �����Ű�� �ڽĿ��� lazy�� �����ֱ�.
	if (lazy[node] != 0){
		tree[node] += (end - start + 1)*lazy[node];
	}
	if (start != end){
		lazy[2 * node] += lazy[node];
		lazy[2 * node + 1] += lazy[node];
	}
	lazy[node] = 0;
}

void update_range(int node,int start,int end,int i,int j,long long value){
	update_lazy(node, start, end);
	if (i > end || j < start)
		return;
	if (start >= i && end <= j){
		tree[node] += (end - start + 1)*value;
		if (start != end){
			lazy[2 * node] += value;
			lazy[2 * node + 1] += value;
		}
		return;
	}
	update_range(2 * node, start, (start + end) / 2, i, j, value);
	update_range(2 * node + 1, (start + end) / 2+1,end , i, j, value);
	tree[node] = tree[2 * node] + tree[2 * node + 1];
}

long long query(int node,int start,int end,int i,int j){
	update_lazy(node, start, end);
	if (i > end || j < start){
		return 0;
	}
	if (start >= i&& end <= j){
		return tree[node];
	}
	long long m1 = query(2 * node, start, (start + end) / 2, i, j);
	long long m2 = query(2 * node + 1, (start + end) / 2+1,end , i, j);
	return m1 + m2;
}

int main(){
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	m += k;
	for (int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);

	init(1, 1, n);
	for (int test = 0; test < m; test++){
		int t1;
		scanf("%d", &t1);
		if (t1 == 1){
			int start, end;
			long long v;
			scanf("%d %d %lld", &start, &end, &v);
			update_range(1, 1,n, start, end, v);
		}
		else if (t1 == 2){
			int start, end;
			scanf("%d %d", &start, &end);
			printf("%lld\n", query(1, 1, n, start, end ));
		}
	}
	return 0;
}
//#include<cstdio>
//#include<cmath>
//#include<vector>
//using namespace std;
//
//void init(vector<long long>& A, vector<long long>& tree, int node, int start, int end){
//	if (start == end)
//		tree[node] = A[start];
//	else{
//		init(A, tree, 2 * node, start, (start + end) / 2);
//		init(A, tree, 2 * node + 1, (start + end) / 2 + 1, end);
//		tree[node] = tree[2 * node] + tree[2 * node + 1];
//	}
//}
//
//void update_lazy(vector<long long>& tree, vector<long long>& lazy, int node, int start, int end){
//	if (lazy[node] != 0){                 // lazy�� ���� ����ִٸ� update�� ù��° �湮�� �ƴ϶� ���̹Ƿ� �̶� lazy�� update �����ش�.
//		tree[node] += (end - start + 1)*lazy[node];
//	}
//	if (start != end){        //leaf ��尡 �ƴϸ� lazy�� �����ش�. ������ lazy���� ���� �� �����Ƿ� += ���� ó��
//		lazy[2 * node] += lazy[node];
//		lazy[2 * node + 1] += lazy[node];
//	}
//	lazy[node] = 0;         //lazy���� �̿��ؼ� ���� node�� update ���������Ƿ� lazy���� 0���� �ٲ��ش�.
//}
//
//void update_range(vector<long long>& tree, vector<long long>& lazy, int node, int start, int end, int left, int right, long long diff){
//	update_lazy(tree, lazy, node, start, end);                   //lazy�� ���� update �����ش�.
//	if (left > end || right < start)
//		return;
//	if (left <= start && right >= end){                //�������� ������ ���ԵǸ�
//		tree[node] += (end - start + 1)*diff;     //��带 update���ش�.
//		if (start != end){                       //���� ��尡 ���� ��尡 �ƴ϶��
//			lazy[2 * node] += diff;              //�ڽĿ��� lazy���� �����ش�.
//			lazy[2 * node + 1] += diff;
//		}
//		return;
//	}
//	update_range(tree, lazy, 2 * node, start, (start + end) / 2, left, right, diff);
//	update_range(tree, lazy, 2 * node + 1, (start + end) / 2 + 1, end, left, right, diff);
//	tree[node] = tree[2 * node] + tree[2 * node + 1];
//}
//
//long long sum(vector<long long>& tree, vector<long long>& lazy, int node, int start, int end, int left, int right){
//	update_lazy(tree, lazy, node, start, end);
//	if (left > end || right < start){
//		return 0;
//	}
//	if (left <= start && right >= end){
//		return tree[node];
//	}
//	return sum(tree, lazy, node * 2, start, (start + end) / 2, left, right) + sum(tree, lazy, node * 2 + 1, (start + end) / 2 + 1, end, left, right);
//}
//
//int main(){
//	int n, m, k;
//	scanf("%d %d %d", &n, &m, &k);
//	vector<long long> A(n);
//	int h = (int)ceil(log2(n));
//	int tree_size = (1 << (h + 1)) - 1;
//	vector<long long> tree(tree_size);
//	vector<long long> lazy(tree_size);
//	m += k;
//	for (int i = 0; i < n; i++)
//		scanf("%lld", &A[i]);
//
//	init(A, tree, 1, 0, n - 1);
//	for (int test = 0; test < m; test++){
//		int t1;
//		scanf("%d", &t1);
//		if (t1 == 1){
//			int start, end;
//			long long v;
//			scanf("%d %d %lld", &start, &end, &v);
//			update_range(tree, lazy, 1, 0, n - 1, start - 1, end - 1, v);
//		}
//		else if (t1 == 2){
//			int start, end;
//			scanf("%d %d", &start, &end);
//			printf("%lld\n", sum(tree, lazy, 1, 0, n - 1, start - 1, end - 1));
//		}
//	}
//	return 0;
//}