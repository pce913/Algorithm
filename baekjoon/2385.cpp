#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
//http://codersbrunch.blogspot.kr/2016/08/2385-secret-sharing.html
//345�� 34512 �߿��� ���������� ū �༮�� 34512 �̴�.
vector<string> a;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	int front_zero_cnt = 0;
	for (int i = 0; i < n; i++){
		string s;
		cin >> s;
		a.push_back(s);
		if (s[0] == '0')
			front_zero_cnt++;
	}
	if (front_zero_cnt == n){   //��� ������ �պκ��� 0���� �����ϸ� �̰��� �Ұ����� ����̴�.
		cout << "INVALID";
		return 0;
	}
	//���鹮�ڿ��� ���� ������ �ڹٲ� �� �ִ� ��(p,q)�� ���Ͽ� ���߿� ��� �տ� ������ p+q < q+p�� �� �� �ִ�.
	sort(a.begin(), a.end(), [](const string& x, const string& y){return x + y < y + x; });
	string temp = "";
	int k;
	for (k = 0; k < a.size(); k++){
		if (a[k][0] == '0')
			temp += a[k];
		else
			break;
	}
	//0���� �����ϴ� �༮���� �����ϰ� �� �տ� ���� �;� �ϴ����� p+temp+q < q+temp+p�� �� �� �ִ�.
	int p = min_element(a.begin() + k, a.end(), [&](const string& x, const string&y){return x + temp + y < y + temp + x; }) - a.begin();   //������ �ּҰ��� ��ġ�� �˷��ش�.
	//���� min_element�� �Ⱦ��� pair�� �̿��ؼ� �ε����� �Բ� �����ϴ� ����� ������ ���ŷӱ� ������ �� ����� ����ߴ�.
	cout << a[p];
	for (int i = 0; i < a.size(); i++){
		if (i != p){
			cout << a[i];
		}
	}
	return 0;
}