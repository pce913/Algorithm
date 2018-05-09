#include<stdio.h>
#include<cstring>

const int MAXN = 2000001;

int MX[MAXN];     //MX[i]:ù��° �÷��̾ �ݵ�� ���� ��ǥ�� (x,y)��� x��ǥ�� i�϶��� y��ǥ.

int main(){
	int m, n;
	scanf("%d %d", &m, &n); //m: x����, n: y����
	memset(MX, -1, sizeof(MX));
	MX[0] = 0;
	int last = 0;
	for (int i = 1; i <= m; i++){
		if (MX[i] == -1){
			MX[i] = MX[last] + (i - last) + 1;
			last = i;
		}
		MX[MX[i]] = i;
	}

	int T;
	scanf("%d",&T);
	for (int test = 0; test < T; test++){
		int x, y;
		scanf("%d %d",&x,&y);
		if (MX[x] == y){
			printf("Farmer John\n");
		}
		else{
			printf("Bessie\n");
		}
	}
	return 0;
}