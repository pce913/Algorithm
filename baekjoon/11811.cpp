#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<tuple>
#include<iomanip>
#include<algorithm>
#include<functional>
#include<cmath>
#include<unordered_set>
#include<unordered_map>
using namespace std;

int a[1005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			int x;
			cin >> x;
			a[i] |= x;     //(a[1]&a[2]) | (a[1]&a[3]) ...
		}  //(a[1]&a[2]) �϶��� ����. �̰��� a[1]�� a[2]�� ���� ��ġ�� ��Ʈ�� ������ �ִ°��̴�.
	}  //���������� (a[1]&a[3]) �� a[1]�� a[3]�� ���� ��ġ�� ��Ʈ�� ������ �ִ� ���̴�. ��, ���� ��ġ�� �κ��� �Ϻκо� ������ ������ �ȴ�.
	for (int i = 1; i <= n; i++)
		cout << a[i] << " ";
	return 0;
}