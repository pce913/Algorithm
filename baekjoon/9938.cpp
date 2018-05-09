#include<stdio.h>
int n, L;
int parent[300005];
bool check[300005];   //������ ����ִ��� ���ִ��� üũ.

/*
http://blog.naver.com/PostView.nhn?blogId=kks227&logNo=220791837179
	�� ���� ���� ���� �׻� �ڽ������� ���� �Ŀ� Union ��Ų��.
	�׷��� �Ǹ� �� ������ ��Ʈ��常 Ȯ�����ָ� �ȴ�.
*/

int Find(int x){
	return x == parent[x] ? x : parent[x] = Find(parent[x]);
}

void Union(int x, int y){    //y: ������ ������
	parent[y] = x;
	printf("LADICA\n");
}

void init(){
	for (int i = 1; i <= L; i++){
		parent[i] = i;
	}
}

int main(){
	scanf("%d %d", &n, &L);
	init();
	for (int qq = 1; qq <= n; qq++){
		int a, b;
		scanf("%d %d", &a, &b);
		if (!check[a]){  //��Ģ 1 ����
			check[a] = true;
			Union(Find(b), Find(a));
		}
		else if (!check[b]){   //��Ģ 2 ����
			check[b] = true;
			Union(Find(a), Find(b));
		}
		else{
			a = Find(a), b = Find(b);
			if (!check[a]){    //��Ģ 3 ����
				check[a] = true;
				Union(b, a);
			}
			else if (!check[b]){  //��Ģ 4 ����
				check[b] = true;
				Union(a, b);
			}
			else{
				printf("SMECE\n");
			}
		}
	}
	return 0;
}