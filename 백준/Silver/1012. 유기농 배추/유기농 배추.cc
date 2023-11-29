#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

int T, M, N, K, X, Y;
int b[50][50];
int visited[50][50];
int dx[4] = { 0,0,-1,1 };	// 일반적인 좌표(x,y)로 저장하기 위함
int dy[4] = { -1,1,0,0 };	// 상하좌우 순
queue <pair<int, int>> q;

void bfs(int x, int y) {	// 방문 배추 체크
	visited[x][y] = 1;
	q.push(make_pair(x, y));

	while (!q.empty()) {
		int v1 = q.front().first;
		int v2 = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int new_x = v1 + dx[i];
			int new_y = v2 + dy[i];
			
			if (0 <= new_x && 0 <= new_y && new_x < M && new_y < N
				&& visited[new_x][new_y] == 0 && b[new_x][new_y] == 1) {
				// 이웃하면서(동서남북 위치) 방문한 적 없는 집일 때
				q.push(make_pair(new_x, new_y));
				visited[new_x][new_y] = 1;
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	for (int i = 0; i < T; i++) {
		memset(b, 0, sizeof(b));
		memset(visited, 0, sizeof(visited));
		cin >> M >> N >> K;
		for (int j = 0; j < K; j++) {
			cin >> X >> Y;
			b[X][Y] = 1;
		}
		
		int result = 0;
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < N; k++) {
				if (b[j][k] == 1 && visited[j][k] == 0) {
					bfs(j, k);
					result++;
				}
			}
		}

		cout << result << "\n";
	}
	

	return 0;
}