#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;
int digit[5][5];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
vector<int> v;

void dfs(int y, int x, int num, int cnt) {
	if (cnt == 6) {
		v.push_back(num);
		return;
	}
	for (int i = 0; i < 4; i++) {
		int new_y = y + dy[i];	// 이웃한 좌표(상하좌우)로 이동
		int new_x = x + dx[i];
		if (0 <= new_y && new_y < 5 && 0 <= new_x && new_x < 5) {
			dfs(new_y, new_x, num * 10 + digit[new_y][new_x], cnt + 1);	// 원래 수를 왼쪽으로 1칸씩 밀고 뒤에 새로운 수 추가하는 원리
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);     // 시간초과방지

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> digit[i][j];
		}
	}
	// 모든 좌표에 대해 가능한 6자리 수 만들기
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			dfs(i, j, 0, 0);
		}
	}

	sort(v.begin(), v.end());		// unique(,) 사용을 위해 정렬
	v.erase(unique(v.begin(), v.end()), v.end());		// 6자리 수들 중 중복 수 제거

	cout << v.size();	// 서로 다른 6자리 수의 개수 출력

	return 0;
}