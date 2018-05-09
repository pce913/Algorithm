//#include<stdio.h>
//#define MAX(a,b) ((a)>(b)?(a):(b) )
//int D[101][101];
//int M[101];
//int S[101];
//bool check[101][101];
//int n, m;
////-4000000
//int merge(int i,int j){
//	if (i < 0){
//		return -8000000;
//	}
//	if (j == 0)
//		return 0;
//	if (check[i][j] == true)
//		return D[i][j];
//	
//	
//	check[i][j] = true;
//	D[i][j] = D[i][j - 1];
//	for (int k = i; k >=3; k--){        
//		D[i][j] = MAX(D[i][j], merge(k - 2, j - 1)+S[k]-S[i-1]);  //���� �ٽ� �����ϱ�
//	}
//	return D[i][j];
//	
//}
//
//int main(){
//
//	scanf("%d %d",&n,&m);
//	//scanf("%d",M[1]);
//	//S[1] = M[1];
//
//	for (int i = 1; i <= n; i++){
//		scanf("%d",&M[i]);
//		S[i] = S[i - 1] + M[i];
//		for (int j = 1; j <= m; j++){
//			D[i][j] = -400000;
//		}
//	}
//
//	printf("%d",merge(n,m));
//
//	return 0;
//}
#include<stdio.h>

int N, M;
int A[101];
int D[101][101];              // D[i][j]  : i ������ �迭�� j���� �������� �������� ������ �ִ�
bool check[101][101];
const int MINF = -1000000000;

int go(int n,int m){
	if (m == 0){          // m���� ������ ��� �ִ�.
		return 0;
	}
	if (n <= 0){            // �ִ밪�� ���ϴ� �����̱� ������ ���� ���Ѵ� ���� �������ָ� ������ ã���� ���� �� �� �ְԵȴ�.
		return MINF;
	}
	if (check[n][m]){
		return D[n][m];
	}

	check[n][m] = true;
	int& ans = D[n][m];
	D[n][m]=go(n - 1, m);                    // ���� ���� x.
	int sum = 0;
	for (int k = n; k >= 1; k--){                 //�̷��� �ڿ������� ���ϸ� i~j������ ���� �����ϴ�
		sum += A[k];                              // �迭�� ������ �ʾƵ� �Ǿ ����.
		int temp=go(k - 2, m - 1)+sum;                 //���� ���� o.
		if (ans < temp)
			ans = temp;
	}
	return ans;
}
int main(){
	scanf("%d %d",&N,&M);
	for (int i = 1; i <= N; i++){
		scanf("%d",&A[i]);
	}
	printf("%d", go(N, M));
	return 0;
}