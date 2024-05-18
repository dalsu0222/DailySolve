#include<iostream>
#include<queue>
#include<cstring>

using namespace std;

int w, h;
int map[51][51];
bool visited[51][51];
int cnt;

int dx[8] = { -1,-1,-1,0,0,1,1,1 };		// 3x3 기준으로 맨 위 왼쪽부터 시작하는 방향 (가운데 제외)
int dy[8] = { -1,0,1,-1,1,-1,0,1 };

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	visited[x][y] = true;
	while (!q.empty()) {
		int tmpx = q.front().first;
		int tmpy = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++) {
			int nx = tmpx + dx[i];
			int ny = tmpy + dy[i];
			if (nx < 0 || ny < 0 || nx >= h || ny >= w)
				continue;
			if (!visited[nx][ny] && map[nx][ny] == 1) {
				q.push(make_pair(nx, ny));
				visited[nx][ny] = 1;
			}
		}
	}
}

int main() {
	while (1) {
		cin >> w >> h;
		if (w == 0 && h == 0)
			break;

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> map[i][j];
			}
		}

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (!visited[i][j] && map[i][j] == 1) {
					bfs(i, j);
					cnt++;
				}
			}
		}


		cout << cnt << "\n";
		cnt = 0;
		memset(visited, false, sizeof(visited));
		memset(map, 0, sizeof(map));
	}

	return 0;
}