#include<stdio.h>
int dist[21][21];
bool unused[21][21];

int main(){
	int n;
	scanf("%d",&n);
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			scanf("%d",&dist[i][j]);
		}
	}
	for (int k = 1; k <= n; k++){
		for (int i = 1; i <= n; i++){
			if (i == k)
				continue;

			for (int j = 1; j <= n; j++){
				if (i == j)
					continue;
				if (j == k)
					continue;

				if (dist[i][j] > dist[i][k] + dist[k][j]){           // �������� �־��� �ִܰŸ�����
					printf("-1");                                    // �� ª������ ��� �־��� ���ǰ� ����� �ǹǷ�
					return 0;                                        // �Ұ����� ���� �Ǵ��ϰ� -1 ���.
				}
				if (dist[i][j] == dist[i][k] + dist[k][j]){          // ���Ƽ� ���� ����� �հ� �ٷ� ���� ����� ���̰� �������
					unused[i][j] = true;                             // �ٷ� ���� ��δ� �������� �Ǵ� ��ΰ� �ȴ�.
				}
			}
		}
	}

	int ans=0;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			if (unused[i][j] == false){
				ans += dist[i][j];
			}
		}
	}       
	printf("%d",ans/2);   // �� ������ ����� �׷����̴�.
	return 0;
}