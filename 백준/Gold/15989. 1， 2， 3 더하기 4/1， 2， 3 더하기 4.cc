#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;
int T;
int n;
int dp[10001][4];	// dp[i][j] : 정수 i를 만들 때 마지막으로 더한 수가 j인 경우의 수 저장

int main(void)
{
	/* 
	중복되지 않는 가짓수를 구하기 위해, 정수 i를 만들 때 오름차순으로만 더할 수 있다고 가정
	*/
	dp[1][1] = 1;
	dp[2][1] = 1;   dp[2][2] = 1;
	dp[3][1] = 1;   dp[3][2] = 1;   dp[3][3] = 1;

	for (int i = 4; i <= 10000; i++) {	
		// // 수를 분해했을때 마지막 수가 1->dp[n-1] , 2->dp[n-2], 3->dp[n-3]
		dp[i][1] = dp[i - 1][1];	// 정수 i를 만들 때 1로 끝나는 경우  -> 그 이전에 1만 올 수 있음
		dp[i][2] = dp[i - 2][1] + dp[i - 2][2];	//정수 i를 만들 때 2로 끝나는 경우 -> 그 이전에 1,2 올 수 있음
		dp[i][3] = dp[i - 3][1] + dp[i - 3][2] + dp[i - 3][3];	// 정수 i를 만들 때 3으로 끝나는 경우 -> 그 이전에 1,2,3 올 수 있음 
	}

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> n;
		cout << dp[n][1] + dp[n][2] + dp[n][3] << '\n';
	}

	return 0;
}