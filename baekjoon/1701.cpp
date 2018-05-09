#include<stdio.h>
#include<map>
#include<cstring>
using namespace std;
const long long MAXN = 5005;
const long long BASE = 26;
const long long MOD1 = 1e9 + 513;
const long long MOD2 = 1e9 + 531;
long long power1[MAXN], power2[MAXN], hash1[MAXN], hash2[MAXN];
char s[MAXN];
long long n;
bool go(long long mid){
	map<long long, long long> mp1, mp2;
	for (long long i = mid; i <= n; i++){
		long long thash1 = (hash1[i] - (hash1[i - mid] * power1[mid]) % MOD1 + MOD1) % MOD1;
		long long thash2 = (hash2[i] - (hash2[i - mid] * power2[mid]) % MOD2 + MOD2) % MOD2;
		mp1[thash1]++, mp2[thash2]++;
		if (mp1[thash1] >= 2 && mp2[thash2] >= 2){
			return true;
		}
	}
	return false;
}

int main(){
	scanf("%s", &s[1]);
	n = strlen(&s[1]);

	power1[0] = 1;
	power2[0] = 1;
	for (long long i = 1; i <= n; i++){
		power1[i] = (power1[i - 1] * BASE) % MOD1;
		power2[i] = (power2[i - 1] * BASE) % MOD2;
	}
	for (long long i = 1; i <= n; i++){
		hash1[i] = (hash1[i - 1] * BASE + s[i] - 'a') % MOD1;
		hash2[i] = (hash2[i - 1] * BASE + s[i] - 'a') % MOD2;
	}

	long long left = 1;
	long long right = n;
	long long ans = 0;
	while (left <= right){
		long long mid = (left + right) >> 1;
		if (go(mid)){
			ans = mid;
			left = mid + 1;
		}
		else{
			right = mid - 1;
		}
	}
	printf("%lld", ans);
	return 0;
}
//#include <iostream>
//#include <algorithm>
//#include<cstring>
//using namespace std;
//
//char s[5005];
//int pi[5005];
//int fill_pi(char p[]){   //1���̽�
//	memset(pi, 0, sizeof(pi));
//	int m = strlen(p + 1);
//	pi[1] = 0;
//	int j = 1;
//	int ans = 0;
//	for (int i = 2; i <= m; i++){
//		while (j > 1 && p[i] != p[j]){
//			j = pi[j - 1] + 1;
//		}
//		if (p[i] == p[j]){
//			pi[i] = j;
//			j += 1;
//		}
//		else{
//			pi[i] = 0;
//		}
//		ans = max(ans, pi[i]);
//	}
//	return ans;
//}
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cin >> s+1;
//	int ans = 0;
//	int n = strlen(s + 1);
//	for (int i = 0; i < n; i++){    //kmp ���� �̿�. kmp�� pi�� '�� ��'���� �����Ͽ� prefix==suffix�� �����ϴ� ���� �� ���̸� �����ϰ� �ִ�.
//		ans = max(ans, fill_pi(&s[i])); //prefix==suffix��� ���� �̹� ���ڿ����� �ι� ���� �ߴٴ� ���̹Ƿ�(prefix���� �ѹ�, suffix���� �ѹ�) ���� ���ϴµ� �̿� �����ϴ�.
//	}                                   //���⼭ '�� ��' ������ ó���ϱ� ���� �Է����� �־��� ���ڿ��� �պκ� ���� �ϳ��� ����鼭 �Ź� kmp�� ���� �ȴ�.
//	cout << ans << '\n';
//	return 0;
//}