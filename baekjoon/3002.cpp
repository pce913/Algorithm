#include<stdio.h>
const int MAXN = 250005;
int tree[4*MAXN][10];   //tree[node][i]: node�� ��Ÿ���� �������� i�� � �ִ�?
int a[MAXN], lazy[4 * MAXN];
void init(int node,int start,int end){
	if (start == end){
		tree[node][a[start]] = 1;
	}
	else{
		init(2 * node, start, (start + end) / 2);
		init(2 * node + 1, (start + end) / 2 + 1, end);
		for (int i = 0; i < 10; i++){
			tree[node][i] = tree[2 * node][i] + tree[2 * node + 1][i];
		}
	}
}

void update_lazy(int node,int start,int end){
	if (lazy[node] != 0){
		int temp[10];
		for (int i = 0; i < 10; i++){//���±��� ������ ������ ��ĭ�� ����Ʈ ���ָ� �ȴ�.
			temp[(i + lazy[node]) % 10] = tree[node][i]; //������� ������ 3�� 5�� �����ߴٸ�, 
		}                                       //1�� ������Ʈ �ǹǷ� 4�� 5�� ���� �Ѵٰ� �� �� �ִ�.
		for (int i = 0; i < 10; i++){ 
			tree[node][i] = temp[i];
		}
		if (start != end){
			lazy[2 * node] += lazy[node];
			lazy[2 * node + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}

void update_range(int node,int start,int end,int i,int j){
	update_lazy(node, start, end);
	if (start > j || end < i){
		return;
	}
	if (start >= i && end <= j){
		lazy[node] += 1;    //�̷��� ������Ʈ�ϴ°��� �ڵ尡 ª�Ƽ� �� ������.
		update_lazy(node, start, end);
		return;
	}
	update_range(2 * node, start, (start + end) / 2, i, j);
	update_range(2 * node + 1, (start + end) / 2+1,end , i, j);
	for (int i = 0; i<10; i++){
		tree[node][i] = tree[2 * node][i] + tree[2 * node + 1][i];
	}
}

int query(int node,int start,int end,int i,int j){
	update_lazy(node, start, end);
	if (start > j || end < i){
		return 0;
	}
	if (start >= i && end <= j){
		int ans = 0;
		for (int i = 0; i < 10; i++){
			ans += tree[node][i] * i;
		}
		return ans;
	}
	int s1 = query(2 * node, start, (start + end) / 2, i, j);
	int s2 = query(2 * node + 1, (start + end) / 2 + 1, end, i, j);
	return s1 + s2;
}

int main(){
	int n, m;
	scanf("%d %d",&n,&m);
	for (int i = 1; i <= n; i++){
		scanf("%1d",&a[i]);
	}
	init(1, 1, n);
	for (int qq = 0; qq < m; qq++){
		int a, b;
		scanf("%d %d",&a,&b);
		printf("%d\n",query(1,1,n,a,b));
		update_range(1, 1, n, a, b);
	}
	return 0;
}
//#include <cstdio>
//#include <algorithm>
//#define MAX_N 250000
//using namespace std;
////seg[node][i]: node�� ��Ÿ���� �������� i�� � �ִ�?
//int seg[4 * MAX_N][10], lazy[4 * MAX_N], n, m, x, y, v[10];
//int a[MAX_N];
//void u_lazy(int node, int x, int y) {
//	if (!lazy[node])return;
//	for (int i = 0; i < 10; i++)   //������Ʈ�Ǵ� ���� 1�̹Ƿ� ������ ��ĭ�� ����Ʈ ���ش�. ����. 
//		v[(i + lazy[node]) % 10] = seg[node][i];
//	for (int i = 0; i < 10; i++)
//		seg[node][i] = v[i];
//	if (x != y) {
//		lazy[node * 2] += lazy[node];
//		lazy[node * 2 + 1] += lazy[node];
//	}
//	lazy[node] = 0;
//	return;
//}
//int init(int pos, int val, int node, int x, int y) {
//	if (pos < x || y < pos)
//		return seg[node][val];
//	if (x == y)   //���⼭�� �ᱹ x==y==pos�� �� ���̴�. ������ update�̴�.
//		return seg[node][val] = seg[node][val] + 1;
//	int mid = (x + y) >> 1;
//	return seg[node][val] = init(pos, val, node * 2, x, mid) + init(pos, val, node * 2 + 1, mid + 1, y);
//}
//void update(int lo, int hi, int node, int x, int y) {
//	u_lazy(node, x, y);
//	if (y < lo || hi < x)
//		return;
//	if (lo <= x&&y <= hi) {
//		lazy[node]++;   //update ��Ű���� ������ ��Ÿ���� lazy���� 1 ������Ų��. ��, ������ ���� 1�� �������� �� ���̴�.
//		u_lazy(node, x, y);   //lazy�� ��� ���Ѿ� �ϹǷ� update_lazy ȣ��
//		return;
//	}
//	int mid = (x + y) >> 1;
//	update(lo, hi, node * 2, x, mid);
//	update(lo, hi, node * 2 + 1, mid + 1, y);
//	for (int i = 0; i < 10; i++)
//		seg[node][i] = seg[node * 2][i] + seg[node * 2 + 1][i];
//}
//int query(int lo, int hi, int node, int x, int y) {
//	u_lazy(node, x, y);
//	if (y < lo || hi < x)
//		return 0;
//	if (lo <= x&&y <= hi) {
//		int ret = 0;
//		for (int i = 1; i < 10; i++) {
//			ret += seg[node][i] * i;
//		}
//		return ret;
//	}
//	int mid = (x + y) >> 1;
//	return query(lo, hi, node * 2, x, mid) + query(lo, hi, node * 2 + 1, mid + 1, y);
//}
//int main() {
//	scanf("%d%d", &n, &m);
//	for (int i = 1; i <= n; i++) {
//		int x;
//		scanf("%1d", &x);
//		init(i, x, 1, 1, n);
//	}
//
//	while (m--) {
//		scanf("%d%d", &x, &y);
//		printf("%d\n", query(x, y, 1, 1, n));
//		update(x, y, 1, 1, n);
//	}
//	return 0;
//}
