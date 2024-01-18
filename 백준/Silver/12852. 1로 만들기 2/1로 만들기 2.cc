#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int dp[1000001];
vector<int> nums;	// N을 1로 만드는 방법에 해당하는 정답배열

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);     // 시간초과방지

	int N;
	cin >> N;


	// 초기값 세팅
	dp[1] = 0;	dp[2] = dp[3] = 1;
	for (int i = 4; i <= N; i++)
		dp[i] = 1e6;

	// dp 연산 최적화
	// i가 2와 3으로 나누어떨어지는 경우 최솟값 갱신해주고,
	// 그 이후에 1로 빼는 경우와 비교하여 최솟값을 또 갱신해준다.
	for (int i = 2; i <= N; i++) {
		if (i % 2 == 0)
			dp[i] = min(dp[i], dp[i / 2] + 1);
		if (i % 3 == 0)
			dp[i] = min(dp[i], dp[i / 3] + 1);
		dp[i] = min(dp[i], dp[i - 1] + 1);
	}

	cout << dp[N] << "\n";

	while (1) {
		cout << N << " ";
		if (N == 1) break;
		// 값이 최소로 갱신되는 경우, 그 경우에 맞춰 N을 다시 계산해줌
		// 1로 만들기에 해당하는 방법은 총 3가지, 3가지를 모두 고려한다.
		if (dp[N] == dp[N - 1] + 1)
			N -= 1;
		else if (N % 2 == 0 && dp[N] == dp[N / 2] + 1)
			N /= 2;
		else if (N % 3 == 0 && dp[N] == dp[N / 3] + 1)
			N /= 3;
	}

	return 0;
}