#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> s;
	int sum = 0;     //3�� ������� �˱� ���ؼ� �� �ڸ��� ���� ���Ѵ�.
	for (int i = 0; i < s.size(); i++){
		sum += s[i] - '0';
	}
	sort(s.begin(), s.end());
	if (s[0] == '0' && sum % 3 == 0){
		reverse(s.begin(), s.end());
		cout << s;
	}
	else{
		cout << "-1";
	}
	return 0;
}
//#include<iostream>
//#include<string>
//#include<algorithm>
//using namespace std;
//
//int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	string s;
//	cin >> s;
//	sort(s.begin(), s.end());
//	reverse(s.begin(), s.end());
//	int num = atoi(s.c_str());    //�Է��� �ִ� 10^5���� ���ڷ� �̷���� �����Ƿ�
//	if (num % 30 == 0)             //���ڷ� �ٲ� ���� ����.
//		cout << s;
//	else
//		cout << "-1";
//	return 0;
//}