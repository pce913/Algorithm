#include<stdio.h>

//1753��: �ִ� ��� ������ �˼� �Ϸ�.
template <typename T>
void swap(T& a,T& b){
	T temp = a;
	a = b;
	b = temp;
}

template <typename T>
struct priority_queue{
	T* heap;    //Ȥ�ó� �迭 ũ�Ⱑ �ʹ� ũ�ٰ� �Ǵܵ� ��쿡�� �� �κ��� vector�� �ٲ���. �迭�� �̸� ��Ƴ����� stack �޸𸮰� �ʰ� �ǹǷ� ���� �Ҵ� ����.
	int n = 0;
	priority_queue(){
		heap = new T[10000005];
		n = 0;
	}
	~priority_queue(){
		delete[] heap;
	}
	void push(T value){
		heap[n++] = value;
		int node = n - 1;
		//��Ʈ�� �����ϰų� value�̻��� ���Ҹ� ���� ������ ���� ������ �ݺ�
		while (node > 0 && heap[(node - 1) / 2] < heap[node]){
			swap(heap[(node - 1) / 2], heap[node]);
			node = (node - 1) / 2;
		}
	}
	void pop(){
		heap[0] = heap[n - 1];
		n--;
		int node = 0;
		while (true){
			int left = 2 * node + 1;
			int right = 2 * node + 2;
			if (left >= n)  //���� ��忡 ���� ������
				break;
			int next = node;
			if (heap[next] < heap[left]){  //���� operator< �� ����ϹǷ� �� ������ ����Ҷ� '<' �� ���ִ°� ����. 
				next = left;
			}
			if (right < n && heap[next] < heap[right]){
				next = right;
			}
			if (next == node)  //�� �ڼ��� ��� �ڱ� �ڽ� ������ ���Ҹ� ������ ������
				break;
			swap(heap[node], heap[next]);
			node = next;
		}
	}
	T top(){
		return heap[0];
	}
	bool empty(){
		return n == 0;
	}
};

template <typename T>
struct ppriority_queue{
	int n;
	T* heap;
	ppriority_queue(){
		n = 0;
		heap = new T[10000005];
	}
	~ppriority_queue(){
		delete[] heap;
	}
	void push(T x){
		heap[n++] = x;
		int node = n - 1;
		while (node > 0 && heap[(node - 1) / 2] < heap[node]){
			swap(heap[node], heap[(node - 1) / 2]);
			node = (node - 1) / 2;
		}
	}
	void pop(){
		heap[0] = heap[n - 1];
		n--;
		int node = 0;
		while (true){
			int left = 2 * node + 1;
			int right = 2 * node + 2;
			if (left >= n){   //���������� �����Ѱ��
				break;
			}
			int next = node;
			if (heap[next] < heap[left]){
				node = left;
			}
			if (right < n && heap[next] < heap[right]){
				node = right;
			}
			if (next == node)
				break;
			swap(heap[node], heap[next]);
			node = next;
		}
	}
	T top(){
		return heap[0];
	}
	bool empty(){ return n == 0; }
};

template<typename T>
struct ppriority_queue{
	int n;
	T* heap;
	ppriority_queue(){
		n = 0;
		heap = new T[100005];
	}
	~ppriority_queue(){
		delete[] heap;
	}
	void push(T x){
		heap[n++] = x;
		int node = n - 1;
		while (node > 0 && heap[(n - 1) / 2] < heap[node]){
			swap(heap[(n - 1) / 2], heap[node]);
			node = (n - 1) / 2;
		}
	}
	void pop(){
		heap[0] = heap[n - 1];
		n--;
		int node = 0;
		while (true){
			int left = 2 * node + 1, right = 2 * node + 2;
			if (left >= n)
				break;
			int next = node;
			if (heap[next] < heap[left]){
				next = left;
			}
			if (right < n && heap[next] < heap[right]){
				next = right;
			}
			if (next == node)
				break;
			swap(heap[next], heap[node]);
			node = next;
		}
	}
}


//***********  vector ����
//template <typename T>
//struct priority_queue{
//	vector<T> heap;    //Ȥ�ó� �迭 ũ�Ⱑ �ʹ� ũ�ٰ� �Ǵܵ� ��쿡�� �� �κ��� vector�� �ٲ���. �迭�� �̸� ��Ƴ����� stack �޸𸮰� �ʰ� �ǹǷ� ���� �Ҵ� ����.
//	void push(T value){
//		heap.push_back(value);
//		int node = (int)heap.size() - 1;
//		//��Ʈ�� �����ϰų� value�̻��� ���Ҹ� ���� ������ ���� ������ �ݺ�
//		while (node > 0 && heap[(node - 1) / 2] < heap[node]){
//			swap(heap[(node - 1) / 2], heap[node]);
//			node = (node - 1) / 2;
//		}
//	}
//	void pop(){
//		heap[0] = heap.back();
//		heap.pop_back();
//		int node = 0;
//		while (true){
//			int left = 2 * node + 1;
//			int right = 2 * node + 2;
//			if (left >= heap.size())  //���� ��忡 ���� ������
//				break;
//			int next = node;
//			if (heap[next] < heap[left]){  //���� operator< �� ����ϹǷ� �� ������ ����Ҷ� '<' �� ���ִ°� ����. 
//				next = left;
//			}
//			if (right < heap.size() && heap[next] < heap[right]){
//				next = right;
//			}
//			if (next == node)  //�� �ڼ��� ��� �ڱ� �ڽ� ������ ���Ҹ� ������ ������
//				break;
//			swap(heap[node], heap[next]);
//			node = next;
//		}
//	}
//	T top(){
//		return heap[0];
//	}
//	bool empty(){
//		return heap.empty();
//	}
//};

struct Edge{
	int to, cost;
	Edge(){}
	Edge(int _to, int _cost) :to(_to), cost(_cost){}
	bool operator<(const Edge& e)const{
		return this->cost > e.cost;
	}
};

int main(){
	//ppriority_queue<int> q;
	//q.push(3);
	//q.push(6);
	//q.push(2);
	//while (!q.empty()){
	//	printf("%d ", q.top());
	//	q.pop();
	//}
	ppriority_queue<Edge> qq;
	qq.push(Edge(1, 15));
	qq.push(Edge(2, 17));
	qq.push(Edge(3, 10));
	qq.push(Edge(2, 5));
	while (!qq.empty()){
		printf("%d %d\n", qq.top().to, qq.top().cost);
		qq.pop();
	}
	return 0;
}