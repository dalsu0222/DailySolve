#include <iostream>

using namespace std;
int dp[50001];	//  dp[i] = i를 최소 개수의 제곱 합으로 표현했을 때 개수
int n;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		dp[i] = dp[i - 1] + 1;	// 초기화
		for (int j = 1; j * j <= i; j++) {	// i보다 작은 제곱수들을 이용하여 최소갯수 구하기
			dp[i] = min(dp[i], dp[i - j * j] + 1);	// dp[j*j] + (n-j*j == k^2,다른제곱수)
		}
	}
	cout << dp[n];

	return 0;
}
