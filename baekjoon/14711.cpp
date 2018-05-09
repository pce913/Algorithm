//#include <iostream>
//#include <cstdio>
//
//using namespace std;
//
//char ans[1009][1009];
//bool tmp[1009][1009];
//
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	for (int i = 1; i <= n; i++) scanf(" %c", &ans[1][i]);
//	for (int i = 1; i <= n; i++) {
//		if (ans[1][i] == '#') {
//			tmp[1][i - 1] ^= 1;
//			tmp[1][i + 1] ^= 1;
//			tmp[2][i] ^= 1;
//		}
//	}
//	for (int i = 2; i <= n; i++) {
//		for (int j = 1; j <= n; j++) {
//			if (tmp[i - 1][j] == 1) {  //�ٷ� ������ Ȧ���� �������� ��� (# �̰� . �̰� ��� ����) ���� �˰ڴ�.
//				               //#�� �ִ� �ڸ� ���� '.' ���� ������ ���� ���� �����ϹǷ� #�� �ִ� �ڸ� ���� '.' �� ���� ¦���� ������� �Ѵ�.
//
//				ans[i][j] = '#';
//				tmp[i - 1][j] ^= 1;
//				tmp[i][j - 1] ^= 1;
//				tmp[i + 1][j] ^= 1;
//				tmp[i][j + 1] ^= 1;
//			}
//			else ans[i][j] = '.';
//		}
//	}
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++) {
//			printf("%c", ans[i][j]);
//		}
//		puts("");
//	}
//	return 0;
//}
#include<stdio.h>

char input[1005];
int a[4][1005];
int temp2[1005];

/*1.�� ���� ��Ȯ�� �ƴ� ���¿��� ù°���� �����´�.
2.�׷��� ���� ���´�.(2°��)   �ؿ� ���Ͽ� ��°�� �����⸦ �Ѵ�.
3.�� ��� ���� ���� ��°���̴�.*/
// �ݺ����ش�.

int main(){
	int n;
	scanf("%d", &n);
	scanf("%s", &input[1]);
	if (n == 1){
		printf("%c",input[1]);
		return 0;
	}

	for (int i = 1; i <= n; i++){
		a[1][i] = (input[i] == '.');
		temp2[i] = a[1][i];
	}

	for (int i = 1; i <= n; i++){
		if (a[1][i] == 0){   //# �϶�
			temp2[i - 1] = !temp2[i - 1];
			temp2[i] = !temp2[i];
			temp2[i + 1] = !temp2[i + 1];
		}
	}
	//n�� 1 �� ��� ����
	for (int i = 1; i <= n; i++)
		printf("%c", a[1][i] == 0 ? '#' : '.');
	printf("\n");
	for (int i = 1; i <= n; i++){
		a[2][i] = temp2[i];
		printf("%c", a[2][i] == 0 ? '#' : '.');
	}
	printf("\n");
	/////////////////////////////////////   n-2���� �ݺ�
	for (int k = 1; k <= n - 2; k++){
		for (int i = 1; i <= n; i++){
			if (a[1][i] == 0){  //#�̸�
				temp2[i] = !temp2[i];   	//temp2 ���� ��°�� ������ �� ����. //���� ����
			}
		}
		for (int i = 1; i <= n; i++){
			if (a[2][i] == 0){        //��°�� ������ ����.
				temp2[i - 1] = !temp2[i - 1];
				temp2[i] = !temp2[i];
				temp2[i + 1] = !temp2[i + 1];
			}
		}
		for (int i = 1; i <= n; i++){
			a[3][i] = temp2[i];
			printf("%c", a[3][i] == 0 ? '#' : '.');
			a[1][i] = a[2][i];
			a[2][i] = a[3][i];
		}
		printf("\n");
	}
	return 0;
}