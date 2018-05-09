#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
const int MAXN = 100005;
int n;
int D[MAXN], r[MAXN], pi[MAXN], lcp[MAXN], sa[MAXN];
//D[i]: LCP[i+1]~ LCP[n] �߿��� �������� sa[i]�� ��Ÿ���� ���̻��� ���̺��� ū LCP�� ����

void fill_pi(string& s){
	pi[0] = 0;
	int j = 0;
	for (int i = 1; i < n; i++){
		while (j>0 && s[i] != s[j]){
			j = pi[j - 1];
		}
		if (s[i] == s[j]){
			pi[i] = j + 1;
			j += 1;
		}
		else{
			pi[i] = 0;
		}
	}
}

int get_lcp(vector< vector<int> >& group, int k, int i, int j){
	int ans = 0;
	while (i < n&&j < n&&k >= 0){
		if (group[k][i] == group[k][j]){
			ans += (1 << k);
			i += (1 << k);
			j += (1 << k);
		}
		k--;
	}
	return ans;
}

void fill_D(){  //D[i]: LCP[i+1]~ LCP[n] �߿��� �������� sa[i]�� ��Ÿ���� ���̻��� ���̺��� ū LCP�� ����
	for (int i = 0; i < n; i++){
		D[i] = 1;
	}
	for (int i = n - 1; i >= 0; i--){
		for (int j = i + 1; j < n; j++){
			if (lcp[j] >= n - sa[i]){   //n - sa[i]: ���̻� sa[i]�� ����
				D[i] += D[j];
				j += D[j] - 1;    //�˰ڴ�. ���ڵ尡 �־�� ���� �ٸ鼭 Ȯ���ϹǷ� �ð��ʰ��� �ȳ���.
			}
			else
				break;
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> s;
	n = s.size();
	fill_pi(s);
	vector< vector<int> > group(22, vector<int>(n + 1));
	for (int i = 0; i < n; i++){
		sa[i] = i;
	}
	for (int i = 0; i < n; i++){
		group[0][i] = s[i] - 'A';
	}
	group[0][n] = -1;
	int k = 0;

	for (int len = 1; len / 2 < n; len *= 2){
		auto cmp = [&](const int& u, const int& v){
			return group[k][u] == group[k][v] ? group[k][u + len] < group[k][v + len] : group[k][u] < group[k][v];
		};
		sort(sa, sa + n, cmp);
		group[k + 1][sa[0]] = 0;
		group[k + 1][n] = -1;
		for (int i = 1; i < n; i++){
			group[k + 1][sa[i]] = group[k + 1][sa[i - 1]] + cmp(sa[i - 1], sa[i]);
		}
		k++;
	}
	for (int i = 1; i < n; i++){
		lcp[i] = get_lcp(group, k, sa[i - 1], sa[i]);
	}
	fill_D();
	for (int i = 0; i<n; i++){
		r[sa[i]] = i;
	}
	vector< pair<int, int> > ans;
	ans.push_back({ n, 1 });
	int x = pi[n - 1];    //x: ����
	while (x > 0){
		int idx = r[n - x];   //���ݺ��� ���̻�(n - x)�� sa�󿡼� ���° �ε��������� �����´�. ����.
		ans.push_back({ x, D[idx] });
		x = pi[x - 1];
	}
	cout << ans.size() << "\n";
	for (int i = ans.size() - 1; i >= 0; i--){
		cout << ans[i].first << " " << ans[i].second << "\n";
	}
	return 0;
}