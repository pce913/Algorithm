//#include<stdio.h>
//#include<cstring>
//
//int C, D, dd;
//int d[201][101][101][2][2];   //d[N][x][y][sx][sy] : N�Ͽ� X���� x��° �������� �߰�, Y���� y��° �������� ������ �ּҺ��,
//                   //sx,sy�� 0�� ���, �ش����� ù �޽�, 1�ΰ�� �ش� ���� �������� �޽�    
////bool check[211][111][111][2][2];   //���⼭�� check�迭 �Ⱦ��°� ����.
//int a[101];           //a���� �湮�ؾ� �ϴ� ���� ����
//int b[101];
//
//int an, bn;
//
//int go(int day,int x,int y,int prevx,int prevy){
//	if (x == an && y == bn){
//		return 0;
//	}
//	if (day >= 200){
//		return 1e9;
//	}
//	//����ó��
//
//	if (d[day][x][y][prevx][prevy]!=-1){
//		return d[day][x][y][prevx][prevy];
//	}
//	int& ans = d[day][x][y][prevx][prevy];
//
//	if (x < an && y < bn){     //�� ���� ��� ������ �ϴ� ���
//		int temp = C;         
//		if (a[x] != b[y])   //�� ���� �ٸ� ������� �̿��� ���
//			temp += C;
//		if (ans == -1 || ans > temp + go(day + 1, x + 1, y + 1, 0, 0))
//			ans = temp + go(day + 1, x + 1, y + 1, 0, 0);
//	}
//	if (x < an){           //X���� �����ϴ� ���. Y���� �޽�
//		int temp = C;
//		temp += dd;
//		if (prevy == 0)
//			temp += D;
//		if (ans == -1 || ans > temp + go(day + 1, x + 1, y, 0, 1))
//			ans = temp + go(day + 1, x + 1, y, 0, 1);
//	}
//	if (y < bn){      //Y���� �����ϴ� ���. X���� �޽�
//		int temp = C;
//		temp += dd;
//		if (prevx == 0){
//			temp += D;
//		}
//		if (ans == -1 || ans > temp + go(day + 1, x, y + 1, 1, 0)){
//			ans = temp + go(day + 1, x, y + 1, 1, 0);
//		}
//	}
//
//	int temp = 0;               // �� �� ��� ���� ���
//	temp += 2 * dd;
//	if (prevx == 0){
//		temp += D;
//	}
//	if (prevy == 0){
//		temp += D;
//	}
//	if (ans == -1 || ans > temp + go(day + 1, x, y, 1, 1)){
//		ans = temp + go(day + 1, x, y, 1, 1);
//	}
//
//	return ans;
//}
//
//int main(){
//	int T;
//	scanf("%d",&T);
//	for (int test = 0; test < T; test++){
//		scanf("%d %d %d",&C,&D,&dd);
//		an = 0;
//		bn=0;
//		while (true){
//			int temp;
//			scanf("%d",&temp);
//			if (temp == 0)
//				break;
//			a[an] = temp;
//			an++;
//		}
//		while (true){
//			int temp;
//			scanf("%d",&temp);
//			if (temp == 0)
//				break;
//			b[bn] = temp;
//			bn++;
//		}
//		memset(d, -1, sizeof(d));
//		printf("%d\n",go(0,0,0,0,0));
//	}
//	return 0;
//}
#include<stdio.h>
#include<cstring>

int C, D, dd;
int d[101][101][2][2];   //d[x][y][sx][sy] :  X���� x��° �������� �߰�, Y���� y��° �������� ������ �ּҺ��,
//sx,sy�� 0�� ���, �ش����� ù �޽�, 1�ΰ�� �ش� ���� �������� �޽�    
//bool check[211][111][111][2][2];   //���⼭�� check�迭 �Ⱦ��°� ����.
int a[101];           //a���� �湮�ؾ� �ϴ� ���� ����
int b[101];

int an, bn;

int go(int x, int y, int prevx, int prevy){
	if (x == an && y == bn){
		return 0;
	}
	
	//����ó��

	if (d[x][y][prevx][prevy] != -1){
		return d[x][y][prevx][prevy];
	}
	int& ans = d[x][y][prevx][prevy];

	if (x < an && y < bn){     //�� ���� ��� ������ �ϴ� ���
		int temp = C;
		if (a[x] != b[y])   //�� ���� �ٸ� ������� �̿��� ���
			temp += C;
		if (ans == -1 || ans > temp + go( x + 1, y + 1, 0, 0))
			ans = temp + go( x + 1, y + 1, 0, 0);
	}
	if (x < an){           //X���� �����ϴ� ���. Y���� �޽�
		int temp = C;
		temp += dd;
		if (prevy == 0)
			temp += D;
		if (ans == -1 || ans > temp + go(x + 1, y, 0, 1))
			ans = temp + go(x + 1, y, 0, 1);
	}
	if (y < bn){      //Y���� �����ϴ� ���. X���� �޽�
		int temp = C;
		temp += dd;
		if (prevx == 0){
			temp += D;
		}
		if (ans == -1 || ans > temp + go( x, y + 1, 1, 0)){
			ans = temp + go(x, y + 1, 1, 0);
		}
	}

	int temp = 0;               // �� �� ��� ���� ���
	temp += 2 * dd;
	if (prevx == 0){
		temp += D;
	}
	if (prevy == 0){
		temp += D;
	}
	if (ans == -1 || ans > temp + go(x, y, 1, 1)){
		ans = temp + go( x, y, 1, 1);
	}

	return ans;
}

int main(){
	int T;
	scanf("%d", &T);
	for (int test = 0; test < T; test++){
		scanf("%d %d %d", &C, &D, &dd);
		an = 0;
		bn = 0;
		while (true){
			int temp;
			scanf("%d", &temp);
			if (temp == 0)
				break;
			a[an] = temp;
			an++;
		}
		while (true){
			int temp;
			scanf("%d", &temp);
			if (temp == 0)
				break;
			b[bn] = temp;
			bn++;
		}
		memset(d, -1, sizeof(d));
		printf("%d\n", go(0, 0, 0, 0));
	}
	return 0;
}
//#include<stdio.h>
//#include<algorithm>
//using namespace std;
//
//int C, D, dd;
//int d[101][101][4];             //0: �Ѵ� �ٴ°��, 1: X�� �ٴ� ���, 2:Y�� �ٴ� ��� ,3: �Ѵ� ���� ���
//
//bool check[101][101][4];   
//int a[101];           //a���� �湮�ؾ� �ϴ� ���� ����
//int b[101];
//
//int an, bn;
//
//int go(int x, int y, int what,int prevx,int prevy){
//	if (x == an && y == bn){
//		return 0;
//	}
//	if (x > an || y > bn){
//		return 1e9;
//	}
//
//	//����ó��
//
//	if (check[x][y][what]){
//		return d[x][y][what];
//	}
//	check[x][y][what] = true;
//	int& ans = d[x][y][what];
//
//
//	int nx, ny,temp;
//	if (what == 0){
//		temp = C;
//		if (a[x] != b[y])   //�� ���� �ٸ� ������� �̿��� ���
//			temp += C;
//
//		nx = 0;
//		ny = 0;
//	}
//	else if (what == 1){
//		temp = C;
//		temp += dd;
//		if (prevy == 0)
//			temp += D;
//		
//		nx = 0;
//		ny = 1;
//	}
//	else if (what == 2){
//		temp = C;
//		temp += dd;
//		if (prevx == 0){
//			temp += D;
//		}
//		nx = 1;
//		ny = 0;
//	}
//	else if (what == 3){
//		temp = 0;               // �� �� ��� ���� ���
//		temp += 2 * dd;
//		if (prevx == 0){
//			temp += D;
//		}
//		if (prevy == 0){
//			temp += D;
//		}
//		nx = 1;
//		ny = 1;
//	}
//
//	for (int i = 0; i<4; i++){
//		/*int dx = -(~nx);
//		int dy = -(~ny);*/
//		
//		int dx = nx == 1 ? 0 : 1;
//		int dy = ny == 1 ? 0 : 1;
//		if (ans > temp + go(x+dx, y + dy, i, nx, ny))
//			ans = temp + go(x + dx, y + dy, i, nx, ny);
//	}
//
//	return ans;
//}
//
//int main(){
//	int T;
//	scanf("%d", &T);
//	for (int test = 0; test < T; test++){
//		scanf("%d %d %d", &C, &D, &dd);
//		an = 0;
//		bn = 0;
//		while (true){
//			int temp;
//			scanf("%d", &temp);
//			if (temp == 0)
//				break;
//			a[an] = temp;
//			an++;
//		}
//		while (true){
//			int temp;
//			scanf("%d", &temp);
//			if (temp == 0)
//				break;
//			b[bn] = temp;
//			bn++;
//		}
//		//memset(d, -1, sizeof(d));
//
//		for (int i = 0; i < an; i++){
//			for (int j = 0; j < bn; j++){
//				for (int k = 0; k < 4; k++){
//					d[i][j][k] = 1e9;
//				}
//			}
//			
//		}
//
//		int ans1 = go(0, 0, 0, 0, 0);
//		int ans2 = go(0, 0, 1, 0, 0);
//		int ans3 = go(0, 0, 2, 0, 0);
//		int ans4 = go(0, 0, 3, 0, 0);  //�� ���� ������ �� �ƴ�
//		printf("%d\n", min({ans1,ans2,ans3,ans4}));
//	}
//	return 0;
//}