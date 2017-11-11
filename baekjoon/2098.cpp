#include<stdio.h>
#include<algorithm>
using namespace std;
const int INF = 1e9;
int w[20][20], D[(1 << 20)][20];     //����ͷ� ©���� D[mask][i] �� �ϴ°��� ���ϴ�. ���� �湮�� ���°� mask�̰� ���� �湮�Ѱ��� i�϶��� �ִܰŸ�. 
int main(){
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			scanf("%d", &w[i][j]);
		}
	}
	for (int i = 0; i < (1 << n); i++){
		for (int j = 0; j < n; j++){
			D[i][j] = INF;
		}
	}

	D[1][0] = 0;
	for (int mask = 0; mask < (1 << n); mask++){
		for (int i = 0; i < n; i++){  //���� �湮�� �� i
			if (!(mask&(1 << i))){
				for (int j = 0; j < n; j++){  //���� �湮�Ѱ� j
					if (i != j && (mask&(1 << j)) && w[j][i] != 0){
						D[mask | (1 << i)][i] = min(D[mask | (1 << i)][i], D[mask][j] + w[j][i]);
					}
				}
			}
		}
	}
	int ans = INF;
	for (int i = 0; i < n; i++){
		if (w[i][0] != 0){
			ans = min(ans, D[(1 << n) - 1][i] + w[i][0]);
		}
	}
	printf("%d", ans);
	return 0;
}