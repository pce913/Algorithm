#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<tuple>
using namespace std;
int n, k;
string w[2][55]; //�Է����� �־����� �ܾ ����. w[0]���� �״�� ����, w[1]���� ����� ����.
const int MOD = 835454957;
struct State{
	int len;  //�߰��ؾ� �ϴ� ���ڿ��� ���� 
	string stick;  //Ƣ��� ���ڿ�
	int dir;   //��������, ����������   �����̸� 0, �������̸� 1
	State(int _len, string _stick, int _dir) :len(_len), stick(_stick), dir(_dir){}
	bool operator<(const State& t)const{
		return make_tuple(len, stick, dir) < make_tuple(t.len, t.stick, t.dir);
	}
};

map<State, int> D;   //���¸� �����ؾ� �ϹǷ� �迭�� ����� ����� ��� ���� ����Ѵ�.
bool isPalin(const string& s){   //�Ӹ�������� �ƴ��� Ȯ��
	int i = 0;
	int j = s.size() - 1;
	while (i < j){
		if (s[i++] != s[j--])
			return false;
	}
	return true;
}

bool starts_with(const string& s1, const string& s2){   //s1�� s2�� �����ϴ���
	return s2.size() <= s1.size() && s1.compare(0, s2.size(), s2) == 0;
}

int go(State state){
	if (D.count(state) > 0){
		return D[state];
	}

	int ans = 0;
	if (isPalin(state.stick)){
		ans++;
	}
	for (int i = 0; i < n; i++){
		string s = w[state.dir][i];
		if (state.len >= (int)s.size()){    //���� �߰��ؾߵǴ� ���ڿ� s�� ���̰� �߰��ؾ� �Ǵ� ���ڿ� ���� len���� �۴ٸ�,
			if (starts_with(state.stick, s)){  //Ƣ��� ���ڿ� stick�� s�� �����ϴ���   //���� ���¿��� Ƣ��� ���ڰ�, �߰��Ϸ��� ���� s���� ���̰� �� ���
				ans = (ans + go({ (int)state.len - (int)s.size() - 1, state.stick.substr(s.size()), state.dir })) % MOD; //������ �ٲ��� �ʰ� �ܼ��� �߰��Ϸ��� ������ ������ Ƣ��� ���ڰ� ���������� �ٲ��.
			}
			else if (starts_with(s, state.stick)){  //���ڿ� s�� Ƣ��� ���ڿ� b�� �����ϴ���
				ans = (ans + go({ (int)state.len - (int)s.size() - 1, s.substr(state.stick.size()), 1 - state.dir })) % MOD;  //������ �ٲ��.
			}
		}
	}
	D[state] = ans;
	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++){
		cin >> w[0][i];
		w[1][i] = w[0][i];
		reverse(w[1][i].begin(), w[1][i].end());
	}
	int ans = go({ k, "", 0 }) - 1;   //�� ���ڿ��� ���Խ�Ű�� �ʱ� ���� -1
	if (ans < 0) {
		ans = MOD - 1;
	}
	cout << ans;
	return 0;
}

//WeissBlume �� �ڵ�

//#include<bits/stdc++.h>
//using namespace std;
//using ll = long long;
//const int MOD(835454957);
//
//int n, m, len[55];
//char s[2][55][16];
//int d[111][22][55][2];
//
//inline bool is_palindrome(const string& x) {
//	for (int i = 0; i + i < x.size(); i++)
//	if (x[i] != x[x.size() - i - 1])
//		return false;
//	return true;
//}
//
//int go(const int left, const int covered, const int last, const int flip)
//{
//	int &ret = d[left][covered][last][flip];
//	if (~ret) return ret;
//	ret = is_palindrome(string(s[flip][last]).substr(covered));
//
//	for (int i = 0; i < n; i++) if (left > len[i]) {
//		const int minl = min(len[last] - covered, len[i]);
//		int matches = 0;
//		for (int j = 0; j < minl; j++) {
//			if (s[flip][last][covered + j] == s[!flip][i][j]) ++matches;
//			else break;
//		}
//		if (matches < minl) continue;
//		if (covered + matches >= len[last]) {
//			ret = (ret + go(left - len[i] - 1, matches, i, !flip)) % MOD;
//		}
//		else {
//			ret = (ret + go(left - len[i] - 1, covered + matches, last, flip)) % MOD;
//		}
//	}
//
//	return ret;
//}
//
//int main()
//{
//	scanf("%d%d", &n, &m);
//	for (int i = 0; i < n; i++) {
//		scanf("%s", s[0][i]), len[i] = strlen(s[0][i]);
//		for (int j = 0; j < len[i]; j++) s[1][i][len[i] - 1 - j] = s[0][i][j];
//	}
//
//	int ans = 0;
//	memset(d, -1, sizeof d);
//	for (int i = 0; i < n; i++) if (m >= len[i]) {
//		ans = (ans + go(m - len[i], 0, i, 0)) % MOD;
//	}
//
//	printf("%d\n", ans);
//	return 0;
//}