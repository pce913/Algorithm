//2751��: �� �����ϱ�2 ������ �˼� �Ϸ�.
template <typename T>
void swap(T& x, T& y){
	T temp = x;
	x = y;
	y = temp;
}

template <typename T>
void sort(T arr,int start,int end) { //vector�� ���Ľ�Ű�� ������ T�� T&�� �ٲ���� �Ѵ�.
	if (start >= end)
		return;
	int left = start;
	int right = end;
	int pivot = arr[(start + end) / 2];
	while (true) {
		while (arr[left] < pivot){
			left++;
		}
		while (arr[right] > pivot){
			right--;
		}
		if (left >= right)
			break;
		swap(arr[left], arr[right]);
	}
	sort(arr,start, left - 1);
	sort(arr,right + 1, end);
}