#include <iostream>
#define MOD 1000000007

using namespace std;
int n, m;
long long dp[1001][1001];	// (i,j)에 도착하는 경우의 수

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for(int i=1 ; i<=n ; i++){
		for (int j = 1; j <= m; j++) {
			if (i == 1 && j == 1) {
				dp[i][j] = 1;
				continue;
			}
			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1] + dp[i - 1][j - 1]) % MOD;
		}
	}
	cout << dp[n][m];

	return 0;
}
