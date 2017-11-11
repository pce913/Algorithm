//#include<queue>
//#include<vector>
//#include<iostream>
//#include<string>
//#include<list>
//using namespace std;
//
//int main(){
//	string a,t;
//	string q,rq="";
//	list<char> L;
//	cin >> a;
//	cin >> t;
//	int alength=a.length();
//	int tlength = t.length();
//
//	if (alength > tlength){
//		cout << t;
//		return 0;
//	}
//	for (int i = 0; i < t.length(); i++){
//		L.push_back(t.at(i));
//	}
//	auto li = L.begin();
//	auto le = --L.end();
//	for (int i = 0;i<alength-1;i++){
//		q += *li;
//		li++;
//	}
//	
//	for (; li != L.end(); li++){     //���⼭ ����
//		   //1.�տ������� ��
//		q += *li;               //�Ǿ� ����.
//
//		if (q == a){
//			auto eli = ++li;
//			for (int i = 0; i < alength; i++){         //alength��ŭ tli�� �̵���Ű�� ���� ��� �� �ִ�.
//				li--;
//			}
//			auto bli = li;
//			li--;
//			L.erase(bli,eli);
//			for (auto li3 = L.begin(); li3 != L.end(); li3++){
//				cout << *li3;
//			}
//			cout << '\n';
//			q = "";
//			q += *li;
//			q += *eli;
//
//
//
//			auto li2 = --L.end();
//			for (int i = 0; i<alength - 1; i++){
//				rq = (*li2) + rq;
//				li2--;
//			}
//		     
//			for (; li2 != L.begin(); li2--){           //L.begin()���� �ϸ� ���� ���� �� �ִ�.
//				rq = (*li2) + rq;
//
//				if (rq == a){
//					auto bli2 = li2;
//					for (int i = 0; i < alength; i++){         //alength��ŭ tli�� �̵���Ű�� ���� ��� �� �ִ�.
//						li2++;
//					}
//					auto eli2 = li2;
//					L.erase(bli2,eli2);
//					for (auto li3 = L.begin(); li3 != L.end(); li3++){
//						cout << *li3;
//					}
//					cout << '\n';
//					rq = "";
//					rq += *li2;
//					rq += *eli2;
//					break;
//				}
//				else{
//					rq.erase(rq.begin());
//				}
//			}
//		}
//		else{
//			q.erase(q.begin());
//		}
//		//2.a�� length��ŭ ������ �Ŀ� a�� �� 
//		//3.a�� ������ ���� ���������
//		//4.�ٸ��� ��� �Ѿ.
//	}
//	return 0;
//}
#include<stdio.h>
#include<stack>
#include<vector>
#include<string>
using namespace std;

int main(){
	vector<char> T;
	stack<char> L, R;
	string sA;
	char t = NULL;
	while (t != '\n'){
		scanf("%c",&t);
		sA += t;
	}
	sA.erase(sA.size() - 1);
	t = NULL;
	while (t != '\n'){
		scanf("%c", &t);
		T.push_back(t);
	}
	int tsize = T.size()-1;
	int asize = sA.size();
	int lidx = 0 -1;
	int ridx = tsize - 1 +1;
	
	bool goRight = false;
	while (ridx-lidx > 1){ 
		L.push(T[++lidx]);
		string comp;
		for (int i = 0; (i < asize) && (!L.empty()); i++){
			comp=L.top()+comp;
			L.pop();
		}
		if (sA == comp){
			goRight = true;
		}
		else{
			int csize = comp.size();
			for (int i = 0; i <csize; i++){
				L.push(comp.at(i));
			}
		}



		while (goRight && ridx - lidx > 1){
			R.push(T[--ridx]);
			string comp2;
			for (int i = asize - 1; i >= 0 && (!R.empty()); i--){
				comp2 += R.top();
				R.pop();
			}
			if (sA == comp2){
				goRight = false;
			}
			else{
				int csize = comp2.size();
				for (int i = csize-1; i >= 0; i--){
					R.push(comp2.at(i));
				}
			}
		}
	}
	

	while (!L.empty()){
		R.push(L.top());
		L.pop();
		string comp2;
		for (int i = asize - 1; i >= 0 && (!R.empty()); i--){
			comp2 += R.top();
			R.pop();
		}

		if (comp2 == sA){
			continue;
		}
		else{
			int csize = comp2.size();
			for (int i = csize - 1; i >= 0; i--){
				R.push(comp2.at(i));
			}
		}
	}
	
	while (!R.empty()){
		printf("%c",R.top());
		R.pop();
	}

	return 0;
}