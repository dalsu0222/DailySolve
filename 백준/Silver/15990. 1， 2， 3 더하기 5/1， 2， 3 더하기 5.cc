#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>
#define MAX 100000
#define MOD 1000000009
// 표기 편의상 MAX,MOD를 미리 지정

using namespace std;

int T;
int n;
long long dp[MAX + 1][4];	// long long으로 변경

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);     // 시간초과방지

	// dp[n][1] = n을만드는데 마지막에 오는 수가 1인 경우
	dp[1][1] = 1;
	dp[2][2] = 1;
	dp[3][3] = dp[3][2] = dp[3][1] = 1;

	for (int i = 4; i <= MAX; i++) {	
		// dp[i][k] = i를 만드는데 마지막에 오는 수가 k이면,
		// 수 k를 제외한 수로 구성이 되어야 하므로 
		// dp[i-k]에서 k(1~3 중 1개)를 제외한 나머지 수(1~3중 앞에서 선택된 수 외 나머지 2개)가 와야한다.
		dp[i][1] = (dp[i - 1][2] + dp[i - 1][3]) % MOD;
		dp[i][2] = (dp[i - 2][1] + dp[i - 2][3]) % MOD;
		dp[i][3] = (dp[i - 3][2] + dp[i - 3][1]) % MOD;
	}

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> n;
		// dp[n][1] 당 약 10억정도 표현, 세 개를 합쳤을때 결과가 21억을 초과하므로, long long 으로 결과 선언
		long long result = (dp[n][1] + dp[n][2] + dp[n][3]) % MOD;
		cout << result << "\n";
	}

	return 0;
}