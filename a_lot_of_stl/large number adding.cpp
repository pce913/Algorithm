#include<iostream>
using namespace std;
//백준 1793 타일링
char s[255][1005], r1[1005], r2[1005];
void solve(int test) {
	int n;
	cin >> n;
	cout << "#" << test << " " << s[n] << "\n";
}

void _strcpy(char c[],char t[]) {
	int i = 0;
	for (; t[i]; i++)c[i] = t[i];
	c[i] = 0;
}
int _strlen(char c[]) {
	int i = 0;
	for (; c[i]; i++);
	return i;
}
void _swap(char& x, char& y) {
	char t = x;
	x = y;
	y = t;
}
void reverse(char c[],int n) {
	for (int i = 0,k = n-1; i < k; i++,k--) {
		_swap(c[i], c[k]);
	}
}

void make_bigNum(char r[], char num1[],char num2[]) {
	int sum = 0;
	int rn = 0;
	int n1 = _strlen(num1), n2 = _strlen(num2);
	while (n1 > 0 || n2 > 0 || sum) {
		if (n1 > 0) {
			sum += num1[--n1] - '0';
		}
		if (n2 > 0) {
			sum += num2[--n2] - '0';
		}
		r[rn++] = (sum % 10) + '0';
		sum /= 10;
	}
	r[rn] = 0;
	reverse(r, rn);
}

void iFirst() {
	s[0][0] = s[1][0] = '1';
	for (int i = 2; i <= 250; i++) {
		make_bigNum(r1, s[i - 2], s[i - 2]);
		make_bigNum(r2, r1, s[i - 1]);
		_strcpy(s[i], r2);
	}
}

int main() {
	freopen("input.txt","r",stdin);
	iFirst();
	ios::sync_with_stdio(false), cin.tie(0);
	int T;
	cin >> T;
	for (int test = 1; test <= T; test++)solve(test);
	return 0;
}
