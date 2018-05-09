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

char M[505][505];
bool check[505][505][4];
int dx[] = { -1, 0, 1, 0 };   //0: up, 1: right, 2: down, 3: left
int dy[] = { 0, 1, 0, -1 };
int ls[] = { 3, 2, 1, 0 };
int rs[] = { 1, 0, 3, 2 };
char print[300];
int n, m;
bool endss;
bool infi;
int sx, sy;
int timer = 0;
void dfs(int cx,int cy,int dir){
	check[cx][cy][dir] = true;
	//��Ȧ�� �����ų� ĭ�� ����� ��쿡�� ���� ����
	//��Ȧ�� ���信 ���Խ��Ѿ� �ϴ��� ���ƾ� �ϴ��� ��ȣ�ϴ�. �Ƹ��� ���Խ�Ű�� �������̴�.
	++timer;
	if (M[cx][cy] == '\\')   //�������� �����
		dir = ls[dir];
	else if (M[cx][cy] == '/') //���������� ��� ���
		dir = rs[dir];
	int nx = cx + dx[dir];
	int ny = cy + dy[dir];
	if (M[nx][ny] == 'C'){
		endss = true;
		return;
	}
	if (nx >= 1 && nx <= n && ny >= 1 && ny <= m){
		if (!endss){
			if (!check[nx][ny][dir])
				dfs(nx, ny, dir);
			else{
				infi = true;
				return;
			}
		}
	}
	else {   //ĭ�� ��� ���
		endss = true;
		return;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	print[0] = 'U', print[1] = 'R', print[2] = 'D', print[3] = 'L';
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> &M[i][1];
	}
	cin >> sx >> sy;
	//���� ��ġ�� ���信 ���Խ��Ѿ���.
	int ans = -1;
	char pp;
	for (int dir = 0; dir < 4; dir++){
		memset(check, false, sizeof(check));
		endss = false;
		timer = 0;
		dfs(sx, sy, dir);
		if (infi){    //���� Ʋ���� �ִ°��� ����� �ƴϴ�.
			cout << print[dir] << "\n";
			cout << "Voyager";
			return 0;
		}
		if (ans < timer){
			ans = timer;
			pp = print[dir];
		}
	}
	cout << pp << "\n";   //U,R,D,L ������ ����ؾ� �Ѵ�.s
	cout << ans << "\n";
	return 0;
}