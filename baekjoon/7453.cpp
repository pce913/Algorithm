//#include<stdio.h>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//int main(){
//	int n;
//	scanf("%d",&n);
//	vector<int> a(n), b(n), c(n), d(n);
//	for (int i = 0; i < n; i++){
//		scanf("%d %d %d %d",&a[i],&b[i],&c[i],&d[i]);
//	}
//	vector<int> first, second;
//	for (int i = 0; i < n; i++){
//		for (int j = 0; j < n; j++){
//			first.push_back(a[i] + b[j]);
//			second.push_back(c[i]+d[j]);
//		}
//	}
//	sort(second.begin(),second.end());
//	int ans = 0;
//
//	for (int& num : first){
//		auto range = equal_range(second.begin(),second.end(),-num);       // equal_range�� ���� ������ ������ �� �� �ִ�.
//		ans += range.second - range.first;
//	}
//	printf("%d",ans);
//	return 0;
//}
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	vector<int> a(n), b(n), c(n), d(n);
	for (int i = 0; i < n; i++){
		scanf("%d %d %d %d", &a[i], &b[i], &c[i], &d[i]);
	}
	vector<int> first, second;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			first.push_back(a[i] + b[j]);
			second.push_back(c[i] + d[j]);
		}
	}
	sort(first.begin(), first.end());
	sort(second.begin(), second.end());
	long long ans = 0;

	for (int i = 0; i<first.size(); i++){
		int num = first[i];
		num = -num;
		int left = 0;
		int right = second.size() - 1;
		while (left <= right){
			int mid = (left + right) / 2;
			if (num < second[mid]){
				right = mid - 1;
			}
			else if (num > second[mid]){
				left = mid + 1;
			}
			else{
				long long c1 = 1;
				long long c2 = 1;
				int& curr1 = i;
				int curr2 = mid;

				while (curr1 < first.size() - 1 && first[curr1] == first[curr1 + 1]){
					c1++;
					curr1++;
				}

				while (curr2 < second.size() - 1 && second[curr2] == second[curr2 + 1]){
					c2++;
					curr2++;
				}

				curr2 = mid;
				while (curr2 > 0 && second[curr2] == second[curr2 - 1]){
					c2++;
					curr2--;
				}
				ans += c1*c2;
				break;
			}
		}
	}
	printf("%lld", ans);
	return 0;
}