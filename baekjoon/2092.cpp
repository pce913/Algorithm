#include <stdio.h>
#include<vector>
using namespace std;
vector<char> ans;
int main(){
	int n;
	scanf("%d", &n);
	if (n == 0){
		printf("0");
		return 0;
	}

	while (n != 0){
		if (n%-2 == 0){   //n�� ��ȣ�� ����Ƶ� ������ �������ٸ�
			n /= -2;
			ans.push_back('0');
		}
		else{  //������ �������� �������� �������� -1�� ������ �ʵ��� �����ؾ� �Ѵ�.   7 % -2 = 1   , -7 % 2 = -1 , -7 % -2 = -1. ��, ������ ��ȣ�� ���󰣴�.
			if (n > 0){
				n /= -2;
			}
			else{
				n = (n - 1) / -2;
			}
			ans.push_back('1');
		}
	}
	for (auto it = ans.rbegin(); it != ans.rend(); it++){
		printf("%c",*it);
	}
	return 0;
}