#include<stdio.h>
#include<vector>
#include<cstring>
using namespace std;

int M[305][305];
int adj[305][305];
int parent[305];
int sccCnt;
bool check[305];
int Find(int x){
	if (x == parent[x])
		return x;
	else
		return parent[x] = Find(parent[x]);
}

void Union(int x,int y){
	x = Find(x);
	y = Find(y);
	if (x != y){
		parent[y] = x;
		sccCnt++;
	}
}

void solve(){
	memset(adj, 0, sizeof(adj));
	memset(check, false, sizeof(check));
	int n;
	scanf(" %d",&n);
	for (int i = 1; i <= n; i++){
		parent[i] = i;
	}

	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			scanf("%1d",&M[i][j]);
		}
	}

	for (int i = 1; i <= n; i++){    //SCC�� n^2���� �����.
		for (int j = 1; j <= n; j++){
			if (M[i][j] && M[j][i]){
				Union(i, j);
			}
		}
	}

	for (int i = 1; i <= n; i++){  //SCC���� ���� �׷��� ����
		for (int j = 1; j <= n; j++){
			if (M[i][j] && Find(i) != Find(j)){
				adj[Find(i)][Find(j)] = 1;
			}
		}
	}

	for (int k = 1; k <= n; k++){
		for (int i = 1; i <= n; i++){   //���ʿ��� ���� ����
			for (int j = 1; j <= n; j++){
				if (adj[Find(i)][Find(j)] && adj[Find(i)][Find(k)] && adj[Find(k)][Find(j)]){
					adj[Find(i)][Find(j)] = 0;
				}
			}
		}
	}

	vector< pair<int,int> > ans;
	for (int i = 1; i <= n; i++){
		int before = i;
		for (int j = i + 1; j <= n; j++){
			if (!check[i] && !check[j] && Find(i) == Find(j)){
				check[j] = true;
				ans.push_back({ before, j });
				before = j;
			}
		}
		if (before != i){
			ans.push_back({ before, i });
		}
		check[i] = true;
	}

	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			if (adj[Find(i)][Find(j)]){
				ans.push_back({ i, j });
				adj[Find(i)][Find(j)] = 0;
			}
		}
	}

	printf("%d\n",ans.size());
	for (int i = 0; i < ans.size(); i++){
		printf("%d %d\n",ans[i].first,ans[i].second);
	}
	printf("\n");
}

int main(){
	int T;
	scanf("%d",&T);
	for (int test = 1; test <= T; test++){
		solve();
	}
	return 0;
}

//#include <stdio.h>
//#include<vector>
//using namespace std;
//#define REP(i,a,b) for(int i=a;i<=b;++i)
//#define FOR(i,n) for(int i=0;i<n;++i)
//#define pb push_back
//#define all(v) (v).begin(),(v).end()
//#define sz(v) ((int)(v).size())
//#define inp1(a) scanf("%d",&a)
//#define inp2(a,b) scanf("%d%d",&a,&b)
//#define inp3(a,b,c) scanf("%d%d%d",&a,&b,&c)
//#define inp4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)
//#define inp5(a,b,c,d,e) scanf("%d%d%d%d%d",&a,&b,&c,&d,&e)
//using namespace std;
//typedef long long ll;
//typedef pair<ll, ll> pll;
//typedef vector<int> vi;
//typedef vector<ll> vl;
//typedef pair<int, int> pii;
//typedef vector<pii> vii;
//typedef vector<pll> vll;
//typedef vector<vector<int> > vvi;
//typedef pair<int, pair<int, int> > piii;
//typedef vector<piii> viii;
//const double EPSILON = 1e-9;
//const double PI = acos(-1);
//const int MOD = 1e9 + 7;
//const int INF = 0x3c3c3c3c;
//const long long INFL = 0x3c3c3c3c3c3c3c3c;
//const int MAX_N = 102;
//
//int cango[303][303];
//int sccId[303];
//int N, T, sccCnt;
//int adj[303][303];
//vi sccMem[303];
//int main() {
//	inp1(T);
//	while (T--){
//		sccCnt = 0;
//		memset(sccId, -1, sizeof(sccId));
//		memset(cango, 0, sizeof(cango));
//		memset(adj, 0, sizeof(adj));
//		FOR(i, 303) sccMem[i].clear();
//		getchar();
//		inp1(N);
//		for (int i = 0; i < N; i++){
//			for (int j = 0; j < N; j++){
//				scanf("%1d", &cango[i][j]);
//			}
//		}
//		for (int i = 0; i < N; i++){   //n^2 ���� SCC�� �����.
//			if (sccId[i] == -1)
//				sccId[i] = sccCnt++, sccMem[sccId[i]].pb(i);
//			for (int j = i + 1; j < N; j++){
//				if (sccId[j] != -1)   //�̹� j ��尡 �ٸ� scc�� ���ԵǾ� �ִٸ� continue
//					continue;
//				if (cango[i][j] && cango[j][i])
//					sccId[j] = sccId[i],sccMem[sccId[j]].pb(j);
//			}
//		}
//
//		for (int i = 0; i < N; i++){
//			for (int j = 0; j < N; j++){
//				if (cango[i][j] && sccId[i] != sccId[j])    //i���� j�� �� �� �ִµ� ���� �ٸ� �׷��̸�
//					adj[sccId[i]][sccId[j]] = 1;  //i���� j�� ���� ��� �ϳ��� �����ش�.
//			}
//		}
//
//		for (int k = 0; k < sccCnt; k++){
//			for (int i = 0; i < sccCnt; i++){
//				for (int j = 0; j < sccCnt; j++){
//					if (adj[i][j] && adj[i][k] && adj[k][j])   //���ʿ��� ���� ����.
//						adj[i][j] = 0;
//				}
//			}
//		}
//
//		vii ans;
//		for (int i = 0; i < sccCnt; i++){
//			if (sccMem[i].size() <= 1)
//				continue;
//			for (int j = 0; j < sccMem[i].size(); j++){
//				ans.pb({ sccMem[i][j], sccMem[i][(j + 1) % sccMem[i].size()] });
//			}
//		}
//
//		for (int i = 0; i < sccCnt; i++){
//			for (int j = 0; j < sccCnt; j++){
//				if (adj[i][j])
//					ans.pb({ sccMem[i][0], sccMem[j][0] });   //�� SCC �� ��ǥ�� ���ؼ� ������ ����Ѵ�.
//			}
//		}
//
//		printf("%d\n", ans.size());
//		for (auto p : ans){
//			printf("%d %d\n", p.first + 1, p.second + 1);
//		}
//		printf("\n");
//	}
//	return 0;
//}