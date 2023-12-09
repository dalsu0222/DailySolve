#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

int N;
int map[64][64];		// N->64까지로 증가
int visited[64][64];		// 방문여부 체크하지 않으면 메모리 초과 에러 발생
queue <pair<int, int>> q;
int dx[2] = { 0,1 };
int dy[2] = { 1,0 };

bool bfs(int i, int j) {
	visited[i][j] = 1;
	q.push(make_pair(i, j));
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 2; i++) {
			int new_x = x + dx[i] * map[x][y];		// cnt = map[x][y]
			int new_y = y + dy[i] * map[x][y];
			if (0 <= new_x && 0 <= new_y && new_x < N && new_y < N
				&& visited[new_x][new_y] == 0) {
				// 방문하고자 하는 곳이 도착지점이면 종료
				if (map[new_x][new_y] == -1) {
					return true;
				}
				// 범위 안이면서 도착지점 아닌경우에, 큐에 다음 장소로 추가
				q.push(make_pair(new_x, new_y));
				visited[new_x][new_y] = 1;
			}
		}
	}
	return false;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	if (bfs(0, 0))
		cout << "HaruHaru";
	else
		cout << "Hing";

	return 0;
}