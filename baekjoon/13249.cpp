#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//���� �浹�� ��, ���� ������ ���� �� �� �ִ�.

vector< pair<int, int> > a;   //dir: 0 ����, 1 ������
int n;
void on_bit(int bit){
	for (int i = 0; i < n; i++){
		a[i].second = bit&(1 << i) ? 1 : -1;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++){
		int x;
		cin >> x;
		a.push_back({ x, 0 });
	}
	int t;
	cin >> t;
	sort(a.begin(), a.end());
	int mother = pow(2, n);
	int son = 0;
	for (int bit = 0; bit < (1 << n); bit++){
		on_bit(bit);
		for (int i = 0; i < n; i++){
			for (int j = i + 1; j < n; j++){  //���� ���� Ƚ���� �����ָ� �ȴ�.
				if (a[i].first + a[i].second*t >= a[j].first + a[j].second*t){
					son++;
				}
			}
		}
	}
	cout << (double)son / mother;
	return 0;
}