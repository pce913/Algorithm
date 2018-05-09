#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> a;
vector<int> b;
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++){
		int x;
		scanf("%d", &x);
		a.push_back(x);
	}
	b.resize(a.size());     //O(nlog(m)) �ڵ��̴�.

	int k = 1;    //������ �����̴�. m�� 6�ϰ�� �������� 110 �̹Ƿ� 2�� shift�� ���� 4�� shift�� ���� ���� �ȴ�.   
	while (k <= m){
		if (k&m){  //���� ���� �ִ� ��Ʈ�� ���� ���.
			copy(a.begin(), a.end(), b.begin());
			for (int j = 0; j < a.size(); j++){
				a[j] = a[j] ^ b[(j + k) % n];
			}
		}
		k *= 2;
	}

	for (int i = 0; i < a.size(); i++){
		printf("%d\n", a[i]);
	}
	return 0;
}