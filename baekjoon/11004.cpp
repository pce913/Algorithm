#include<stdio.h>
#include<algorithm>
using namespace std;
int a[5000001];                //nth_element�� ����ϸ� �� ������ Ǯ �� �ִ�.
int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	for (int i = 0; i < n; i++){
		scanf("%d",&a[i]);
	}
	//sort(a, a + n);
	nth_element(a,a+k-1,a+n);
	printf("%d",a[k-1]);
	return 0;
}