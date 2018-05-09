//#include<stdio.h>
//#include<vector>
//#include<cmath>
//#include<algorithm>
//using namespace std;
//
//struct Info{
//	int candidate, count;
//};
//
//
//int a[300005];
//vector<int> color[300005];
//
//Info init(vector<Info>& tree,int node,int start,int end){
//	if (start == end){
//		tree[node] = { a[start], 1 };
//		return tree[node];
//	}
//	auto L = init(tree, 2 * node, start, (start + end) / 2);
//	auto R = init(tree, 2 * node + 1, (start + end) / 2 + 1, end);
//
//	//Kill the remaining pairs among L.count + R.count numbers that are left.
//	Info S;        
//	if (L.candidate == R.candidate){   
//		S.candidate = L.candidate;
//		S.count = L.count + R.count;
//	}
//	else if (L.count > R.count){
//		S.candidate = L.candidate;
//		S.count = L.count - R.count;
//	}
//	else{
//		S.candidate = R.candidate;
//		S.count = R.count - L.count;
//	}
//	tree[node] = S;
//	return tree[node];
//}
//
//Info query(vector<Info>& tree,int node,int start,int end,int left,int right){
//	if (start > right || end < left){
//		return{ -1, 0 };     //�̷��� count�� 0���� ����� �Ѵ�. �׷��� ��ĥ�� ������ ������ ����.
//	}
//	if (start >= left && end <= right){
//		return tree[node];
//	}
//	auto L = query(tree, 2 * node, start, (start + end) / 2, left, right);
//	auto R = query(tree, 2 * node + 1, (start + end) / 2 + 1, end, left, right);
//	Info S;
//	 //Kill �ϴ� ����. �ϴ� ������ �� �� �ִ� �ĺ��� ã�� �����̴�. �� ������ ���ؼ���
//	 //�� �״�� �ĺ��� ã�� �� ���� ���� ã�� ������ �ƴϴ�. 
//	 //�ĺ��� ���� �� �������̿� ���� ������ ���� �༮�� �������� ���̴�.
//	 //���⼭ L.count - R.count; �� �ϴ� �κ��� Kill�� �ϴ� �����̴�.
//	 // ��, ���� L�� R���� ������ ��� ������ ���� ���� ������ �༮ L.candidate�� R.candidate��
//	 //���� �� pair�� ���ִ� ���̴�.
//	 //�̰��� ����� ���� �� �� ������ ���������� count�� ������ �ƴ� �༮�� ���� �ĺ��� �ȴ�.
//	if (L.candidate == R.candidate){
//		S.candidate = L.candidate;
//		S.count = L.count + R.count;
//	}
//	else if (L.count > R.count){
//		S.candidate = L.candidate;
//		S.count = L.count - R.count;
//	}
//	else{
//		S.candidate = R.candidate;
//		S.count = R.count - L.count;
//	}
//	return S;
//}
//
//int get_count(int x,int left,int right){    //�䱸�ϴ� ���� ���̿� ������ ��� ���� ���� �ִ����� ����.
//	return upper_bound(color[x].begin(), color[x].end(), right) 
//		- lower_bound(color[x].begin(),color[x].end(),left);
//}
//
//int main(){
//	int n, c;
//	scanf("%d %d",&n,&c);
//	for (int i = 1; i <= n; i++){
//		scanf("%d",&a[i]);
//		color[a[i]].push_back(i);
//	}
//	int h = ceil(log2(n));
//	int tree_size = (1 << (h + 1));
//	vector<Info> tree(tree_size);
//	init(tree, 1, 1, n);
//
//	int m;
//	scanf("%d",&m);
//	for (int qq = 0; qq < m; qq++){
//		int x, y;
//		scanf("%d %d",&x,&y);
//		auto p = query(tree, 1, 1, n, x, y);
//		if (p.count > 0 && 2 * get_count(p.candidate, x, y) > y - x + 1){    //p.count > 0 : �ĺ��� �Ǵ� �༮�� �ִ�?
//			printf("yes %d\n",p.candidate);
//		}
//		else{
//			printf("no\n");
//		}
//	}
//	return 0;
//}
//
//#include <iostream>
//#include <map>
//#include <cstring>
//#include <set>
//#include <vector>
//using namespace std;
//const int MAXN = 300002;
//const int lim = 2000;
//map<int, int> tree[MAXN];
//int n, c, cnt[10001], q, v, l, r, tot[10001], arr[MAXN];
//vector<int> data[MAXN];
//set<int> st;
//void update(int n, int pos, int add){
//	for (int i = pos; i<MAXN; i += i&-i){
//		tree[i][n] += add;
//	}
//}
//int query(int n, int pos){
//	int sum = 0;
//	for (int i = pos; i>0; i -= i&-i){
//		if (tree[i].find(n) != tree[i].end())
//			sum += tree[i][n];
//	}
//	return sum;
//}
//int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cin >> n >> c;
//	for (int i = 1; i <= n; i++){
//		cin >> arr[i];
//		update(arr[i], i, 1);
//		tot[arr[i]]++;
//	}
//	for (int i = 1; i <= c; i++){
//		data[tot[i]].push_back(i);
//		st.insert(tot[i]);
//	}
//	cin >> q;
//	for (int i = 1; i <= q; i++){
//		cin >> l >> r;
//		int len = r - l + 1;
//		int cap = len / 2 + 1;
//		int color = -1;
//		if (len <= 5000){
//			memset(cnt, 0, sizeof(cnt));
//			for (int j = l; j <= r; j++){
//				cnt[arr[j]]++;
//				if (cnt[arr[j]] >= cap){
//					color = arr[j]; break;
//				}
//			}
//		}
//		else{
//			auto it = st.lower_bound(cap);
//			for (; it != st.end() && color == -1; it++){
//				for (int j = 0; j<data[*it].size(); j++){
//					int clr = data[*it][j];
//					if (query(clr, r) - query(clr, l - 1) >= cap){
//						color = clr; break;
//					}
//				}
//			}
//		}
//		if (color == -1)cout << "no\n";
//		else cout << "yes " << color << "\n";
//	}
//	return 0;
//}