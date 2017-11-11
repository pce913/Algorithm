#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int D[1001][1001];               //D[n][m]:  s1���ڿ��� �տ��� n���� ���Ұ�, s2���ڿ��� �տ��� m���� ��������
int main(){                      // �ִ���� �κ� ���ڿ��� ����.
	string s1,s2;
	cin >> s1>>s2;
	
	int n = s1.size();
	int m = s2.size();
	int x=1;
	for (; x <= m; x++){
		if (s1[0] == s2[x - 1]){
			break;
		}
	}
	for (; x <= m; x++){
		D[1][x] = 1;
	}

	x = 1;
	for (; x <= n; x++){
		if (s1[x - 1] == s2[0]){
			break;
		}
	}
	for (; x <= n; x++){
		D[x][1] = 1;
	}
	/////  ��ó��
	
	for (int i = 2; i <= n; i++){
		for (int j = 2; j <= m; j++){
			if (s1[i - 1] == s2[j - 1]){
				D[i][j] = D[i - 1][j - 1] + 1;
			}
			else{
				D[i][j] = max(D[i - 1][j], D[i][j - 1]);
			}
		}
	}
	cout << D[n][m];
	
	return 0;
}