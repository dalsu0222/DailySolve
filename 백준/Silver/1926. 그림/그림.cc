#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;
int n, m;
int map[501][501];
bool visited[501][501];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int cnt;		// 각 그림의 넓이
int max_size;			// 그림의 최대 넓이
int result;	// 그림의 개수

void bfs(int x, int y) {
	visited[x][y] = true;
	queue <pair<int, int>> q;
	q.push(make_pair(x, y));
	cnt = 0;	// 그림 넓이 초기화
	result++;		// 전체 그림갯수  = bfs 동작 시작 횟수

	while (!q.empty()) {
		cnt++;		// 각 그림의 넓이 = 근처 칸으로 건너가는 횟수

		pair<int, int> tmp = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = tmp.first + dx[i];
			int ny = tmp.second + dy[i];
			if (nx <= 0 || ny <= 0 || nx > n || ny > m)
				continue;
			if (!visited[nx][ny] && map[nx][ny] == 1) {
				visited[nx][ny] = true;
				q.push(make_pair(nx, ny));
			}
		}
	}
	if (cnt > max_size) {
		max_size = cnt;
	}
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if(!visited[i][j] && map[i][j] == 1)
				bfs(i, j);
		}
	}

	cout << result << "\n";
	cout << max_size;

	return 0;
}