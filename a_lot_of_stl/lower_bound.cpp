#include<stdio.h>
//12015��: ���� �� �����ϴ� �κ� ����2 ������ �˼� �Ϸ�.
template <typename T>
int lower_bound(T arr[],int start,int end,T value){   //arr�� vector�϶��� T& �� ���־�� �Ѵ�.
	int left = start;
	int right = end;
	int ans = end + 1;   //lower_bound�� value���� ���� ��� v.end() �� ����Ű�Ƿ� �̷��� �ʱ�ȭ �Ѵ�.
	while(left <= right){
		int mid = (left + right) >> 1;
		if (value <= arr[mid]){
			ans = mid;
			right = mid - 1;
		}
		else{
			left = mid + 1;
		}
	}
	return ans;
}

template <typename T>
void llower_bound(T arr[],int start,int end,int value){
	int left = start;
	int right = end;
	int ans = end + 1;
	while (left <= right){
		int mid = (left + right) >> 1;
		if (value <= arr[mid]){
			ans = mid;
			right = mid - 1;
		}
		else
			left = mid + 1;
	}
	return ans;
}


//template <typename T>
//void llower_bound(T arr,int start,int end,int value){
//	int left = start;
//	int right = end;
//	int ans = end + 1;
//	while (left <= right){
//		int mid = (left + right) >> 1;
//		if (value <= arr[mid]){
//			ans = mid;
//			right = mid - 1;
//		}
//		else{
//			left = mid + 1;
//		}
//	}
//	return ans;
//}



int main(){
	int a[15] = { 0, 1, 4, 9, 16, 20, 20, 20, 20, 20, 20, 20 };
	printf("%d", lower_bound(a, 0, 11, 12));
	return 0;
}