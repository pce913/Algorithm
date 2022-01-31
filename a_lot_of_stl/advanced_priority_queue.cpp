
/*
*  임의의 원소를 삭제, 변경 가능한 priority_queue
* 
	http://www.secmem.org/blog/2020/08/16/heap/
	백준 7785번 회사에 있는 사람 문제로 검수 완료.
*/

template <typename T>
struct Elem {
	T val;
	int id;
	bool operator< (const Elem& e)const {
		if (val != e.val) {
			return val < e.val;
		}
		return id < e.id;
	}
};

template <typename T>
void swap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

template <typename T>
struct priority_queue {
	Elem* heap;
	int* pos;
	int n = 0;
	priority_queue() {
		heap = new Elem[10000005];
		pos = new int[10000005];
		n = 0;
	}
	~priority_queue() {
		delete[] heap;
		delete[] pos;
	}
	void push(int id, T value) {
		heap[n++] = { id, value };
		pos[id] = n - 1;
		up(n - 1);
	}

	void up(int node) {
		while (node > 0 && heap[(node - 1) / 2] < heap[node]) {
			swap(pos[heap[(node - 1) / 2].id], pos[heap[node].id]);
			swap(heap[(node - 1) / 2], heap[node]);			
			node = (node - 1) / 2;
		}
	}

	void pop() {
		heap[0] = heap[n - 1];
		n--;
		pos[heap[0].id] = 0;
		down(0);
	}

	void down(int node) {
		while (true) {
			int left = 2 * node + 1;
			int right = 2 * node + 2;
			if (left >= n)
				break;
			int next = node;
			if (heap[next] < heap[left]) {
				next = left;
			}
			if (right < n && heap[next] < heap[right]) {
				next = right;
			}
			if (next == node)
				break;
			swap(pos[heap[node].id], pos[heap[next].id]);
			swap(heap[node], heap[next]);
			node = next;
		}
	}

	void del(int id) {
		int node = pos[id];
		T origin = heap[node].val;
		heap[node] = heap[n - 1];
		n--;
		pos[heap[node].id] = node;
		if (heap[node].val < origin) {
			down(node);
		}
		else {
			up(node);
		}
	}

	void change(int id, T value) {
		int node = pos[id];
		T origin = heap[node].val;
		heap[node].val = value;
		if (heap[node].val < origin) {
			down(node);
		}
		else {
			up(node);
		}
	}

	T top() {
		return heap[0].val;
	}
	bool empty() {
		return n == 0;
	}
};