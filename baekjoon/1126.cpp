//#include<stdio.h>
//#include<algorithm>
//using namespace std;
//
//const int MINF = -100000000;
//int n;
//int A[50];
//int D[50][250001];          // D[i][j] : i ��° �������� ��������� �������� j �϶��� ����
//bool check[50][250001];
//int go(int k,int diff){
//	if (diff > 250000){
//		return MINF;
//	}
//	if (k == n){
//		if (diff == 0){
//			return 0;
//		}
//		else{
//			return MINF;
//		}
//	}
//	if (check[k][diff])
//		return D[k][diff];
//
//	check[k][diff] = true;
//	int& ans = D[k][diff];
//	ans = go(k + 1, diff);
//	ans = max(ans, go(k + 1, diff + A[k]));      // ���� ž ���� �÷���������
//	if (A[k] > diff){                //���� ž ���� �÷� ��������
//		ans = max(ans, go(k + 1, A[k] - diff) + diff);
//	}
//	else{
//		ans = max(ans, go(k + 1, diff - A[k]) + A[k]);
//	}
//	return ans;                                             //ans���� �ᱹ ���̰� ���� �ֵ鸸
//}
//
//int main(){
//	scanf("%d",&n);
//	for (int i = 0; i < n; i++){
//		scanf("%d",&A[i]);
//	}
//	int ans = go(0,0);
//	if (ans == 0)
//		printf("-1");
//	else
//		printf("%d", ans);
//	return 0;
//}
#include<stdio.h>
#include<algorithm>
using namespace std;

const int MINF = -100000000;
int A[50];
int D[50][250001];          // D[i][j] : i ��° �������� ��������� �������� j �϶� ���̰� ���� �κ��� ����.
bool check[50][250001];
int go(int k, int diff){
	if (diff > 250000){
		return MINF;
	}
	if (k < 0){
		if (diff == 0){
			return 0;
		}
		else{
			return MINF;
		}
	}
	if (check[k][diff])
		return D[k][diff];

	check[k][diff] = true;
	int& ans = D[k][diff];
	ans = go(k - 1, diff);
	ans = max(ans, go(k - 1, diff + A[k]));      // ���� ž ���� �÷���������
	if (A[k] > diff){                               // ���� ž ���� �÷���������
		ans = max(ans, go(k - 1, A[k] - diff) + diff);
	}
	else{
		ans = max(ans, go(k - 1, diff - A[k]) + A[k]);
	}
	return ans;
}

int main(){
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d", &A[i]);
	}
	int ans = go(n-1, 0);
	if (ans == 0)
		printf("-1");
	else
		printf("%d",ans);
	return 0;
}