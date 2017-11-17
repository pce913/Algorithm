//10845��: ť ������ �˼� �Ϸ�
template <typename T>
struct queue{
	T* arr;
	int n;    //  ����ִ� ����
	int ffront, rear;    //������ ffront, �������� rear
	queue(){
		arr = new T[10000005];
		n = 0;
		rear = 0, ffront = 0;
	}
	~queue(){
		delete[] arr;
	}
	void push(T t){
		arr[rear++] = t;
		n++;
	}
	T front(){
		return arr[ffront];
	}
	T back(){
		return arr[rear - 1];
	}
	int size(){
		return n;
	}
	void pop(){
		ffront++;
		n--;
	}
	bool empty(){
		return n == 0;
	}
};