#include<stdio.h>
#include <stack>
using namespace std;
int M[500001];

int main(){
	int n;
	scanf("%d",&n);
	for (int i = 0; i < n; i++){
		scanf("%d",&M[i]);
	}
	stack< pair<long long, long long> > s;
	long long ans = 0;
	for (int i = 0; i < n; i++){
		pair<long long, long long> p = {M[i],1};    //first: Ű  second: ���� Ű�� ���� ����� ����
		while (!s.empty()){
			if (s.top().first <= M[i]){
				ans += s.top().second;
				if (s.top().first == M[i]){
					p.second += s.top().second;
				}
				s.pop();
			}
			else{
				break;
			}
		}
		if (!s.empty())                 //������ ������� �ʴ� == ���� �� �� �ִ�. 
			ans += 1LL;   //���� ���� �ִ°��� ���� ž�� �ִ� �༮���� �۴�.
		s.push(p);
	}
	printf("%lld",ans);
	return 0;
}

//#include<iostream>
//#include<stack>
//#include<vector>
//
//using namespace std;
//
//int main()
//{
//	int num;
//	cin >> num;
//	vector<long long int> v;
//	stack<long long int> s;
//
//	for (int i = 0; i < num; i++)
//	{
//		long long int a;
//		scanf("%lld", &a);
//		v.push_back(a);
//	}
//
//	vector<long long int> result;
//	for (int i = 0; i < num - 1; i++)
//	{
//		int p = v[i];
//		int count = 0;
//		for (int j = i + 1; j < num; j++)
//		{
//			if (j == i + 1)
//			{
//				s.push(v[j]);
//				count++;
//				if (p < v[j])
//					break;
//			}
//			else
//			{
//				if (s.top() <= v[j])
//				{
//					s.pop();
//					s.push(v[j]);
//					count++;
//				}
//				else
//					break;
//			}
//		}
//		result.push_back(count);
//	}
//
//	int sum = 0;
//	for (int i = 0; i < result.size(); i++) {
//		sum = sum + result[i];
//	}
//
//	printf("%d", sum);
//	return 0;
//}
//#include<iostream>
//#include<stack>
//#include<vector>
//
//using namespace std;
//
//int main()
//{
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	int num;
//	cin >> num;
//	vector<long long> v;
//	stack<long long> s;
//
//	for (int i = 0; i < num; i++)
//	{
//		long long a;
//		//scanf("%lld", &a);
//		cin >> a;
//		v.push_back(a);
//	}
//
//	vector<long long> result;
//	for (int i = 0; i < num - 1; i++)
//	{
//		long long p = v[i]; //
//		long long count = 0;
//		for (int j = i + 1; j < num; j++)
//		{
//			if (j == i + 1)
//			{
//				s.push(v[j]);
//				count++;
//				if (p < v[j])
//					break;
//			}
//			else
//			{
//				if (s.top() <= v[j])
//				{
//					s.pop();
//					s.push(v[j]);
//					count++;
//				}
//				else
//					break;
//			}
//		}
//		result.push_back(count);
//	}
//
//	long long sum = 0;
//	for (int i = 0; i < result.size(); i++) {
//		sum = sum + result[i];
//	}
//
//	//printf("%lld", sum);
//	cout << sum;
//	return 0;
//}