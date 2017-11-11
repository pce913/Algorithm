#include<vector>
#include<iostream>
using namespace std;

const int MAXN = 500001;
vector<int> a[MAXN];
long long money[MAXN];
bool check[MAXN];
int preorder[MAXN];
int postorder[MAXN];
int pre = 0;


void dfs(int node){
	check[node] = true;
	preorder[node]=++pre;
	for (int i = 0; i < a[node].size(); i++){
		int next = a[node][i];
		if (!check[next]){
			check[next] = true;
			dfs(next);
		}
	}
	postorder[node] = pre;          //Ʈ����� ������ 1���������� �����ϱ� ���ؼ� pre�� post�� �����.
}

void update(vector<int>& tree, int x, int diff){
	for (int i = x; i < tree.size(); i += i&-i){   //������ ��Ʈ�� ���ؼ� õ�� ��带 ã�´�.
		tree[i] += diff;
	}
}

int query(vector<int>& tree,int x){
	int ans = 0;
	for (int i = x; i>0; i -= i&-i){
		ans += tree[i];
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	cin >> money[1];

	vector<int> tree(n + 5);   //����Ʈ�� Ʈ�� ������� ������?
	for (int i = 2; i <= n; i++){
		int x;
		cin >> money[i] >> x;
		a[x].push_back(i);
		a[i].push_back(x);
	}

	dfs(1);

	for (int i = 0; i < m; i++){
		char q;
		cin >> q;
		if (q == 'p'){
			int w, x;  //w�� ��� ������ ������ x��ŭ ������Ų��.
			cin >> w >> x;
			update(tree, preorder[w],x );
			update(tree, postorder[w]+1, -x);     //postorder + 1    mark�� ���� �����̴�.  �ٷ� ���� �ε������� -x ���ش�.
			// ���� ���� �Ǿ� �ִ� ��� ���޿��� -1 ���ش�. �ֳ��ϸ� ���� update ���ָ� �ȵǱ� �����̴�.
			money[w] -= x;     
		}
		else{
			int x;
			cin >> x;                  //������ �߰��߰��� �����Ƿ� 1���� ���������δ� ���� ���ϱ� ��ư�
			cout << money[x] + query(tree, preorder[x])<<"\n";    //��� ���� Ʈ���� ����Ѵ�.
		}
	}

	return 0;
}