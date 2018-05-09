#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
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

int main(){                                   // map�� ����� ��ǥ���� �̿�
	int n;
	scanf("%d",&n);
	vector<int> a(n);
	vector<int> b(n);
	for (int i = 0; i < n; i++){
		scanf("%d",&a[i]);
		b[i] = a[i];
	}
	sort(b.begin(), b.end());                 // unique�� ����ؼ� ��� �ߺ����� �����ϱ� ���� sort �Ѵ�. 
	b.erase(unique(b.begin(),b.end()),b.end());    //http://soen.kr/lecture/ccpp/cpp4/42-2-3.htm����   unique�� ���ϰ��� ���� ��������. �ߺ��� ���ŵ� ������ ���� �ε����� ���ϵȴ�.
	                                               // b�迭���� �ߺ����� ���� ������ sorting�Ǿ� �ִ�.
	map<int, int> d;                                   // ��ǥ���� ���
	for (int i = 0; i < b.size(); i++){
		d[b[i]] = i + 1;
	}
	for (int i = 0; i < n; i++){
		a[i] = d[a[i]];
	}

	int h = (int)ceil(log2(MAX));
	int tree_size = (1 << (h + 1));
	vector<int> tree(tree_size);
	int ans = 0;
	for (int i = 0; i < n; i++){
		int num = a[i];
		int temp = query(tree, 1, 1, MAX, 1, num - 1);
		ans = max(ans, temp + 1);
		update(tree, 1, 1, MAX, num, temp + 1);
	}
	printf("%d", ans);
	return 0;
}