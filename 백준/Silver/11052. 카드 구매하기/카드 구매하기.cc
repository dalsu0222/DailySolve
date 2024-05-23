#include <iostream>

using namespace std;
int n;
int dp[1001];	// dp[i] : i개 카드를 구매할때의 최대 비용
int cost[1001];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> cost[i];
	}

	dp[1] = cost[1];	// 1개 구매 비용은 cost[1]과 동일
	for (int i = 2; i <= n; i++) {	
		// i개의 카드 구매비용의 최대를 구하면 된다.
		// j개 카드 구매비용 + i-j 개의 카드를 구매하는 최대금액
		for (int j = 1; j <= i; j++) {	// 1~i개의 카드 활용
			dp[i] = max(dp[i], cost[j] + dp[i - j]);
		}

	}
	cout << dp[n];

	return 0;
}