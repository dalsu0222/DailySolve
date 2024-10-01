#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, result;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	vector<int> S(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> S[i];
	}
	vector<int> c(10, 0);	// 등장한 종류(0~9) 갯수 저장
	int l = 0, r = 0;
	while (r < n) {
		c[S[r++]]++;	// 오른쪽으로 꼬치 과일 확보
		while (10 - count(c.begin(), c.end(), 0) > 2) {	// 종류가 2개 초과라면
			c[S[l++]]--;	// 종류가 2개 이하가 되면, 좌측 포인터의 전진을 멈춤. 확보한 맨 좌측의 꼬치 과일 버리기.
		}
		result = max(result, r - l);	// l ~  r-1 까지가 현재 확보된 꼬치 과일 개수.
	}
	cout << result;
	

	return 0;
}
