#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> a;

int D[2001][2001];
bool check[2001][2001];

int go(int x, int y){
	if (check[x][y])
		return D[x][y];
	check[x][y] = true;

	int& ans = D[x][y];
	int term = a[y] - a[x];
	int z = a[y] + term;
	auto lower = lower_bound(a.begin() + y + 1, a.end(), z);    //z�� lower_bound�� ã�´�.
	//O(logn)
	int index = -1;
	if (lower != a.end() && *lower == z){    //���� ���� ������ �ִ� ���. �Ǵ� �������� �����ϴ� ���
		index = lower - a.begin();    //�ε��� ����.
	}

	if (index == -1){   //���� ���� ���°�� �ش� DP�� 2�̴�. ����!
		ans = 2;
	}
	else{
		ans = go(y, index) + 1;  //���� ���� ������ �ִ� ���. �Ǵ� �������� �����ϴ� ��� ��� ������ش�.
	}
	return ans;

}


int main(){
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		int x;
		scanf("%d", &x);
		a.push_back(x);
	}
	sort(a.begin(), a.end());

	int ans = 1;    //�ʱ�ȭ 1�� ����� ��.
	for (int i = 0; i < n; i++){
		for (int j = i + 1; j < n; j++){
			ans = max(ans, go(i, j));
		}
	}
	printf("%d", ans);
	return 0;
}