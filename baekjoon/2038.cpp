#include<stdio.h>

int D[1000005];    //input�� 20�� �̶�� ������
                 //������ ���� �ȿ��� ����� ���� ã�� �� �ִ�.
int main(){
	int n;
	scanf("%d",&n);

	if (n == 1){
		printf("1");
		return 0;
	}

	D[1] = 1;
	D[2] = 2;
	int next = 1;    //������ �� ��� ������ ��ġ
	int sum = 1;
	int j;
	bool isFind = false;
	for (int i = 2; i <= n; i++){
		for (j = next + 1; j <= next + D[i]; j++){
			D[j] = i;
			sum += D[j];
			if (sum >= n){
				isFind = true;
				break;
			}
		}
		if (isFind)
			break;
		next += D[i];
	}
	printf("%d",j);
	return 0;
}
//#include<stdio.h>
//#include<map>
//using namespace std;
//
//map<long long, long long> mm;
//
//int main(){
//	long long n;
//	scanf("%lld",&n);
//	
//	mm[0] = 1;
//	long long sum=0;
//	long long i;
//	for (i = 1; i <= n; i++){
//		mm[i] = 1 + mm[i - mm[mm[i - 1]]];
//		sum += mm[i];
//
//		// sum���� ����ؼ� ��� ������ f(i)���� ���� �ְ� �ᱹ sum�� n�� ������
//		// �׶� i���� n�϶� f(n)�� ���� �ȴ�.
//		if (sum >= n)
//			break;
//	}
//	printf("%lld",i);
//	return 0;
//}