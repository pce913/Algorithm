#include<stdio.h>
                  //���丮�󿡼� 2�� 5�� ������ ã���ָ�ȴ�.
                 //5�� ������ 2�� �������� �׻� �����Ƿ� 5�� ������ ã���ָ� �ȴ�.
                 //�����ڷẸ�ϱ� Ȯ���� ���� �Ǿ���.
int main() {
	int n;
	int ans = 0;
	scanf("%d",&n);
	for (int i = 5; i <= n; i *= 5) {
		ans += n / i;
	}
	printf("%d",ans);
	return 0;
}