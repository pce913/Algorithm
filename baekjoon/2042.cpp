#include<stdio.h>
#include<algorithm>
using namespace std;

long long a[1000005], bucket[1000005];   //sqrt decomposition ���
long long sz;
long long n, m, k;
void init(){
	for (long long i = 1; i <= n; i++){
		bucket[i / sz] += a[i];
	}
}

void update(long long b, long long c){
	bucket[b / sz] -= a[b];
	a[b] = c;
	bucket[b / sz] += a[b];
}

long long query(long long b, long long c){
	long long ans = 0;
	long long left = b;
	long long right = c;
	while (left%sz != 0 && left <= right){
		ans += a[left++];
	}
	while ((right + 1) % sz != 0 && left <= right){
		ans += a[right--];
	}
	while (left <= right){
		ans += bucket[left / sz];
		left += sz;
	}
	return ans;
}

int main(){
	scanf("%lld %lld %lld", &n, &m, &k);
	m += k;
	sz = sqrt(n);
	for (long long i = 1; i <= n; i++){
		scanf("%lld", &a[i]);
	}
	init();
	for (long long qq = 0; qq < m; qq++){
		long long x, b, c;
		scanf("%lld %lld %lld", &x, &b, &c);
		if (x == 1){
			update(b, c);
		}
		else{
			printf("%lld\n", query(b, c));
		}
	}
	return 0;
}


//#include<stdio.h>
//long long A[1000001];
//long long tree[3000001];
//
//void update(int node,int start,int end,int i,long long diff){
//	if (i > end || i < start)
//		return;
//	tree[node] += diff;
//	if (start != end){
//		update(2*node,start,(start+end)/2,i,diff);
//		update(2*node+1, (start + end) / 2+1, end, i, diff);
//	}
//}
//
//long long sum(int node, int start, int end, int i, int j){
//	if (i > end || j < start)
//		return 0;
//	if (i <= start && j >= end)
//		return tree[node];
//
//	return sum(2 * node, start, (start + end) / 2, i, j)+
//		sum(2 * node + 1, (start + end) / 2 + 1, end, i, j);
//}
//
//void init(int node, int start, int end){
//	if (start == end)
//		tree[node] = A[start];
//	else{
//		init(2 * node, start, (start + end) / 2);
//		init(2 * node + 1, (start + end) / 2 + 1, end);
//		tree[node] = tree[2 * node] + tree[2 * node + 1];
//	}
//}
//
//int main(){
//	int n, m,k;
//	scanf("%d %d %d", &n, &m,&k);
//	m += k;
//	for (int i = 1; i <= n; i++)
//		scanf("%lld", &A[i]);
//
//	init(1, 1, n);
//	for (int test = 0; test < m; test++){
//		int a, b;
//		long long c;
//		scanf("%d %d %lld", &a, &b, &c);
//		if (a == 1){
//			long long diff = c - A[b];
//			A[b] = c;
//			update(1,1,n,b,diff);
//		}
//		else if (a == 2){
//			printf("%lld\n", sum(1, 1, n, b, c));
//		}	
//	}
//	return 0;
//}

//#include<stdio.h>
//long long tree[3000000];                                  // ���׸�Ʈ Ʈ�� ����� ����.
//int base = 1;                       // b -> ������ �ϴ� Ʈ�� ����� ����
//
//void update(int node,long long diff){    // x: update�� ��� ��ȣ.  diff: ���� ���� �����Ϸ��� ���� ����     
//	node += base;
//	tree[node] += diff;                     // �����Ϸ��� ���� ���̸�ŭ �����ش�.
//	while (node > 1){                   //�ؿ������� ���� �ö���鼭 update ��Ų��.
//		tree[node / 2] += diff;
//		node /= 2;
//	}
//}
//
//long long sum(int left,int right){
//	left += base;
//	right += base;
//	long long ans = 0;
//	while (left < right){           //left�� right�� �ٲ���ٴ°��� ���� �� ã�Ҵٴ� �Ŵ�.
//		if (left % 2 == 0){         //���࿡ ������ ���� �ڽ��̸�
//			left /= 2;              //���� �ø���.
//		}
//		else{
//			ans += tree[left];     //������ ������ �ڽ��̸� ���信 �����ְ�
//			left++;             //���������� ��ĭ �̵��Ŀ�
//			left /= 2;             //���� �ø���.
//		}
//		if (right % 2 == 1){       //�������� ������ �ڽ��̸�
//			right /= 2;            //���� �ø���.
//		}
//		else{
//			ans += tree[right];
//			right--;
//			right /= 2;
//		}
//	}
//	if (left == right){              //left�� right�� �������� ���ܰ� �������� �ѹ��� �����ش�.
//		ans += tree[left];
//	}
//	return ans;
//}
//
//int main(){
//	int n, m, k;
//	scanf("%d %d %d",&n,&m,&k);
//	m += k;
//	while (base <= n){             // ������ �ϴ� ���� ����� ������ ���Ѵ�. ���ܳ��� ������ ä���� �־�� �Ѵ�.
//		base *= 2;                 // complete binary tree
//	}
//	base--;
//	for (int i = 1; i <= n; i++){
//		long long x;
//		scanf("%lld",&x);
//		update(i,x);
//	}
//
//	for (int test = 0; test < m; test++){
//		int t1;
//		scanf("%d",&t1);
//		if (t1 == 1){
//			int t2;
//			long long t3;
//			scanf("%d %lld",&t2,&t3);
//			update(t2,t3-tree[base+t2]);          
//		}
//		else if (t1 == 2){
//			int t2,t3;
//			scanf("%d %d",&t2,&t3);
//			printf("%lld\n",sum(t2,t3));
//		}
//	}
//	return 0;
//}