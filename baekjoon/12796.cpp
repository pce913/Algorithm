#include<stdio.h>
/*
	A: 1x1 , B: 1x1 , C: 1xp �� �ξ�����
	�ֻ�: (AB)C --> p+1
	�־�: A(BC) --> p+p
	�־� - �ֻ� = (p+p) - (p+1) = p - 1
	��, p-1�� k��� �ϸ� ������ �׻�
	3
	1 1 1 k+1 �� �ȴ�.
*/
int main(){
	int k;
	scanf("%d",&k);
	printf("3\n");
	printf("1 1 1 %d",k+1);
	return 0;
}