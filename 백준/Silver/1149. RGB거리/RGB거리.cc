#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;
int N;
int input[3];
int house[1001][3];	// house[i][0] : i번째 집을 빨간색으로 칠할 때 최소비용, house[i][1] : 초록색, house[i][2] : 파란색
// 2차원배열 -> 색깔별로 dp 배열을 각각 만들어서(0~2) 모아둔 것.
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);

	cin >> N;
	house[0][0] = 0;
	house[0][1] = 0;
	house[0][2] = 0;
	for (int i = 1; i <= N; i++) {
		cin >> input[0] >> input[1] >> input[2];	// R,G,B 비용
		/*
		house[i]가 빨강색으로 칠해지기 위해서는 이전 집이 초록색이거나 파란색,
		파란색으로 칠해지기 위해서는 이전 집이 빨강색이거나 초록색,
		초록색으로 칠해지기 위해서는 이전 집이 빨강색이거나 파란색이어야 함.
		*/
		house[i][0] = min(house[i - 1][1], house[i - 1][2]) + input[0];	// 이전집들을 칠한 나머지 두 개의 색 중 최소비용을 선택
		house[i][1] = min(house[i - 1][0], house[i - 1][2]) + input[1];
		house[i][2] = min(house[i - 1][0], house[i - 1][1]) + input[2];
	}
	cout << min(house[N][0], min(house[N][1], house[N][2]));
	
	return 0;
}