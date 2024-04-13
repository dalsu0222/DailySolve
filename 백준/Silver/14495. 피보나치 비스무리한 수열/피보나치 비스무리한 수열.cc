#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;
int N;
int n;
long long dp[117];	// 자료형 int-> ll 변경

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	dp[1] = dp[2] = dp[3] = 1;	// 초기화
	for (int i = 4; i <= n; i++) {	
		//  n번째 피보나치 비스무리한 수열( f(n) = f(n-1) + f(n-3) 만족)
		dp[i] = dp[i - 1] + dp[i - 3];
	}
	cout << dp[n];

	return 0;
}