#include<iostream>
#include<string>
#include <cstring>
#include<algorithm>
#include <vector>
using namespace std;
//������(��Ʈ��ŷ) �ϴ� ������ ��ͷ� Ǯ��� ����!
//�������� LCS�� ã�� ������ 9252���� �����صξ���.
string s1, s2;
int D[1005][1005];
string ans;
int go(int i,int j){
	if (i == s1.size() || j == s2.size())return 0;
	int& ret = D[i][j];
	if (ret != -1)
		return ret;
	ret = 0;
	if (s1[i] == s2[j]){
		ret = go(i + 1, j + 1) + 1;
	}
	else{
		ret = max(go(i + 1, j), go(i, j + 1));
	}
	return ret;
}

void backtracking(int i,int j){
	if (i == s1.size() || j == s2.size())return;
	if (s1[i] == s2[j]){
		ans.push_back(s1[i]);
		backtracking(i + 1, j + 1);
	}
	else{
		if (D[i + 1][j] > D[i][j + 1]){
			backtracking(i + 1, j);
		}
		else{
			backtracking(i, j + 1);
		}
	}
}

int main(){                      // �ִ���� �κ� ���ڿ��� ����.
	cin >> s1 >> s2;
	memset(D, -1, sizeof(D));
	cout << go(0, 0) << "\n";
	backtracking(0, 0);
	cout << ans;
	return 0;
}