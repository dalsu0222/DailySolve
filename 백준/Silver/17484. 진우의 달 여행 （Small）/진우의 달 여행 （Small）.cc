#include <iostream>
#include <stack>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	int map[10][10], dp[7][7][3];		// DP[i][j][직전에 온 방향(왼쪽 위, 위, 오른쪽 위)] 

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];

			// 초기화
			dp[i][j][0] = dp[i][j][1] = dp[i][j][2] = map[i][j];
			if (j == 0) dp[i][j][0] = 9999;
			if (j == m - 1) dp[i][j][2] = 9999;
		}
	}

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < m; j++) {

			// 이전에 선택한 방향을 제외한 방향 중에서 최솟값 선택
			if (j != 0)
				dp[i][j][0] += min(dp[i - 1][j - 1][1], dp[i - 1][j - 1][2]);

			dp[i][j][1] += min(dp[i - 1][j][0], dp[i - 1][j][2]);

			if (j != m - 1)
				dp[i][j][2] += min(dp[i - 1][j + 1][0], dp[i - 1][j + 1][1]);
		}
	}

	int result = 9999;
	for (int j = 0; j < m; j++) {
		for (int k = 0; k < 3; k++) {	//	직전 방향 중 가장 작은 값 선택
			result = min(result, dp[n - 1][j][k]);
		}
	}
	cout << result;

	return 0;
}