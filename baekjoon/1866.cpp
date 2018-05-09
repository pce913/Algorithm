#include<stdio.h>
#include<algorithm>
using namespace std;

/*
	D[i]�� ä�ﶩ �ΰ��� ���� ����� ���� �� �� �ִ�.
	1. n�� ������ Ʈ������ ����ϴ� ���
	2. m������ n�� ������ �︮���ͷ� ����ϴ� ���
	�︮������ ������ġ x=(m+n)/2   --> ���� m�� n ���̿��� ������ ����� ���°� �̵��̴�.
	for (int k=j; k<=i; k++) {
		c += abs(x - a[k])*t;
	}
	���� ����ؾ� �ϴ� �� for���� �������� ���ؼ� O(N) -> O(1)�� �ٲ�.
*/

int a[3005],D[3005],sum[3005];   //D[i]: 1 ~ n������ ������ ����Ҷ� ��� ����� �ּڰ�.
int main(){
	int n, t, h;
	scanf("%d",&n);
	for (int i = 1; i <= n; i++){
		scanf("%d",&a[i]);
	}
	scanf("%d %d",&t,&h);
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++){
		sum[i] = sum[i - 1] + a[i];
	}
	for (int i = 1; i <= n; i++){
		D[i] = D[i - 1] + a[i] * t;
		for (int j = i; j >= 1; j--){
			int x = (i + j) / 2;
			int c1 = (a[x] * (x - j + 1) - (sum[x] - sum[j - 1]))*t;
			int c2 = ((sum[i] - sum[x - 1]) - a[x] * (i - x + 1))*t;
			D[i] = min(D[i], D[j - 1] + h + c1 + c2);
		}
	}
	printf("%d",D[n]);
	return 0;
}

//#include <iostream>
//#include <algorithm>
//using namespace std;
//int a[3001];
//int d[3001];
//int s[3001];
//int n;
//int t;
//int h;
//int main() {
//	cin >> n;
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	cin >> t >> h;
//	sort(a + 1, a + n + 1);
//	for (int i = 1; i <= n; i++) {
//		s[i] = s[i - 1] + a[i];
//	}
//	for (int i = 1; i <= n; i++) {
//		d[i] = d[i - 1] + a[i] * t;
//		for (int j = i; j >= 1; j--) {
//			int c = h;
//			int x = (i + j) / 2;
//			c += ((s[i] - s[x - 1]) - a[x] * (i - x + 1))*t;
//			c += (a[x] * (x - j + 1) - (s[x] - s[j - 1]))*t;
//			if (d[i] > d[j - 1] + c) {
//				d[i] = d[j - 1] + c;
//			}
//		}
//	}
//	cout << d[n] << '\n';
//	return 0;
//}