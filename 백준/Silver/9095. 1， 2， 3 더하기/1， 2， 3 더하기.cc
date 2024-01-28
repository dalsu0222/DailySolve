#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int T;
int n;
int dp[12];		// 1<= N <=11	

int main(void)
{
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	for (int i = 4; i <= 11; i++) {	// 수를 분해했을때 마지막 수가 1->dp[n-1] , 2->dp[n-2], 3->dp[n-3]
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];	
	}

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> n;
		cout << dp[n] << '\n';
	}

	return 0;
}