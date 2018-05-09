#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
using namespace std;

/*�Է����� ������ ��� ���ڿ��� trie�� ������ �� ���� Ȯ������ ���ڿ��� ���� 
���ڷ� �Ѿ�� ��ΰ� 2 �̻��� ��쳪 �ش� �������� ���ڿ��� ������ ��찡 
��ư�� ������ �ϴ� ����̴� ī��Ʈ�� ���������־� return�ϴ� ������ �����Ͽ� �ذ� �����ϴ�.*/

struct Node{
	bool valid;   //���ڿ��� ������ �ƴ����� ǥ��.
	int child[26];   //�ڽ��� ����ȣ�� ����.
	int cnum;
	Node(){
		valid = false;
		cnum = 0;
		for (int i = 0; i < 26; i++){
			child[i] = -1;
		}
	}
};

int n;
int root;
vector<Node> trie;
string a[100005];
int make_node(){   //���� ��� ��ȣ�� ����
	trie.push_back({});
	return (int)trie.size() - 1;
}

void make_trie(string& s){
	int node = root;    //��Ʈ���
	for (int i = 0; i < s.size(); i++){
		int c = s[i] - 'a';
		if (trie[node].child[c] == -1){
			int next = make_node();
			trie[node].child[c] = next;
			trie[node].cnum++;
		}
		node = trie[node].child[c];
	}
	trie[node].valid = true;
}

//�ڽ��� ������ 1���϶���

int get_cnt(string& s){
	int node = root;
	bool isOne = false;
	int cnt = 1; //������ 1   //���ڿ��� ������ ��� ��ư�� �ѹ� �� ������ �ϴ� ���.
	for (int i = 0; i < (int)s.size() - 1; i++){
		int c = s[i] - 'a';
		node = trie[node].child[c];
		if (trie[node].cnum > 1 || trie[node].valid){
			cnt++;
		}
	}
	return cnt;
}

void solve(){
	int sum = 0;
	for (int i = 0; i < n; i++){
		sum += get_cnt(a[i]);
	}
	cout <<fixed<<setprecision(2) <<(double)sum / n<<'\n';
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	while (cin>>n){
		trie.clear();
		root = make_node();
		for (int i = 0; i < n; i++){
			cin >> a[i];
			make_trie(a[i]);
		}
		solve();
	}
	return 0;
}