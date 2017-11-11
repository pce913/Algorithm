//#include<stdio.h>
//#include<vector>
//#include<cstring>
//using namespace std;
//#define MAXN 1000000001    //31624             //1000000001 �̰��ϸ� �޸� �ʰ�
//
//long long att;
//long long A, B;
//long long N, dsize;
//bool prime[MAXN];
//long long gcd(long long a, long long b){
//	return b == 0 ? a : gcd(b, a%b);
//}
//long long lcm(long long a, long long b, long long g){
//	return a*b / g;
//}
//
//long long calc(vector<long long >& d, long long y, long long _l, long long c, long long k){
//	if (c < 2){
//		return _l;
//	}
//
//	long long g;
//	long long l;
//	for (long long x = y + 1; x < dsize; x++){
//		g = gcd(_l, d[x]);
//		l = lcm(_l, d[x], g);
//		//k�� 4�̻� �϶����� ���ȣ��.
//		long long val = calc(d, x, l, c - 1, k);
//		if (val != 0){
//			//att += (B / val - A / val)*((!(k & 1)) ? -1 : 1);
//			if (!(k & 1)){        //k�� ¦���̸�
//				att -= B / val - A / val;
//			}
//			else{
//				att += B / val - A / val;
//			}
//		}
//
//		//prlong longf("%lld\n", B - A + 1 - att);
//	}
//	return 0;
//}
//
//
//long long main(){
//	long long T;
//	scanf("%d", &T);
//	for (long long tc = 1; tc <= T; tc++){
//		scanf("%lld %lld %lld", &A, &B, &N);
//		att = 0;
//		// 1. N�� ����� ���Ѵ�. ��Ȯ���� �Ҽ��� ����� ���Ѵ�.
//		vector<long long> d;
//		memset(prime, true, sizeof(bool)* MAXN);
//
//		bool isNo = true;
//		long long q = 2;
//		long long temp = N;
//
//		vector<long long> primeNum;
//		for (long long i = 2; i*i <= MAXN ; i++){
//			if (prime[i] == true){
//				primeNum.push_back(i);
//				for (long long j = i + i; j < MAXN; j += i){    
//					prime[j] = false;
//				}
//			}
//		}
//		long long next = 0;
//		long long nsize = primeNum.size();
//		while (temp != 1){             //�ȳ����� ��� while���� �Ⱥ��������Ƿ� �ð��ʰ� ���� �� �ִ�.    while���� ���������ͼ� �ð��ʰ� ���� ���̴�!
//			if (temp%q == 0 && q <= MAXN && q >= 0){
//				do{
//					temp = temp / q;
//				} while (temp%q == 0);
//				d.push_back(q);            //q�� �̿��ؼ� prime[] �̳� d�� �����ϸ� ��Ÿ�� ����  -> while���� ������ �����鼭 ���� ��� �ö󰡼� ��Ÿ�ӿ����� ����.
//			}
//			if (next < nsize){
//				q = primeNum[next];
//				next++;
//			}
//		}
//
//		// 2. ����� ���� �����佺�׳׽��� ü�� �Ѵ�. ���⼭�� ������ �߿��ϹǷ� ���� ���.
//		//    ���� ���߿� '����-��������' ����ؾ� ��.
//		dsize = d.size();
//		for (long long i = 0; i < dsize; i++){
//			att += B / d[i] - A / d[i];
//			if (A % d[i] == 0)
//				att += 1;
//
//		}
//		for (long long k = 2; k <= dsize; k++){
//			for (long long i = 0; i < dsize - 1; i++){
//				calc(d, i, d[i], k, k);
//			}
//		}
//		prlong longf("Case #%d: %lld\n", tc, B - A + 1 - att);
//	}
//	return 0;
//}
#include<stdio.h>
#include<vector>
#include<cmath>
#include<cstring>
using namespace std;
bool prime[100001];

long long gcd(long long a, long long b){
	return b == 0 ? a : gcd(b, a%b);
}
long long lcm(long long a, long long b){
	return a*b / gcd(a, b);
}

int main(){
	vector<long long> p;           // �Ҽ��� ���� ���´�.
	memset(prime, true, sizeof(prime));
	for (long long i = 2; i*i <= 100000; i++){
		if (prime[i] == true){
			for (long long j = i*i; j <= 100000; j += i){               // ��Ʈ N������ �ϴ� �Ҽ��� ���� ���´�.
				prime[j] = false;
			}
		}
	}
	for (long long i = 2; i <= 100000; i++){
		if (prime[i]){
			p.push_back(i);
		}
	}
	long long T;
	scanf("%lld", &T);
	for (long long test = 1; test <= T; test++){
		long long a, b, n;
		scanf("%lld %lld %lld", &a, &b, &n);
											//n�� ���μ����� �Ѵ�.
		vector<long long> prime_factor;
		long long tempN = n;
		for (long long i = 0; i < p.size(); i++){               // ���� ũ�� ���� ����.
			if (tempN%p[i] == 0){
				prime_factor.push_back(p[i]);
				while (tempN%p[i] == 0){       //&& tempN !=p[i]
					tempN /= p[i];
				}
			}
		}
		if (tempN != 1){         // ��ƮN������ �Ҽ��� ��� ������µ��� 1�� �ȵǾ��ٴ°���
			prime_factor.push_back(tempN);   // ���� ū �Ҽ��� �ϳ� �����ִٴ� ���̴�. �װ��� ���Խ�����.
		}

		long long ans = b - a + 1;
		for (long long bit = 1; bit < (1 << prime_factor.size()); bit++){  //
			long long on_bit_cnt = 0;
			long long LCM = 1;
			for (long long i = 0; i < prime_factor.size(); i++){
				if (bit&(1 << i)){
					LCM = lcm(LCM, prime_factor[i]);
					on_bit_cnt++;
				}
			}
			
			if (on_bit_cnt & 1){               // �����ϴ� ������ ������ Ȧ���϶�
				ans -= b / LCM - ((a - 1) / LCM);
			}
			else{
				ans += b / LCM - ((a - 1) / LCM);
			}
		}
		printf("Case #%lld: %lld\n", test, ans);
	}
	return 0;
}