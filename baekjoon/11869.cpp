#include<stdio.h>
//http://blog.myungwoo.kr/27   ���⿡ ���� ����Ǿ� �ִ�.
//������ xĭ �ű�� ���� �����̸� x�� �������ٰ� �����ϸ� �ȴ�.
int main(){
	int n;
	scanf("%d", &n);
	int ans = 0;
	for (int i = 0; i < n; i++){
		int x;
		scanf("%d", &x);
		ans ^= x;
	}
	printf("%s", ans == 0 ? "cubelover" : "koosaga");
	return 0;
}