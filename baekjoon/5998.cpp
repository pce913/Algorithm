#include<stdio.h>
#include<map>
using namespace std;
#define min(a,b) ((a) < (b) ? (a): (b))
//meet in the middle ��ũ�� ���
long long lights[35];   //lights[i]: ���� i�� �ٸ� ������� ��� ����Ǿ��ִ��� ��Ʈ����ũ�� ����.
map<long long, long long> mp;   //DP�� �ƴ����� map�� ����ؼ� �����ϹǷ� �ݺ������� ó���ϱ� �����. �ݺ������� ó���ϸ� long long ���� �̹Ƿ� �ð��ʰ� ���Ŵ�.
long long n, m;
long long ans = 1e18;
void go1(long long i, long long mask, long long cost){
	if (i == n / 2){
		if (mp.count(mask) > 0){
			mp[mask] = min(mp[mask], cost);
		}
		else{
			mp[mask] = cost;
		}
		return;
	}

	go1(i + 1, mask, cost);
	go1(i + 1, mask^lights[i], cost + 1);
}

void go2(long long i, long long mask, long long cost){
	if (i == n){
		mask ^= (1LL << n) - 1;     //  B�׷쿡�� ���� ���� A�׷쿡�� �����־�� �Ѵٴ� �ǹ�. ����.
		if (mp.count(mask) > 0){
			ans = min(ans, mp[mask] + cost);
		}
		return;
	}

	go2(i + 1, mask, cost);
	go2(i + 1, mask^lights[i], cost + 1);
}

int main(){
	scanf("%lld %lld", &n, &m);
	for (long long i = 0; i < n; i++){
		lights[i] = (1LL << i);            //LL �Ⱥ��̸� Ʋ����.
	}
	for (long long i = 0; i < m; i++){
		long long x, y;
		scanf("%lld %lld", &x, &y);
		x--, y--;
		lights[x] |= (1LL << y);
		lights[y] |= (1LL << x);
	}

	//A�� B. �� �׷����� ����.
	go1(0, 0, 0);
	go2(n / 2, 0, 0);
	printf("%lld", ans);
	return 0;
}