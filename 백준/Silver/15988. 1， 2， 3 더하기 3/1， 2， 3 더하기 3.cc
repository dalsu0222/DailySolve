#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int T;
int n;
long long dp[1000001];		// 1<= N <=1,000,000

int main(void)
{
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> n;

		for (int i = 4; i <= n; i++) {	// 수를 분해했을때 마지막 수가 1->dp[n-1] , 2->dp[n-2], 3->dp[n-3]
			dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % 1000000009;
		}

		cout << dp[n] << '\n';
	}

	return 0;
}