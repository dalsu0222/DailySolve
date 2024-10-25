#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int r, c, k;
int result;
char map[6][6];
bool visited[6][6];
int dx[4] = { -1,1,0,0 };	// 상하좌우 순
int dy[4] = { 0,0,-1,1 };

void dfs(int x, int y, int dist) {
	if (x == 0 && y == c - 1 && dist == k) {
		result++;
		return;
	}
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		// 갈 수 없는 길인경우, continue
		if (nx < 0 || ny < 0 || nx >= r || ny >= c
			|| visited[nx][ny] || map[nx][ny] == 'T') {
			continue;
		}
		visited[nx][ny] = true;
		dfs(nx, ny, dist + 1);
		visited[nx][ny] = false;	// 백트래킹, 최단거리만이 정답은 아니므로 필요. 갔다가 다시 되돌아오기
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> r >> c >> k;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> map[i][j];
		}
	}

	visited[r - 1][0] = true;
	dfs(r - 1, 0, 1);	// 깊이 우선 탐색을 이용하여, 갈 수 있는 경로를 단위로 목표지점까지 한 번에 탐색하여 체크함.

	cout << result;
	
	return 0;
}
