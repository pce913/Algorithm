#include<stdio.h>
#include<algorithm>
using namespace std;

int a[205];
int D[205][205];
int main(){
	int n, k;
	scanf("%d %d",&n,&k);
	for (int i = 1; i <= n; i++){
		scanf("%d",&a[i]);
	}
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			D[i][j] = 1e9;
		}
		D[i][i] = 0;
	}
	/*
	������ ���� �ٲ� �� ������ ������ ���� ���� ������ ������ �ٲٱ⸸ �ص� 
	������ Ƚ���� ������ ���� ���Ͻ�ų �� �ֱ� ������ � [x, y] ������ ���� ������ ������ٸ�
	�� ���� ������ x��° ���� ���̶�� �����ص� �ȴ�.  <-- (a[i] != a[k + 1])  �� ����. (a[k] != a[i+len])�� �ȴ�.
	*/
	for (int len = 1; len < n; len++){
		for (int i = 1; i <= n - len; i++){
			for (int k = i; k <= i + len - 1; k++){  //(a[i] != a[k + 1]) �̰��� �ٽ��̴�.
				D[i][i + len] = min(D[i][i + len], D[i][k] + D[k + 1][i + len] + (a[i] != a[k + 1]));
			}
		}
	}

	printf("%d",D[1][n]);
	return 0;
}