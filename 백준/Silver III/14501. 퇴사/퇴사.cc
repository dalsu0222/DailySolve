#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;
int N;
int T, P;
vector<pair<int, int>> v;
int dp[17];		// dp[i] = i번째 날까지 할 수 있는 최대 이익

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);     // 시간초과방지

	cin >> N;
	v.push_back(make_pair(0, 0));	// 1 ~ N 사용을 위한 작업
	for (int i = 0; i < N; i++) {
		cin >> T >> P;
		v.push_back(make_pair(T, P));
	}

	int last;
	for (int i = N; i > 0; i--) {	// N일부터 거꾸로 진행
		last = i + v[i].first;
		if (last > N + 1) {	// 상담 끝나는 시점이 퇴사 이후인 경우(마지막날 1일짜리 상담은 가능)
			dp[i] = dp[i + 1];	// 상담 불가
		}
		else {
			dp[i] = max(dp[i + 1], dp[last] + v[i].second);	// 상담을 안하고 넘어가기 or 상담 하고 넘어가기 중에 큰 값 선택
		}
	}

	cout << dp[1];

	return 0;
}