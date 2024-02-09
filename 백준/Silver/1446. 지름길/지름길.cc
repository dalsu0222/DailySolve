#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
int N, D;
int dp[10001];
vector<pair<int, int>> v[10001];
int s, e, l;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);     // 시간초과방지

	cin >> N >> D;
	for (int i = 0; i < N; i++) {
		cin >> s >> e >> l;
		if (e <= D && e - s > l) {
			v[e].push_back(make_pair(s, l));	// end 지점에 (시작지점,비용) 저장
		}
	}

	dp[0] = 0;
	for (int i = 1; i <= D; i++) {
		// 초기화와 갱신을 동시에 진행
		dp[i] = dp[i - 1] + 1;
		for (int j = 0; j < v[i].size(); j++) {	// i까지의 지름길(v[i])이 존재한다면
			dp[i] = min(dp[i], dp[v[i][j].first] + v[i][j].second);	// 시작지점까지 비용+지름길 비용이 기존비용보다 적다면 갱신
		}
	}
	
	cout << dp[D];

	return 0;
}