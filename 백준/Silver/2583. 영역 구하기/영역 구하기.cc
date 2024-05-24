#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int m, n, k;
int map[101][101];
bool visited[101][101];
int dx[4] = { -1,0,1,0 };	// 북쪽부터 시계방향
int dy[4] = { 0,1,0,-1 };
int cnt;		// 영역 넓이
int result;		// 영역 개수
vector<int> area;		// 각 영역넓이 저장

void bfs(int x, int y) {
	visited[x][y] = true;
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	cnt++;

	while (!q.empty()) {
		int tmpx = q.front().first;
		int tmpy = q.front().second;
		q.pop();

		for (int a = 0; a < 4; a++) {
			int nx = tmpx + dx[a];
			int ny = tmpy + dy[a];
			if (nx < 0 || ny < 0 || nx >= m || ny >= n)
				continue;
			if (!visited[nx][ny] && map[nx][ny] == 0) {	// 분리된 영역일경우, 카운트
				visited[nx][ny] = true;
				cnt++;	// 방문할때마다 영역의 넓이 1 증가
				q.push(make_pair(nx, ny));
			}
		}
	}
}

int main() {
	cin >> m >> n >> k;
	
	int x1, y1, x2, y2;
	for (int i = 0; i < k; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		for (int j = y1; j < y2; j++) {
			for (int r = x1; r < x2; r++) {
				map[j][r] = 1;
			}
		}
	}
	
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited [i][j] && map[i][j] == 0) {
				bfs(i, j);	
				result++;	// 영역 추가
				area.push_back(cnt);
				cnt = 0;	// 초기화
			}
		}
	}

	sort(area.begin(), area.end());
	cout << result << "\n";
	for (int i = 0; i < result; i++) {
		cout << area[i] << " ";
	}

	
	return 0;
}