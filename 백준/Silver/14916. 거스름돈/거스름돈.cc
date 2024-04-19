#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
int n;

int main(void)
{
	/* 
		일단 최대한 5원짜리를 쓰고,
		남은돈에서 만약 잔돈이 2원짜리로 나누어 떨어지지않는다면 
		5원을 1개 덜 쓰고 잔돈을 2원짜리로 나누는 방식의 반복을 이용
	*/
	cin >> n;
	int five = n / 5;		// 최대한의 5원짜리 동전개수 활용
	int r = (n - five * 5) % 2;
	while (r != 0) {	// 잔돈이 2원짜리로 나누어떨어질때까지 진행
		if (five == 0) {
			cout << -1;
			return 0;
		}
		five -= 1;	// 5원짜리 동전 1개를 줄이기
		r = (n - five * 5) % 2;	// 5원짜리 동전 제외 나머지를 2원으로 나눠떨어지는지 여부 갱신
	}
	cout << five + (n - five * 5) / 2;	// 5원짜리 + 2원짜리 동전개수 

	return 0;
}