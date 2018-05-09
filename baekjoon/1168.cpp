//#include<stdio.h>
//
//int tree[100005];
//int n, k;
//void update(int x,int value){
//	for (int i = x; i <= n; i += i&-i){
//		tree[i] += value;
//	}
//}
//
//int query(int x){
//	int ans = 0;
//	for (int i = x; i > 0; i -= i&-i){
//		ans += tree[i];
//	}
//	return ans;
//}
//
//int main(){
//	scanf("%d %d", &n, &k);
//	for (int i = 1; i <= n; i++){
//		update(i, 1);
//	}
//	int last = 0;
//	printf("<");
//	for (int i = n; i >= 1; i--){
//		int pre = 0;              // ���� ��ġ �տ� ��� �ִ�?
//		if (last != 0){
//			//pre = sum(tree, 1, 1, n, 1, last - 1);
//			pre = query(last - 1);
//		}
//		int index = (pre + k) % i;      // �����۽� �����̹Ƿ� �ε����� �ٽ� ������ �� ��츦 ����ؼ� %i
//		if (index == 0){                //���� �͵� �߿� ���°��? �� �����ϰ� �ִ°��� index�̴�.
//			index = i;
//		}
//		last = query(tree, 1, 1, n, index);
//		last=
//		printf("%d", last);
//		if (i != 1){
//			printf(", ");
//		}
//		update(tree, 1, 1, n, last, -1);
//	}
//	printf(">");
//	return 0;
//}
#include<stdio.h>
int tree[4 * 100005];
void init(int node,int start,int end){
	if (start == end){
		tree[node] = 1;
	}
	else{
		init(2 * node, start, (start + end) / 2);
		init(2 * node + 1, (start + end) / 2+1,end );
		tree[node] = tree[2 * node] + tree[2 * node + 1];
	}
}

void update(int node, int start, int end,int i,int value){
	if (i > end || i < start)
		return;
	tree[node] += value;
	if (start != end){
		update(2 * node, start, (start + end) / 2, i, value);
		update(2 * node + 1, (start + end) / 2 + 1, end, i, value);
	}
}

int sum(int node, int start, int end,int left,int right){
	if (left > end || right < start){
		return 0;
	}
	if (left <= start && right >= end){
		return tree[node];
	}
	return sum(2 * node, start, (start + end) / 2, left, right) +
		sum(2 * node + 1, (start + end) / 2 + 1, end, left, right);
}

int query(int node, int start, int end, int k){
	if (start == end){
		return start;
	}
	if (k <= tree[2 * node]){    // go left
		return query(2 * node, start, (start + end) / 2, k);
	}
	else{   //go right   ����
		return query(2 * node + 1, (start + end) / 2+1, end, k - tree[2 * node]);
	}
}

int main(){
	int n, k;
	scanf("%d %d",&n,&k);
	init(1, 1, n);
	int last = 0;
	printf("<");
	for (int i = n; i >=1; i--){
		int pre = 0;              // ���� ��ġ �տ� ��� �ִ�?
		if (last != 0){
			pre = sum(1, 1, n, 1, last - 1);
		}
		int next = (pre + k) % i;      // �����۽� �����̹Ƿ� �ε����� �ٽ� ������ �� ��츦 ����ؼ� %i
		if (next == 0){               //(pre + k) % i �� ���� �ε����� ���Ѵ�.
			next = i;                 //���� ���� �ִ� �༮���߿� ���°��? �� �����ϰ� �ִ°��� index �̴�.
		}
		last = query(1, 1, n, next);    //�����۽� ���� ��ġ�� ������.
		printf("%d",last);
		if (i != 1){
			printf(", ");
		}
		update(1, 1, n, last, -1);
	}
	printf(">");
	return 0;
}