#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;
int N;
int map[101][101];
int max_cnt;
bool visited[101][101];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int cnt;

void bfs(int x, int y, int h) {
	queue<pair<int, int>> q;
	if (map[x][y] - h > 0) {	// 안전지대일 경우만 이웃지대 방문
		q.push(make_pair(x, y));
		visited[x][y] = true;

		while (!q.empty()) {
			int cur_x = q.front().first;
			int cur_y = q.front().second;
			q.pop();
			for (int a = 0; a < 4; a++) {
				int new_x = cur_x + dx[a];
				int new_y = cur_y + dy[a];
				if (new_x < 0 || new_y < 0 || new_x >= N || new_y >= N)	// 범위밖일경우 연산 진행X
					continue;
				if (map[new_x][new_y] - h > 0 && !visited[new_x][new_y]) {	// 아직 방문하지 않은 안전지대일 경우, 연산 진행
					q.push(make_pair(new_x, new_y));
					visited[new_x][new_y] = true;
				}
				
			}
		}
		cnt++;		// 높이 h에서의 안전구역 개수 1 증가
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);

	cin >> N;
	int max_H = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (max_H < map[i][j])	// 최대지역의 높이 저장
				max_H = map[i][j];
		}
	}

	for (int h = 0; h <= max_H; h++) {	// 물이 없는 경우부터, 지대의 최대높이 직전까지만 수행
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!visited[i][j]) {
					bfs(i, j, h);
				}
			}
		}
		// 결과 갱신 및 cnt, visited 초기화
		if (max_cnt < cnt) {
			max_cnt = cnt;
		}
		cnt = 0;
		memset(visited, false, sizeof(visited));
	}
	
	cout << max_cnt;

	return 0;
}