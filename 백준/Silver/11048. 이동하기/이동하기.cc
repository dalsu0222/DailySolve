#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;
int N, M;
int map[1001][1001];
int dp[1001][1001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);

	/* 
		dp[i][j] -> 해당 위치에서 얻을 수 있는 사탕 개수의 최댓값
		1. 크기 N*M의 방 배열(map)에 사탕 수 입력받기
		2. 0번째 열과 행에 대해 dp배열 초기화 (왼쪽&위쪽으로 이동할 수 없으므로)
		3. 1번째 이상의 열과 행에 대해, dp[i][j] 값 갱신. 올 수 있는 모든 방향인 위&왼쪽&대각선의 세가지 방향 중에서의 최댓값 저장 후 dp[i][j]에 반영
	*/

	cin >> N >> M;
	for (int i = 0; i < N; i++) {	// 1.
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	// 2.
	dp[0][0] = map[0][0];
	for (int i = 1; i < N; i++) {
		dp[i][0] = map[i][0] + dp[i - 1][0];
	}
	for (int j = 1; j < M; j++) {
		dp[0][j] = map[0][j] + dp[0][j - 1];
	}

	for (int i = 1; i < N; i++) {	
		for (int j = 1; j < M; j++) {
			// 3.
			int max_v = max(dp[i - 1][j], dp[i][j - 1]);
			int max_v2 = max(max_v, dp[i - 1][j - 1]);
			dp[i][j] = map[i][j] + max_v2;
		}
	}

	/* dp 값 확인
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << dp[i][j] << " ";
		}
		cout << "\n";
	}
	*/

	cout << dp[N - 1][M - 1];	// (N,M)에서의 최대사탕개수 출력

	return 0;
}