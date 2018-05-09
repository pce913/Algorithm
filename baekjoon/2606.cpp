#include<iostream>

using namespace std;

int p[101];

int n, m;//��ǻ���� ��, ������ ��
int Find(int x)
{
	if (x == p[x])
		return x;
	else
	{
		int y = Find(p[x]);
		p[x] = y;
		return y;
	}
}

void Union(int x, int y)
{
	x = Find(x);
	y = Find(y);
	if (x != y)
		p[y] = x;
}
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		p[i] = i;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		Union(a, b);
	}

	int count = 0;
	for (int i = 1; i <= n; i++)
	{                           
		if (Find(i) == Find(1))    //���� Find(i)==Find(1) �̾�� �ؿ�. ���� ������ �񱳴�
			count++;         // parent�� �ϴ°��� �ƴ϶� Find�� �Ѵ�ϴ�.
	}
	printf("%d", count - 1);
	return 0;
}
//#include<stdio.h>
//int parent[101];
//int Find(int x){
//	return parent[x] == x ? x : parent[x] = Find(parent[x]);
//}
//void Union(int x,int y){
//	x = Find(x);
//	y = Find(y);
//	if (x != y)
//		parent[y] = x;
//}
//
//int main(){
//	int n, m;
//	scanf("%d %d",&n,&m);
//	for (int i = 1; i <= n; i++){
//		parent[i] = i;
//	}
//
//	for (int i = 0; i < m; i++){
//		int x, y;
//		scanf("%d %d",&x,&y);
//		Union(x,y);
//	}
//	int ans = 0;
//	for (int i = 2; i <= n; i++){
//		if (Find(1) == Find(i))
//			ans++;
//	}
//	printf("%d",ans);
//	return 0;
//}