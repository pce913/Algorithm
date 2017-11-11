#include<stdio.h>
#include<algorithm>
using namespace std;

struct Triangle{
	int x, y, r;
	Triangle(int _x, int _y, int _r){
		x = _x, y = _y, r = _r;
	}
	Triangle(){}
	bool operator==(const Triangle& t)const{
		return x == t.x && y == t.y && r == t.r;
	}
};
Triangle triangle[15];

Triangle area_of_overlapped_triangle(Triangle a, Triangle b){
	if (a.x > b.x)
		swap(a, b);
	int dx = b.x - a.x;
	a.x += dx;    //�� �ڵ尡 �ݵ�� �־�߸� ��� ��츦 ó�� �� �� �ִ�. �ؿ� if (a.y > b.y)���� swap�� ��츦 ó���ϱ� �����̴�.
	a.r -= dx;
	if (a.r <= 0)  //��ġ�� �ʴ� �ﰢ���϶�
		return{ 0, 0, 0 };

	if (a.y > b.y)
		swap(a, b);
	b.r = min(b.r, a.r - (b.y - a.y));    //y�κ� ������ �Ͼ�� b.r�� ���� �ǰ� ���Ͼ�� a.r - (b.y - a.y)�� ���� �ȴ�.
	if (b.r <= 0)
		return{ 0, 0, 0 };
	else{
		return b;
	}
}

int main(){
	int n;
	scanf("%d",&n);
	for (int i = 0; i < n; i++){
		scanf("%d %d %d", &triangle[i].x, &triangle[i].y, &triangle[i].r);
	}
	long long ans = 0;   //����-���� ���� ���
	for (int bit = 1; bit < (1 << n); bit++){   // �������� �����Ƿ� 1���� ����
		int cnt = 0;
		Triangle temp;
		bool isOverLap = true;
		for (int i = 0; i < n; i++){
			if (bit&(1 << i)){
				cnt++;
				if (cnt == 1){
					temp = triangle[i];
				}
				else{
					temp = area_of_overlapped_triangle(temp, triangle[i]);
				}

				if (temp == Triangle(0, 0, 0)){
					isOverLap = false;
					break;
				}
			}
		}

		if (isOverLap){
			int r = temp.r;
			if (cnt & 1){   //(1LL << (cnt - 1)) �� �̰��� �����ִ��� �׷����ϱ� ��Ȯ�� �˰ڴ�.
				ans += (long long)(1LL << (cnt - 1))*r*r;   //��ġ�� �༮
			}
			else{
				ans -= (long long)(1LL << (cnt - 1))*r*r;
			}
		}
	}
	printf("%lld.%d",ans/2,(ans%2)*5);
}