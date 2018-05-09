#include<stdio.h>

int n;
int D[501][501];
int A[501][2];
int go(int x,int y){
	if (D[x][y])
		return D[x][y];
	if (x == y)
		return 0;

	if (x + 1 == y)
		return A[x][0] * A[x][1] * A[y][1];

	for (int k = x; k <= y-1; k++){
		int t1 = go(x, k);                
		int t2 = go(k + 1, y);
		if (D[x][y] == 0 || D[x][y] > t1 + t2 + A[x][0] * A[k][1] * A[y][1]){   //������ ���� ������� �ϴ� ���� 2��ó�� ��������
			D[x][y] = t1 + t2 + A[x][0] * A[k][1] * A[y][1];                    // �����δ� 3���̴�. (AB)(CD)�� ������ ���� ��. 
		}                                                                       //  5 x 3 , 3 x 2 , 2 x 6 , 6 x 4
	}
	return D[x][y];
}
int main(){
	scanf("%d",&n);
	for (int i = 1; i <= n; i++){
		scanf("%d %d",&A[i][0],&A[i][1]);
	}
	printf("%d",go(1,n));
	return 0;
}