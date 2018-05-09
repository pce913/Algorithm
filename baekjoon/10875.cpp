#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

struct Info{
	int go;
	char dir;
};
struct Line{
	int x1, y1, x2, y2;    //x1 <= x2   , y1 <=y2
};

vector<Info> info;
vector<Line> line;
int dx[] = { 1, 0, -1, 0 };    // 0:������, 1:�Ʒ� , 2:����, 3:��
int dy[] = { 0, -1, 0, 1 };
int dir = 0;
int remain_dist = 2e9+7;

int change_dir(int dir,char oper){
	int next_dir;
	if (oper == 'R'){
		next_dir=(dir + 1) % 4;
	}
	else{
		next_dir = (dir + 3) % 4;
	}
	return next_dir;
}

bool can_go(int nx1,int ny1,int nx2,int ny2){     
	bool canGo = true;
	if (ny1 == ny2){   //x���� ������ (������) , y���� ������ (������)
		for (int i = 0; i < line.size()-1; i++){     //������ ���� ���� boundary�� �� �� ����.
			int gx1 = line[i].x1;
			int gy1 = line[i].y1;
			int gx2 = line[i].x2;
			int gy2 = line[i].y2;

			if (gx1 == gx2){                //������ boundary
				if (ny1 <= gy2 && ny1 >= gy1 && gx1 <= nx2 && gx1 >= nx1){
					canGo = false;
					int temp_dist = 0;
					if (dir == 0){   //�������� ���� �����Ƿ� ���ʿ��� �� ����̴�.		
						temp_dist = gx1 - nx1;
					}
					else if(dir==2){   // ������ ���� �����Ƿ� �����ʿ��� �� ����̴�.
						temp_dist = nx2 - gx1;
					}
					remain_dist = min(remain_dist, temp_dist);

				}
			}
		}
	}
	else{
		for (int i = 0; i < line.size()-1; i++){        //������ ���� ���� boundary�� �ƴϴ�.
			int gx1 = line[i].x1;
			int gy1 = line[i].y1;
			int gx2 = line[i].x2;
			int gy2 = line[i].y2;

			if (gy1 == gy2){
				if (nx1 <= gx2 && nx1 >= gx1 && gy1 <= ny2 && gy1 >= ny1){
					canGo = false;
					int temp_dist = 0;
					if (dir == 1){   //�Ʒ��� ���� �����Ƿ� ������ �� ����̴�.
						temp_dist = ny2 - gy1;
					}
					else if (dir == 3){   //���� ���� �����Ƿ� �Ʒ����� �� ����̴�.
						temp_dist = gy1 - ny1;
					}   
					remain_dist = min(remain_dist, temp_dist);

				}
			}
		}
	}

	return canGo;
}

//������ �ε��� ��� ó���� ��� �Ѵ�.
long long lets_go(int sx,int sy){
	int cx = sx;
	int cy = sy;
	long long ans = 0;

	for (int i = 0; i < info.size(); i++){
		int go=info[i].go;
		int nx = cx + dx[dir] * go;
		int ny = cy + dy[dir] * go;
		int ix1 = min(cx, nx);
		int iy1 = min(cy, ny);
		int ix2 = max(cx, nx);
		int iy2 = max(cy, ny);

		if (i > 2){
			if (iy1 == 0 && iy2 == 0 && ix1 <= 0 && iy1 >= 0){
				if (dir == 0){
					ans += 0-ix1;
				}
				return ans;
			}
		}

		if (can_go(ix1, iy1, ix2, iy2)){
			line.push_back({ix1,iy1,ix2,iy2});
			ans += (ix2 - ix1) + (iy2 - iy1);
			cx = nx;
			cy = ny;
			dir = change_dir(dir, info[i].dir);
			
		}
		else{
			ans += remain_dist;
			return ans;
		}
	}
	//����� ������ ���ϰ� ������ ��ã������ ó���ؾ� �Ѵ�.
	int nx = cx + dx[dir] * 1e9;
	int ny = cy + dy[dir] * 1e9;
	int ix1 = min(cx, nx);
	int iy1 = min(cy, ny);
	int ix2 = max(cx, nx);
	int iy2 = max(cy, ny);
	can_go(ix1, iy1, ix2, iy2);
	ans += remain_dist;

	return ans;
}

int main(){
	int l,n;     // l: ��ĭ����.  n: �Ӹ��� ��� ȸ���ϴ���.
	scanf("%d %d",&l,&n);
	for (int i = 1; i <= n; i++){
		int go;
		char dir;
		scanf("%d %c",&go,&dir);
		info.push_back({ go, dir });
	}
	l += 1;
	line.push_back({ -l, - l,l,-l });    //�Ʒ� boundary
	line.push_back({ l, -l, l, l });  //������ boundary
	line.push_back({ -l, l, l, l });  //�� boundary
	line.push_back({ -l, -l, -l, l });  //���� boundary
	printf("%lld", lets_go(0, 0));
	return 0;
}
//#include<stdio.h>
//#include<vector>
//#include<algorithm>
//using namespace std;
//struct Line{
//	int x1, y1, x2, y2;
//	int dir;
//	Line(){}
//	Line(int x1, int y1, int x2, int y2) :x1(x1), y1(y1), x2(x2), y2(y2){
//		if (x1 == x2)
//			dir = 0;
//		else
//			dir = 1;
//		set_point();
//	}
//	void set_point(){
//		if (x1>x2)
//			swap(x1, x2);
//		if (y1>y2)
//			swap(y1, y2);
//	}
//};
//vector<Line> line;
//int l, n;
//const int inf = 0x3f3f3f3f;
//pair<int, int> spin[1001];
////
//int dx[4] = { 0, -1, 0, 1 };
//int dy[4] = { 1, 0, -1, 0 };
//int main(){
//	scanf("%d%d", &l, &n);
//	for (int i = 0; i<n; i++){
//		char input[2];
//		scanf("%d%s", &spin[i].first, input);
//		if (input[0] == 'L')
//			spin[i].second = 1;
//		else
//			spin[i].second = -1;
//	}
//	spin[n] = { inf, -1 };
//	//�ʱ� �׵θ�
//	line.push_back(Line(-l - 1, -l - 1, l + 1, -l - 1));
//	line.push_back(Line(-l - 1, -l - 1, -l - 1, l + 1));
//	line.push_back(Line(-l - 1, l + 1, l + 1, l + 1));
//	line.push_back(Line(l + 1, -l - 1, l + 1, l + 1));
//	int x, y, dir;
//	x = y = 0;
//	dir = 3;
//	long long ans = 0;
//	for (int i = 0; i <= n; i++){
//		int t = inf;
//		for (int j = 0; j<line.size(); j++){
//			if (line[j].dir == 0){
//				if (dir == 0){
//					if (x == line[j].x1&&y<line[j].y1){
//						t = min(t, line[j].y1 - y);
//					}
//				}
//				else if (dir == 1){
//					if (line[j].y1 <= y&&y <= line[j].y2&&line[j].x1<x)
//						t = min(t, x - line[j].x1);
//				}
//				else if (dir == 2){
//					if (x == line[j].x1&&line[j].y2<y){
//						t = min(t, y - line[j].y2);
//					}
//				}
//				else{
//					if (line[j].y1 <= y&&y <= line[j].y2&&x<line[j].x1)
//						t = min(t, line[j].x1 - x);
//				}
//			}
//			else{
//				if (dir == 0){
//					if (line[j].x1 <= x&&x <= line[j].x2&&y<line[j].y1){
//						t = min(t, line[j].y1 - y);
//					}
//				}
//				else if (dir == 1){
//					if (line[j].y1 == y&&line[j].x2<x)
//						t = min(t, x - line[j].x2);
//				}
//				else if (dir == 2){
//					if (line[j].x1 <= x&&x <= line[j].x2&&line[j].y1<y)
//						t = min(t, y - line[j].y1);
//				}
//				else{
//					if (line[j].y1 == y&&x<line[j].x1)
//						t = min(t, line[j].x1 - x);
//				}
//			}
//		}
//		if (t <= spin[i].first){
//			printf("%lld\n", ans + t);
//			return 0;
//		}
//		ans += spin[i].first;
//		int nx = x + dx[dir] * spin[i].first;
//		int ny = y + dy[dir] * spin[i].first;
//		dir = (dir + spin[i].second + 4) % 4;
//		line.push_back(Line(x, y, nx, ny));
//		x = nx;
//		y = ny;
//	}
//	return 0;
//}