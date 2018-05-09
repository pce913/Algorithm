#include<iostream>
#include<string>
#include<queue>
#include<vector>
using namespace std;

//trie: ���� ������ �־� ����, �������� ������ �����µ�
//������ �ִ� ������ ������ ���ϵ� �߿� �ִ�? �� ������ �����.
//aho-corasick: ���� ������ �־�����, �ϳ��� �� ���ڿ��� �����µ�
//�� ���ڿ� �ȿ� ���ϵ��� ��� �����ϴ�? �� ������ �����.

//aho-corasick���� '� ������ ���� ��� ã�Ҵ�?'�� ��������
//Node ������ indexes��� �迭�� �ʿ���.  ���� �����ڷ� ����.

struct Node{   //�� ������ ������ ��� ã�Ҵϰ� �ƴ϶� ���� ���θ� �����Ƿ� indexes�ʿ� ����.
	bool valid;
	int child[26];
	int pi;
	Node(){
		for (int i = 0; i < 26; i++){
			child[i] = -1;
		}
		valid = false;
		pi = -1;
	}
};
vector<Node> trie;

int make_node(){
	trie.push_back({});
	return (int)trie.size() - 1;
}

void make_trie(int root, string& s){   //Ʈ���� ����� ����� ����.
	int node = root;
	for (int i = 0; i < s.size(); i++){
		int c = s[i] - 'a';
		if (trie[node].child[c] == -1){
			int next = make_node();
			trie[node].child[c] = next;
		}
		node = trie[node].child[c];
	}
	trie[node].valid = true;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int root = make_node();
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		string s;
		cin >> s;
		make_trie(root, s);
	}
	queue<int> q;
	trie[root].pi = root;  //���������� pi�� ��Ʈ�� �� �� �ۿ� ����.
	q.push(root);
	while (!q.empty()){
		int cur = q.front();
		q.pop();
		for (int i = 0; i < 26; i++){  //������ġ cur���� ������ġ next�� pi�� �������ش�.
			int next = trie[cur].child[i];
			if (next == -1)
				continue;
			if (cur == root){
				trie[next].pi = root;
			}
			else{
				int x = trie[cur].pi;
				while (x != root && trie[x].child[i] == -1){
					x = trie[x].pi;
				}
				if (trie[x].child[i] != -1){
					x = trie[x].child[i];
				}
				trie[next].pi = x;
			}
			int pi = trie[next].pi;
			trie[next].valid |= trie[pi].valid;   //�̰� �ȳ����� 100%���� Ʋ����!!!!!!!!!!! ����.
			q.push(next);
		}
	}
	int m;
	cin >> m;
	for (int qq = 0; qq < m; qq++){
		string s;
		cin >> s;
		int node = root;
		bool isYes = false;
		for (int i = 0; i < s.size(); i++){
			int c = s[i] - 'a';
			while (node != root&& trie[node].child[c] == -1){
				node = trie[node].pi;
			}
			if (trie[node].child[c] != -1){
				node = trie[node].child[c];
			}
			if (trie[node].valid){
				isYes = true;
				break;
			}
		}
		cout << (isYes ? "YES" : "NO") << "\n";
	}
	return 0;
}