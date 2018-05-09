#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> plus_set;
vector<int> minus_set;
int main(){
	int n;
	scanf("%d",&n);
	int zero_cnt = 0;
	int one_cnt = 0;
	for (int i = 0; i < n; i++){
		int x;
		scanf("%d",&x);
		if (x == 1){
			one_cnt++;     //1�� ���� �ʴ°� ����.
		}
		else if (x>0){
			plus_set.push_back(x);     //����� ū �������
		}
		else if (x < 0){
			minus_set.push_back(x);   //������ ���� �������� ���´�.
		}
		else{
			zero_cnt++;    //0�� ������ ������ �������� �ִ�.
		}
	}
	sort(plus_set.begin(), plus_set.end());
	reverse(plus_set.begin(), plus_set.end());
	sort(minus_set.begin(),minus_set.end());

	if (plus_set.size() % 2 == 1){     // �ؿ��ִ� �ݺ������� ¦�� �����ֱ� ���� �ڵ��̴�.
		plus_set.push_back(1);
	}
	if (minus_set.size() % 2 == 1){   // �ؿ��ִ� �ݺ������� ¦�� �����ֱ� ���� �ڵ��̴�.
		minus_set.push_back(zero_cnt > 0 ? 0 : 1);
	}

	int ans = one_cnt;
	for (int i = 0; i < plus_set.size(); i+=2){
		ans += plus_set[i] * plus_set[i + 1];
	}
	for (int i = 0; i < minus_set.size(); i+=2){
		ans += minus_set[i] * minus_set[i + 1];
	}
	printf("%d",ans);
	return 0;
}