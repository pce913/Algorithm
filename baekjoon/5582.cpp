#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

//�Է����� �־��� �� ���ڿ��� ���̻� �迭�� ��ġ�°����� ������ Ǯ �� �ִ�.
//�̰��� �� ���ڿ��� ��ģ ���� ���̻� �迭�� ���� ����� ����.
int n;
int get_lcp(vector<vector<int>> &group, int k, int i, int j) {
	int ans = 0;
	while (i < n && j < n && k >= 0) {
		if (group[k][i] == group[k][j]) {
			ans += (1 << k);
			i += (1 << k);
			j += (1 << k);
		}
		k -= 1;
	}
	return ans;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string a, b;
	cin >> a >> b;
	int na = a.length();
	int nb = b.length();   
	string s = a + "#" + b;     //#�� ���� ����� �������� �ʴ� ���ڸ� �߰����ָ� �ݷʸ� ���� �� �ִ�. ���� �����ڷ� ����.
	n = s.length();
	vector<int> sa(n);
	vector<vector<int>> group(22, vector<int>(n + 1));
	for (int i = 0; i<n; i++) {
		sa[i] = i;
	}
	for (int i = 0; i<n; i++) {
		group[0][i] = s[i];
	}
	group[0][n] = -1;
	int k = 0;
	for (int len = 1; len / 2 < n; len *= 2) {
		auto cmp = [&](int u, int v) {
			if (group[k][u] == group[k][v]) {
				return group[k][u + len] < group[k][v + len];
			}
			else {
				return group[k][u] < group[k][v];
			}
		};
		sort(sa.begin(), sa.end(), cmp);
		group[k + 1][sa[0]] = 0;
		group[k + 1][n] = -1;
		for (int i = 1; i<n; i++) {
			if (cmp(sa[i - 1], sa[i])) {
				group[k + 1][sa[i]] = group[k + 1][sa[i - 1]] + 1;
			}
			else {
				group[k + 1][sa[i]] = group[k + 1][sa[i - 1]];
			}
		}
		k++;
	}
	vector<int> lcp(n);
	lcp[0] = -1;
	for (int i = 1; i<n; i++) {
		lcp[i] = get_lcp(group, k, sa[i - 1], sa[i]);
	}

	int ans = 0;
	for (int i = 1; i<n; i++) {
		if ((sa[i - 1] < na && sa[i] < na) || (sa[i - 1] >= na && sa[i] >= na))//���� ���� ���ڿ� �������� lcp�� ���ϴ°��� ���� ���ƾ� �ϹǷ� �� ������ �߰����ش�.
			continue;
		ans = max(ans, lcp[i]);
	}
	cout << ans << '\n';
	return 0;
}
//#include<iostream>
//#include<string>
//#include<algorithm>
//using namespace std;
////LCS ����: Longest Common Sequence
//int D[4005][4005];   //D[i][j]: ù° ���ڿ��� i���� ���Ұ�, ��° ���ڿ��� j���� ��������
//                     //         i�� j���� '����'���� ���� �� ���� �κ� ���ڿ��� ����
//int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	string a,b;
//	cin >> a >> b;
//	for (int i = 0; i < a.size(); i++){
//		for (int j = 0; j < b.size(); j++){
//			if (a[i] == b[j]){
//				if (i - 1 >= 0 && j - 1 >= 0)
//					D[i][j] = D[i - 1][j - 1] + 1;
//				else
//					D[i][j] = 1;
//			}
//			else{
//				D[i][j] = 0;
//			}
//		}
//	}
//	int ans = 0;
//	for (int i = 0; i < a.size(); i++){
//		for (int j = 0; j < b.size(); j++){
//			ans = max(ans, D[i][j]);
//		}
//	}
//	cout << ans;
//	return 0;
//}