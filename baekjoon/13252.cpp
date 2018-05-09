#include<iostream>
#include<iomanip>
#include<map>
using namespace std;
long long m;   //������ �¸��ϴ� ������ ������ �� ������ �ִ��� ���� Ĩ�� �δ� ���̴�.
//Ĩ�� ���� �ΰ� �Ǹ� ��� ������ k���� Ĩ�� �ִٰ� �� ��� ��� ������ k+1���� Ĩ�� ������ ���� ���̴�.
map< pair<long long, long long>, double > D;    //D[n][k]: ���� n���� ����ְ� ���� ���尡 k�� �϶� �̱� Ȯ��. 
double go(long long n, long long k){
	if (n <= 0)
		return 0;
	if (k == 0)
		return n >= 1;
	if (D.count({ n, k }) > 0)
		return D[{n, k}];
	double p = (double)(n%m) / m; //Ĩ�� �� ���� ������ ������ Ȯ��
	double ans = p*go(n - (n / m + 1), k - 1) + (1.0 - p)*go(n - (n / m), k - 1);
	return D[{n, k}] = ans;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n, k;
	cin >> n >> m >> k;
	cout << fixed << setprecision(10) << go(n, k);
	return 0;
}