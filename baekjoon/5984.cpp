#include<stdio.h>
#include<algorithm>
using namespace std;

bool check[255];
int a[255];
int main(){
	int n;
	scanf("%d",&n);
	for (int i = 1; i <= n; i++){
		a[i] = i;
	}

	check[1] = true;
	int cur = 1;
	int next;
	int getup=1;
	while (true){
		next = (cur + getup - 1)%n+1;       //1���̽�. ������ �̵��� �ڸ��� �����Ѵ�.
		if (check[a[next]] || next==1){     //�̹� �ѹ� �̵��ߴ� �Ҹ� �� �̵���Ű���� �Ѵٸ� ���� ã�� ���̴�.
			break;
		}
		check[a[next]] = true;
		swap(getup, a[next]);  //�Ͼ �༮�� ���� �ڸ��� �ɰ� �ɾ� �ִ� �༮�� �Ͼ��.
		cur = next;
	}
	printf("%d",getup);
	return 0;
}