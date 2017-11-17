//���� �����ڷ� �״��. �˼� �Ϸ�.
template <typename T>
void swap(T& a,T& b){
	T temp = a;
	a = b;
	b = temp;
}

template <typename T>
bool next_permutation(T a[],int n){
	int i = n - 1;   //�ڿ������� ����.
	while (i > 0 && a[i - 1] >= a[i]){
		i--;
	}
	if (i <= 0){
		return false;  //������ ����
	}
	int j = n - 1;
	while (a[j] <= a[i - 1]){
		j--;
	}
	swap(a[i - 1], a[j]);
	j = n - 1;
	while (i < j){        //a[i]���� ������ �����´�.
		swap(a[i], a[j]);
		i++;
		j--;
	}
	return true;
}