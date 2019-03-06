#include<iostream>
using namespace std;
int arr[305] = { 2,1,8,5,4,6,3,7,9,1 };
int tmp[305];
void msort(int src[],int s,int e) {
	if (s >= e)return;
	int mid = (s + e) / 2;
	msort(src, s, mid);
	msort(src, mid + 1, e);
	int left = s, right = mid + 1;
	int idx = s;
	while (left <= mid && right <= e) {
		if (src[left] < src[right]) {
			tmp[idx++] = src[left++];
		}
		else {
			tmp[idx++] = src[right++];
		}
	}
	while (left <= mid)tmp[idx++] = src[left++];
	while (right <= e)tmp[idx++] = src[right++];
	for (int i = s; i < idx; i++)src[i] = tmp[i];
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	msort(arr, 0, 9);
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << " ";
	}
	return 0;
}
