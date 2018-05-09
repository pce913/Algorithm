//#include<stdio.h>
//#include<string>
//#include<vector>
//#include<iostream>
//using namespace std;
//long long D[1<<15][101];          //D[S][M]: ������ ���Ե� �� S, �׶� �������� M�� ���� ����
//bool check[1 << 15][101];
//
//int a[16];
//int len[16];
//int ten[51];        //10�� �ŵ��������� �̸� �� ���س���.
//int n;
//int k;       //������ �� k
//long long gcd(long long a, long long b){     // ���м� ���·� ��Ÿ���� ���� �ִ����� ������.
//	return b == 0 ? a : gcd(b, a%b);
//}
//
//long long go(int mask,int m){
//	
//	if (mask == 0 && m==0){       //���� ����
//		return 1;
//	}
//
//	if (check[mask][m]){
//		return D[mask][m];
//	}
//	check[mask][m] = true;
//	long long& ans = D[mask][m];
//
//	/*for (int j = 0; j < k; j++){
//		for (int l = 0; l < n; l++){
//			if ((mask&(1 << l))==0){
//				int next = (j*ten[len[l]] % k + a[l] % k) % k;
//				ans += go(mask ^ (1 << l), next);
//			}
//		}
//	}*/
//	for (int j = 0; j < k; j++){
//		for (int l = 0; l < n; l++){
//			if (mask&(1 << l)){
//				int next = (j*ten[len[l]]%k - a[l]%k) % k;             // �̰� �߸��Ǿ���.
//				ans += go(mask & ~(1 << l), next);           //�ӹ� ��Ʈ ����.
//			}
//		}
//	}
//	return ans;
//}
//
//int main(){
//	scanf("%d",&n);
//	vector<string> num(n);         //�Է¹޴� ������ ���ҵ� num�� �ʿ��� ����: len�� ä���� �ϱ� �����̴�.
//	
//	for (int i = 0; i < n; i++){
//		cin >> num[i];
//		len[i] = num[i].size();
//		//a[i] = stoi(num[i]);
//		//a[i] %= k;
//	}
//
//	scanf("%d",&k);
//	for (int i = 0; i < n; i++){       //num���� �Է� ���� ���� int������ ��ȯ��. stoi ���� ����
//		for (int j = 0; j < len[i]; j++){
//			a[i] = a[i] * 10 + (num[i][j] - '0');
//			a[i] %= k;
//		}
//	}
//
//
//	ten[0] = 1;
//	for (int i = 1; i <= 50; i++){
//		ten[i] = ten[i - 1] * 10;
//		ten[i] %= k;
//	}
//	long long t1=0;
//	long long t2 = 1;
//	/*for (int i = 0; i < k; i++){
//		t1 += go(0, i);
//	}*/
//	t1 = go((1<<n)-1, 0);
//
//
//
//	for (int i = 2; i <= n; i++){         //�и�� �� n!�� ����
//		t2 *= (long long)i;
//	}
//
//	long long g = gcd(t1, t2);
//	t1 /= g;
//	t2 /= g;
//	printf("%lld/%lld",t1,t2);
//	return 0;
//}
#include<stdio.h>
#include<string>
#include<vector>
#include<iostream>
using namespace std;
long long D[1 << 15][101];          //D[S][M]: ������ ���Ե� �� S, �׶� �������� M�� ���� ����
bool check[1 << 15][101];

int a[16];
int len[16];
int ten[51];        //10�� �ŵ��������� �̸� �� ���س���.
int n;
int k;       //������ �� k
long long gcd(long long a, long long b){     // ���м� ���·� ��Ÿ���� ���� �ִ����� ������.
	return b == 0 ? a : gcd(b, a%b);
}


int main(){
	scanf("%d", &n);
	vector<string> num(n);         //�Է¹޴� ������ ���ҵ� num�� �ʿ��� ����: len�� ä���� �ϱ� �����̴�.

	for (int i = 0; i < n; i++){
		cin >> num[i];
		len[i] = num[i].size();
		//a[i] = stoi(num[i]);
		//a[i] %= k;
	}

	scanf("%d", &k);
	for (int i = 0; i < n; i++){       //num���� �Է� ���� ���� int������ ��ȯ��. stoi ���� ����
		for (int j = 0; j < len[i]; j++){
			a[i] = a[i] * 10 + (num[i][j] - '0');
			a[i] %= k;
		}
	}


	ten[0] = 1;
	for (int i = 1; i <= 50; i++){
		ten[i] = ten[i - 1] * 10;
		ten[i] %= k;
	}
	D[0][0] = 1;
	for (int i = 0; i < (1 << n); i++){   // ����ũ ä���
		for (int j = 0; j < k; j++){            //������ ���� : 0 ~ k-1  �̰� �� ���°���?
			for (int l = 0; l < n; l++){        //�����ִ� ��Ʈ Ȯ��
				if ((i&(1 << l)) == 0){
					int next = (j*ten[len[l]]%k+a[l]%k)%k;
					D[i | (1 << l)][next] += D[i][j];                          //�̷���� ��ͷ� ��� ��Ÿ����.
				}
			}
		}
	}
	long long t1 = D[(1<<n)-1][0];
	long long t2 = 1;

	for (int i = 2; i <= n; i++){         //�и�� �� n!�� ����
		t2 *= (long long)i;
	}

	long long g = gcd(t1, t2);
	t1 /= g;
	t2 /= g;
	printf("%lld/%lld", t1, t2);
	return 0;
}