#include<stdio.h>
#include<vector>
using namespace std;
                                       // ��ī�� ���� ���
int main(){
	long long n, k, m;         
	scanf("%lld %lld %lld",&n,&k,&m);
	vector< vector<int> > d(m+1,vector<int>(m+1));      // ������ ���� m ���� �Ľ�Į�� �ﰢ���� �����Ѵ�.
	for (int i = 0; i <= m; i++) {
		d[i][0] = d[i][i] = 1;
		for (int j = 1; j < i ; j++) {
			d[i][j] = d[i - 1][j - 1] + d[i - 1][j];
			d[i][j] %= m;
		}
	}

	vector<int> a, b;
	while (n>0 || k > 0){                         // n �� k �� m�������� ��Ÿ����.
		a.push_back(n%m);
		b.push_back(k%m);
		n /= m;
		k /= m;
	}
	long long ans = 1;
	for (int i = 0; i<a.size(); i++){
		ans *= d[a[i]][b[i]];
		ans %= m;
	}
	printf("%lld",ans);
	return 0;
}