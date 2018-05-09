#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN = 200005;
int dead[MAXN], num[MAXN], a[MAXN];
//�ϴ� ���ϰ� ���µ� ������� �ؿ��ִ°��߿� ���������ϴ� ���� �Ŷ���� ���ָ� �ȴ�.
//http://codersbrunch.blogspot.kr/2016/01/1781.html
priority_queue<int> pq;
int main(){
	ios::sync_with_stdio(false), cin.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> dead[i] >> num[i];
		a[i] = i;
	}
	sort(a + 1, a + 1 + n, [&](const int i, const int j){return dead[i] < dead[j]; });
	int d = 0;
	int ans = 0;
	for (int i = 1; i <= n; i++){
		d = dead[a[i]];
		pq.push(-num[a[i]]);
		while (pq.size() > d){
			pq.pop();
		}
	}
	while (!pq.empty()){
		ans += -pq.top();
		pq.pop();
	}
	cout << ans;
	return 0;
}