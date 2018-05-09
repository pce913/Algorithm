#include<iostream>
#include<set>
using namespace std;
//long long
long long A[100005];
int dir[100005];
set<long long> st;
int main(){
	ios::sync_with_stdio(false), cin.tie(0);
	int n, q;
	long long t;
	cin >> n >> t >> q;
	for (int i = 1; i <= n; i++)
		cin >> A[i] >> dir[i];

	for (int i = 1; i <= n - 1; i++){
		if (dir[i] == 1 && dir[i + 1] == 2){
			if (A[i] + t >= A[i + 1] - t){
				st.insert((A[i] + A[i + 1]) / 2LL);
			}
		}
	}
	for (int i = 1; i <= q; i++){ //lower_bound()���� �ٸ��� �浹 ��ġ�� �Ѿ���� ���̴�.
		int Q;
		cin >> Q;
		long long ans;
		if (dir[Q] == 1){ //������
			auto x = st.lower_bound(A[Q]);
			auto y = st.lower_bound(A[Q] + t);
			ans = (x != y) ? *x : A[Q] + t;
		}
		else{
			auto x = st.lower_bound(A[Q]);
			auto y = st.lower_bound(A[Q] - t);
			ans = (x != y) ?  *(--x) : A[Q] - t;
		}
		cout << ans << "\n";
	}
	return 0;
}