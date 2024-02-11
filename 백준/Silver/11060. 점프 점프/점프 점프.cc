#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;
int N;
int arr[1001];
int dp[1001];	// dp[i] = i번째 칸까지 올 수 있는 최소 점프 수

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);     // 시간초과방지

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	fill(dp, dp + 1001, 1e6);	// 임의의 큰 수로 dp 배열 초기화
	dp[1] = 0;	

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= arr[i]; j++) {
			if (i + j <= N) {	// 점프하고자 하는 곳이 크기 N이하의 범위라면
				dp[i + j] = min(dp[i] + 1, dp[i + j]);	// 기존 점프수와 새로 점프하는 수 중 최솟값 선택
			}
		}
	}

	if (dp[N] == 1e6)
		cout << "-1";
	else
		cout << dp[N];

	return 0;
}