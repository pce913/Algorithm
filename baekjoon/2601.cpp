#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
/*���� ������ ���簢����
����, �� ���簢���� ���� �� �ֵ��� �ϴ� ���簢���� ���� �� �������� ������ ����
�Ѵ�.��, �̷��� ������ �� ���� �����Ͽ�, �� ���� ���� ���� �ϴ� ���簢���� ����
�� �� �־��� ���簢���� ���� �� �ֵ��� �ϴ� ���̴�.�̷��� ������ ��ǥ ������
�� ����� ����, �� ������ ���� ���簢������ ��Ÿ���� �ȴ�.���� �̷��� ������
�ٲٰ� ���� ���簢���� ���� ���� ��ġ�� �����̳� ���� ã�� ������ �ٲ�� �ȴ�.*/

struct Line{
	int x, y, ly;
	bool isOpen;
	bool operator<(const Line& l)const{
		if (this->x == l.x){
			return this->isOpen < l.isOpen;    //�̰͵� �ݵ�� �޾���� �Ѵ�. ��, x��ǥ�� ���� ��� �ݴ� ��ȣ���� ����.
		}
		return this->x < l.x;
	}
};
int MAX_Y = 0;
const int MAXN = 200005;
vector<Line> line;
vector<int> ypos;
int tree[4 * MAXN],lazy[4*MAXN];

void update_lazy(int node,int start,int end){
	if (lazy[node] != 0){
		tree[node] += lazy[node];
	}
	if (start != end){
		lazy[2 * node] += lazy[node];
		lazy[2 * node + 1] += lazy[node];
	}
	lazy[node] = 0;
}

void update_range(int node,int start,int end,int i,int j,int value){
	update_lazy(node, start, end);
	if (i > end || j < start){
		return;
	}
	if (start >= i && end <= j){
		tree[node] += value;
		if (start != end){
			lazy[2 * node] += value;
			lazy[2 * node + 1] += value;
		}
		return;
	}
	update_range(2 * node, start, (start + end) / 2, i, j, value);
	update_range(2 * node + 1, (start + end) / 2+1,end , i, j, value);
	tree[node] = max(tree[2 * node], tree[2 * node + 1]);
}

int query(){
	update_lazy(1, 1, MAX_Y);
	return tree[1];
}


int main(){
	int mx1, my1, mx2, my2, d, m;
	scanf("%d %d %d %d %d %d", &mx1, &my1, &mx2, &my2, &d, &m);
	for (int i = 0; i < m; i++){
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		int nx = max(mx1, x2 - d);
		int ny = min(my1, y2 + d);
		if (nx <= x1 && ny >= y1){
			line.push_back({ nx, ny, y1, true });
			line.push_back({ x1 + 1, y1, ny, false });    //���⿡ +1���ϸ� Ʋ���� �ȴ�.
			ypos.push_back(ny);     // nx == x1 �̶�� nx���� ���� �ϱ� ���ؼ� +1�� ���ش�. ��, �̷����� ���� ��ȣ���� ���� ���ƾ� �Ѵ�.
			ypos.push_back(y1);     // nx == x1 �� �Ǵ� ���� ���� ���� �ִ� �簢���� ũ�Ⱑ ī���� ũ�� d�� �������̴�. �̷��� ���� ��ȣ���� ���� ���ƾ� ���� ����� ���ŵȴ�. 
		}                          //�̷� ��츦 �����ϰ�� �ݴ� ��ȣ���� ���� ���ƾ� �ϹǷ� operator ������ ���־���.
	}
	sort(line.begin(), line.end());
	sort(ypos.begin(), ypos.end());
	ypos.erase(unique(ypos.begin(), ypos.end()), ypos.end());
	for (int i = 0; i < line.size(); i++){
		line[i].y = lower_bound(ypos.begin(), ypos.end(), line[i].y) - ypos.begin() + 1;
		line[i].ly = lower_bound(ypos.begin(), ypos.end(), line[i].ly) - ypos.begin() + 1;
	}

	MAX_Y = ypos.size();
	int ans = 0;
	for (int i = 0; i < line.size(); i++){
		int y = line[i].y;
		int ly = line[i].ly;
		bool isOpen = line[i].isOpen;
		if (y>ly)
			swap(y, ly);

		if (isOpen){
			update_range(1, 1, MAX_Y, y, ly, 1);
		}
		else{
			update_range(1, 1, MAX_Y, y, ly, -1);
		}
		ans = max(ans, query());
	}
	printf("%d", ans);
	return 0;
}
//#include<stdio.h>
//#include<vector>
//#include<algorithm>
//using namespace std;
///*���� ������ ���簢����
//����, �� ���簢���� ���� �� �ֵ��� �ϴ� ���簢���� ���� �� �������� ������ ����
//�Ѵ�.��, �̷��� ������ �� ���� �����Ͽ�, �� ���� ���� ���� �ϴ� ���簢���� ����
//�� �� �־��� ���簢���� ���� �� �ֵ��� �ϴ� ���̴�.�̷��� ������ ��ǥ ������
//�� ����� ����, �� ������ ���� ���簢������ ��Ÿ���� �ȴ�.���� �̷��� ������
//�ٲٰ� ���� ���簢���� ���� ���� ��ġ�� �����̳� ���� ã�� ������ �ٲ�� �ȴ�.*/
//
//struct Line{
//	int x, y, ly;
//	bool isOpen;
//	bool operator<(const Line& l)const{
//		if (this->x == l.x){
//			return this->isOpen < l.isOpen;    //�̰͵� �ݵ�� �޾���� �Ѵ�. ��, x��ǥ�� ���� ��� �ݴ� ��ȣ���� ����.
//		}
//		return this->x < l.x;
//	}
//};
//
//const int MAXN = 200005;
//vector<Line> line;
//vector<int> ypos;
//int tree[4 * MAXN],cnt[4*MAXN];
//
//void update(int node, int start, int end, int i, int j, int value){
//	if (i >end || j < start){
//		return;
//	}
//	if (start >= i && end <= j){
//		cnt[node] += value;
//	}
//	else{
//		update(2 * node, start, (start + end) / 2, i, j, value);
//		update(2 * node + 1, (start + end) / 2+1,end , i, j, value);
//	}
//	if (start == end){
//		tree[node] = cnt[node];
//	}
//	else{
//		tree[node] = cnt[node] + max(tree[2 * node], tree[2 * node + 1]);
//	}
//}
//
//int main(){
//	int mx1, my1, mx2, my2, d, m;
//	scanf("%d %d %d %d %d %d",&mx1,&my1,&mx2,&my2,&d,&m);
//	for (int i = 0; i < m; i++){
//		int x1, y1, x2, y2;
//		scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
//		int nx = max(mx1, x2 - d);
//		int ny = min(my1, y2 + d);
//		if (nx <= x1 && ny >= y1){
//			line.push_back({ nx, ny, y1, true });
//			line.push_back({ x1 + 1, y1, ny, false });    //���⿡ +1���ϸ� Ʋ���� �ȴ�.
//			ypos.push_back(ny);     // nx == x1 �̶�� nx���� ���� �ϱ� ���ؼ� +1�� ���ش�. ��, �̷����� ���� ��ȣ���� ���� ���ƾ� �Ѵ�.
//			ypos.push_back(y1);     // nx == x1 �� �Ǵ� ���� ���� ���� �ִ� �簢���� ũ�Ⱑ ī���� ũ�� d�� �������̴�. �̷��� ���� ��ȣ���� ���� ���ƾ� ���� ����� ���ŵȴ�. 
//		}                          //�̷� ��츦 �����ϰ�� �ݴ� ��ȣ���� ���� ���ƾ� �ϹǷ� operator ������ ���־���.
//	}
//	sort(line.begin(), line.end());
//	sort(ypos.begin(), ypos.end());
//	ypos.erase(unique(ypos.begin(), ypos.end()), ypos.end());
//	for (int i = 0; i < line.size(); i++){
//		line[i].y = lower_bound(ypos.begin(), ypos.end(), line[i].y) - ypos.begin() + 1;
//		line[i].ly = lower_bound(ypos.begin(), ypos.end(), line[i].ly) - ypos.begin() + 1;
//	}
//	const int MAX_Y = ypos.size();
//	int ans = 0;
//	for (int i = 0; i < line.size(); i++){
//		int y = line[i].y;
//		int ly = line[i].ly;
//		bool isOpen = line[i].isOpen;
//		if (y>ly)
//			swap(y, ly);
//
//		if (isOpen){
//			update(1, 1, MAX_Y, y, ly, 1);
//		}
//		else{
//			update(1, 1, MAX_Y, y, ly, -1);
//		}
//		ans = max(ans, tree[1]);
//	}
//	printf("%d",ans);
//	return 0;
//}