#include<stdio.h>
#include<algorithm>
using namespace std;
//knuth optimization ����
int a[1005];
int D[1005][1005];
int P[1005][1005];
int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++){
		scanf("%d", &a[i]);
	}
	a[m + 1] = n;
	sort(a + 1, a + m + 2);
	for (int i = 0; i <= m + 1; i++){
		for (int j = i; j <= m + 1; j++){
			D[i][j] = 1e9;
			P[i][j] = i;
		}
		D[i][i] = 0;      // D[i][j] ���� i�� j�� ���� �����ִ� �����ε� �ڸ��� ������ ũ�Ⱑ 0 �̶��(i==j) ����� 0 �̴�.
		D[i][i + 1] = 0;  //��, ������ �ִ� ���� ������ �� ���̿� '�ڸ��� ��ġ'�� �Ѱ��� �����Ƿ� ���� ����� 0 �̴�.
	}

	for (int len = 3; len <= m + 2; len++){   //len�� 3���� �����ؾ� �Ѵ�. ����.
		for (int i = 0; i + len <= m + 2; i++){
			int j = i + len - 1;
			for (int k = P[i][j-1]; k <= P[i+1][j]; k++){
				if (D[i][j] > D[i][k] + D[k][j] + a[j] - a[i]){
					D[i][j] = D[i][k] + D[k][j] + a[j] - a[i];
					P[i][j] = k;
				}
			}
		}
	}
	printf("%d", D[0][m + 1]);
	return 0;
}