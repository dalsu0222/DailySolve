#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int dp[1000001] = { 0 };

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);     // 시간초과방지

	int N;
	cin >> N;

	// 초기값 세팅	, dp[0]과 dp[1]은 구하지 않으므로 고려하지 않음
	dp[2] = 1;
	dp[3] = 1;	

	// 각각의 수의 최적화된 해(여기서는 연산최소값)의 경우를 잘 살펴보고
	// 그에맞는 dp배열을 구하는 법을 고민해보자

	for (int i = 4; i <= N; i++) {
		if (i % 3 != 0 && i % 2 != 0) {
			dp[i] = 1 + dp[i - 1];
		}
		else if (i % 3 == 0 && i % 2 == 0) {
			dp[i] = min(1 + dp[i / 3], 1 + dp[i / 2]);
		}
		else if (i % 3 == 0) {
			dp[i] = min(1 + dp[i / 3], 1 + dp[i - 1]);
		}
		else if (i % 2 == 0) {
			dp[i] = min(1 + dp[i / 2], 1 + dp[i - 1]);
		}
	}

	cout << dp[N];

	return 0;
}