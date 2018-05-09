#include<stdio.h>

const int MAXR = 5000;
int D[11][MAXR + 5];   //D[i][j]: i���� ��Ʈ�� ����ؼ� j �ڸ��� ���� ���� �� �ִ� ����� ���� (1�� �� ���� �ƴϾ ��.)
int ans[MAXR + 5];
int main(){
	int n, k;    //
	scanf("%d %d", &n, &k);
	if (k == 1){
		printf("1");
		for (int i = 1; i <= n - 1; i++){
			printf("0");
		}
		return 0;
	}
	//////////
	for (int i = 1; i <= MAXR; i++){
		D[1][i] = i;
	}
	for (int i = 2; i <= 10; i++){
		for (int j = 2; j <= MAXR; j++){
			D[i][j] = D[i][j - 1] + D[i - 1][j - 1];
			if (D[i][j] > 1e7){
				D[i][j] = 1e7;
			}
		}
	}

	int i;
	int cipher = 1;
	bool isFirst = true;
	for (i = MAXR; i >= 1; i--){
		if (D[k][i - 1] < n){   //����. 
			if (isFirst){
				isFirst = false;
				cipher = i;
			}
			ans[i] = 1;
			n -= D[k][i - 1];
			k--;
		}
		if (k == 0)
			break;
	}

	for (i = cipher; i >= 1; i--)
		printf("%d", ans[i]);

	return 0;
}