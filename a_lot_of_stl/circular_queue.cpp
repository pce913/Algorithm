//���� 1260 DFS�� BFS ������ ���� �Ϸ�.
template<typename T>
struct queue{
	int n;
	T* arr;
	int sz;
	int ffront, rear;
	queue(){
		n = rear = ffront = 0;
		sz = 2;
		arr = new T[sz];
	}
	~queue(){
		delete[] arr;
	}
	void push(T x){
		if (n == sz){
			T* temp = new T[sz];
			for (int i = 0; i < n; i++)
				temp[i] = arr[i];
			delete[] arr;
			arr = new T[2 * sz];
			rear = (rear - 1 + sz) % sz;
			int idx = 0;
			while (rear != ffront){   //�̷����ϸ� ������ �ϳ��� �ȵ��� �ȴ�.
				arr[idx++] = temp[ffront];
				ffront = (ffront + 1) % sz;
			}
			arr[idx] = temp[ffront];
			sz *= 2;
			ffront = 0;
			rear = idx + 1;
			delete[] temp;
		}
		arr[rear] = x;
		rear = (rear + 1) % sz;
		n++;
	}
	T front(){
		return arr[ffront];
	}
	void pop(){
		ffront = (ffront + 1) % sz;
		n--;
	}
	bool empty(){
		return n == 0;
	}
};