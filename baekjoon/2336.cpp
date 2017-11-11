#include<stdio.h>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

const int INF = 500001;

struct Exam{
	int first, second, third;
};

bool cmp(const Exam& a,const Exam& b){
	return a.second < b.second;
}

void init(vector<int>& tree, int node, int start, int end){
	tree[node] = INF;
	if (start != end){
		init(tree,2*node,start,(start+end)/2);
		init(tree, 2 * node + 1, (start + end) / 2+1,end );
	}
}

int query(vector<int>& tree,int node,int start,int end,int left,int right){           //������ �ּҰ��� ����.
	if (left > end || right < start){
		return -1;
	}
	if (left <= start && right >= end){
		return tree[node];
	}
	int m1 = query(tree,2*node,start,(start+end)/2,left,right);
	int m2 = query(tree, 2 * node + 1, (start + end) / 2+1,end , left, right);
	if (m1 == -1){
		return m2;
	}
	else if (m2 == -1){
		return m1;
	}
	else{
		return min(m1,m2);
	}
}

void update(vector<int>& tree,int node,int start,int end,int i,int value){
	if (i > end || i < start)
		return;
	tree[node] = min(tree[node],value);
	if (start != end){
		update(tree,2*node,start,(start+end)/2,i,value);
		update(tree, 2 * node + 1, (start + end) / 2+1,end , i, value);
	}
}

int main(){
	int n;
	scanf("%d",&n);
	vector<Exam> a(n+1);
	int h = (int)ceil(log2(n));
	int tree_size = (1 << (h + 1));
	vector<int> tree(tree_size);                  // tree[i] : ù��° ���� ����� i�϶� ����° ���� ���.
	for (int i = 1; i <= n; i++) {
		int t;
		scanf("%d", &t);
		a[t].first = i;
	}
	for (int i = 1; i <= n; i++) {
		int t;
		scanf("%d", &t);
		a[t].second = i;
	}
	for (int i = 1; i <= n; i++) {
		int t;
		scanf("%d", &t);
		a[t].third = i;
	}
	
	sort(a.begin(), a.end(),cmp);
	int ans = 0;
	init(tree,1,1,n);         //������ �ι�° ������ �ߺ� �༮���� �����ϴµ�,
	                           // �� �߿� ù��° ���赵 ������ �� �� �༮���� �ְ�,
	                           // ���������� ����° ������ ������ ���ôٸ� ans++
	for (int i = 1; i <= n; i++){
		int temp = query(tree, 1, 1, n,1,a[i].first);   //������ ù��° ���� ����� ���ų� ���� �༮���� ����° ���� ��� �߿��� �ּҰ�.
		                                                // ��, ���� ���� ����� ������.
		if (temp > a[i].third){                  // ���� �л��� ����° ���� ����� ���� �л��麸�� ���ٸ� ��� ������ �л��̴�,
			ans++;
		}
		update(tree,1,1,n,a[i].first,a[i].third);
	}
	printf("%d",ans);
	return 0;
}