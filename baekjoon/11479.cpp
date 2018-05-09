#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
//��� �κ� ���ڿ��� suffix�� prefix �̴�.
//1.suffix array ����
//2.������ suffix�� ���� prefix�� ���� ����.

int lcp(int n,vector< vector<int> >& group,int k,int i,int j){    //lcp O(logn) ����.
	int ans = 0;
	while (i < n&& j < n&&k >= 0){
		if (group[k][i] == group[k][j]){    //i�� ���̻�� j�� ���̻�� �տ������� 2^k��ŭ�� ����. ��� ��
			ans += (1 << k);
			i += (1 << k);
			j += (1 << k);
		}
		k--;
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> s;
	int n = s.size();
	vector<int> sa(n);
	vector<vector<int> > group(25, vector<int>(n + 1));  //20���� ��� ������ �ؿ� len�� �αװ��� �ƹ��� Ŀ�� 20�� ���� �ʱ� �����̴�. ��, len�� �ƹ��� Ŀ�� 2^20�� ���� �ʴ´�.
	for (int i = 0; i < n; i++){
		sa[i] = i;
	}
	for (int i = 0; i < n; i++){
		group[0][i] = s[i];

	}
	group[0][n] = -1;
	int k = 0;   //�׷� ����.
	for (int len = 1; len / 2 < n; len *= 2){  //suffix array ���ϱ�
		auto cmp = [&](const int& u, const int& v){
			if (group[k][u] == group[k][v]){
				return group[k][u + len] < group[k][v + len];
			}
			else{
				return group[k][u] < group[k][v];
			}
		};
		sort(sa.begin(), sa.end(), cmp);

		group[k + 1][sa[0]] = 0;
		group[k + 1][n] = -1;
		for (int i = 1; i < n; i++){
			if (cmp(sa[i - 1], sa[i])){
				group[k + 1][sa[i]] = group[k + 1][sa[i - 1]] + 1;
			}
			else{
				group[k + 1][sa[i]] = group[k + 1][sa[i - 1]];
			}
		}
		k++;
	}
	long long ans = 0;
	for (int i = 0; i < n; i++){
		int cp = 0;
		if (i>0){
			cp = lcp(n, group, k, sa[i - 1], sa[i]);    //lcp�� suffix array ���� ������ ���̻� �迭 ������ ���踦 ���°��̴�.
		}    //���̰� n�� ���ڿ��� prefix�� ������ n�̴�.
		ans += (s.size() - sa[i]) - cp;   //s.size()-sa[i] : i��° suffix �� ����. ���̰� n�� ���ڿ��� prefix�� ������ n�̴�.
	}                                      //���⼭ ��ġ�� �κ��� lcp�� ����� �Ѵ�.
	cout << ans;
	return 0;
}



