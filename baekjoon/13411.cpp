#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
	�ӵ�^2 �� ���ؼ� ���ϴ� ����.
	�츮�� ���� �� �� ���� �ð��̴�. ��, �Ÿ�/�ӷ�.
	�Ϲ������� �� ���� ��Һ񱳸� �Ѵٰ� �ϸ� �Ÿ�1/�ӷ�1 , �Ÿ�2/�ӷ�2 �� ���Ѵ�.
	�׷��� �ؿ��� distance �Լ����� sqrt�� �Ⱥٿ����Ƿ� �츮�� ������ �Ÿ�1/�ӷ�1 , �Ÿ�2/�ӷ�2 �� �ƴ϶�
	(�Ÿ�1)^2/(�ӷ�1)^2 , (�Ÿ�2)^2/(�ӷ�2)^2 �� ���ϴ� ���̴�.
	�� ���� ��Һ񱳸� �Ҷ� �纯�� ���� ���� �����൵ ��Һ񱳿� ������ �����Ƿ�
	���� �и� ���� (�ӷ�1)^2 �� (�ӷ�2)^2�� ������ ���̴�.
	
*/
struct Info{
	long long robot, dist, velo;
	bool operator<(const Info& e)const{
		long long a = dist*(e.velo*e.velo);   
		long long b = e.dist*(velo*velo);
		if (a != b){
			return a < b;
		}
		return robot < e.robot;
	}
};

vector<Info> info;

long long distance(long long x1, long long y1, long long x2, long long y2){
	return (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n;
	cin >> n;
	for (long long i = 1; i <= n; i++){
		long long x, y, z;
		cin >> x >> y >> z;
		info.push_back({ i, distance(0, 0, x, y), z });
	}
	sort(info.begin(), info.end());
	for (long long i = 0; i < info.size(); i++){
		cout << info[i].robot << "\n";
	}
}