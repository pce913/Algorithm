#include<stdio.h>
#include<algorithm>
using namespace std;
const int MAXN = 270000;
int D[MAXN][65]; //D[idx][num]: ������ idx�� num�� ���� �� �ִٰ� �Ҷ� �׶��� left �ε���.
int a[MAXN];

///*2 2 2 2 2 2 2 2
//        ^ 
//	�̰��� �ٷ� D[8][4] = 4 �� ��Ÿ��.

////���� �� �ִ� ���ڴ� Ŀ���� 65 �����̴�.
////� ���� x�� �������� �츮�� ���ϴ� ���� w�� ����� ���ؼ��� 2�� ������ ��ŭ�� w�� �ʿ��ϴ�.
////���� ��� 5(w)�� ����� ���ؼ��� 2(x)�� 8�� �ʿ��ϴ�. 

int main(){
	int n;
	scanf("%d",&n);
	for (int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		D[i][a[i]] = i;
	}
	for (int j = 1; j <= 65; j++){
		for (int i = 1; i <= n; i++){
			if (D[i][j] != 0 && D[D[i][j] - 1][j] != 0){
				D[i][j+1] = D[D[i][j] - 1][j];
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= 65; j++){
			if (D[i][j]!=0)
				ans = max(ans, j);
		}
	}
	printf("%d",ans);
	return 0;
}

//#include <iostream>
//#include<algorithm>
//using namespace std;
//const int MAXN = 262145;
//int n;
//long long a[MAXN];
//int dp[MAXN][67];
//int main(){
//	ios::sync_with_stdio(false); cin.tie(0);
//	cin >> n;
//	for (int i = 1; i <= n; i++){
//		cin >> a[i];
//		dp[i][a[i]] = i;
//	}
//	for (int i = 2; i <= 66; i++){
//		for (int j = 1; j <= n; j++){
//			if (!dp[j][i - 1])continue;
//			int idx = dp[j][i - 1] - 1;
//			if (dp[idx][i - 1]){
//				dp[j][i] = dp[idx][i - 1];
//			}
//		}
//	}
//	int ans = 0;
//	for (int i = 1; i <= n; i++){
//		for (int j = 0; j<67; j++){
//			if (dp[i][j]){
//				ans = max(ans, j);
//			}
//		}
//	}
//	cout << ans;
//	return 0;
//}
//#include <cstdio>  
//#include <algorithm>  
//using namespace std;
//int f[262200][65], a[262200];    //f[idx][num]: ������ idx�� num�� ���� �� �ִٰ� �Ҷ� �׶��� right �ε���.
////���� �� �ִ� ���ڴ� Ŀ���� 65 �����̴�.
////� ���� x�� �������� �츮�� ���ϴ� ���� w�� ����� ���ؼ��� 2�� ������ ��ŭ�� w�� �ʿ��ϴ�.
////���� ��� 5(w)�� ����� ���ؼ��� 2(x)�� 8�� �ʿ��ϴ�. 
//
///*2 2 2 2 2 2 2 2
//        ^ 
//	�̰��� �ٷ� f[4][4] = 4 �� ��Ÿ��.
// */
//int main()
//{    //����� ��������.
//	int n, m;
//	scanf("%d", &n);
//	for (int i = 1; i <= n; i++) scanf("%d", &a[i]), f[i][a[i]] = i, m = max(m, a[i]);
//	//m: ���� �� �ִ� ������ �ִ�
//	for (int j = 1; j <= m; j++){   //j: ���� �� �ִ� ����
//		for (int i = 1; i <= n; i++){  //i: �ε���
//			if (f[i][j] != 0 && f[f[i][j] + 1][j] != 0){
//				f[i][j + 1] = f[f[i][j] + 1][j];
//				if (j + 1 > m)
//					m = j + 1;   //���� m���� �޶����� ���� �ٱ��� for���� m�� ������ �޴´�.
//				     //�̷��� ���ϰ�
//			}
//		}
//	}
//	printf("%d", m);
//}