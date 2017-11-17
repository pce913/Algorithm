//1707��: �̺� �׷��� ������ �˼� �Ϸ�.
template <typename T>
struct vector{
	const int DEFAULT_SZ = 256;
	int n;
	int sz;
	T* arr;
	vector<T>(){    //done
		n = 0;
		sz = DEFAULT_SZ;
		arr = new T[DEFAULT_SZ];
	}
	~vector<T>(){    //done
		delete[] arr;
	}
	void resize(int _n){   //done
		delete[] arr;
		arr = new T[_n];
		n = _n;
		sz = _n;
	}
	int size(){     //done
		return n;
	}
	void push_back(T x){
		if (n == sz){
			vector<T> t;   //����� ���ÿ� ������ �ϸ� ���� �𸣰����� ���۷��� ���°� �ȴ�. 
			t = *this;    //���� ���ٷ� �и� ���״�.
			sz *= 2;
			delete[] arr;
			arr = new T[sz];
			for (int i = 0; i < t.size(); i++){
				arr[i] = t[i];
			}
		}
		arr[n++] = x;
	}

	void operator=(const vector<T>& t){   //���⿡ �ٴ� const���� �� ���־߸� ���ο��� resize, size�� ���� �Լ� ȣ���� �����ϴ�.
		n = t.n;
		sz = t.sz;
		delete[] arr;
		arr = new T[sz];
		for (int i = 0; i < n; i++){  //�ִ°� n��ŭ�� �ִ´�.
			arr[i] = t[i];
		}
	}
	T& operator[](const int& i)const{
		return arr[i];
	}
	T* begin(){
		return arr;
	}
	T* end(){
		return arr + n;
	}
	void clear(){
		n = 0;
		sz = DEFAULT_SZ;
		delete[] arr;
		arr = new T[sz];
	}
	void pop_back(){
		n--;
	}
};