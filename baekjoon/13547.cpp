#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
//http://kesakiyo.tistory.com/25
int n;
int size;
struct Query{
	int left, right, idx;
	bool operator<(const Query& q)const{   //sqrt decomposition �̿� �� mo's algorithm �̿�
		int lidx = this->right / size;
		int ridx = q.right / size;
		if (lidx == ridx){
			return this->left < q.left;
		}
		return lidx < ridx;
	}
};

vector<Query> query;
int a[100005], ans[100005], check[1000005];
int cnt = 0;
void add(int x){  //������ ��Ȱ�� �ϱ� ���� �Լ� add�� erase
	check[x]++;
	if (check[x] == 1){
		cnt++;
	}
}

void erase(int x){
	check[x]--;
	if (check[x] == 0){
		cnt--;
	}
}

int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	int q;
	scanf("%d", &q);
	for (int qq = 1; qq <= q; qq++){
		int x, y;
		scanf("%d %d", &x, &y);
		query.push_back({ x, y, qq });
	}
	size = sqrt(n);
	sort(query.begin(), query.end());
	int left = 1, right = 1;
	add(a[1]);   //�̰� �� �־�����.
	for (int k = 0; k < query.size(); k++){
		int nleft = query[k].left;
		int nright = query[k].right;
		for (int i = left; i < nleft; i++){
			erase(a[i]);
		}
		for (int i = left - 1; i >= nleft; i--){
			add(a[i]);
		}
		for (int i = right + 1; i <= nright; i++){
			add(a[i]);
		}
		for (int i = right; i > nright; i--){
			erase(a[i]);
		}
		left = nleft;
		right = nright;
		ans[query[k].idx] = cnt;
	}
	for (int i = 1; i <= q; i++){
		printf("%d\n", ans[i]);
	}
	return 0;
}