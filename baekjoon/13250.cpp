#include<stdio.h>
//�� * Ȯ�� = ��밪.
double D[1000005];
int main(){
	int n;
	scanf("%d",&n);
	for (int i = 1; i <= n; i++){
		for (int j = i - 1; j >= i - 6; j--){
			if (j >= 0){
				D[i] += (D[j]) / 6;   //   1/6 -> �� �ֻ��� ���ڰ� ������ Ȯ��.
			}
		}
		D[i] += 1;  //���� ���¿��� �ѹ��� ������ ��� n�� �ȴ�.
	}
	printf("%.11f",D[n]);
	return 0;
}