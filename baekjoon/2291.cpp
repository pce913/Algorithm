#include<stdio.h>

int D[15][225][225]; // D[i][j][k] : ���̰� i�̰� ���� j�̸� �����ϴ� ���ڰ� k�� ������ ����. 
int main() {
	int n, m, s;
	scanf("%d %d %d",&n,&m,&s);
	for (int i = 1; i <= m; i++) {
		D[1][i][i] = 1;
	}

	for (int i = 1; i <= n - 1; i++){
		for (int j = 1; j <= m; j++){
			for (int k = 1; k <= m; k++){
				for (int l = 1; l <= k; l++){
					if (j + l > m)
						continue;
					D[i + 1][j + l][l] += D[i][j][k];
				}
			}
		}
	}

	int x = n;
	int y = m;
	int z = 1; //������
	int remain = s;
	while (x>=1){    //������ �ϱ�.
		if (D[x][y][z] >= remain){
			printf("%d ",z);
			x -= 1;
			y -= z;
		}
		else{
			remain -= D[x][y][z];
			z++;
		}
	}
	return 0;
}