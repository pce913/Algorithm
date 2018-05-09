#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<tuple>
#include<iomanip>
#include<algorithm>
#include<functional>
#include<cmath>
#include<unordered_set>
#include<unordered_map>
#include <bitset>
using namespace std;

//long long
const long long MAXN = 1505, BASE = 40017, MOD1 = 1e9 + 513, MOD2 = 1e9 + 531;
char A[MAXN], B[MAXN];
long long conv[26][1505], suma[26][1505], sumb[26][1505];     //���ĺ��� ����Ƚ��
long long power1[MAXN], power2[MAXN], hash_a1[MAXN], hash_a2[MAXN], hash_b1[MAXN], hash_b2[MAXN];
long long n, m;
long long pup[26];
set<long long> st_b1[1505], st_b2[1505]; //st[len] : ���̿� ���ؼ� 
vector<long long> v_a1[1505], v_a2[1505];  //v[len]: ���̿� ���ؼ�
long long get_value(char alpha, long long cnt){   //���� Ƚ���� ���� �ؽ�
	return conv[alpha - 'a'][cnt];
}
void init(){
	//bitset<64000000> bt;
	long long xx = 1;
	for (long long i = 0; i < 26; i++){
		for (long long j = 1; j <= 1500; j++){
			conv[i][j] = xx++;
		}
	}
	for (long long i = 1; i <= n; i++){  //�������� ���ؾ� �ϴµ� �׷��� �ʰ� �ֳ�.
		for (long long j = 0; j < 26; j++){
			suma[j][i] += suma[j][i - 1];
		}
		suma[A[i] - 'a'][i]++;
	}
	for (long long i = 1; i <= m; i++){
		for (long long j = 0; j < 26; j++){
			sumb[j][i] += sumb[j][i - 1];
		}
		sumb[B[i] - 'a'][i]++;
	}
	for (long long len = 1; len <= n; len++){   //�Ѹ� �ؽ�
		for (long long i = 1; i + len - 1 <= n; i++){
			long long j = i + len - 1;
			long long hash1 = 0, hash2 = 0;
			for (long long x = 0; x < 26; x++){
				long long cnt = suma[x][j] - suma[x][i - 1];
				hash1 = (hash1*BASE + get_value(x + 'a', cnt)) % MOD1;   //BASE�� ������߸� �浹 ���Ͼ� �� ���̴�.
				hash2 = (hash2*BASE + get_value(x + 'a', cnt)) % MOD2;
			}
			v_a1[len].push_back(hash1);
			v_a2[len].push_back(hash2);
		}
	}

	for (long long len = 1; len <= m; len++){
		for (long long i = 1; i + len - 1 <= m; i++){
			long long j = i + len - 1;
			long long hash1 = 0, hash2 = 0;
			for (long long x = 0; x < 26; x++){
				long long cnt = sumb[x][j] - sumb[x][i - 1];
				hash1 = (hash1*BASE + get_value(x + 'a', cnt)) % MOD1;
				hash2 = (hash2*BASE + get_value(x + 'a', cnt)) % MOD2;
			}
			if (hash1 == 320680538)
				int aaa = 3;
			st_b1[len].insert(hash1);
			st_b2[len].insert(hash2);
		}
	}

	//1.������ ������ó�� ��� �������� � ���ĺ��� ��� �����ߴ��� ����.
	//2.�װ� �̿��ؼ� ª�� ���̷� ����.
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> (A + 1);
	cin >> (B + 1);
	n = strlen(A + 1), m = strlen(B + 1);
	init();
	for (long long len = n; len >= 1; len--){
		for (long long i = 0; i < v_a1[len].size(); i++){
			long long hash_a1 = v_a1[len][i], hash_a2 = v_a2[len][i];
			if (st_b1[len].count(hash_a1)>0 && st_b2[len].count(hash_a2) > 0){    //���� ���� ������ ���̳ʸ� ��ġ ����
				cout << len;
				return 0;
			}
		}
	}
	cout << "0";
	return 0;
}
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<iostream>
//#include<string>
//#include<cstring>
//#include<vector>
//#include<stack>
//#include<queue>
//#include<set>
//#include<map>
//#include<tuple>
//#include<iomanip>
//#include<algorithm>
//#include<functional>
//#include<cmath>
//#include<unordered_set>
//#include<unordered_map>
//using namespace std;
////long long
//const long long MAXN = 1505, BASE = 40017, MOD1 = 1e9 + 513, MOD2 = 1e9 + 531;
//char A[MAXN], B[MAXN];
//long long conv[26][1505];     //���ĺ��� ����Ƚ��
//long long power1[MAXN],power2[MAXN],hash_a1[MAXN], hash_a2[MAXN], hash_b1[MAXN], hash_b2[MAXN];
//long long n, m;
//long long pup[26];
//set<long long> st_b1[1505],st_b2[1505]; //st[len] : ���̿� ���ؼ� 
//vector<long long> v_a1[1505], v_a2[1505];  //v[len]: ���̿� ���ؼ�
//long long get_value(char alpha, long long cnt){   //���� Ƚ���� ���� �ؽ�
//	return conv[alpha - 'a'][cnt];
//}
//
//void init(){
//	long long xx = 1;
//	for (long long i = 0; i < 26; i++){
//		for (long long j = 0; j <= 1500; j++){
//			conv[i][j] = xx++;
//		}
//	}
//
//	long long L = max(m, n);
//	power1[0] = power2[0] = 1;
//	for (long long i = 1; i <= L; i++){
//		power1[i] = (power1[i - 1] * BASE) % MOD1;
//		power2[i] = (power2[i - 1] * BASE) % MOD2;
//	}
//
//	for (long long i = 1; i <= n; i++){
//		pup[A[i] - 'a']++;
//		hash_a1[i] = ((hash_a1[i - 1] * BASE)%MOD1 + get_value(A[i], pup[A[i] - 'a'])) % MOD1;
//		hash_a2[i] = ((hash_a2[i - 1] * BASE)%MOD2 + get_value(A[i], pup[A[i] - 'a'])) % MOD2;
//	}
//	for (long long len = 1; len <= n; len++){
//		for (long long i = 1; i + len - 1 <= n; i++){
//			v_a1[len].push_back((hash_a1[i + len - 1] - (hash_a1[i - 1] * power1[len]) % MOD1 + MOD1) % MOD1);   //power�� �ؽ��̵� ������� �Ѵ�!!!!!!
//			v_a2[len].push_back((hash_a2[i + len - 1] - (hash_a2[i - 1] * power2[len]) % MOD2 + MOD2) % MOD2);
//		}
//	}
//
//	memset(pup, 0, sizeof(pup));
//	for (long long i = 1; i <= m; i++){
//		pup[B[i] - 'a']++;
//		hash_b1[i] = ((hash_b1[i - 1] * BASE)%MOD1 + get_value(B[i], pup[B[i] - 'a'])) % MOD1;
//		hash_b2[i] = ((hash_b2[i - 1] * BASE)%MOD2 + get_value(B[i], pup[B[i] - 'a'])) % MOD2;
//	}
//	for (long long len = 1; len <= m; len++){
//		for (long long i = 1; i + len - 1 <= m; i++){
//			st_b1[len].insert((hash_b1[i + len - 1] - (hash_b1[i - 1] * power1[len]) % MOD1 + MOD1) % MOD1);
//			st_b2[len].insert((hash_b2[i + len - 1] - (hash_b2[i - 1] * power2[len]) % MOD2 + MOD2) % MOD2);
//		}
//	}
//}
//
//long long main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cin >> (A + 1);
//	cin >> (B + 1);
//	n = strlen(A + 1), m = strlen(B + 1);
//	init();
//	for (long long len = n; len >= 1; len--){
//		for (long long i = 0; i < v_a1[len].size(); i++){
//			long long hash_a1 = v_a1[len][i], hash_a2 = v_a2[len][i];
//			if (st_b1[len].count(hash_a1)>0 && st_b2[len].count(hash_a2)>0){    //���� ���� ������ ���̳ʸ� ��ġ ����
//				cout << len;
//				return 0;
//			}
//		}
//	}
//	cout << "0";
//	return 0;
//}