//#include<stdio.h>
//#include<vector>
//using namespace std;
//
//void update(vector<int>& tree, int x, long long diff){
//	for (int i = x; i<tree.size(); i += i&-i){
//		tree[i] += diff;
//	}
//}
//
//long long sum(vector<int>& tree, int x){
//	long long ans = 0;
//	for (int i = x; i > 0; i -= i&-i){
//		ans += tree[i];
//	}
//	return ans;
//}
//
//long long sum(vector<int>& tree, int left, int right){
//	if (left > right)
//		return 0;
//	return sum(tree, right) - sum(tree, left - 1);
//}
//
//int main(){
//	int n;
//	scanf("%d", &n);
//	vector<int> a(n + 1);
//	vector<int> tree1(n + 1);             // tree1[i] : i�� ������ ����
//	vector<int> tree2(n + 1);             // tree2[i] : i ���� ���ʿ� i���� ū ���� � �ִ����� ����.
//	for (int i = 1; i <= n; i++){
//		scanf("%d", &a[i]);
//	}
//	long long ans = 0;
//	for (int i = 1; i <= n; i++){                    // 7578�� ���� ����ó�� �ذ��Ѵ�. A[i]<A[j], B[i]>B[j]
//		update(tree1, a[i], 1);                     //  ��� ������ �ι� Ǯ���ش�.
//		update(tree2, a[i], sum(tree1, a[i] + 1, n));
//		ans += sum(tree2, a[i] + 1, n);
//	}
//	printf("%lld", ans);
//	return 0;
//}
#include<stdio.h>
#include<vector>
using namespace std;                                        //http://wowoto.me/boj5012/ ����

void update(vector<int>& tree, int x, long long diff){
	for (int i = x; i<tree.size(); i += i&-i){
		tree[i] += diff;
	}
}

long long sum(vector<int>& tree, int x){
	long long ans = 0;
	for (int i = x; i > 0; i -= i&-i){
		ans += tree[i];
	}
	return ans;
}

long long sum(vector<int>& tree, int left, int right){
	if (left > right)
		return 0;
	return sum(tree, right) - sum(tree, left - 1);
}

int main(){
	int n;
	scanf("%d", &n);
	vector<int> a(n + 1);
	vector<int> tree1(n + 1);             // tree1[i] : i�� ������ ����
	vector<int> tree2(n + 1);             // tree2[i] : i�� ������ ����. for���� ���鼭 update
	for (int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		update(tree1, a[i], 1);
	}
	long long ans = 0;
	for (int i = 1; i <= n; i++){
		update(tree1, a[i], -1);
		ans += sum(tree2, a[i] + 1, n)*sum(tree1, 1, a[i] - 1);    // ���ʰ� ���������� ������ Ǭ��.
		update(tree2, a[i], 1);                                   // ���� ������ ū�ֵ��� ���ʿ� ��ִ���*���� �ֵ��� �����ʿ� ��ִ���
	}
	printf("%lld", ans);
	return 0;
}

