#include<stdio.h>
#include<algorithm>
using namespace std;
//7469��: k��° ���� ������ �˼� �Ϸ�.

template <typename T>
int upper_bound(T arr[], int start, int end, T value){   //arr�� vector�϶��� T& �� ���־�� �Ѵ�.
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

template <typename T>
void uupper_bound(T arr[],int start,int end,int value){
	int left = start, right = end;
	int ans = start;
	while (left <= right){
		int mid = (left + right) >> 1;
		if (value >= arr[mid]){
			ans = mid + 1;
			left = mid + 1;
		}
		else
			right = mid - 1;
	}
	return ans;
}

//template<typename T>
//int uupper_bound(T arr[],int start,int end,T value){
//	int left = start;
//	int right = end;
//	int ans = 0;
//	while (left <= right){
//		int mid = (left + right) >> 1;
//		if (arr[mid] <= value){
//			ans = mid + 1;
//			left = mid + 1;
//		}
//		else{
//			right = mid - 1;
//		}
//	}
//	return ans;
//}
//
//
//template <typename T>
//int llower_bound(T arr,int start,int end,int value){
//	int left = start;
//	int right = end;
//	int ans = end + 1;
//	while (left <= right){
//		int mid = (left + right) >> 1;
//		if (arr[mid] >= value){
//			ans = mid;
//			right = mid - 1;
//		}
//		else{
//			left = mid + 1;
//		}
//	}
//	return ans;
//}


int a[17] = { 1, 2, 3, 4, 4, 4, 4, 5, 6, 7, 8, 9, 9, 9, 9, 9 };
int main(){
	printf("%d",uupper_bound(a,0,15,4) - llower_bound(a,0,15,4));
	return 0;
}