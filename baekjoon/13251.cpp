#include<stdio.h>

int a[55];
//double D[2505][2505];  //���װ��. ���װ���� double ������ ���س��ƾ߸� �´´�. �ȱ׷��� �����÷ο� ������ Ʋ����. long long�� �ȵ�.
double nCr(int x, int y)  //double�� �ؾ߸� �´´�. �ȵ巯�� �����÷ο� ������ Ʋ����.   double������ �ϸ� 1e300 �̻��� ���� ǥ�� �����ϴ�.
{                              //double�� ���װ���� ������ �ſ� ũ�Ƿ� ���� �׳� ����ϴ°� ����.
	double ans = 1.0;
	for (int i = 0; i < y; i++)
	{
		ans *= (double)(x - i);
		ans /= (double)(i + 1);
	}
	return ans;
}

int main(){
	int n = 0;
	int m, k;
	scanf("%d", &m);
	for (int i = 1; i <= m; i++){
		scanf("%d", &a[i]);
		n += a[i];
	}
	scanf("%d", &k);
	double mother = nCr(n, k);
	double son = 0;
	for (int i = 1; i <= m; i++){
		if (a[i] < k)continue;
		son += nCr(a[i], k);
	}
	printf("%.10lf", son / mother);
	return 0;
}
//#include<stdio.h>
//
////n�� �ִ� 2500���� ���� �� �����Ƿ� ���װ���� �� ���� ����.
///*
//ù ��°�� ���� ���൹�� i�� ���� Ȯ��: A[i]/n
//�� ��°�� ���� ���൹�� i�� ���� Ȯ��: (A[i] - 1)/(n - 1)
//...
//k���� ���൹�� ��� i���� �� Ȯ��
//sum( (A[i] - j)/(n - j) )
//*/
//
//int a[55];
//int main(){
//	int n = 0;
//	int m, k;
//	scanf("%d", &m);
//	for (int i = 1; i <= m; i++){
//		scanf("%d", &a[i]);
//		n += a[i];
//	}
//	scanf("%d", &k);
//	double ans = 0;
//	for (int i = 1; i <= m; i++){
//		double temp = 1;
//		for (int j = 0; j <= k - 1; j++){
//			temp *= (double)(a[i] - j) / (n - j);
//		}
//		ans += temp;
//	}
//	printf("%.10lf", ans);
//	return 0;
//}