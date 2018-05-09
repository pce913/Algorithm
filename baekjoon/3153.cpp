#include<stdio.h>
#include<vector>
#include<cstring>
#include<stack>
using namespace std;
/*
� ������ �ݵ�� ���̾�߸� �Ѵٴ� ������ 2-SAT �Ŀ� �� ��Ƶ�� �Ϸ��� 
(x1 �� x1)
�̷� ���� �߰��ϸ� �ȴ�.
*/
//������ ����
char M[105][105];
int tower[105][105];
int n, m;
int dx[] = { -1, 1, 0, 0 };  //�� �� �� ��
int dy[] = { 0, 0, -1, 1 };
int tnum = 0;
bool check[105 * 105 * 8];
vector<int> a[105 * 105 * 8],r[105*105*8];
stack<int> s;
int group[105 * 105 * 8];

int convert(int x, int dir){  //Ÿ�� ��ȣ�� ��ź�� �� ������ �˾ƾ���.
	return x + dir*tnum;
}

int exchange(int x,int dir){
	return x + (dir ^ 1)*tnum;
}

void add_edge(int x,int y){
	a[x].push_back(y);
	r[y].push_back(x);
}

void dfs(int node){
	check[node] = true;
	for (int next : a[node]){
		if (!check[next]){
			dfs(next);
		}
	}
	s.push(node);
}

void dfs_rev(int node,int gnum){
	group[node] = gnum;
	for (int next : r[node]){
		if (group[next] == 0){
			dfs_rev(next,gnum);
		}
	}
}

void solve(){
	for (int i = 1; i <= 4 * tnum; i++){
		if (!check[i]){
			dfs(i);
		}
	}

	int gnum = 0;
	while (!s.empty()){
		int node = s.top();
		s.pop();
		if (group[node] == 0){
			dfs_rev(node, ++gnum);
		}
	}

	for (int i = 1; i <= n; i++){   //0: ��, 1:��, 2:��, 3:��
		for (int j = 1; j <= m; j++){
			if (M[i][j] == 'T'){
				int t = tower[i][j];
				if (group[t + 3 * tnum] < group[t + 2 * tnum] && group[t] < group[t + tnum]){
					printf("1");
				}
				else if (group[t + 2 * tnum] < group[t + 3 * tnum] && group[t] < group[t + tnum]){
					printf("2");
				}
				else if (group[t + 2 * tnum] < group[t + 3 * tnum] && group[t + tnum] < group[t]){
					printf("3");
				}
				else if (group[t + 3 * tnum] < group[t + 2 * tnum] && group[t + tnum] < group[t]){
					printf("4");
				}
			}
			else{
				printf("%c",M[i][j]);
			}
		}
		printf("\n");
	}
}

void look_at_tower_each_other(){   //ok
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			if (M[i][j] == 'T'){
				for (int k = 0; k < 4; k++){
					int nx = i;
					int ny = j;
					while (nx + dx[k] >= 1 && nx + dx[k] <= n && ny + dy[k] >= 1 && ny + dy[k] <= m){
						if (M[nx + dx[k]][ny + dy[k]] == '#')
							break;
						if (M[nx + dx[k]][ny + dy[k]] == 'T'){
							int t = tower[nx + dx[k]][ny + dy[k]];
							add_edge(exchange(t, k), convert(t, k));   //(x1 V x1) 
							break;
						}
						nx += dx[k];
						ny += dy[k];
					}
				}
			}
		}
	}
}

void candidate_tower(){
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			if (M[i][j] == 'n'){
				vector< pair<int,int> > px, py;
				for (int k = 0; k < 4; k++){
					int nx = i;
					int ny = j;
					while (nx + dx[k] >= 1 && nx + dx[k] <= n && ny + dy[k] >= 1 && ny + dy[k] <= m){
						if (M[nx + dx[k]][ny + dy[k]] == '#')
							break;
						if (M[nx + dx[k]][ny + dy[k]] == 'T'){
							int t = tower[nx + dx[k]][ny + dy[k]];
							if (k <= 1)
								px.push_back({ exchange(t, k ^ 1), convert(t, k ^ 1) });
							else
								py.push_back({ exchange(t, k ^ 1), convert(t, k ^ 1) });
							break;
						}
						nx += dx[k];
						ny += dy[k];
					}
				}
				if (px.size() == 2)px.clear();
				else if (py.size() == 2)py.clear();
				else if (px.size() == 1 && py.size() == 0){
					add_edge(px[0].first, px[0].second);
				}
				else if (px.size() == 0 && py.size() == 1){
					add_edge(py[0].first, py[0].second);
				}
				else if (px.size() == 1 && py.size() == 1){   //������ �ϳ� �̻� ħ���ڸ� �μ��� �ȴ�. (x V y)
					add_edge(px[0].first, py[0].second);
					add_edge(py[0].first, px[0].second);
				}
			}
		}
	}
}

int main(){
	scanf("%d %d",&n,&m);
	for (int i = 1; i <= n; i++)
		scanf("%s",&M[i][1]);

	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			if (M[i][j] == 'T'){
				tower[i][j] = ++tnum;
			}
		}
	}
	look_at_tower_each_other();
	candidate_tower();
	solve();
	return 0;
}
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <math.h>
//#include <assert.h>
//#include <limits.h> 
//#include <stack>
//#include <queue>
//#include <map>
//#include <set>
//#include <algorithm>
//#include <string>
//#include <functional>
//#include <vector>
//#include <numeric>
//#include <deque>
//#include <utility>
//#include <bitset>
//#include <iostream>
//using namespace std;
//typedef long long lint;
//typedef long double llf;
//typedef pair<int, int> pi;
///*
//� ������ �ݵ�� ���̾�߸� �Ѵٴ� ������ 2-SAT �Ŀ� �� ��Ƶ�� �Ϸ��� 
//(x1 �� x1)
//�̷� ���� �߰��ϸ� �ȴ�.
//*/
//int n, m;
//char str[105][105];
//int idx[105][105], p;
//
//vector<int> gph[40005]; // up = 0, dn = 1, le = 2, ri = 3;
//vector<int> rev[40005];
//bool vis[40005];
//vector<int> dfn;
//int comp[40005], cmp;
//
//bool ok(int p){
//	return comp[p ^ 1] < comp[p];
//}
//
//void dfs(int x){
//	if (vis[x]) return;
//	vis[x] = 1;
//	for (auto &i : gph[x]){
//		dfs(i);
//	}
//	dfn.push_back(x);
//}
//
//void rdfs(int x, int p){
//	if (comp[x]) return;
//	comp[x] = p;
//	for (auto &i : rev[x]){
//		rdfs(i, p);
//	}
//}
//
//void solve_2sat(){
//	for (int i = 0; i<4 * p; i++){
//		if (!vis[i]){
//			dfs(i);
//		}
//	}
//	reverse(dfn.begin(), dfn.end());
//	for (auto &i : dfn){
//		if (!comp[i]){
//			rdfs(i, ++cmp);
//		}
//	}
//	for (int i = 0; i<4 * p; i++){
//		if (comp[i] == comp[i ^ 1]){
//			assert(0);
//		}
//	}
//	for (int i = 0; i<n; i++){
//		for (int j = 0; j<m; j++){
//			if (str[i][j] != 'T'){
//				putchar(str[i][j]);
//			}
//			else{
//				int p = idx[i][j];
//				if (ok(4 * p + 2) && ok(4 * p + 1)){ 
//					putchar('1');
//				}
//				else if (ok(4 * p + 3) && ok(4 * p + 1)){
//					putchar('2');
//				}
//				else if (ok(4 * p + 3) && ok(4 * p)){
//					putchar('3');
//				}
//				else{  //�̰��� �ݵ�� else�� ���ƾ� ����. ��, 1,2,3,4 �� ��� ���� �� �� �ִ� Ÿ���� ���� �� �ֱ� �����̴�.
//					putchar('4');
//				}
//			}
//		}
//		puts("");
//	}
//}
//
//void add_edge(int x, int y){
//	gph[x].push_back(y);
//	rev[y].push_back(x);
//}
//
//void always_true(int x){
//	add_edge(x ^ 1, x);
//}
//
//void proc_tower(){  
//	for (int i = 0; i<n; i++){
//		for (int j = 0; j<m; j++){
//			if (str[i][j] == 'T'){   //Ÿ������ ���� ���ֺ��� �ִٸ� ���� ���� ��� ó��.
//				for (int k = j + 1; k<m; k++){
//					if (str[i][k] == 'T'){
//						always_true(idx[i][j] * 4 + 2);
//						break;
//					}
//					if (str[i][k] == '#') break;
//				}
//				for (int k = j - 1; k >= 0; k--){
//					if (str[i][k] == 'T'){
//						always_true(idx[i][j] * 4 + 3);
//						break;
//					}
//					if (str[i][k] == '#') break;
//				}
//				for (int k = i + 1; k<n; k++){
//					if (str[k][j] == 'T'){
//						always_true(idx[i][j] * 4 + 0);
//						break;
//					}
//					if (str[k][j] == '#') break;
//				}
//				for (int k = i - 1; k >= 0; k--){
//					if (str[k][j] == 'T'){
//						always_true(idx[i][j] * 4 + 1);
//						break;
//					}
//					if (str[k][j] == '#') break;
//				}
//			}
//		}
//	}
//}
//
//void proc_evil(){
//	for (int i = 0; i<n; i++){
//		for (int j = 0; j<m; j++){
//			if (str[i][j] == 'n'){
//				vector<int> px, py;
//				for (int k = j + 1; k<m; k++){
//					if (str[i][k] == 'T'){
//						py.push_back(4 * idx[i][k] + 2);   //��ź�� ��������� �ݴ�������� ���.
//						break;
//					}
//					if (str[i][k] == '#') break;
//				}
//				for (int k = j - 1; k >= 0; k--){
//					if (str[i][k] == 'T'){
//						py.push_back(4 * idx[i][k] + 3);
//						break;
//					}
//					if (str[i][k] == '#') break;
//				}
//				for (int k = i + 1; k<n; k++){
//					if (str[k][j] == 'T'){
//						px.push_back(4 * idx[k][j] + 0);
//						break;
//					}
//					if (str[k][j] == '#') break;
//				}
//				for (int k = i - 1; k >= 0; k--){
//					if (str[k][j] == 'T'){
//						px.push_back(4 * idx[k][j] + 1);
//						break;
//					}
//					if (str[k][j] == '#') break;
//				}
//				if (px.size() == 2) px.clear();
//				if (py.size() == 2) py.clear();
//				if (px.size() == 0 && py.size() == 0){
//					assert(0);
//				}
//				if (px.size() == 1 && py.size() == 0){
//					always_true(px[0]);
//				}
//				if (px.size() == 0 && py.size() == 1){
//					always_true(py[0]);
//				}
//				if (px.size() == 1 && py.size() == 1){
//					add_edge(px[0] ^ 1, py[0]);
//					add_edge(py[0] ^ 1, px[0]);
//				}
//			}
//		}
//	}
//}
//
//int main(){
//	cin >> n >> m;
//	for (int i = 0; i<n; i++){
//		cin >> str[i];
//		for (int j = 0; j<m; j++){
//			if (str[i][j] == 'T') idx[i][j] = (p++);
//		}
//	}
//	proc_tower();
//	proc_evil();
//	solve_2sat();
//}

//#include<stdio.h>
//#include<vector>
//#include<cstring>
//#include<stack>
//using namespace std;
//
//char M[105][105];
//int tower[105][105]; //tower[i][j]: (i,j)�� ��ġ�� Ÿ���� ��ȣ
//bool check[105*105*8];
//int tnum = 0;
//int n, m;
//int dx[] = { -1, 1, 0, 0 };   //�� �� �� ��
//int dy[] = { 0, 0, -1, 1 };
//int group[105 * 105 * 8], ans[105 * 105 * 8];
//vector<int> a[105*105*8],r[105*105*8];
//stack<int> s;
//struct Info{
//	int tnum, dir;
//	bool isCandi;
//};
//
//void dfs(int node){   //child�� 0�� �༮�鵵 ���ÿ� �־���� �ϳ�?
//	check[node] = true;
//	for (int next : a[node]){
//		if (!check[next]){
//			dfs(next);
//		}
//	}
//	s.push(node);
//}
//
//void dfs_rev(int node,int gnum){
//	check[node] = true;
//	group[node] = gnum;
//	for (int next : r[node]){
//		if (!check[next]){
//			dfs_rev(next,gnum);
//		}
//	}
//}
//
//
//int convert(int x, int dir){  //Ÿ�� ��ȣ�� ��ź�� �� ������ �˾ƾ���.
//	return x + dir*tnum;
//}
//
//int exchange(int x,int dir){
//	return x + (dir ^ 1)*tnum;
//}
//
//void search(int cx,int cy){
//	vector<Info> candi;   //�־��� input���� candi�� ��� �������� ����.
//	for (int i = 0; i < 4; i++){     //tnum: �ĺ��� �Ǵ� Ÿ�� ��ȣ, dir: ��ź�� �� ����
//		int nx = cx;
//		int ny = cy;
//		int ndx = nx + dx[i];
//		int ndy = ny + dy[i];
//		while (ndx >= 1 && ndx <= n && ndy >= 1 && ndy <= m && M[ndx][ndy] != '#' && tower[ndx][ndy] == 0){
//			nx += dx[i];
//			ny += dy[i];
//			ndx = nx + dx[i];
//			ndy = ny + dy[i];
//		}
//		if (tower[nx + dx[i]][ny + dy[i]] != 0){
//			candi.push_back({ tower[nx + dx[i]][ny + dy[i]] , i ^ 1 , true});  //'��ź�� �� ����'�� �����ؾ� �ϹǷ� Ž���ϴ� ����� �ݴ��̴�.
//		}
//	}
//
//	int real_size = candi.size();
//	for (int i = 0; i < candi.size(); i++){
//		int x = candi[i].dir;
//		for (int j = i + 1; j < candi.size(); j++){
//			int y = candi[j].dir;
//			if (x ^ 1 == y){
//				candi[i].isCandi = false;
//				candi[j].isCandi = false;
//				real_size-=2;
//			}
//		}
//	}
//	if (real_size == 1){
//		int x;
//		int dir;
//		for (int i = 0; i < candi.size(); i++){
//			if (candi[i].isCandi){
//				x = candi[i].tnum;
//				dir = candi[i].dir;
//				break;
//			}
//		}
//		ans[convert(x, dir)] = 2;    //true�� �༮�� 2������
//		ans[exchange(x, dir)] = 1;  //false�� �༮�� 1������ ǥ����
//	}
//	else if (real_size == 2){
//		int x[2];
//		int dir[2];
//		int t = 0;
//		for (int i = 0; i < candi.size(); i++){
//			if (candi[i].isCandi){
//				x[t] = candi[i].tnum;
//				dir[t++] = candi[i].dir;
//			}
//		}
//
//		int conx = convert(x[0], dir[0]);
//		int cony = convert(x[1], dir[1]);
//		a[exchange(x[0], dir[0])].push_back(cony);
//		a[exchange(x[1], dir[1])].push_back(conx);
//		r[cony].push_back(exchange(x[0], dir[0]));
//		r[conx].push_back(exchange(x[1], dir[1]));
//	}
//	//bool tobreak = false;
//	//for (auto x = candi.begin(); x != candi.end(); x++){
//	//	for (auto y = candi.begin() + 1; y != candi.end(); y++){
//	//		if ((x->dir) ^ 1 == (y->dir)){  //���ֺ��� �ִ� ��찡 ������
//	//			candi.erase(x);
//	//			candi.erase(y);
//	//			tobreak = true;
//	//			break;
//	//		}
//	//	}
//	//	if (tobreak)
//	//		break;
//	//}
//	//if (candi.size() == 1){
//	//	int x = candi[0].tnum;
//	//	int dir = candi[0].dir;
//	//	ans[convert(x, dir)] = 2;    //true�� �༮�� 2������
//	//	ans[exchange(x, dir)] = 1;  //false�� �༮�� 1������ ǥ����
//	//}
//	//else if (candi.size() == 2){
//	//	int x = candi[0].tnum;
//	//	int xdir = candi[0].dir;
//	//	int y = candi[1].tnum;
//	//	int ydir = candi[1].dir;
//	//	int conx = convert(x, xdir);
//	//	int cony = convert(y, ydir);
//	//	a[exchange(x, xdir)].push_back(cony);
//	//	a[exchange(y, ydir)].push_back(conx);
//	//	r[cony].push_back(exchange(x, xdir));
//	//	r[conx].push_back(exchange(y, ydir));
//	//}
//}
//
//int main(){
//	scanf("%d %d",&n,&m);
//	for (int i = 1; i <= n; i++)
//		scanf("%s",&M[i][1]);
//	for (int i = 1; i <= n; i++){
//		for (int j = 1; j <= m; j++){
//			if (M[i][j] == 'T'){   //�� Ÿ���� ��ȣ ���̱�.
//				tower[i][j] = ++tnum;
//			}
//		}
//	}
//	for (int i = 1; i <= n; i++){
//		for (int j = 1; j <= m; j++){
//			if (M[i][j] == 'n'){
//				search(i, j);
//			}
//		}
//	}
//
//	for (int i = 1; i <= 4 * tnum; i++){
//		if (!check[i] && a[i].size()!=0){
//			dfs(i);
//		}
//	}
//	memset(check, false, sizeof(check));
//	int gnum = 0;
//	while (!s.empty()){
//		int node = s.top();
//		s.pop();
//		if (!check[node]){
//			dfs_rev(node, ++gnum);
//		}
//	}
//
//	//��ž���� ���� ���µ� �ƹ� ħ���ڵ� ������ ���ϴ� ���� ��� ����?
//	for (int i = 1; i <= tnum; i++){
//		if (ans[i] == 0 && ans[i + tnum] == 0){
//			if (group[i] < group[i + tnum]){
//				ans[i] = 1;
//				ans[i + tnum] = 2;
//			}
//			else{
//				ans[i] = 2;
//				ans[i + tnum] = 1;
//			}
//		}
//		if (ans[i + 2 * tnum] == 0 && ans[i + 3 * tnum] == 0){
//			if (group[i + 2 * tnum] < group[i + 3 * tnum]){
//				ans[i + 2 * tnum] = 1;
//				ans[i + 3 * tnum] = 2;
//			}
//			else{
//				ans[i + 2 * tnum] = 2;
//				ans[i + 3 * tnum] = 1;
//			}
//		}
//	}
//	printf("********************\n");
//	for (int i = 1; i <= n; i++){
//		for (int j = 1; j <= m; j++){
//			if (M[i][j] == 'T'){
//				int ti = tower[i][j];
//				if (ans[ti + 3 * tnum] == 2 && ans[ti + 2 * tnum] == 2)printf("1");
//				if (ans[ti + 4 * tnum] == 2 && ans[ti + 2 * tnum] == 2)printf("2");
//				if (ans[ti + 4 * tnum] == 2 && ans[ti] == 2)printf("3");
//				if (ans[ti + 3 * tnum] == 2 && ans[ti] == 2)printf("4");
//			}
//			else{
//				printf("%c",M[i][j]);
//			}
//		}
//		printf("\n");
//	}
//
//
//	return 0;
//}