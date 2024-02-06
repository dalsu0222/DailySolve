#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
int N;
int map[101][101];
bool isRoad;		// i에서 j로의 경로가 있는지의 여부

void bfs(int x,int y, bool visited[101]) {
	//visited[x] = true;	// x->x로의 간선은 별개로 존재해야하므로 처음방문체크 X
	queue<int> q;		// 목표 지점 큐
	q.push(x);
	while (!q.empty()) {
		int a = q.front();
		q.pop();

		if (visited[a] && a == y) {	// 큐의 top 원소(a)가 목표지점(y)과 일치한다면
			isRoad = true;	// x에서 y로의 경로가 있다고 판단
			break;
		}
		for (int i = 0; i < N; i++) {
			if (!visited[i] && map[a][i] == 1) {	// 아직 i를 방문하지 않았고, a에서 i로의 경로가 있다면
				q.push(i);	
				visited[i] = true;
			}
		}
		
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);     // 시간초과방지

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			bool visited[101] = { false, };
			bfs(i, j, visited);	// i에서 j로의 경로 여부 검사

			if (isRoad) {
				cout << 1 << " ";
			}
			else
				cout << 0 << " ";

			isRoad = false;		// 다음 계산을 위해 경로 여부 초기화
		}
		cout << "\n";
	}

	return 0;
}