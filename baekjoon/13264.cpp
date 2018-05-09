#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
//radix sort�� �̿��ϸ� suffix array�� ������ ���� �� ������, lcp�� ���Ҷ� �������� �ʳ�?
struct suffix {
	int index;
	int rank[2];
}; 
//t���ڸ� �������� ���ĵǾ� �ִٸ�, t*2���ڸ� �������ε� ������ �� �ִ�.
void radix_sort(int len, vector<int> &sa, vector<int> &group) {
	int n = sa.size();   //n: suffix array�� ���� �� ���ڿ��� ����.
	vector<suffix> a(n);
	for (int i = 0; i<n; i++) {
		a[i].index = sa[i];  //index: ��� ���̻� ������ ����
		a[i].rank[0] = group[sa[i]];  //rank[0]: �ش� ���̻簡 ��� �׷������� ����.
		if (sa[i] + len < n) {
			a[i].rank[1] = group[sa[i] + len];  //rank[1]: �ش� ���̻�+len�� ��� �׷������� ����.
		}
		else {
			a[i].rank[1] = -1;  //��� ũ�Ⱑ n�� �Ѿ�� -1�� �������ش�. ������ ũ�Ⱑ n�� ���� ���� ������ n�� �Ѿ���� �ʴ´�. 
		}
	}
	vector<suffix> temp(n);
	for (int p = 1; p >= 0; p--) { //2�� �ݺ�
		vector<int> cnt(n + 1, 0);
		vector<int> sum(n + 2, 0);
		for (int i = 0; i < n; i++) {
			cnt[a[i].rank[p] + 1] += 1;  //����, '�ش� ���̻�+len �� �׷��ȣ' + 1 �� ������ �����ش�.
		}
		for (int i = 1; i < n + 1; i++) {   //�������� �����ش�. �׷��� �ִ� n�� ���� �� �ִ�.
			sum[i] = sum[i - 1] + cnt[i - 1]; //sum[i]���� i - 1 ��°������ �������� ������ �ִ�. i��°�� �ƴϴ�.
		} 
		for (int i = 0; i<n; i++) {
			temp[sum[a[i].rank[p] + 1]++] = a[i];
		}
		for (int i = 0; i<n; i++) {
			a[i] = temp[i];
		}
	}
	//�� ���� ���� ����Ǹ� sa�� �׷캰�� �����ִ�.

	for (int i = 0; i<n; i++) {
		sa[i] = a[i].index;
	}  
	group[a[0].index] = 0;   //���� �� �׷� ��Ἲ
	for (int i = 1; i<n; i++) {    
		if (a[i].rank[0] == a[i - 1].rank[0] && a[i].rank[1] == a[i - 1].rank[1]) {
			group[a[i].index] = group[a[i - 1].index];
		}
		else {
			group[a[i].index] = group[a[i - 1].index] + 1;
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> s;
	int n = s.length();
	vector<int> sa(n);
	vector<int> group(n);
	for (int i = 0; i<n; i++) {
		sa[i] = i;
	}
	for (int i = 0; i<n; i++) {
		group[i] = s[i] - 'a';
	}
	for (int len = 1; len / 2 < n; len *= 2) {   //���� �׷��̴�? �� Ȯ���ϴ� �۾��� logn�� ����� �Ѵ�.  1���ڷ� ����, 2���ڷ� ����, 4���ڷ� ����...
		radix_sort(len, sa, group);  //stl sort�� radix sort�� ��ü�� ���̴�.
	}
	for (int i = 0; i<n; i++) {
		cout << sa[i] << '\n';
	}
	return 0;
}
//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<string>
//using namespace std;
//
//int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	string s;
//	cin >> s;
//	int n = s.size();
//	vector<int> sa(n);   //sa: suffix array     �̰� push.back()���� �ʰ� �̸� ������ ����� ���°� �������̴�.
//	vector<int> group(n + 1);
//	for (int i = 0; i < n; i++){
//		sa[i] = i;
//	}
//	for (int i = 0; i < n; i++){
//		group[i] = s[i];
//	}
//	group[n] = -1;    //������ ���̻� �迭 �� �Ҷ� �ʿ���. ���� ���� ��Ʈ�� 13013�� ���� ����.
//	for (int len = 1; len / 2 < n; len *= 2){   //logn�� ����.
//		auto cmp = [&](const int& u,const int& v){   //[&]: ���� �Լ� �ۿ� �ִ� ��� �������� ���۷��� ���·� �������ڴ�.
//			if (group[u] == group[v]){   //���� �� �׷��ȣ�� ���ϰ� �� �׷��ȣ�� ���ٸ�
//				return group[u + len] < group[v + len];  //len��ŭ ������ �κ��� ���Ѵ�. ����.
//			}
//			else{
//				return group[u] < group[v];
//			}
//		};
//		sort(sa.begin(), sa.end(), cmp);
//
//		/////������ ���� �ε����� �׷��ȣ�� ������ �ٸ����� ���Ͽ� ���� �׷��ȣ�� �����.
//		vector<int> group2(n + 1);   
//		group2[sa[0]] = 0;   //���ĵ� suffix array�� �Ǿտ� �ִ� ���̻� �迭�� �翬�� 0�� �׷��� �ȴ�.
//		group2[n] = -1;
//		for (int i = 1; i < n; i++){
//			if (cmp(sa[i - 1], sa[i])){   //sa[i-1]�� sa[i]���� �׷������ �ռ��ٸ�, ��, ���������� �տ� �ִٸ�
//				group2[sa[i]] = group2[sa[i - 1]] + 1;    //���� ���ĵ� �������� �ٽ� �׷��ȣ�� �Ű��ش�.
//			}
//			else{  //sa[i-1]�� sa[i]�� ���� �׷������ ����̴�.   sa[i-1]�� sa[i]���� �׷������ �ռ����� ����.
//				group2[sa[i]] = group2[sa[i - 1]];
//			}
//		}
//		group = group2;
//	}
//	for (int i = 0; i < n; i++){
//		cout << sa[i] << "\n";
//	}
//	return 0;
//}