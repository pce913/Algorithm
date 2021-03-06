#include<stdio.h>

int order[55];
int a[55];
int main(){
	int n;
	scanf("%d",&n);
	for (int i = 0; i < n; i++){
		scanf("%d",&a[i]);
		order[a[i]] = i;
	}
	order[n] = -1;    //마지막 접미사를 비교할때 사용함
	int ans = 1;
	for (int i = 0; i < n - 1; i++){
		if (order[a[i] + 1] > order[a[i + 1] + 1]){  //a[i+1]중 하나가 마지막 접미사라고 하면 a[i+1]+1은 마지막을 하나 더 너머선 접미사를 의미하게 된다.
			ans++;                               //그 접미사는 빈 문자열이라고 할 수 있고, 빈 문자열은 사전순으로 가장 앞서므로
		}                                          //order[n] = -1; 을 넣어준다.  마지막 접미사는 당연히 1글자로 이루어져 있고,
	}                                             //1글자로 이루어진 글자마저 접미사 배열상의 인덱스가 하나 앞서는 녀석의 시작 글자와 같다면
	printf("%d",ans);                             //접미사 배열상의 순서에 위배 될 수 밖에 없다.(1글자 짜리는 그 글자로 시작하는 녀석들 중에 사전순으로 가장 앞서기 때문이다.)
	return 0;                                     //따라서 1글자 짜리는 접미사 배열상의 인덱스가 하나 앞서는 녀석과는 무조건 다른 글자여야 한다.           
}                                                