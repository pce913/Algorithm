//7469��: k��° ���� ������ �˼� �Ϸ�.
template <typename T>
int upper_bound(T arr, int start, int end, int value){   //arr�� vector�϶��� T& �� ���־�� �Ѵ�.
	int left = start;
	int right = end;
	int ans = 0;     //lower_bound�ʹ� �ٸ��� �ʱ�ȭ�� 0���� ����� �Ѵ�.
	while (left <= right){
		int mid = (left + right) >> 1;
		if (arr[mid] <= value){
			ans = mid + 1;   //upper_bound�� ��� ���� ū�͵� �� �ٷ� ���� ��ġ�� ����Ű�� �����Ƿ� mid+1; 
			left = mid + 1;
		}
		else{
			right = mid - 1;
		}
	}
	return ans;
}