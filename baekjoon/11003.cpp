#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;

int main(){	
	int N, L;
	scanf("%d %d",&N,&L);
	deque< pair<int, int> > d;
	for (int i = 0; i < N; i++){
		int cur;
		scanf("%d",&cur);                          // �Է°� ���ÿ� ó�� �� �� ����.
		if (!d.empty() && L <= i - d.front().second){     // �͵����� ���̰� l���� Ŭ���� ���� �� �� ����.
			d.pop_front();                                // �̷��� ������ ���ش�.
		}
		while (!d.empty() && cur < d.back().first){         // �������� ���� ũ�Ⱑ ����ũ�⺸�� ū�� �ִٸ�
			d.pop_back();                               //������ ���ش�.
		}
		d.push_back({cur,i});
		printf("%d ", d.front().first);          // ������ �� ���ʿ� �ִ� �༮�� �� ������ �ּҰ��̴�.
	}
	return 0;
}