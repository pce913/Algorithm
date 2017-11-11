#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

#define MAX 1000000

void update(vector<int>& tree, int node, int start, int end, int i, int value){
	if (i > end || i < start){
		return;
	}
	tree[node] = max(tree[node], value);
	if (start != end){
		update(tree, 2 * node, start, (start + end) / 2, i, value);
		update(tree, 2 * node + 1, (start + end) / 2 + 1, end, i, value);
	}
}

int query(vector<int>& tree, int node, int start, int end, int left, int right){     // �ִ밪�� ã�� ����
	if (left > end || right < start){
		return 0;
	}
	if (left <= start && right >= end){
		return tree[node];
	}
	return max(query(tree, 2 * node, start, (start + end) / 2, left, right), query(tree, 2 * node + 1, (start + end) / 2 + 1, end, left, right));
}

int main(){                                       //������ �ִ밪���� Ǭ��.
	int n;                                       // init �Լ��� �ʿ䰡 ����
	scanf("%d", &n);
	int h = (int)ceil(log2(MAX));
	int tree_size = (1 << (h + 1));
	vector<int> tree(tree_size + 1);             //tree[i] : �� i�� ���������� �ϴ� ���� �� �����ϴ� �κ� ������ ����  -> �̸��� �ణ ��ȣ�ϴ�.
	int ans = 0;                                 // ������ �ִ븦 ���ϱ� ���� Ʈ����� �����ϴ°� �� ����.
	for (int i = 0; i < n; i++){
		int num;
		scanf("%d", &num);
		int temp = query(tree, 1, 1, MAX, 1, num - 1);  //num���� ���� �༮�� �߿� �ִ� ���̸� ������ ��
		ans = max(ans, temp + 1);   //num������ ���̸� ���غ���.
		update(tree, 1, 1, MAX, num, temp + 1);
	}
	printf("%d", ans);
	return 0;
}
//#include<stdio.h>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//int main(){
//	int n;
//	scanf("%d", &n);
//	vector<int> A(n);
//	vector<int> D;
//	for (int i = 0; i<n; i++){
//		scanf("%d", &A[i]);
//	}
//
//	for (int i = 0; i < n; i++){
//		auto it = lower_bound(D.begin(), D.end(), A[i]);
//		if (it == D.end()){
//			D.push_back(A[i]);
//		}
//		else{
//			*it = A[i];
//		}
//	}
//	printf("%d", D.size());
//	return 0;
//}