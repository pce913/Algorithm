#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

void update(vector<int>& tree,int x,int diff){
	for (int i = x; i<tree.size(); i += i&-i){
		tree[i] += diff;
	}
}

long long sum(vector<int>& tree,int x){
	long long ans = 0;
	for (int i = x; i > 0; i -= i&-i){
		ans += tree[i];
	}
	return ans;
}

long long sum(vector<int>& tree,int left,int right){
	if (left > right)
		return 0;
	return sum(tree, right) - sum(tree, left - 1);
}

int main(){
	int n;
	scanf("%d",&n);
	vector< pair<int,int> > a(n + 1);
	vector<int> tree(n + 1);
	for (int i = 1; i <= n; i++){
		scanf("%d",&a[i].first);
		a[i].second = i;
		update(tree, i, 1);
	}
	sort(a.begin() + 1, a.end());               // �۾��� ���� �Ϸ�Ǵ����� ������.

	long long total = 0;         //�� �۾��� �����ʿ� �����鼭 ���� �Ϸ���� ���� �۾��� ������ �ҿ�ð��� ���Ҷ� ����.
	int last = 0;    //���������� ����� ���� ���״����� ����.
	vector<long long> ans(n + 1);
	long long remain = n;            //���� �۾��� ����
	for (int i = 1; i <= n; i++){
		total += (a[i].first - last)*remain;            // ����. ���׸�Ʈ Ʈ�� Ȱ�� �ʱ� ����.
		remain -= 1;
		ans[a[i].second] = total - sum(tree,a[i].second+1,n);
		update(tree,a[i].second,-1);
		last = a[i].first;
	}
	for (int i = 1; i <= n; i++) {
		printf("%lld\n", ans[i]);
	}
	return 0;
}