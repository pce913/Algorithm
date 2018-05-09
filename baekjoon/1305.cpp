#include<stdio.h>
int n;
char p[1000005];
int pi[1000005];

void fill_pi(){   //1���̽�
	pi[1] = 0;
	int j = 1;
	for (int i = 2; i <= n; i++){
		while (j > 1 && p[i] != p[j]){
			j = pi[j - 1] + 1;
		}
		if (p[i] == p[j]){
			pi[i] = j;
			j += 1;
		}
		else{
			pi[i] = 0;
		}
	}
}

int main(){
	scanf("%d", &n);
	scanf("%s", &p[1]);
	fill_pi();               //pi�� i���� �������� prefix==sufix �� ���߿� �ִ� ���̸� �����ϰ� �ִ�.
	printf("%d", n - pi[n]);    //��ü ������ ���̿��� pi�� ���ذ��� ������ �ȴ�.
	return 0;
}
//#include<stdio.h>
//#include<iostream>
//#include<string>
//#include<vector>
//using namespace std;
//int n;
//string p;
////�� ������ 1���̽��� Ǯ�� �̻��ϰ� ��� Ʋ����. �� �׷��ɱ�?
//vector<int> preprocessing(string p) {  //0 ���̽�
//	vector<int> pi(n);
//	pi[0] = 0;
//	int j = 0;
//	for (int i = 1; i<n; i++) {
//		while (j>0 && p[i] != p[j]) {
//			j = pi[j - 1];
//		}
//		if (p[i] == p[j]) {
//			pi[i] = j + 1;
//			j += 1;
//		}
//		else {
//			pi[i] = 0;
//		}
//	}
//	return pi;
//}
//
//int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cin >> n >> p;
//	//pi�� i���� �������� prefix==sufix �� ���߿� �ִ� ���̸� �����ϰ� �ִ�.
//	auto pi = preprocessing(p);
//	printf("%d", n - pi[n - 1]);    //��ü ������ ���̿��� pi�� ���ذ��� ������ �ȴ�.
//	return 0;
//}