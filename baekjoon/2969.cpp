#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

/*1.D[i][j]: i, j ��ġ�� ������ �ִ� ������� �Դ���  ���⼭ ���׸�Ʈ Ʈ���� tree�� D�� ��ü �� �� �ִ�.
2.�� row�� col���� segment tree�� ����� �ش�.n������ �����Ƿ� �� ���� �� �ִ�.
���׸�Ʈ Ʈ������ DP�� �ִ��� ����Ǿ� �ִ�.
3.ó�� ������ġ D[a][b] = 1 �� ������ �Ѵ�.������ D[i][j] = 0 �� ������ ���̴�.
4.���� ������ sort�Ѵ�.sort�ϱ� ���ؼ��� 2������ 1�������� ��ȯ�ؾ� �� ���̴�.��ǥ ������ �Բ�
������ �־����.
5.���� ������� ���鼭 ���� ��ǥ�� �� �� �ִ� �ĺ����� ���׸�Ʈ Ʈ������ �����´�.
6.���׸�Ʈ Ʈ������ max���� �������°��̴�.
7.������ max���� 0�� �ƴ϶�� ���� ��ǥ�� �� max + 1 �� �������ش�.
8.max���� �����Դµ� �� ���� 0�̶�� �ϸ��� ������ ���� �ʴ´�.
9.max���� ������ ������ �ߴٸ� ���� ��ǥ�� �����ִ� row�� col�� ���� Ʈ���� update �����ش�.
10.���� �� ���� �ִµ�, ������ ������ ���� ĭ���� update�� �Ѳ����� ����� �Ѵ�.
�ֳ��ϸ� �ǽð����� update �� ��쿡�� ������ ������ ���� �����ִ� ĭ�� ���� ������
max���� ���� �� �� �ֱ� �����̴�.
1 2 2 3 3 3 4 4 4 4  ...   --> ������� 4���� ��쿡�� ��� �ξ��ٰ� �Ѳ����� ������Ʈ �ؾ� �Ѵ�.*/

struct Flower{
	int x, y, w;
	bool operator<(const Flower& f)const{
		return this->w < f.w;
	}
};

const int MAXN = 1501;
  // D[i][j]: i,j ��ġ�� ������ �ִ� ������� �Դ���
int sx, sy;
int row_tree[MAXN][4 * MAXN];   //������ �࿡ ���� �ִ밪�� ã�� ���׸�Ʈ Ʈ��
int col_tree[MAXN][4 * MAXN];   //������ ���� ���� �ִ밪�� ã�� ���׸�Ʈ Ʈ��
vector<Flower> update_list;   //���⼭ w: D[i][j] ��.
vector<Flower> flower;  //���⼭ w: �� ���� ������ ����
int dxr[] = {  1, -1, -1, 1 };  //row ����
int dyr[] = { -2, -2,  2, 2 };
int dxc[] = { 2, 2, -2, -2 }; // col ����
int dyc[] = { 1, -1, -1, 1 };
void update(int tree[], int node, int start, int end, int i, int value){
	if (i > end || i < start){
		return;
	}
	tree[node] = max(tree[node], value);
	if (start != end){
		update(tree, 2 * node, start, (start + end) / 2, i, value);
		update(tree, 2 * node + 1, (start + end) / 2 + 1, end, i, value);
	}
}

int query(int tree[], int node, int start, int end, int i, int j){
	if (i > end || j < start){
		return 0;
	}
	if (start >= i && end <= j){
		return tree[node];
	}
	int m1=query(tree, 2 * node, start, (start + end) / 2, i, j);
	int m2=query(tree, 2 * node + 1, (start + end) / 2+1,end , i, j);
	return max(m1, m2);
}

int main(){
	int n;
	int s_petal = 0;
	scanf("%d %d %d", &n, &sx, &sy);
	flower.resize(n*n);   //resize���ϰ� push_back �ϸ� �޸� �ʰ� ��.
	int fm = 0;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			int x;
			scanf("%d", &x);
			if (i == sx && j == sy)
				s_petal = x;
			flower[fm++] = { i, j, x };
		}
	}
	sort(flower.begin(), flower.end());
	
	update_list.push_back({ sx, sy, 1 });
	Flower aa = { 0, 0, s_petal };
	flower.erase(flower.begin(), lower_bound(flower.begin(), flower.end(), aa));   //���� ���ٺ��� ���� �༮���� �����ְ� �����Ѵ�.
	int cur_w;
	if (flower.size()>0)
		 cur_w = flower[0].w;
	for (int i = 0; i < flower.size(); i++){
		int cx = flower[i].x;
		int cy = flower[i].y;
		int cw = flower[i].w;
		if (cw != cur_w){   //������ ������ ���� �༮���� �Ѳ����� update ���ش�.
			for (int k = 0; k < update_list.size(); k++){
				int ux = update_list[k].x;
				int uy = update_list[k].y;
				int uw = update_list[k].w;
				update(row_tree[ux], 1, 1, n, uy, uw);
				update(col_tree[uy], 1, 1, n, ux, uw);
			}
			cur_w = cw;
			update_list.clear();
		}

		int maxi = 0;
		for (int k = 0; k < 4; k++){   // row ����
			int nx = cx + dxr[k];
			int ny = cy + dyr[k];
			if (nx >= 1 && nx <= n && ny >= 1 && ny <= n){
				int from, to;
				if (ny < cy){    //����
					from = 1;
					to = ny;
				}
				else{   // ������
					from = ny;
					to = n;
				}
				int temp=query(row_tree[nx], 1, 1, n, from, to);
				maxi = max(maxi, temp);
			}
		}
		for (int k = 0; k < 4; k++){  // col ����
			int nx = cx + dxc[k];
			int ny = cy + dyc[k];
			if (nx >= 1 && nx <= n && ny >= 1 && ny <= n){
				int from, to;
				if (nx < cx){   //����
					from = 1;
					to = nx;
				}
				else{   // �Ʒ���
					from = nx;
					to = n;
				}
				int temp=query(col_tree[ny], 1, 1, n, from, to);
				maxi = max(maxi, temp);
			}
		}

		if (maxi == 0)
			continue;
		update_list.push_back({ cx, cy, maxi+1 });
	}
	if (!update_list.empty()){  //������Ʈ �� �͵��� �����ִٸ� ���� ���ش�.
		for (int k = 0; k < update_list.size(); k++){
			int ux = update_list[k].x;
			int uy = update_list[k].y;
			int uw = update_list[k].w;
			update(row_tree[ux], 1, 1, n, uy, uw);
			update(col_tree[uy], 1, 1, n, ux, uw);
		}
	}

	int ans = 1;
	for (int i = 1; i <= n; i++){
		ans = max( ans,row_tree[i][1]);    //row������ �ִ밪�� �����͵� ���� ���� �� �ִ�.
	}
	printf("%d",ans);
	return 0;
}