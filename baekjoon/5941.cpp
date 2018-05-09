#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> a[100005];
int cut_cnt = 0;

/*
7 2
7 2
2 1
1 4
4 3
4 5
5 6
*/    //�̰ɷ� �������� ���ذ� ������.

int dfs(int node,int parent,int s){
	vector<int> height;
	for (int i = 0; i < a[node].size(); i++){
		int next = a[node][i];
		if (next != parent){
			height.push_back(dfs(next, node, s)+1);  //����.
		}
	}

	sort(height.begin(), height.end());
	while (height.size() >= 2 && height[height.size() - 2] + height.back() > s){  //���� ������ longest path���� ũ��
		cut_cnt++;  //�ڸ� Ƚ��    --> �� �߶�� �ϹǷ� �ڸ� Ƚ��++ ���ش�.  ���⼭ �߶����� �κ��� v.back()�� �ش��ϴ� subƮ���� �����̴�.
		height.pop_back();
	}
	if (height.size()>=1 && height.back() > s){
		cut_cnt++;
		height.pop_back();
	}

	if (height.empty())
		return 0;
	else
		return height.back();
}

int main(){
	int n, s;
	ReadInt(&n), ReadInt(&s);
	for (int i = 0; i < n - 1; i++){
		int x, y;
		ReadInt(&x), ReadInt(&y);
		a[x].push_back(y);
		a[y].push_back(x);
	}

	int left = 0;
	int right = n - 1;
	int ans = 0;
	while (left <= right){
		int mid = (left + right) >> 1;
		cut_cnt = 0;
		dfs(1, -1, mid);
		if (cut_cnt <= s){   //mid��� longest path�� ����� ���� �ڸ� Ƚ���� s���� �۴ٸ�
			ans = mid;
			right = mid - 1;  //longest path ������ �ٿ��� �� ���� �ڸ��� �غ���.
		}
		else{
			left = mid + 1;
		}
	}
	printf("%d",ans);
	return 0;
}