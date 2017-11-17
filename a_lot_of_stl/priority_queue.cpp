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