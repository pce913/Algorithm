#include<stdio.h>

int a[55];
double D[1005];  //D[i]: i�ְ� ���� ��, ��ȣ �ܰ��� ���
int main(){
	int n, j, c;
	scanf("%d",&n);
	int sum = 0;
	for (int i = 1; i <= n; i++){
		scanf("%d",&a[i]);
		sum += a[i];
	}
	scanf("%d %d",&j,&c);
	D[0] = a[1];
	double p = D[0] / sum;   //��ȣ�� ��÷�� Ȯ��
	for (int i = 1; i <= c; i++){
		D[i] = (D[i - 1] + j)*p + D[i - 1] * (1 - p);
		sum += j;
		p = D[i] / sum;
	}
	printf("%.10lf",D[c]);
	return 0;
}