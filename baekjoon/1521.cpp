#include<iostream>
#include<algorithm>
#include<iomanip>
#include<vector>
#include<map>
using namespace std;

//��ġ�� ���� ������ ã�Ƽ� ���� �� ����������
//��ġ: i< j �̸鼭 A[i]> A[j] �� ��.
map< vector<int>, double > D;   //D : ���� ������ ���������� ���
double go(vector<int>& a){
	if (D.count(a) > 0)
		return D[a];

	double ans = 0;
	int cnt = 0;   //��ȯ Ƚ��
	for (int i = 0; i < (int)a.size() - 1; i++){
		for (int j = i + 1; j < (int)a.size(); j++){
			if (a[i]>a[j]){
				swap(a[i], a[j]);
				ans += go(a) + 1;     // ���⼭ +1 �ϴ� ������ ���� ������ �������� swap�� '�ѹ�' �� ���� �����ִ� ���̴�. �׷��� ����̴�.
				cnt++;
				swap(a[i], a[j]);
			}
		}
	}
	if (cnt > 0){
		ans = ans / cnt;
	}
	return D[a] = ans;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> a;
	for (int i = 0; i < n; i++){
		int x;
		cin >> x;
		a.push_back(x);
	}
	cout << fixed << setprecision(10) << go(a);
	return 0;
}