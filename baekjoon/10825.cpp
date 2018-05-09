#include<tuple>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;

struct Sub{
	string name;      //�Ǵ� string tuple ���Ҷ� char�� �� �� ���� �ִ�.
	int kor,eng,math;
};

bool cmp(const Sub& u, const Sub& v){
	return make_tuple(-u.kor, u.eng, -u.math, u.name) < make_tuple(-v.kor, v.eng, -v.math, v.name);       //true �� ��� u �� v �տ� �ξ��.
}
int main(){
	int N;
	cin >> N;

	Sub* M = new Sub[N];
	for (int i = 0; i < N; i++)
		cin >> M[i].name >> M[i].kor >> M[i].eng >> M[i].math;
	
	sort(M,M+N,cmp);
	
	for (int i = 0; i < N; i++)
		cout << M[i].name << "\n";
	return 0;
}