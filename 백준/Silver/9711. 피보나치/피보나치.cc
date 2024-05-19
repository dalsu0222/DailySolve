#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
long long dp[10001];	// 시간초과 방지 -> 재귀대신 dp로 풀이
long long p, q;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);	// 추가
	int t;
	cin >> t;

	
	for (int tc = 1; tc <= t; tc++) {
		cin >> p >> q;
		dp[1] = 1 % q;			// 초기화값도 q로 나눈 나머지로 저장
		dp[2] = 1 % q;			
		for (int i = 3; i <= p; i++) {
			dp[i] = (dp[i - 1] + dp[i - 2]) % q;
		}
		cout << "Case #" << tc << ": " << dp[p] << "\n";
	}

	return 0;
}