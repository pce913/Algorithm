#include<stdio.h>

int D[10][10];  //���װ��
int main(){
	int n, m, k;
	scanf("%d %d %d",&n,&m,&k);
	for (int i = 0; i <= n; i++){
		D[i][0] = 1;
		D[i][i] = 1;
	}
	for (int i = 1; i <= n; i++){
		for (int j = 1; j < i; j++){
			D[i][j] = D[i - 1][j] + D[i - 1][j - 1];
		}
	}
	int mother = D[n][m];
	int son = 0;
	for (int i = k; i <= m; i++){//��� k����� ������ k�� �̻��� ������ �� ã���ش�.
		son += D[m][i] * D[n - m][m - i];
	}

	printf("%.11f", (double)son / mother);
	return 0;
}