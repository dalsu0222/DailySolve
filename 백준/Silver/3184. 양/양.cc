#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;
int r, c;
char map[251][251];
bool visited[251][251];
int total_s, total_w;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

void bfs(int x, int y) {
	visited[x][y] = true;
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));

	int wolf = 0;	int sheep = 0;

	while (!q.empty()) {
		int tmpx = q.front().first;
		int tmpy = q.front().second;
		q.pop();
		if (map[tmpx][tmpy] == 'v') wolf++;	// 늑대, 양 개수 카운트
		if (map[tmpx][tmpy] == 'o') sheep++;

		for (int a = 0; a < 4; a++) {
			int nx = tmpx + dx[a];
			int ny = tmpy + dy[a];
			if (nx <= 0 || ny <= 0 || nx > r || ny > c)
				continue;
			if (map[nx][ny] != '#' && !visited[nx][ny]) {	// 울타리 안에서만 카운트
				visited[nx][ny] = true;
				q.push(make_pair(nx, ny));
			}

		}
	}
	if (sheep > wolf)	// 문제 조건에 따라 최종 양, 늑대 개수 카운트
		total_s += sheep;
	else
		total_w += wolf;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> r >> c;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cin >> map[i][j];
		}
	}

	// 영역 안의 개수 문제 -> bfs로 접근
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			// '.' -> 빈 필드, 어떠한 처리도 X
			if (visited[i][j])
				continue;
			bfs(i, j);
		}
	}
	cout << total_s << " " << total_w;
	
	return 0;
}