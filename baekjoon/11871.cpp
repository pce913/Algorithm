#include<stdio.h>
/*�� �����̿� ���� sprague-grundy value�� �Ű��ְ� 
�� ������ xor �������� ���� ���������� ���� ���� �����Ѵ�.
�̰��� �� ����2 ������ �Ȱ��� ���� �����ϸ�, ������ Ǫ�� ����� �����ϴ�.
�� ����2 ������ �� �������� sprague-grundy value �� ��� ���� ������ ������ ���� ������
�׳� �Է��ϴ´�� xor�� �� �� �ִ� ���̴�.
���� �����ڷ� ����.
*/
int main(){
	int n;
	scanf("%d",&n);
	int ans = 0;
	for (int i = 0; i < n; i++){
		int x;
		scanf("%d",&x);
		if (x & 1){
			ans ^= (x + 1) / 2;
		}
		else{
			ans^=((x - 2) / 2);
		}
	}
	printf("%s", ans == 0 ? "cubelover" : "koosaga");
	return 0;
}