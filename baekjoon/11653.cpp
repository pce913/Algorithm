#include<stdio.h>

int main(){
	int n;
	scanf("%d",&n);
	bool have = false;
	for (int i = 2; i*i <= n; i++){
		while ((n%i) == 0){
			have = true;
			printf("%d\n", i);
			n /= i;
		}
	}
	if (n > 1){
		printf("%d\n",n);      // ������� n=6�� ��쿡 6�� ���μ��� 3�� ���� ������ �ɸ��� �ʴ´�.
	}              //�׷� ��쿡�� �� �ϳ� �̰͸� �� ������ָ� �ȴ�.
	return 0;
}