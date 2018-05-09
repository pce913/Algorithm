#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
//��� �κ� ���ڿ��� suffix�� prefix �̴�.
//1.suffix array ����
//2.������ suffix�� ���� prefix�� ���� ����.

int lcp(string& s, int i, int j){    //lcp O(N) ����. O(logn) ������ 11479��: ���� �ٸ� �κй��ڿ��� ����2 �� �ִ�. 
	int k = 0;
	while (i < s.size() && j < s.size() && s[i] == s[j]){
		i++, j++, k++;
	}
	return k;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> s;
	int n = s.size();
	vector<int> sa(n);
	vector<int> group(n + 1);
	for (int i = 0; i < n; i++){
		sa[i] = i;
	}
	for (int i = 0; i < n; i++){
		group[i] = s[i];
	}
	group[n] = -1;
	for (int len = 1; len / 2 < n; len *= 2){  //suffix array ���ϱ�
		auto cmp = [&](const int& u, const int& v){
			if (group[u] == group[v]){
				return group[u + len] < group[v + len];
			}
			else{
				return group[u] < group[v];
			}
		};
		sort(sa.begin(), sa.end(), cmp);

		vector<int> group2(n + 1);
		group2[sa[0]] = 0;
		group2[n] = -1;
		for (int i = 1; i < n; i++){
			if (cmp(sa[i - 1], sa[i])){
				group2[sa[i]] = group2[sa[i - 1]] + 1;
			}
			else{
				group2[sa[i]] = group2[sa[i - 1]];
			}
		}
		group = group2;
	}
	long long ans = 0;
	for (int i = 0; i < n; i++){
		int cp = 0;
		if (i>0){
			cp = lcp(s, sa[i - 1], sa[i]);    //lcp�� suffix array ���� ������ ���̻� �迭 ������ ���踦 ���°��̴�.
		}    //���̰� n�� ���ڿ��� prefix�� ������ n�̴�.
		ans += (s.size() - sa[i]) - cp;   //s.size()-sa[i] : i��° suffix �� ����. ���̰� n�� ���ڿ��� prefix�� ������ n�̴�.
	}                                      //���⼭ ��ġ�� �κ��� lcp�� ����� �Ѵ�.
	cout << ans;
	return 0;
}
//#include<iostream>
//#include<string>
//#include<algorithm>
//#include<vector>
//using namespace std;
////��� �κ� ���ڿ��� suffix�� prefix �̴�.
////1.suffix array ����
////2.������ suffix�� ���� prefix�� ���� ����.
//
//int lcp(string& s,int i,int j){    //lcp O(N) ����. O(logn) ������ 11479��: ���� �ٸ� �κй��ڿ��� ����2 �� �ִ�. 
//	int k = 0;
//	while (i < s.size() && j < s.size() && s[i] == s[j]){
//		i++, j++, k++;
//	}
//	return k;
//}
//
//int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	string s;
//	cin >> s;
//	int n = s.size();
//	vector<int> sa(n);
//	vector<vector<int> > group(20, vector<int>(n + 1));  //20���� ��� ������ �ؿ� len�� �αװ��� �ƹ��� Ŀ�� 20�� ���� �ʱ� �����̴�. ��, len�� �ƹ��� Ŀ�� 2^20�� ���� �ʴ´�.
//	for (int i = 0; i < n; i++){
//		sa[i] = i;
//	}
//	for (int i = 0; i < n; i++){
//		group[0][i] = s[i];
//
//	}
//	group[0][n] = -1;
//	for (int k = 0, len = 1; len / 2 < n; k += 1, len *= 2){  //suffix array ���ϱ�
//		auto cmp = [&](const int& u, const int& v){
//			if (group[k][u] == group[k][v]){
//				return group[k][u + len] < group[k][v + len];
//			}
//			else{
//				return group[k][u] < group[k][v];
//			}
//		};
//		sort(sa.begin(), sa.end(), cmp);
//
//		group[k + 1][sa[0]] = 0;
//		group[k + 1][n] = -1;
//		for (int i = 1; i < n; i++){
//			if (cmp(sa[i - 1], sa[i])){
//				group[k + 1][sa[i]] = group[k + 1][sa[i - 1]] + 1;
//			}
//			else{
//				group[k + 1][sa[i]] = group[k + 1][sa[i - 1]];
//			}
//		}
//	}
//	long long ans = 0;
//	for (int i = 0; i < n; i++){
//		int cp = 0;
//		if (i>0){
//			cp = lcp(s, sa[i - 1], sa[i]);    //lcp�� suffix array ���� ������ ���̻� �迭 ������ ���踦 ���°��̴�.
//		}    //���̰� n�� ���ڿ��� prefix�� ������ n�̴�.
//		ans += (s.size() - sa[i]) - cp;   //s.size()-sa[i] : i��° suffix �� ����. ���̰� n�� ���ڿ��� prefix�� ������ n�̴�.
//	}                                      //���⼭ ��ġ�� �κ��� lcp�� ����� �Ѵ�.
//	cout << ans;
//	return 0;
//}