#include<iostream>
#include<string>
using namespace std;

string words[1005];
string D[1005];        //D[k]: �ڿ��� k���� �������� ���� �Ǵ� ���. (not ����� ��) ���� D[0]�� ����Ǿ� �ִ�.
string pass;
bool canGo(int x, int y){
	bool isMatch = true;
	for (int i = 0; i < words[y].size(); i++){
		if (pass[x + i] != '?' && pass[x + i] != words[y][i]){
			isMatch = false;
			break;
		}
	}
	return isMatch;
}
//bool canGo(int x, int y){
//	bool isMatch = true;
//	for (int i = 0; i <words[y].size(); i++){
//		if (pass[x - i] != '?' && pass[x - i] != words[y][words[y].size()-1-i]){
//			isMatch = false;
//			break;
//		}
//	}
//	return isMatch;
//}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int l, n;

	cin >> l >> n;
	cin >> pass;
	for (int i = 0; i < n; i++){
		cin >> words[i];
	}
	for (int i = l - 1; i >= 0; i--){
		for (int j = 0; j < n; j++){
			int k = i + words[j].length();
			if (k>l)
				continue;

			if (k==l || D[k] != ""){        //D[k] �� ������� �ʰų�, k==l �� ���
				if (canGo(i, j)){
					if (D[i] == "" || D[i] > words[j] + D[k]){   //������ ����� ����
						D[i] = words[j] + D[k];    //D[i] �� ����� ���� words�� D[k]�� ��ģ��. ����. D[k]�� ������ ���޾Ҵ�.
					}
				}
			}
		}
	}
	cout << D[0] << "\n";
	//for (int i = 0; i < l; i++){

	//	for (int j = 0; j < n; j++){
	//		int k = i - words[j].length();
	//		if (k<-1)
	//			continue;

	//		if (k == -1 || D[k] != ""){
	//			if (canGo(i, j)){
	//				if (k == -1){
	//					if (D[i] == "" || D[i]> words[j]){
	//						D[i] = words[j];
	//					}
	//				}
	//				else{
	//					if (D[i] == "" || D[i] > D[k] + words[j]){
	//						D[i] = D[k] + words[j];
	//					}
	//				}		
	//			}
	//		}
	//	}
	//}
	//cout << D[l-1] << "\n";
	return 0;
}