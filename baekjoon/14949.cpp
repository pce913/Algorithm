#include<stdio.h>
const long long MOD = 1e9 + 7;
long long M[205][205];  //M[n][m]: �������� �ڽİ����� n�϶� m���� �ڽ��� ����� ����� ��
long long D[7][205];  //D[h][m]: h�ϱ��� �������� m���� �ڽ��� ���� �� �ִ� ����� ��
long long h, w;
void init(){
	for (long long i = 1; i <= w; i++){
		for (long long j = 1; j <= w; j++){
			M[i][j] += 1;   //
			for (long long k = 1; k <= j; k++){
				M[i][j] = (M[i][j] + M[i - 1][k]) % MOD;    //�������� �ڽİ����� i-1���϶��� ���� �˸� i��°�� ���� ��������.
			}
		}
	}
}

int main(){
	scanf("%lld %lld", &h, &w);
	init();
	D[0][1] = 1;
	for (long long i = 1; i <= h; i++){  //��� �� ���� ���Ұ�
		for (long long j = 1; j <= w; j++){  // �ڽ��� j�� �������
			for (long long k = 1; k <= w; k++){   // ���� ���븦 �������� �Ѵ�.
				D[i][j] = (D[i][j] + (D[i - 1][k] * M[k][j]) % MOD) % MOD;
			}
		}
	}
	long long ans = 0;
	for (long long i = 1; i <= w; i++){
		ans = (ans + D[h][i]) % MOD;
	}
	printf("%lld", ans);
	return 0;
}