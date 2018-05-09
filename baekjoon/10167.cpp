#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;

struct Point{
	int x, y, w;
	bool operator<(const Point& p)const{
		return this->x < p.x;
	}
};

struct Info{
	long long lsum, rsum, total_sum, max_sum;
};

vector<Point> a;
vector<int> ypos;
const int MAXN = 3005;
Info tree[4 * MAXN];
//LSUM->�� ������ ���� ������������ ������ ������ �ִ� ��
//RSUM->�� ������ ������ ������������ ������ ������ �ִ� ��
//TOTALSUM->�� ������ ��� ������ ��
//MAXSUM->�� �������� ���� �� �ִ� �ִ� ������

//LSUM = max(�����ڽ���LSUM, �����ڽ���TOTALSUM + ������ �ڽ��� LSUM)
//RSUM = max(�������ڽ���RSUM, �������ڽ���TOTALSUM + ���� �ڽ���RSUM)
//TOTALSUM = �����ڽ���TOTALSUM + �������ڽ���TOTALSUM
//MAXSUM = max(�����ڽ���RSUM + �������ڽ���LSUM, �����ڽ���MAXSUM, �������ڽ��� MAXSUM, LSUM, RSUM)
void update(int node, int start, int end, int i, int value){
	if (i > end || i < start)
		return;
	if (start == end){
		tree[node].lsum += value;
		tree[node].rsum += value;
		tree[node].total_sum += value;
		tree[node].max_sum += value;
		return;
	}
	update(2 * node, start, (start + end) / 2, i, value);
	update(2 * node + 1, (start + end) / 2 + 1, end, i, value);
	Info& curr = tree[node];
	Info& left = tree[2 * node];
	Info& right = tree[2 * node + 1];
	curr.lsum = max(left.lsum, left.total_sum + right.lsum);
	curr.rsum = max(right.rsum, right.total_sum + left.rsum);
	curr.total_sum = left.total_sum + right.total_sum;
	curr.max_sum = max({ left.rsum + right.lsum, left.max_sum, right.max_sum, curr.lsum, curr.rsum });
}

int main(){
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		int x, y, w;
		scanf("%d %d %d", &x, &y, &w);
		a.push_back({ x, y, w });
		ypos.push_back(y);
	}
	sort(a.begin(), a.end());
	sort(ypos.begin(), ypos.end());
	ypos.erase(unique(ypos.begin(), ypos.end()), ypos.end());
	for (int i = 0; i < a.size(); i++){
		a[i].y = lower_bound(ypos.begin(), ypos.end(), a[i].y) - ypos.begin() + 1;
	}

	const int MAX_Y = ypos.size();
	long long ans = 0;
	for (int i = 0; i < a.size(); i++){
		memset(tree, 0, sizeof(tree));
		if (i>0 && a[i].x == a[i - 1].x)    //���ӵ� �� ���� ���� x ��ǥ��� �ؿ��� �̹� ó�� ���� ���̹Ƿ�
			continue;          //�Ѿ��.

		for (int j = i; j < a.size(); j++){
			int y = a[j].y;
			int value = a[j].w;
			update(1, 1, MAX_Y, y, value);
			if (j < a.size() - 1 && a[j].x == a[j + 1].x)   //��ǥ�� �� �� x��ǥ�� ���� ������ �ݵ�� �ѹ��� ������Ʈ �� �� ���� �Ѵ�. 
				continue;

			long long q = tree[1].max_sum;
			ans = max(ans, q);
		}
	}
	printf("%lld", ans);
	return 0;
}