//n���� Ǯ�� ������ �ð��ʰ� ����.
#include <stdio.h>

int N, M, K;
int main(){
	scanf("%d %d %d", &N, &M, &K);  //N: �����, M:�θ��� ���� ���� ,K: ��ȣ�� '����� ��ġ'
	int d;
	for (d = 1; d < N; d++){        //�� �ȿ� ���� ����
		int rest = (N - d + 1);   //(N - d + 1): ���� �����ִ� ����� ����ΰ�
		int nM = M % rest == 0 ? rest : M % rest;    //�����ϴ� ����� ����� ��ġ 

		if (K == nM)
			break;
		else  //��ȣ�� '����� ��ġ'�� �������ش�.
			K = K > nM ? K - nM : K - nM + (N - d) + 1;   //����
	}
	printf("%d", d);
	return 0;
}

//#include<stdio.h>
//
//int tree[4 * 5000005];
//
//void init(int node, int start,int end){
//	if (start == end){
//		tree[node] = 1;
//	}
//	else{
//		init(2 * node, start, (start + end) / 2);
//		init(2 * node + 1, (start + end) / 2+1,end );
//		tree[node] = tree[2 * node] + tree[2 * node + 1];
//	}
//}
//
//void update(int node,int start,int end,int i,int value){
//	if (i > end || i < start)
//		return;
//	if (start == end){
//		tree[node] += value;
//	}
//	else{
//		update(2 * node, start, (start + end) / 2, i, value);
//		update(2 * node + 1, (start + end) / 2+1,end , i, value);
//		tree[node] = tree[2 * node] + tree[2 * node + 1];
//	}
//
//}
//
//int sum(int node, int start, int end, int i, int j){
//	if (i > end || j < start){
//		return 0;
//	}
//	if (start >= i && end <= j){
//		return tree[node];
//	}
//	int s1=sum(2 * node, start, (start + end) / 2, i, j);
//	int s2=sum(2 * node + 1, (start + end) / 2 + 1,end , i, j);
//	return s1 + s2;
//}
//
//int query(int node, int start, int end, int x){   //x: ���� ���� �ֵ��߿� ���° �ε�����?
//	if (start == end)                       //x�� �ش��ϴ� �ε����� ������ ���° �ε�����? �� ��Ÿ���� query
//		return start;
//	if (x <= tree[2 * node]){
//		return query(2 * node, start, (start + end) / 2, x);
//	}
//	else{
//		return query(2 * node + 1, (start + end) / 2 + 1, end, x - tree[2 * node]);
//	}
//}
//
//int main(){
//	int n, m, k;
//	scanf("%d %d %d",&n,&m,&k);
//	init(1,1,n);
//
//	int out = 1;   //���������� ������ �༮�� �����̴�? �ʱ�ȭ�� 1���� �ϸ� ���ϴ�.
//	int ans = 0;
//	for (int i = n; i >= 1; i--){
//		ans++;
//		int pre = sum(1,1,n,1,out-1);    //�տ� ��� �����ִ�?
//		int next = (pre + m - 1) % i + 1;   //�տ� ��� �����ִµ� �� �߿� �� ��°��? �� ��Ÿ���� ����. 1 ���̽� �϶��� �̷��� ���ش�.
//		out = query(1, 1, n, next);
//		update(1, 1, n, out, -1);
//		if (out == k)
//			break;
//	}
//	printf("%d",ans);
//	return 0;
//}