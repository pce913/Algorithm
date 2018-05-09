#include<stdio.h>
#include<vector>
using namespace std;

const int MAX = 200000;
const int MOD = 1000000007;

void update(vector<long long>& a,int p,long long diff){
	for (int i = p; i<a.size(); i += i&-i){
		a[i] += diff;
	}
}

long long sum(vector<long long>& a,int p){
	long long ans = 0;
	for (int i = p; i > 0; i -= i&-i){
		ans += a[i];
	}
	return ans;
}

long long sum(vector<long long>& a,int left,int right){
	if (left>right)
		return 0;
	return sum(a,right)-sum(a,left-1);
}

int main(){
	vector<long long> cnt(MAX+1);
	vector<long long> dist(MAX+1);
	int n;
	scanf("%d",&n);
	long long ans = 1;
	for (int i = 0; i < n; i++){
		long long x;
		scanf("%lld",&x);
		x++;                    // �� +1�� ���ִ°���? �̰��� ���ϸ� �ð��ʰ��� �ް� �ȴ�. x�� 0�ϰ�� update�Ҷ� ������ �ȴ�.
		
		if (i != 0){                          //x�� �������� ���ʰ� ���������� ������ Ǭ��. '�Ÿ�'�� ����Ҷ��� ���� ó���� ������ �����̴�.
			long long price = (x*sum(cnt, 1, x - 1) - sum(dist, 1, x - 1)) + (sum(dist, x + 1, MAX) - x*sum(cnt, x + 1, MAX));
			price %= MOD;
			ans = (ans*price) % MOD;
		}
		update(cnt,x,1);                     //cnt[x] : x�� �ɾ��� �ִ� ������ ����.         
		update(dist, x, x);                  //dist[x] : x������ �Ÿ�. x������ �Ÿ��� x �̴�.
	}
	printf("%lld\n", ans);
	return 0;
}