#include<stdio.h>
const int INF = 1e9;
int M[105][10005], a[105];
//dx[i][j][4]: i�� ����� ������ j�϶� ä�����ϴ� 4���� ĭ 
int dx[7][4][4] = { { { 0, 0, 0, 0 }, { 0, 1, 2, 3 }, { INF, INF, INF, INF }, { INF, INF, INF, INF } },
{ { 0, 1, 0, 1 }, { INF, INF, INF, INF }, { INF, INF, INF, INF }, { INF, INF, INF, INF } },
{ { 0, 1, 1, 2 }, { 0, 0, 1, 1 }, { INF, INF, INF, INF }, { INF, INF, INF, INF } },
{ { 0, 1, 1, 2 }, { 0, 0, 1, 1 }, { INF, INF, INF, INF }, { INF, INF, INF, INF } },
{ { 0, 1, 1, 2 }, { 0, 1, 1, 1 }, { 0, 1, 1, 2 }, { 0, 0, 0, 1 } },
{ { 0, 1, 2, 2 }, { 0, 1, 1, 1 }, { 0, 0, 1, 2 }, { 0, 0, 0, 1 } },
{ { 0, 0, 1, 2 }, { 0, 1, 1, 1 }, { 0, 1, 2, 2 }, { 0, 0, 0, 1 } } };

int dy[7][4][4] = { { { 1, 2, 3, 4 }, { 1, 1, 1, 1 }, { INF, INF, INF, INF }, { INF, INF, INF, INF } },
{ { 1, 1, 2, 2 }, { INF, INF, INF, INF }, { INF, INF, INF, INF }, { INF, INF, INF, INF } },
{ { 1, 1, 2, 2 }, { 2, 1, 1, 0 }, { INF, INF, INF, INF }, { INF, INF, INF, INF } },
{ { 1, 1, 0, 0 }, { 1, 2, 2, 3 }, { INF, INF, INF, INF }, { INF, INF, INF, INF } },
{ { 1, 1, 2, 1 }, { 1, 1, 2, 0 }, { 1, 1, 0, 1 }, { 1, 2, 3, 2 } },
{ { 1, 1, 1, 2 }, { 1, 1, 0, -1 }, { 1, 2, 2, 2 }, { 3, 2, 1, 1 } },
{ { 2, 1, 1, 1 }, { 1, 1, 2, 2 }, { 1, 1, 1, 0 }, { 1, 2, 3, 3 } } };
int c, p;
//���� ������ ���� ���⿡�� 90�� �ݽð� �������� ȸ���� ����
//���� �׿� �ִ� ����� ���� ���� ����� �������� �� ����
//1�� x
//{ 0, 0, 0, 0 }, { 0, 1, 2, 3 }, { INF, INF, INF, INF }, { INF, INF, INF, INF }

//2�� x
//{ 0, 1, 0, 1 }, { INF, INF, INF, INF }, { INF, INF, INF, INF }, { INF, INF, INF, INF }

//3�� x
//{ 0, 1, 1, 2 }, { 0, 0, 1, 1 }, { INF, INF, INF, INF }, { INF, INF, INF, INF }

//4�� x
//{ 0, 1, 1, 2 }, { 0, 0, 1, 1 }, { INF, INF, INF, INF }, { INF, INF, INF, INF }

//5�� x
//{ 0, 1, 1, 2 }, { 0, 1, 1, 1 }, { 0, 1, 1, 2 }, { 0, 0, 0, 1 }

//6�� x
//{ 0, 1, 2, 2 }, { 0, 1, 1, 1 }, { 0, 0, 1, 2 }, { 0, 0, 0, 1 }

//7�� x
//{ 0, 0, 1, 2 }, { 0, 1, 1, 1 }, { 0, 1, 2, 2 }, { 0, 0, 0, 1 }

//**************************

//1�� y
//{ 1, 2, 3, 4 }, { 1, 1, 1, 1 }, { INF, INF, INF, INF }, { INF, INF, INF, INF }

//2�� y
//{ 1, 1, 2, 2 }, { INF, INF, INF, INF }, { INF, INF, INF, INF }, { INF, INF, INF, INF }

//3�� y
//{ 1, 1, 2, 2 }, { 2, 1, 1, 0 }, { INF, INF, INF, INF }, { INF, INF, INF, INF }

//4�� y
//{ 1, 1, 0, 0 }, { 1, 2, 2, 3 }, { INF, INF, INF, INF }, { INF, INF, INF, INF }

//5�� y
//{ 1, 1, 2, 1 }, { 1, 1, 2, 0 }, { 1, 1, 0, 1 }, { 1, 2, 3, 2 }

//6�� y
//{ 1, 1, 1, 2 }, { 1, 1, 0, -1 }, { 1, 2, 2, 2 }, { 3, 2, 1, 1 }

//7�� y
//{ 2, 1, 1, 1 }, { 1, 1, 2, 2 }, { 1, 1, 1, 0 }, { 1, 2, 3, 3 }
bool isCanPainting(int cx, int cy , int dir){
	for (int k = 0; k < 4; k++){
		int nx = cx + dx[p][dir][k];
		int ny = cy + dy[p][dir][k];
		if (nx< 1 || nx>c  || ny < 1 || M[nx][ny]==1){   //������ �Ѿ�ų�, �̹� ĥ���� �ִ� ���� ĥ�ϸ� �ȵȴ�.
			return false;
		}
	}
	return true;
}

void painting(int cx,int cy , int dir){
	for (int k = 0; k < 4; k++){    //��ĥ�ϱ�. ���������� �Ѿ���� ��ĥ�Ѱ��� ������ �Ѵ�.
		int nx = cx + dx[p][dir][k];
		int ny = cy + dy[p][dir][k];
		M[nx][ny] = 2;
	}
}

void erasing(int cx, int cy, int dir){
	for (int k = 0; k < 4; k++){    //��ĥ�ϱ�. ���������� �Ѿ���� ��ĥ�Ѱ��� ������ �Ѵ�.
		int nx = cx + dx[p][dir][k];
		int ny = cy + dy[p][dir][k];
		M[nx][ny] = 0;
	}
}

bool isAns(int cx, int cy, int dir){
	for (int k = 0; k < 4; k++){
		int nx = cx + dx[p][dir][k];
		int ny = cy + dy[p][dir][k] - 1;
		if (M[nx][ny] == 0){
			return false;
		}
	}
	return true;
}

int main(){
	scanf("%d %d",&c,&p);
	for (int i = 1; i <= c; i++){
		scanf("%d",&a[i]);
		M[i][0] = -1;
		for (int j = 1; j <= a[i]; j++){
			M[i][j] = 1;
		}
	}

	p -= 1;
	int ans = 0;
	for (int dir = 0; dir < 4; dir++){
		for (int i = 1; i <= c; i++){
			int cx = i;
			int cy = a[i];
			if (!isCanPainting(cx,cy,dir))
				continue;
			//painting
			painting(cx, cy, dir);
			if (isAns(cx, cy, dir)){
				ans++;
			}
			//erasing
			erasing(cx, cy, dir);
		}
	}
	printf("%d",ans);
	return 0;
}