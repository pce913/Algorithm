#include<stdio.h>
#include<algorithm>
using namespace std;

const int MAXN = 500005;
int tree[4 * MAXN];
int lazy[4 * MAXN];
int a[MAXN];

void init(int node,int start,int end){
	if (start == end){
		tree[node] = a[start];
		return;
	}
	init(2 * node, start, (start + end) / 2);
	init(2 * node + 1, (start + end) / 2+1,end );
	tree[node] = tree[2 * node] ^ tree[2 * node + 1];
}
void update_lazy(int node,int start,int end){
	if ((end - start + 1) & 1){     //������ Ȧ���� ��쿡�� ������Ʈ ���ش�.
		tree[node] ^= lazy[node];    //������ ¦���� ��쿡�� ������Ʈ�� �ص� ������ ���ڷ� ���ƿ��� �ȴ�.
	}                      //���� �ѹ� xor�� ¦���� �غ���. ���� ���ڷ� ���ƿ��� �ȴ�.
	if (start != end){
		lazy[2 * node] ^= lazy[node];
		lazy[2 * node + 1] ^= lazy[node];
	}
	lazy[node] = 0;
}

void update_range(int node,int start,int end,int i,int j,int value){
	update_lazy(node, start, end);
	if (i > end || j < start){
		return;
	}
	if (start >= i && end <= j){
		if ((end - start + 1)&1){    //������ Ȧ�� �� ��쿡�� ������Ʈ ���ش�.
			tree[node] ^= value;
		}

		if (start != end){
			lazy[2 * node] ^= value;
			lazy[2 * node + 1] ^= value;
		}
		return;
	}
	update_range(2 * node, start, (start + end) / 2, i, j, value);
	update_range(2 * node + 1, (start + end) / 2+1,end , i, j, value);
	tree[node] = tree[2 * node] ^ tree[2 * node + 1];
}

int query(int node,int start,int end,int i,int j){
	update_lazy(node, start, end);
	if (i > end || j < start){
		return 0;
	}
	if (start >= i &&end <= j){
		return tree[node];
	}
	int m1=query(2 * node, start, (start + end) / 2, i, j);
	int m2=query(2 * node + 1, (start + end) / 2+1,end , i, j);
	return m1^m2;
}


int main(){
	int n;
	scanf("%d",&n);
	for (int i = 1; i <= n; i++){
		scanf("%d",&a[i]);
	}
	init(1, 1, n);
	int m;
	scanf("%d",&m);

	for (int q = 0; q < m; q++){
		int qq;
		scanf("%d",&qq);
		if (qq == 1){   //������ XOR
			int a,b,c;
			scanf("%d %d %d",&a,&b,&c);
			if (a>b)
				swap(a, b);
			update_range(1, 1, n , a+1, b+1, c);   //�̰� ����
		}
		else{
			int a, b;
			scanf("%d %d",&a,&b);
			if (a > b)
				swap(a, b);
			printf("%d\n",query(1,1,n,a+1,b+1));
		}
	}
	return 0;
}