#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

vector<string> a;
vector< pair<string, int> > line;

int tree[100005];
int n;

void update(int x,int value){
	for (int i = x; i <= n ; i += i&-i){
		tree[i] += value;
	}
}

int query(int x){
	int ans = 0;
	for (int i = x; i > 0; i -= i&-i){
		ans += tree[i];
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++){
		string s;
		cin >> s;
		a.push_back(s);
	}
	sort(a.begin(), a.end());
	for (int i = 0; i < a.size(); i++){
		line.push_back({ a[i], i + 1 });    // A�� ���������� ������������ ������ �Բ� ����
	}
	for (int i = 0; i < line.size(); i++){
		string &ts = line[i].first;
		reverse(ts.begin(), ts.end());    //�� ���ڿ��� ����� �ٽ� ����
	}
	sort(line.begin(), line.end());     //������ ���ڿ��� �ٽ� ����
	reverse(line.begin(), line.end());   //������ �����´�. �ֳ��ϸ�  �����߿� 
	                             //B'�� A'���� ���� ������ �ռ���  �̶�� ���� ������Ű�� ����
	                          //A'�� ���������� �����ΰ��� ���鼭 A�� B���� ���������� �ռ��� �༮��
	                          //���� �����̴�.
	long long ans = 0;
	for (int i = 0; i < line.size(); i++){
		int x = line[i].second;
		ans+=query(x);
		update(x, 1);
	}
	cout << ans;
	return 0;
}