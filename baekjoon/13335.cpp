#include<stdio.h>
#include<algorithm>
using namespace std;
//dotorya �ڵ� ����.
//rkdxogml5768 �ڵ嵵 ����.
int sum[1005], D[1005];
//D[i]: i��° ���ڰ� ����ϱ� '����'�� �ð�. ������� 3��° ���ڰ� �ٸ����� �ö���� �ð��� 5���, D[3]=4;
int main(){
	int n, w, l;
	scanf("%d %d %d",&n,&w,&l);
	for (int i = 1; i <= n; i++){
		int x;
		scanf("%d",&x);
		sum[i] = sum[i - 1] + x;
	}
	D[0] = -1e9;  // �ʿ�.
	D[1] = 0;
	for (int i = 2; i <= n; i++){
		int j;
		for (j = i - 1; j >= 1; j--){
			if (sum[i] - sum[j - 1] > l)
				break;
		}
		D[i] = max(D[i - 1] + 1, D[j] + w);    //�����ߴ�.
	}
	printf("%d", D[n] + w + 1);
	return 0;
}