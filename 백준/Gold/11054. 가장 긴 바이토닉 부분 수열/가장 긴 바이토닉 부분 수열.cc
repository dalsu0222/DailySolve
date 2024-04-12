#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;
int N;
int input[1001];
int dp[1001];
int rdp[1001];
int result;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// (증가하는 부분수열의 크기 + 감소하는 부분수열의 크기) - 1 값 중 최댓값.
	// -1 을 하는 이유? -> 바이토닉 부분수열에서 최댓값은 중복이 되므로, 1개를 제외시켜주기
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> input[i];
	}
	for (int i = 1; i <= N; i++) {	// 증가하는 부분 수열 구하기
		dp[i] = 1;
		for (int j = 1; j < i; j++) {
			if (input[j] < input[i])
				dp[i] = max(dp[i], dp[j] + 1);
		}
	}
	for (int i = N; i >= 1; i--) {	// 감소하는 부분 수열 구하기
		rdp[i] = 1;
		for (int j = N; j > i; j--) {
			if (input[i] > input[j])
				rdp[i] = max(rdp[i], rdp[j] + 1);
		}
	}
	
	for (int i = 1; i <= N; i++) {	// 최댓값 갱신, (증가하는 부분수열의 크기 + 감소하는 부분수열의 크기) - 1 
		if (result < dp[i] + rdp[i] - 1)
			result = dp[i] + rdp[i] - 1;
	}
	cout << result;


	return 0;
}